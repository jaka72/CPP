#include <stdio.h>

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
		//i++;
	}
	else
		strA = &argv[1][0];

	for (  ; strA[i] != '\0'; i++)
		lenA++;
	
	printf("a)\n");

	i = 0;
	if (argv[2][0] == '-')
	{
		signB = 1;
		strB = &argv[2][1];
		//i++;
	}
	else
		strB = &argv[2][0];

	for (  ; strB[i] != '\0'; i++)
		lenB++;

	if (signB != signA)
		finalsign = 1;


	size_t arrSize = lenA + lenB;
	printf("signA%d, signB%d, lenA%zu, lenB%zu, finalsign%d, arrSize%zu\n", signA, signB, lenA, lenB, finalsign, arrSize);

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


	// print if arrs are correct
	for (i = 0; i < arrSize; i++)
		printf(".%d", arrA[i]);
	printf("\n");
	for (i = 0; i < arrSize; i++)
		printf(".%d", arrB[i]);
	printf("\n");


	int result = 0;
	size_t j = 0;
	for (i = 0; i < lenA; i++)
	{
		printf("loop i%zu\n", i);

		j = 0;
		for ( ; j < lenB; j++)
		{
			result = arrA[i] * arrB[j];
			printf("   result a): %d\n", result);

			if (result > 9)
			{
				printf("      --- %d\n", result);
				for ( size_t q = j; q < lenB; q++)
				{	
					arrFinal[q] = arrFinal[q] + (result % 10);
					arrFinal[q + 1] = arrFinal[q + 1] + (result / 10);
					printf("      final[%zu]: %d\n", q, arrFinal[q]);
				}
			}
			else		// SOMEHERE HERE IS NOT CALCULATING CORRECTLY !!!
			{
				arrFinal[i + j] = arrFinal[i + j] + result; 
				printf("   ... i+j%zu,  arrfinal:%d\n", i + j,  arrFinal[i + j]);
			}
		}
	}

	printf("Final:\n");
	for (i = 0; i < arrSize; i++)
		printf(".%d", arrFinal[i]);
	printf("\n");

}