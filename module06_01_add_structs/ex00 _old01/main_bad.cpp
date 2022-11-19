/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/01 11:38:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen
#include <cstdlib>
#include<bits/stdc++.h> // overflow


void printStats(int isDigit, int isNotDigit, int isPoint, int isF, int sign, int isNeg)
{
    std::cout << "      digits:     " << isDigit << "\n";
    std::cout << "      non-digits: " << isNotDigit << "\n";
    std::cout << "      points:     " << isPoint << "\n";
    std::cout << "      fs:         " << isF << "\n";
    std::cout << "      sign:       " << sign << "\n";
    std::cout << "      isNeg:      " << isNeg << "\n";
}


int checkNrDigits(int limit)
{
    int i = 0;
    while ((float)limit / 10 > 0)
    {
        std::cout << " ---- i=" << i << "\n";
        i++;
    }
    return (i);
}

// int max 2147483647
int check_overflow(std::string str, int limit)
{
    // count nr digits
    //int i = 0;
    int lenStr = strlen(str.c_str());
    int lenLim = checkNrDigits(limit);
    // while (str[i])
    //     i++;

    std::cout << "check overflow\n";
    // std::cout << "          i=" << i << "\n";
    std::cout << "      lenStr" << lenStr << "\n";
    std::cout << "      lenLim" << lenLim << "\n";

    // if (len > )
    
    return (0);
}




int main(int, char **argv)
{
    // if (argc != 2)
    // {
    //     std::cout << "Only 1 argument allowed.\n";
    //     return (1);
    // }
    
    // Check arg if it is just numbers.
    //      If there are more alphabet letters, the input is not valid.

    // char to int      OK
    // char to float    /
    // char to double   /
    //      If it is only 1 non-digit char, it is valid (unless it is non printable).
    
    
    // int to char      ok
    // int to float     ok
    // int to double    ok  
    
    
    
    
    //      If there are only digits, there can be 1 dot as decimal point.



    // If there is 'f' at the end, it must be float. It must not be larger than float. So it can also be double. 
    // If it is without 'f', it can be maximum double. But in this case, can it be float? Or is float not possible ???

    // float   f1 = 340282346638528859811704183484516925440.0000000000000000f;
    // float   f1 = 3402.1232341f;
    // std::cout << std::fixed << std::setprecision(5) << f1 << "\n";


    // //           4.0123457908630371093750000
    // double  d1 = 5.0123456789012345678912345;
    // double  d3 = 5.1999999999999999999999999;

    // std::cout << " float  f1: " << f1 << "f\n";
    // std::cout << " double d1: " << d1 << "d\n";

    // f1 = (int)f1;
    // d1 = (int)d1;

    // std::cout << " int f1: " << f1 << "i\n";
    // std::cout << " int d1: " << d1 << "i\n";


    // f1 = (double)f1;
    // d1 = (float)d1;
    
    // std::cout << " float  f1: " << f1 << "f\n";
    // std::cout << " double d1: " << d1 << "d\n";

    // std::cout << std::fixed << std::setprecision(25) << f1 << "\n";
    // std::cout << std::fixed << std::setprecision(25) << d1 << "\n";
    // std::cout << std::fixed << std::setprecision(25) << d3 << "\n";
    

    // std::string str = "a";

    // check length
    // char    c;
    // int     i = -       1 ;
    // std::cout << "Check sign: "  << i << " \n";
    // float   f;
    // double  d;
    // std::string str = "  x   " ;
    // // std::string str = " -   3  ";
    // // std::string str = "   4147483950  ";    // check all overflow variants !!! 
    //int len = strlen(str.c_str());
    
    // single char, but not a digit
//     if (len == 1)
//     {
//         // eliminate non-printables
//         if (isprint(str[0]) == 0)
//             std::cout << "Single char: it is non-displayable\n";
//         else if (isdigit(str[0]) != 0)
//         {
//             //char c = str[0];
//             i = (int)(str[0] - 48);
//             f = (float)i;
//             d = (double)f;
//             std::cout << "Single char: it is a digit\n";
//             std::cout << "   char:   non-displayable\n";
//             std::cout << "   int:    " << i << "\n";
//             std::cout << "   float:  " << std::fixed << std::setprecision(2) << f << "f \n";
//             std::cout << "   double: " << std::fixed << std::setprecision(2) << d << "\n";
//         }
//         else
//         {
//             std::cout << "Single char: displayable\n";
//             c = (char)(str[0]);
//             i = (int)c;
//             f = (float)i;
//             d = (double)f;
//             std::cout << "   char:   " << c << "\n";
//             std::cout << "   int:    " << i << "\n";
//             std::cout << "   float:  " << std::fixed << std::setprecision(2) << f << "f \n";
//             std::cout << "   double: " << std::fixed << std::setprecision(2) << d << "\n";
        
        
// //            float b = static_cast<float>(i);
//         }
//     }
//     else if (len > 1)
//     {

    std::cout << "INT MAX: " << INT_MAX << "\n";

    check_overflow("   2147483647   ", 0 );


    char    c    = 'a';
    int     intg = -       1 ;
    //std::cout << "Check sign: "  << i << " \n";
    float   f;
    double  d;
    // std::string str = "  x   " ;
    // std::string str = " -   3  ";
    // std::string str = "   4147483950  ";    // check all overflow variants !!! 

        std::string str = argv[1];
    
        int             i = 0, isDigit = 0, isNotDigit = 0, isPoint = 0, isF = 0;
        int             sign = 0;
        int             isNeg = 0;
        char            checkIf_F = 'a';
        

        isNeg = isNeg + 1 - 1;  // temp to silence warning

        std::cout << "A) string: [" << str << "]\n";
        //std::cout << "A1) i" << i << ",  " << (int)str[i] << "\n";



        while (isspace(str[i])) // skip spaces on start
        {
            std::cout << "check space " << (int)str[i] << "[" << str[i] << "]\n";
            i++;
        }
        
        std::cout << "B) First after space " << i << ",  " << (int)str[i] <<"[" << str[i] << "]\n";
        c = str[i];

        if (str[i] == '+' || str[i] == '-')
        {
            // isNotDigit++;
            sign = 1;
            c = str[i];
            if (str[i] == '-')
                isNeg = 1;
            std::cout << "  YES IS SIGN " << str[i] << "\n";
            i++;
            std::cout << "check char " << (int)str[i] << "[" << str[i] << "]\n";
            while (isspace(str[i])) // skip spaces after sign
            {
                std::cout << "First after sign and spaces " << (int)str[i] << "[" << str[i] << "]\n";
                i++;
            }
        }

        std::cout << " First after sign and spaces " << (int)str[i] << "[" << str[i] << "]\n";
        // if (isdigit(str[i]))
        //     isDigit++;



        int start = i;
            
        while (str[i])
        {
            if (isdigit(str[i]) == 0 && str[i] != '.' && str[i] != 'f' && str[i] != ' ')
            {
                isNotDigit++;
                c = str[i];
                std::cout << "nondigit " << (int)str[i] << "\n";
            }
            if (isdigit(str[i]))
                isDigit++;
            if (str[i] == '.')
                isPoint++;
            if (str[i] == 'f')
            {
                isF++;
                if (str[i + 1] == '\0' || str[i + 1] == ' ')
                {
                    checkIf_F = str[i];
                    std::cout << " !!! found space OR end!, last char [" << str[i] << "]\n";
                    //break ;
                }    
            }
            // if (isspace(str[i]))
            if (str[i] == ' ')
            {
                checkIf_F = str[i - 1];
                std::cout << " !!! found space before end!, last char [" << str[i-1] << "]\n";
                break ;
            }
            i++;
        }
        
        while (str[i]) // check the rest of space after 1st group of chars
        {
            if (isprint(str[i]) && str[i] != ' ')
            {
                std::cout << str[i] << " !!! Error, invalid input, found chars after space!\n";
                return 1;
                // break ;
            }
            i++;
        }


        //std::cout << "Check is F: " << checkIf_F << "\n"; 

        std::cout << "   all together: " << isNotDigit + isPoint + isF + isDigit << "\n";


        if (sign == 1 && (isNotDigit + isPoint + isF + isDigit == 0))
        {
            printStats(isDigit, isNotDigit, isPoint, isF, sign, isNeg);
            std::cout << "SINGLE CHAR THE SIGN FOUND\n";
            //c = (char)str[0];
            std::cout << "Must be CHAR, str [" << str << "],  c [" << c << "]\n"; 
            std::cout << "Result: " << c << "\n";
            return (11);
        }
        
        
        if (sign == 0 && (isNotDigit + isPoint + isF + isDigit) == 1)
        {
            std::cout << "SINGLE CHAR \n";
            printStats(isDigit, isNotDigit, isPoint, isF, sign, isNeg);

            if (isNotDigit == 1)
            {
                // std::cout << "Must be char: " << checkIf_F << "\n"; 
                // std::cout << "Must be char: " << str[start] << "\n";
                // c = (char)str[0];
                std::cout << "Must be CHAR, str [" << str << "],  c [" << c << "]\n"; 
                std::cout << "Result: " << c << "\n";
                return (11);
            }
            if (isDigit == 1)
            {
                std::cout << "Must be SINGLE INT, str [" << str << "],  c [" << i << "]\n";
                i = (int)(str[start] - 48);
                std::cout << "Result: " << i << "\n";
                return (11);
            }
        }
        if (sign == 1 && (isNotDigit + isPoint + isF + isDigit) == 1)
        {
            if (isDigit == 1)
            {
                std::cout << "Must be SINGLE INT WITH SIGN, str [" << str << "],  c [" << str[start] << "]\n";
                i = (int)(str[start] - 48);
                if (isNeg == 1)
                    i *= -1;
            
                std::cout << "Result: " << i << "\n";
                return (11);
            }
            else
            {
                std::cout << "INVALID INPUT: sign and alpha" << i << "\n";
            }
                
        }
        // check if all good
        else if (isPoint == 0 && isNotDigit == 0 && isF == 0)
        {
            // std::cout << "Must be integer: " << &str[start] << "\n";
            std::cout << "Must be integer: " << str << "\n";
            printStats(isDigit, isNotDigit, isPoint, isF, sign, isNeg);


            if (check_overflow(&str[start], INT_MAX ) != 0)
            {
                std::cout << "Int overflow!\n";
                return (1);
            }

            
            intg = atoi(&str[start]);
            if (isNeg == 1)
                intg *= -1;
            
            std::cout << "Result: " << intg << "\n";
            std::cout << "        integer: " << intg << " intmax: " << INT_MAX << "\n";
            
            // OVERFLOW ////////////////////////
            // if (intg < INT_MIN - intg) //  NOT SURE OF ALL GOOD ???
            //     std::cout << "        MIN integer oveflow, INTMIN - i = " << INT_MIN - intg << " \n";
            // if (intg > INT_MAX + intg) //  NOT SURE OF ALL GOOD ???
            //     std::cout << "        MAX integer oveflow: \n";
        return (22);
        }

        
        else if (isPoint == 1 && isNotDigit == 0 && isF == 0 && isDigit >= 1)
        {
            printStats(isDigit, isNotDigit, isPoint, isF, sign, isNeg);
            std::cout << "Must be double: " << str << "\n";
            d = atof(&str[start]); // ??????
            if (isNeg == 1)
                d *= -1;
            std::cout << "Result: " << d << "\n";
            return (33);
        }
        else if (isPoint == 1 && isNotDigit == 0 && isF == 1 && checkIf_F == 'f')
        {
            std::cout << "Must be float: " << str << "\n";
            f = atof(&str[start]);
            if (isNeg == 1)
                f *= -1;
            std::cout << "Result: " << f << "\n";
            return (44);
        }
        else   
        {
            std::cout << "Error: last char is not f and not digit!\n";
        }    


        
       
        

    //}
    

    return 0;
}

