#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printArray(size_t *arr, size_t arrSize)
{
	printf("Final array:   ");
	size_t i = 0;
	while (i < arrSize)
		printf("%zu ", arr[i++]);
	printf("\n");
}



void	printArrayReverse(size_t *arr, size_t arrSize, int sign)
{
	write(1, "\nFinal array Reverse:   ", 24);
	int i = arrSize - 1;

	if (arr[i] == 0)
		i--;

	
	if (sign == -1)
		write(1, "-", 1);
	
	char c;
	while (i >= 0)
	{
		if (arr[i] > 9)
		{
			c = arr[i] / 10 + 48;
			write(1, &c, 1);
			//write(1, " ", 1);
			c = arr[i] % 10 + 48;
			write(1, &c, 1);
			//write(1, " ", 1);
		}
		else
		{
			c = arr[i] + 48;
			write(1, &c, 1);
			//write(1, " ", 1);
		}
		i--;
	}
	write(1, "\n", 1);
}




size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

void reverseString(char newstr[], char *oldstr, size_t len)
{
	size_t i = 0;
	while (len > 0)
	{
		newstr[i] = oldstr[len - 1];
		i++;
		len--;
	}
	newstr[i] = '\0';

	printf("newstr: %s\n", newstr);
}




int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("must provide 2 arguments\n");
		return (0);
	}

	char *strA = argv[1];
	char *strB = argv[2];

	size_t const lenA = ft_strlen(strA);
	size_t const lenB = ft_strlen(strB);

	char A[lenA + 1];
	char B[lenB + 1];

	reverseString(A, strA, lenA);
	reverseString(B, strB, lenB);

	size_t arraySize = lenA + 1;
	if (lenA < lenB)
		arraySize = lenB + 1;

	size_t arr[arraySize];
	printf("   arrSize: %ld\n", arraySize);
	for (size_t i = 0; i < arraySize; i++)
		arr[i] = 0;


	size_t ax = 0, by = 0, j = 0, q = 0;
	int result = 0;
	for (size_t i = 0; i < arraySize - 1; )
	{
		if (ax >= lenA)
		{
			printf("   a)\n");
			result = 0  +  (B[by] - 48);
		}
		else if (by >= lenB)
		{
			printf("   b)\n");
			result = (A[ax] - 48)  +  0;
		}
		else
		{
			printf("   c)\n");
			result = (A[ax] - 48)  +  (B[by] - 48);
		}
		printf("   i%ld,  result: %d\n", i, result);
		arr[i] = arr[i] + result;
		j = q;
		for (  ; j < arraySize; j++)
		{
			if (arr[j] > 9)
			{
				arr[j + 1] = arr[j + 1] + (arr[j] / 10);
				arr[j] = arr[j] % 10;
			}
			j++;
		}
		q++;
		i++;
		ax++;
		by++;
	}


	// printf("Final: %s")
	printArray(arr, arraySize);

	printArrayReverse(arr, arraySize, 0);


}