#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printArray(int *arr, size_t arrSize)
{
	printf("Final array:   ");
	size_t i = 0;
	while (i < arrSize)
		printf("%d ", arr[i++]);
	printf("\n");
}



void	printArrayReverse(int *arr, size_t arrSize, int sign)
{
	int i = arrSize - 1;

	if (arr[i] == 0)
		i--;
	if (arr[i] == 0)	// IT CAN HAPPEN THAT THERE ARE 2 ZEROS AT THE END OF ARRAY (end is the begining!)
		i--;			// , MUST SKIP ZEROS

	if (arrSize == 2 && arr[0] == 0 && arr[0] == 0)
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




	// IN CASE OF ONLY 1 STRING IS NEGATIVE:
	// 		

	// SWAP ALWAYS, IF A IS SMALLER THAN B
	if (lenA < lenB && signA != signB)	// smaller must be at 2nd place
	{
		printf("String length A is smaller, must swap!\n");
		char *temp;
		temp = strA;
		strA = strB;
		strB = temp;
		if (signA == 1)
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
				AisBigger = 0;
				if (signB == 1)
					finalSign = 1;
				break;
			}
		}
		if (signA == 1 && AisBigger == 1)
			finalSign = 1;
	}

	printf("newstr strA: %s\n", strA);
	printf("newstr strB: %s\n", strB);
	printf("finalSign: %d\n", finalSign);


	char A[lenA + 1];
	char B[lenB + 1];

	reverseString(A, strA, lenA);
	reverseString(B, strB, lenB);


	printf("newstr A: %s\n", A);
	printf("newstr B: %s\n", B);


	size_t arraySize = lenA + 1;	// Make array. Take size of the longer string, plus 1
	if (lenA < lenB)				// WHY PLUS 1 ???
		arraySize = lenB + 1;




	int arr[arraySize];
	printf("   arrSize: %ld\n", arraySize);
	for (size_t i = 0; i < arraySize; i++)
		arr[i] = 0;


	




	int result = 0;
	for (size_t i = 0; i < arraySize - 1; )
	{
		// ADDITION
		if ((signA == 1 && signB == 1) || (signA == 0 && signB == 0) )
		{
			if (i >= lenA)
				result = 0  +  (B[i] - 48);
			else if (i >= lenB)
				result = (A[i] - 48)  +  0;
			else
				result = (A[i] - 48)  +  (B[i] - 48);

			printf("   i%ld,  result: %d\n", i, result);
			arr[i] = arr[i] + result;
			
			if (arr[i] > 9)
			{
				arr[i + 1] = arr[i + 1] + (arr[i] / 10);
				arr[i] = arr[i] % 10;
			}
		}

		// SUBSTRACTION
		else if (signB != signA)	// somehwere here needs to correct calculation, borrowing and carrying on
		{						// A is always bigger or the same as B
			printf("Substraction:  ");

				if (A[i] < B[i])
				{
					printf("  A < B, ");
					result = ((A[i] - '0') + 10) - (B[i] - '0');	// add 10 ->HERE IT MUST LOOP AND BORROW FROM THE NEXT
					
					if (A[i + 1] != '0')
					{
						printf("  Ai+1 != 0 \n");
						A[i + 1] = A[i + 1] - '0' - 1;			// UNTIL IT FINDS THE DIGIT TO BORROW
					}
					else										// IN CASE OF ZEROES: 0 TURNS INTO 9, AND THE NEXT IS - 1
					{
						printf("  Ai+1 == 0 \n");
						for (size_t j = i + 1; j < lenA; j++)
						{
							if (A[j] != '0')
							{
								A[j] = A[j] - '0' - 1;
								printf("      break: Aj+1 != 0:   newA+1: %d \n", A[j]);
								break ;
							}
							else
							{
								A[j] = '9';
								printf("      loop:  Aj+1 == 0:   newA+1: %d \n", A[j + 1] - '0');
							}
						}
					}
				}
				
				
				else
					result = (A[i] - '0') - (B[i] - '0');
				arr[i] = result;
				
				
				printf("   i%ld,  result: %d\n", i, result);
			//}
		}
		i++;
	}


	printArray(arr, arraySize);

	write(1, "\nFinal array Reverse:   ", 24);
	if (finalSign == 1)
		write(1, "-", 1);
	printArrayReverse(arr, arraySize, 0);


}