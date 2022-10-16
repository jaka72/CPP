/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat_main.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 15:15:49 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/13 18:44:18 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"

/*			  
size_t strlcat(      char *restrict dest, 
			   const char *restrict src, 
			   size_t dstsize);

Prilepi source na konec dest[10] in doda \0. 
Obe skupaj sta dolgi najvec (odvisno):
	srclen + size   ALI   srclen + dstlen

	if  argsize < destlen  => return: srclen + argsize
	if  argsize > destlen  => return: srclen + destlen

Od srclen se vedno odsteje -1 glede na size, ker je zadnji znak vedno \0
npr: abc, DEF, 0 =  abc\0     return 3,   ok
npr: abc, DEF, 1 =  abc\0     return 4,   ok   == srclen + size = 4
npr: abc, DEF, 2 =  abc\0     return 5,   ok
npr: abc, DEF, 3 =  abc\0     return 6,   ok
npr: abc, DEF, 4 =  abc\0     return 6,   ok
npr: abc, DEF, 5 =  abcD\0    return 6,   ok    == abc + D + \0  == 5
npr: abc, DEF, 7 =  abcDEF\0  return 6,   ok
npr: abc, DEF, 15 = abcDEF\0  return 6,   ok

Ce je size 0, vrne dolzino dest. 
Drugace vrne srclen + size, vendar nikoli ne vec, 
kot destlen + srclen (v primeru da je size vec kot srclen)
- ce je size > srclen, vrne destlen + srclen
- ce je size < srclen, vrne srclen + 

Za pazit:  dest buffer ima neko vrednost, npr dest[10].  Size je zgleda lahko vec 
															kot 10 in ni narobe.
			Ce je size manjsa kot dolzine dest, potem dest ostane nespremenjena, 
									ampak source ne bo viden. Vrne destlen. 

PROBLEM JE PRI OVERLAP: dest = 5, size je 7, se pravi return 5 + 7 -1 = 11


///// FROM MANUAL ///////////////////////////////////////////////////////

strlcat() appends string src to the end of dst.

							5  -   3         - 1   = 1
						abcD\0 -  abc        -\0   = D						   
It will append at most dstsize - strlen(dst) - 1 characters.  
It will then NUL-terminate.
(Unless dstsize is 0 or the original dst string was longer than dstsize (in 
practice this should not happen as it means that either dstsize is incorrect 
or that dst is not a proper string).
							????
If the src and dst strings overlap, the behavior is undefined. ???

RETURN VALUES
Besides quibbles over the return type (size_t versus int) and signal handler 
safety (snprintf(3) is not entirely safe on some systems), the following two 
are equivalent:

Strlcat() returns the total length of the string they tried to create. 
For strlcat() that means the initial length of dst plus the length of src. ???  THIS SEEMS INCORRECT STATEMENT
IN FACT IT RETURNS SIZE + SRCLEN

								(it probably means, source has been truncated)
If the return value is >= dstsize, the output string has been truncated.  
It is the caller's responsibility to handle this.
*/

/////CLONE FROM LOOG. /////////////////////////////////
static size_t	strlen_max(const char *dest, size_t size)
{
	size_t	len;

	len = 0;					// ZGLEDA DA JE TO NUJNO, DA LEN NI VISJA KOT SIZE !!!
	while (len < size && dest[len] != '\0') 
		len++;
	return (len);
}

size_t			clone_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_initial_len;
	size_t	src_index;

	dst_initial_len = strlen_max(dst, size);  // 2 moznosti: dolzina od dest, ali size, 
	src_index = 0;							  // ce je size manjsa od len dest
	while (dst_initial_len + src_index + 1 < size && src[src_index] != '\0')
	{
		dst[dst_initial_len + src_index] = src[src_index]; // kopiranje src na konec dest
		src_index++;
	}
	if (dst_initial_len + src_index < size)
		dst[dst_initial_len + src_index] = '\0';
	return (dst_initial_len + ft_strlen(src));
}
///////////////////////////////////////////


// THIS ONE IS NEW AND WORKING 
size_t ft_strlcat2(char *dest, const char *src, size_t size)
{
	size_t length;
	size_t i;

	length = ft_strlen(dest);
	if (size < ft_strlen(dest))
		length = size;
	i = 0;
	while (src[i] != '\0' && size > length + i + 1)
	{
		dest[length + i] = src[i];
		i++;
	}
	if (size > length + i)
		dest[length + i] = '\0';
	return (length + ft_strlen(src));
}


/////////////////////////////////////////////////////

size_t	ft_strlcat_old(char *dest, const char *src, size_t size)
{
	char	*end;
	char 	*source;
	size_t	len;
	size_t i;

	source = (char *)src;  // nujno cast, drugac ne dela
	end = (char *)ft_memchr(dest, '\0', size); // locates first '\0'

	if (end == NULL) // ?? WHY IS THIS NECESARRY  ???
	{ // if it's not found in first 'size' bytes
		printf("end is null!\n");
		return (size + ft_strlen(src));
	}
	len = ft_strlen(dest) + ft_strlen(source); // je to isto: lendst + lensrc
	i = 0;
	while (ft_strlen(dest) < size - 1 && source[i] != '\0') // NUJNO dest < size !!!
	{	// 
		*end++ = source[i++];  // kopira v dest od \0 dalje, ampak ne vec kot size -1
		//printf("dest[]: %c\n", *end);
	}
	*end = '\0';
	if (dest == src)
		return (len + i);
	else
		return (len);
}


// gcc main.c ft_strlcat.c libft.h ft_strlen.c -lbsd

int main(void)
//int main(void) 
{

	char    *dest;
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	dest[0] = '\0';
	dest[11] = 'a';
	//printf("dest: %s\n\n", dest);


/*                           abcd + EFG = abcdEFG
   VRNE DOLZINO dest IN src:  4   +  3  =   7
   ARGUMENT size POMENI SKUPNO DOLZINO dest + src + \0 , TOREJ 4 + 3 + 1 = 8
   TOREJ CE HOCEM, DA SE CELI src SKOPIRA, MORAM DAT V ARGUMENT +1
*/

/*	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	char buff3[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + strlen("there is no stars in the sky");
*/
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_STRLCAT ---------------------------------------------\n\n"RESET);

	printf(MAG"Test JAKA 00: arg_size < destlen\n"RESET);
	char *str0 = "AAAAA";
//	char dest0a[15] = "1234567890"; 
	char dest0b[15] = "1234567890";
	char dest0c[15] = "1234567890";
	int size = 7;
	printf("arg_size: %d, dest: \"%s\", src: \"%s\"\n", size, dest0c, str0);
//	printf("     orig: %lu, %s\n",        strlcat(dest0a, str0, size), dest0a);
	printf(HWHT"    clone: %lu, %s\n",  clone_strlcat(dest0b, str0, size), dest0b);
	printf("     mine: %lu, %s\n\n"RESET,   ft_strlcat(dest0c, str0, size), dest0c);

	
	
	printf(MAG"Test JAKA 01: arg_size > destlen\n"RESET);
	char *str01 = "AAAAA";
	//char dest01a[15] = "1234567890"; 
	char dest01b[15] = "1234567890";
	char dest01c[15] = "1234567890";
	size = 17;
	printf("arg_size: %d, dest: \"%s\", src: \"%s\"\n", size, dest01c, str01);
	//printf("     orig: %lu, %s\n",        strlcat(dest01a, str01, size), dest01a);
	printf(HWHT"    clone: %lu, %s\n",  clone_strlcat(dest01b, str01, size), dest01b);
	printf("     mine: %lu, %s\n\n"RESET,   ft_strlcat(dest01c, str01, size), dest01c);



	printf(MAG"Test JAKA 02: arg_size < destlen, but together smaller then destlen:\n"RESET);
	char *str02 = "AAAAA";
	//char dest02a[15] = "1234567890"; 
	char dest02b[15] = "1234567890";
	char dest02c[15] = "1234567890";
	size = 3;
	printf("arg_size: %d, dest: \"%s\", src: \"%s\"\n", size, dest02c, str02);
	//printf("     orig: %lu, %s\n",        strlcat(dest02a, str02, size), dest02a);
	printf(HWHT"    clone: %lu, %s\n",  clone_strlcat(dest02b, str02, size), dest02b);
	printf("     mine: %lu, %s\n\n"RESET,   ft_strlcat(dest02c, str02, size), dest02c);



	printf(MAG"Test JAKA 03: arg_size > destlen, but together not enough for both strings:\n"RESET);
	char *str03 = "AAAAA";
	//char dest03a[15] = "1234567890"; 
	char dest03b[15] = "1234567890";
	char dest03c[15] = "1234567890";
	size = 13;
	printf("arg_size: %d, dest: \"%s\", src: \"%s\"\n", size, dest03c, str03);
	//printf("     orig: %lu, %s\n",        strlcat(dest03a, str03, size), dest03a);
	printf(HWHT"    clone: %lu, %s\n",  clone_strlcat(dest03b, str03, size), dest03b);
	printf("     mine: %lu, %s\n\n"RESET,   ft_strlcat(dest03c, str03, size), dest03c);



	printf(MAG"Test UNIT 09\n"RESET);
	char *str1a = "cdefghi"; 
	//char dest1a[15] = "AB";  
	char dest1b[15] = "AB";
	char dest1c[15] = "AB";
	//printf("  orig: %lu, %s\n",        strlcat(dest1a, str1a, 10), dest1a);
	printf("     clone: %lu, %s\n",  clone_strlcat(dest1b, str1a, 10), dest1b);
	printf("      mine: %lu, %s\n\n",   ft_strlcat(dest1c, str1a, 10), dest1c);

	printf(MAG"Test UNIT 01 \n"RESET);
	char *str = "lie !\0lol\r\n"; // len 5 +
	//char dest1[0xF00] = "there";  // len 5 = max 10
	char dest2[0xF00] = "there";
	char dest3[0xF00] = "there";
	size_t max = strlen("lie !\0lol\r\n") + strlen("there");
	printf("max: %lu\n", max);
	//printf("  orig: %lu, %s\n",        strlcat(dest1, str, 15), dest1);
	printf("     clone: %lu, %s\n",  clone_strlcat(dest2, str, 15), dest2);
	printf("      mine: %lu, %s\n\n",   ft_strlcat(dest3, str, 15), dest3);

	printf(MAG"Test UNIT 09 \n"RESET);
	//your strlcat crash because it read too many bytes or attempt to write on buff !
	//char   str1[15] = "GHJ";
	//char dest2a[15] = "abcde";
	char dest2b[15] = "abcde";
	char dest2c[15] = "abcde";
	//printf("   orig: %lu, %s\n",       strlcat(dest2a, dest2a, 20), dest2a);
	printf("      clone: %lu, %s\n", clone_strlcat(dest2b, dest2b, 20), dest2b);
	printf("       mine: %lu, %s\n\n",  ft_strlcat(dest2c, dest2c, 20), dest2c);


	printf(MAG"\nTest 01 Warmachine\n"RESET);
	//char buff1a[15] = "abcde"; 
	char buff1b[15] = "abcde";
	char buff1c[15] = "abcde";
	//buff1a[11] = 'a'; 
	//buff1b[11] = 'a'; 
	//buff1c[11] = 'a';
	//printf("   orig: %lu, %s\n",        strlcat(buff1a, "FGH", 4), buff1a);
	printf("      clone: %lu, %s\n",  clone_strlcat(buff1b, "FGH", 4), buff1b);
	printf("       mine: %lu, %s\n",     ft_strlcat(buff1c, "FGH", 4), buff1c);

  	return (0);
}


