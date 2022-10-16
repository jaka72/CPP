#include <stdio.h>
#include <string.h>
#include "../srcs_eval/libft.h"
#include "../libft_mains.h"
/*
void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
The memmove() function copies len bytes from string src to string dst.

The two strings may overlap;
								???
The copy is always done in a non-destructive manner.

// Src len ne sme bit vecja od destlen !!! segfault, ali kopira cudne znake
//      Sicer vcasih dela, ce ni razlika prevelika ?
// Len ne sme bit vecja od srclen !!! Segfault

RETURN VALUES
     The memmove() function returns the original value of dst.


// ERRORS
// THERE NEEDS TO BE HANDLED THE CASES WHERE dest and src CAN BE COPIED INTO EACH OTHER:
// 			memmove(dest, src, 8)
//          memmove(src, dest, 8)

// IN THE TEST THERE IS THIS TRICK: dest = source = 1;    THIS CAUSES THE FOLLOWING ERROR:
cat test03.output
	lorem ipum dolor sit a
cat user_output_test03
	llllllllum dolor sit aj    // REPEATING THE SAME LETTER, INSTAD OF MOVING ON

*/

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	char *s;
	char *d;

	// char s[20];	// error, can not be later:  s = (char*)src
	// char d[20];

	if (!dest && !src)
		return (NULL);
	s = (char*)src;
	d = (char*)dest;
	if (s < d)  // THIS IS NEEDED IN CASE SRC IS LOCATED IN MEMORY BEFORE DEST 
	{			//   TO HANDLE OVERLAPPING
				//  IT NEEDS TO START COPYING AT THE END, TO PREVENT REPETITION
				// THE STR IS COPIED INTO ITSELF, WITH OFFSET, is: dest + 3, src
		s = s + len - 1;
		d = d + len - 1;  	// HERE SETS BOTH D AND S TO THE END OF len - 1 
		while (len-- > 0)	// COPIES FROM END TO START
		{
			printf("   -------- %c\n", *s);
			*d-- = *s--;
			// d-- = s--;
		}
	}
	else
		while (len-- > 0)
			*d++ = *s++;
	return (dest);
}

// HERE WAS A VERSION THAT DID NOT SUPPORT OVERLAP!

// VAJA PONAVLJANJE //////////////////////////////////////////




int main(void) 
{
	printf(HYEL"\n------------------------------------------------------------");
	printf("\n--- FT_MEMMOVE ---------------------------------------------\n\n"RESET);

	//char *weird = "thiß ß \xde \xad \xbe \xef triñg will be øvérlapéd !\r";
	//printf("weird string: %s\n", weird);
	//printf("weird characters:  %c %c %c \n", '\xde', '\xbe', '\xef');  // de == 222, be == 190, ef == 239
	//printf("this is not normal c: %s\n", "ñ");

	printf(MAG"\nSIMPLE TEST:\n"RESET);
	char source1a[50] = "SOURCE";
	char source2b[50] = "SOURCE";
	char dest1a[50] = "destination";
	char dest2b[50] = "destination";
	int n = 6;
	printf("dest: %s,  src: %s\n", dest1a, source1a);
	printf("memmove(dest, src, %d)\n", n);
  	printf(HWHT"   orig: %s\n",       (char*)memmove(dest1a, source1a, n));
	printf("   mine: %s\n\n"RESET, (char*)ft_memmove(dest2b, source2b, n));

	char *str = "abcdefghijkl";


	printf("   -------- %c\n", *str);
	str++;
	printf("   -------- %c\n", *str);

	printf("   -------- %c\n", *str);


// 	printf(MAG"\nUNIT TEST 03:\n"RESET);
// 	char src[]  = "lorem ipsum dolor sit amet";
// 	char src1[] = "lorem ipsum dolor sit amet";
// 	char *dest;
// 	char *dest1;
// 	dest  = src + 1;
// 	dest1 = src1 + 1;
// 	printf("dest: %s,  src: %s\n", dest, src);
// 	printf("memmove(dest, src, 8)\ndest  = src + 1;\n");
// 	printf(HWHT"   orig: %s\n",        (char*)memmove(dest, src, 8));
// 	printf("   mine: %s\n\n"RESET, (char*)ft_memmove(dest1, src1, 8));



// 	printf(MAG"\nTEST: DESTINATION = SOURCE:\n"RESET);
// 	char src3a[]  = "abcde";
// 	char src3b[] = "abcde";
// 	char *dest3a;
// 	char *dest3b;
// 	dest3a = src3a + 1;
// 	dest3b = src3b + 1;
// 	printf(" src:    %s\n dest:   \"\"\n dest  = src + 1; \n", src3a);
// 	printf(" dest:   %s          memmove(dest, src, 1)\n", dest3a);
// 	printf(HWHT"     orig: %s\n",        (char*)memmove(dest3a, src3a, 1));
// 	printf("     mine: %s\n\n"RESET, (char*)ft_memmove(dest3b,  src3b, 1));

// // NOT WORKING ???
// 	// char src4a[]  = "abcde";
// 	// char *dest4a  = "ABCD";
// 	// char *result;
// 	// result = (char*)ft_memmove(dest4a, src4a, 2);
// 	// printf("result: [%s]\n", result);


// 	printf(MAG"\nUNIT TEST 05: dest into dest\n"RESET);
// 	char dst1[80]; //   F0 == 240
// 	char dst2[80];
// //	char *src2 = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
// 	char *src2 = "This string will be overlapped!";
// 	int size = 5;
// 	memset(dst1, '-', sizeof(dst1));
// 	memset(dst2, '-', sizeof(dst2));
// 	dst1[sizeof(dst1) - 1] = '\0';
// 	dst2[sizeof(dst2) - 1] = '\0';
// //	printf("Dst1 after memset():  [%s]\n", dst1);
// 	memcpy(dst1, src2, strlen(src2));
// 	memcpy(dst2, src2, strlen(src2));
// //	printf("strlen(src): %ld\n", strlen(src2));
// 	printf("Dst after memcopy():\n        [%s]\n", dst1);
// 	   memmove(dst1 + 20, dst1, size); // OVERLAP + 3
// 	ft_memmove(dst2 + 20, dst2, size); // OVERLAP + 3
// 	printf("   orig: %s\n", dst1);
// 	printf("   mine: %s\n\n", dst2);


// 	printf(MAG"\nTEST 06\n"RESET);
// 	char dst3a[80];
// 	char dst3b[80];
// 	char *src3 = "This string will be overlapped!";
// 	memset(dst3a, '-', sizeof(dst3a));
// 	memset(dst3b, '-', sizeof(dst3b));
// 	dst3a[sizeof(dst3a) - 1] = '\0';
// 	dst3b[sizeof(dst3b) - 1] = '\0';
// 	memcpy(dst3a, src3, strlen(src3));
// 	memcpy(dst3b, src3, strlen(src3));
// 	printf("Dst after memcopy():\n        [%s]\n", dst3a);
// 	   memmove(dst3a + 1, dst3a, 1);
// 	ft_memmove(dst3b + 1, dst3b, 1);
// 	printf("   orig: %s\n", dst3a);
// 	printf("   mine: %s\n\n", dst3b);


// 	printf(MAG"\nTEST 07\n"RESET);
// 	char dst4a[80];
// 	char dst4b[80];
// 	char *src4 = "This string will be overlapped!";
// 	memset(dst4a, '-', sizeof(dst4a));
// 	memset(dst4b, '-', sizeof(dst4b));
// 	dst4a[sizeof(dst4a) - 1] = '\0';
// 	dst4b[sizeof(dst4b) - 1] = '\0';
// 	memcpy(dst4a, src4, strlen(src4));
// 	memcpy(dst4b, src4, strlen(src4));
// 	printf("Dst after memcopy():\n        [%s]\n", dst4a);
// 	   memmove(dst4a + 20, dst4a, 15);
// 	ft_memmove(dst4b + 20, dst4b, 15);
// 	printf("   orig: %s\n", dst4a);
// 	printf("   mine: %s\n\n", dst4b);


/*
	printf("\nUNIT TEST overlapping experiment 01:\n");
	char dst2a[20]; //   F0 == 240
	char dst2b[20];
	//char *string2 = "thiß ßtriñg will be øvérlapéd !";  // WHAT TO DO WITH THESE WEIRD CHARS
	char *string2 = "THIS string will be øvérlapéd !";
	size = 15;
	memset(dst2a, '-', sizeof(dst2a));
	memset(dst2b, '-', sizeof(dst2b));	
	printf("dst1 after memset:  %s\n", dst2a);
	memcpy(dst2a, string2, strlen(string2));
	memcpy(dst2b, string2, strlen(string2));
	printf("dst1 after memcpy:  %s\n", dst2a);
	  memmove(dst2a + 5, dst2a, strlen(string2));
	//ft_memmove2(dst2b + 5, dst2b, size);
	ft_memmove(dst2b + 5, dst2b, size);
	printf("dst1 after memmove: %s\n\n", dst2a);
	printf("dst2 after memmove: %s\n\n", dst2b);





Test code: TEST UNIT test 05
	char dst1[0xF0]; //   F0 == 240
	char dst2[0xF0];
	char *data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	int size = 0xF0 - 0xF;

	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));
	memcpy(dst1, data, strlen(data));
	memcpy(dst2, data, strlen(data));
	memmove(dst1 + 3, dst1, size);
	ft_memmove(dst2 + 3, dst2, size);
	if (!memcmp(dst1, dst2, size))
		exit(TEST_SUCCESS);
	exit(TEST_FAILED);

Diffs:
     memmove: |thithiß ßޭ��triñg will be øvérlapéd !
				AAAAAAAAAAAAAAAA��j|
  ft_memmove: |thithithithithiAAAAAAAAAAAAthithiß ßޭ��triñg will be øvérlapéd !
				AAAAAAAAAAAAAA|
*/



  	return (0);
}
