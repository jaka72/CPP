#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printArray(int *arr, size_t arrSize)
{
	size_t i = 0;
	while (i < arrSize)
		printf("%d,", arr[i++]);
	printf("\n");
}



void	printArrayReverse(int *arr, size_t arrSize, int sign)
{
	int i = arrSize - 1;

	if (arr[i] == 0)
		i--;
	if (arr[i] == 0)	// IT CAN HAPPEN THAT THERE ARE 2 ZEROS AT THE END OF ARRAY (end is the begining!)
		i--;			// , MUST SKIP ZEROS

	if (arrSize == 2 && arr[0] == 0 && arr[1] == 0)
		write(1, "0", 1);

	if (sign == -1)
		write(1, "-", 1);
	
	char c;
	while (i >= 0)
	{
		if (arr[i] > 9)
		{
			c = arr[i] / 10 + 48;
			write(1, &c, 1);
			c = arr[i] % 10 + 48;
			write(1, &c, 1);
		}
		else
		{
			c = arr[i] + 48;
			write(1, &c, 1);
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




void reverseString(int newArr[], char *oldstr, size_t len, size_t biggerLen)
{
	size_t i = 0;

	while (i < biggerLen)	// Fill with zeroes
	{
		newArr[i] = 0;
		i++;
	}

	i = 0;
	while (len > 0)
	{
		newArr[i] = oldstr[len - 1] - 48;

		i++;
		len--;
	}
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

	int signA = 0, signB = 0, finalSign = 0;
	if (argv[1][0] == '-')		// Skip minus and store string
	{
		strA = argv[1] + 1;
		signA++;
	}
	if (argv[2][0] == '-')
	{
		strB = argv[2] + 1;
		signB++;
	}
	if (signA == 1 && signB == 1)
		finalSign = 1;

	size_t lenB = ft_strlen(strB);
	size_t lenA = ft_strlen(strA);



	// IN CASE OF ONLY 1 STRING IS NEGATIVE

	if (lenA > lenB && signA == 1)
		finalSign = 1;
	else if (lenA < lenB && signA != signB)	// smaller must be at 2nd place
	{
		printf("String length A is smaller, must swap!\n");
		char *temp;
		temp = strA;
		strA = strB;
		strB = temp;
		size_t tempLen;		// swap also the lengths
		tempLen = lenA;
		lenA = lenB;
		lenB = tempLen;
		if (signB == 1)
			finalSign = 1;
	}
	// IF BOTH HAVE SAME LENGTH, FIND BIGGER STRING, check each digit
	else if (lenA == lenB && signA != signB)
	{
		int AisBigger = 1;
		for (size_t i = 0; i < lenA; i++)
		{
			if (strA[i] < strB[i])
			{
				printf("Strings have same length, but A is smaller, must swap!\n");
				char *temp;
				temp = strA;
				strA = strB;
				strB = temp;
				size_t tempLen;		// swap also the lengths
				tempLen = lenA;
				lenA = lenB;
				lenB = tempLen;
				AisBigger = 0;
				if (signB == 1)
					finalSign = 1;
				break;
			}
		}
		if (signA == 1 && AisBigger == 1)
			finalSign = 1;
	}


	printf("newstr A:  %s\n", strA);
	printf("newstr B:  %s\n", strB);
	printf("finalSign: %d\n", finalSign);



	// MAKE BOTH LENGTHS THE SAME, SO THAT BOTH REVERSED ARRAYS WILL HAVE SAME SIZE
	size_t biggerLen;
	if (lenA > lenB)
		biggerLen = lenA;
	else
		biggerLen = lenB;




	int A[biggerLen];	// both lengths are now the same!
	int B[biggerLen];

	reverseString(A, strA, lenA, biggerLen);
	reverseString(B, strB, lenB, biggerLen);

	printArray(A, biggerLen);
	printArray(B, biggerLen);

	// size_t arraySize = lenA + 1;	// Make array. Take size of the longer string, plus 1
	// if (lenA < lenB)				// WHY PLUS 1 ???
	//  	arraySize = lenB + 1;


	size_t arraySize;		// Make array. Take size of the longer string, plus 1
	arraySize = biggerLen + 1;

	int arr[arraySize];
	printf("   arrSize: %ld\n", arraySize);
	for (size_t i = 0; i < arraySize; i++)
		arr[i] = 0;



	int result = 0;
	for (size_t i = 0; i < arraySize - 1; )
	{
		
		if ((signA == 1 && signB == 1) || (signA == 0 && signB == 0) )	// ADDITION
		{
			result = (A[i])  +  (B[i]);

			printf("   i%ld,  result: %d,  a[i]: %d\n", i, result, A[i]);
			arr[i] = arr[i] + result;
			
			if (arr[i] > 9)
			{
				arr[i + 1] = arr[i + 1] + (arr[i] / 10);
				arr[i] = arr[i] % 10;
			}
		}
		
		else if (signB != signA)		// SUBSTRACTION
		{
			printf("Substraction: %d - %d,   ", A[i], B[i]);

			if (A[i] >= B[i])					// a < b, can substract normally 
				result = (A[i]) - (B[i]);

			else if (A[i] < B[i])
			{
				result = ((A[i]) + 10) - (B[i]);	// add 10 ->HERE IT MUST LOOP AND BORROW FROM THE NEXT
				
				if (A[i + 1] != 0)					// Next is not zero, can borrow
					A[i + 1] = A[i + 1] - 1;
				else
				{
					for (size_t j = i + 1; j < arraySize; j++)	// Next digit is zero. Turn 0 to 9 and loop all digits
					{											// all zeroes turn to 9, until it finds non-zero
						if (A[j] != 0)
						{
							A[j] = A[j] - 1;			// non-zero, can borrow
							break ;
						}
						else
							A[j] = 9;					// turn 0 to 9
					}
				}
			}

			arr[i] = result;
			printf("   i%ld,  result: %d\n", i, result);
		}
		i++;
	}


	printArray(arr, arraySize);

	write(1, "\nFinal array Reverse:   ", 24);
	if (finalSign == 1)
		write(1, "-", 1);
	printArrayReverse(arr, arraySize, 0);


}


/*	INFIN_ADD

	vars: signA, signB, finalSign
			Check minus and store args to new string, from after minus
			If both negative, store finalSign

	vars: lenA, lenB
			Store each length

	var: AisBigger, finalSign
	Scenario only 1 str is negative:
			A is shorter than B:  swap strings and lengths, set finalSign
			A is longer than B:  set finalSign minus, if signA is negative
			A is same length B:	 loop A, compare each digit
								 if encountered digit A[i] is smaller then B[i]
								 		swap strings and lengths
										set finalSign
										set AisBigger = 0
							after loop:
								if A is negative and bigger, finalSign = 1 				
	
	vars: 2 new int arrays
	Both arrays same size as the longest string.
	Reset both arrays all to zeroes.
	Store both strings into int arrays in reverse order

	Loop 
		Addition (both signs are same)
			Add a + b, store to result		5 + 5 = 10	// in case the result is 10 or bigger:
			arr[i] = arr[i] + result		15 = 5 + 10
							5 stays %,  10 goes to next place
		
		
		Substraction	
			a) a >= b		5 - 3   --> simply substract, store to result

			b) a < b		3 - 5
				...... here need to continue
*/