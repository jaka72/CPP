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



size_t calculateArraysize(char *a, char *b, size_t *lenA, size_t *lenB, int *sign, size_t *jEnd, size_t *iEnd)
{
	size_t finalLen = 0;

	while (a[*lenA])
		(*lenA)++;
	printf("lenA %zu\n", *lenA);
	if (a[0] == '-')
	{
		//(*lenA)--;
		*sign *= -1;
		(*jEnd)++;
	}
	finalLen = *lenA;

	while (b[*lenB])
		(*lenB)++;
	if (b[0] == '-')
	{
		//(*lenB)--;
		*sign *= -1;
		(*iEnd)++;
	}

	finalLen = finalLen + (*lenB);
	if (*sign == -1)					// in case one str is negative
		finalLen--;

	if (a[0] == '-' && b[0] == '-')		// in case both str are negative
		finalLen = finalLen - 2;

	return (finalLen - 1);
}



// WHEN BOTH ARE NEGATIVE, THEN IT PRINTS 1 ZERO IN FRONT 

int main(int argc, char **argv)
{
	(void)argc;
	char *b = argv[1];
	char *a = argv[2];
	size_t lenA = 0;
	size_t lenB = 0;
	int sign 	= 1;

	size_t jEnd = 0;
	size_t iEnd = 0;

	size_t const arrSize = calculateArraysize(a, b, &lenA, &lenB, &sign, &jEnd, &iEnd);
	
	
	printf("lenA%zu, lenB%zu, jEnd%zu, iEnd%zu, arrSize%zu\n", lenA, lenB, jEnd, iEnd, arrSize);


	size_t arr[arrSize];
	

	size_t i = 0;
	while (i < arrSize)	// reset all to zeroes
		arr[i++] = 0;

	i 			= lenB;
	size_t j 	= lenA;
	size_t x 	= 0;
	size_t y 	= 0;
	size_t q 	= 0;
	int result 	= 0;



	while (j > jEnd)
	{
		//printf("LOOP j%zu\n", j - 1);
		i = lenB;
		y = q;
		while (i > iEnd)
		{
			x = y;
			result = (a[j - 1] - 48) * (b[i - 1] - 48);
			arr[x] = arr[x] + result;
			while (x < arrSize - 1)
			{
				if (arr[x] > 10)
				{
					arr[x + 1] = arr[x + 1] + (arr[x] / 10);
					arr[x] = arr[x] % 10;
				}
				x++;
			}
			i--;
			y++;
		}
		j--;
		q++;
	}

	printf("array size: %lu\n", sizeof(arr) / sizeof(arr[0]));

	printArray(arr, arrSize);

	printArrayReverse(arr, arrSize, sign);

}
