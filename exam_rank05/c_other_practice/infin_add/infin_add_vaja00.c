#include <unistd.h>
#include <stdio.h>


int checkIfAisSmaller(char *strA, char *strB, size_t lenA)
{
	//printf("CIS()\n");
	size_t i = 0;
	while (strA[i])
	{
		// printf("a%d  b%d\n", strA[i], strB[i]);
		if (strA[i] < strB[i])
			return (1);
		i++;
	}
	return (0);
}



int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("must have 2 args\n");
		return (0);
	}

	int signA = 0;
	int signB = 0;
	int finalSign = 0;
	char *strA;
	char *strB;
	if (argv[1][0] == '-')
	{
		signA = 1;
		strA = &argv[1][1];		// Store to argv string, set the minus sign
	}
	else
		strA = &argv[1][0];
	
	
	if (argv[2][0] == '-')
	{
		signB = 1;
		strB = &argv[2][1];
	}
	else
		strB = &argv[2][0];


	if (signA == 1 && signB == 1)
		finalSign = 1;




	size_t i = 0;
	while (argv[1][i])
		i++;
	if (signA == 1)
		i--;
	size_t lenA = i;					// get lengths

	i = 0;
	while (argv[2][i])
		i++;
	if (signB == 1)
		i--;
	size_t lenB = i;

	size_t biggerLen = lenA + 1;			// get biggest length
	if (lenA < lenB)
		biggerLen = lenB + 1;


	//printf("lenA%zu,  lenB%zu\n", lenA, lenB);


	int arrA[biggerLen];
	int arrB[biggerLen];
	int arrFinal[biggerLen];


	for (i = 0; i < biggerLen; i++)		// reset all to zero
	{
		arrA[i] = 0;
		arrB[i] = 0;
		arrFinal[i] = 0;
	}



	// Find if A is smaller
	int AisSmaller = 0;
	if (signA != signB)
	{
		if (lenA < lenB)
			AisSmaller = 1;
		else if (lenA == lenB)
			AisSmaller = checkIfAisSmaller(strA, strB, lenA);
	}
	//printf("aissmaller: %d,   biggerlen: %zu\n", AisSmaller, biggerLen);



	if (AisSmaller == 1) 				// swap strings and lengths 
	{
		char *temp = strA;
		strA = strB;
		strB = temp;
		size_t tempLen = lenA;
		lenA = lenB;
		lenB = tempLen;
		if (signB == 1)
			finalSign = 1;
	}

	if (AisSmaller == 0 && signA == 1)
		finalSign = 1;


	size_t x = 0;
	for (i = lenA; i > 0; i--)
		arrA[x++] = strA[i - 1] - '0';			// store string into array of ints, reverse order

	for (i = lenB, x = 0; i > 0; i--)
		arrB[x++] = strB[i - 1] - '0';

	//printf("\n");

	// check if stored correctly
	// for (i = 0; i < lenA; i++)
	//     printf(".%d", arrA[i]);
	// printf("\n");
	// for (i = 0; i < lenB; i++)
	//     printf(".%d", arrB[i]);
	// printf("\n");
	

	int result = 0;
	if ((signA == 0 && signB == 0) || (signA == 1 && signB == 1))	// ADDITION
	{
		for (i = 0; i < biggerLen; i++)
		{
			result = arrA[i] + arrB[i];
			//printf("Result: %d\n", result);
			if (result > 9)
			{
				arrA[i + 1] = arrA[i + 1] + 1;
				arrFinal[i] = result % 10;
			}
			else
				arrFinal[i] = result;
		}
	}
	else if (signA != signB)		// SUBSTRACTION
	{
		for (i = 0; i < biggerLen; i ++)
		{
			if (arrA[i] >= arrB[i])
				arrFinal[i] = arrA[i] - arrB[i];
			else
			{
					// substr 1 from next a+1
					// add 10 to a ,then substract a - b

					// if next is zero, start loop
					//			 each zero turns to 9, until found non-zero
				if (arrA[i + 1] != 0)
				{
					arrA[i + 1] = arrA[i + 1] - 1;
					arrFinal[i] = (arrA[i] + 10) - arrB[i];
				}
				else if (arrA[i + 1] == 0)
				{
					for (size_t j = i; j < biggerLen; j++)
					{
						arrA[j + 1] = 9;
						arrFinal[i] = 10 - arrB[i];
						if (arrA[j + 2] != 0)
						{
							arrA[j + 2] = arrA[j + 2] - 1;
							break ;
						}
					}
				}
			}
		}
	}

	if (finalSign == 1)
		write(1, "-", 1);

	for (i = biggerLen; i > 0; i--)
	{
		//printf("   %d\n", arrFinal[i - 1]);
		if (arrFinal[i - 1] != 0)
			break ;
	}


	// for (  i = biggerLen; i > 0; i--)
	for (    ; i > 0;   i--)
		printf("%d", arrFinal[i - 1]);

}
