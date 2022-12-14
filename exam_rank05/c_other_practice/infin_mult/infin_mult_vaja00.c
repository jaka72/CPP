#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("provide 2 args!\n");
		return (0);
	}

	int signA = 0;
	int signB = 0;
	int finalsign = 0;
	char *strA;
	char *strB;
	size_t lenA = 0;
	size_t lenB = 0;
	size_t i = 0;

	if (argv[1][0] == '-')
	{
	   	signA = 1;
		strA = &argv[1][1];
	}
	else
		strA = &argv[1][0];

	for (  ; strA[i] != '\0'; i++)
		lenA++;
	i = 0;
	if (argv[2][0] == '-')
	{
		signB = 1;
		strB = &argv[2][1];
	}
	else
		strB = &argv[2][0];

	for (  ; strB[i] != '\0'; i++)
		lenB++;

	if (signB != signA)
		finalsign = 1;
	size_t arrSize = lenA + lenB;
	//printf("signA%d, signB%d, lenA%zu, lenB%zu, finalsign%d, arrSize%zu\n", signA, signB, lenA, lenB, finalsign, arrSize);
	// save to array in reverse order
	int arrA[arrSize];
	int arrB[arrSize];
	int arrFinal[arrSize];

	for (i = 0; i < arrSize; i++)
	{
		arrA[i] = 0;
		arrB[i] = 0;
		arrFinal[i] = 0;
	}
	
	size_t x = 0;
	for (i = lenA; i > 0; i--, x++)
		arrA[x] = strA[i - 1] - '0';

	x = 0;
	for (i = lenB; i > 0; i--, x++)
		arrB[x] = strB[i - 1] - '0';
	// NEW
	int result = 0;
	size_t j = 0;
	size_t q = 0;
	for (i = 0; i < lenB; i++)
	{
		for (j = 0; j < lenA; j++)
		{
			result = arrB[i] * arrA[j];
			arrFinal[i + j] = arrFinal[i + j] + result;
			if (arrFinal[i + j] > 9)
			{
				for (q = i + j; q < arrSize; q++)
				{
					//printf("          i%zu j%zu, res%d %d,  %d\n", i, j, result, arrFinal[q], arrFinal[q + 1]);
					arrFinal[q + 1] = arrFinal[q + 1] + (arrFinal[q] / 10);
					arrFinal[q] = arrFinal[q] % 10;
					//printf("      ... i%zu j%zu, res%d %d,  %d\n", i, j, result, arrFinal[q], arrFinal[q + 1]);
					if (arrFinal[q + 1] < 10)
						break ;
				}
			}
		}
	}
	if (arrSize == 2 && arrFinal[0] == 0 && arrFinal[1] == 0)
	{
		write(1, "0", 1);
		return 0;
	}
	if (finalsign == 1)
		write(1, "-", 1);
	for (i = arrSize; i > 0; i--)
	{
		if (arrFinal[i - 1] != 0)
			break ;
	}
	for ( ; i > 0; i--)
		printf("%d", arrFinal[i - 1]);
	printf("\n");
}