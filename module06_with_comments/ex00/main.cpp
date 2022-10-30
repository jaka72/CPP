/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/30 22:18:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstring>   // strlen


int main(/*int argc, char **argv*/)
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
    char    c;
    int     i;
    float   f;
    double  d;
    // std::string str = "123.";
    std::string str = "   123  ";
    int len = strlen(str.c_str());
    
    // single char, but not a digit
    if (len == 1)
    {
        // eliminate non-printables
        if (isprint(str[0]) == 0)
            std::cout << "Single char: it is non-displayable\n";
        else if (isdigit(str[0]) != 0)
        {
            //char c = str[0];
            i = (int)(str[0] - 48);
            f = (float)i;
            d = (double)f;
            std::cout << "Single char: it is a digit\n";
            std::cout << "   char:   non-displayable\n";
            std::cout << "   int:    " << i << "\n";
            std::cout << "   float:  " << std::fixed << std::setprecision(2) << f << "f \n";
            std::cout << "   double: " << std::fixed << std::setprecision(2) << d << "\n";
        }
        else
        {
            std::cout << "Single char: displayable\n";
            c = (char)(str[0]);
            i = (int)c;
            f = (float)i;
            d = (double)f;
            std::cout << "   char:   " << c << "\n";
            std::cout << "   int:    " << i << "\n";
            std::cout << "   float:  " << std::fixed << std::setprecision(2) << f << "f \n";
            std::cout << "   double: " << std::fixed << std::setprecision(2) << d << "\n";
        
        
//            float b = static_cast<float>(i);
        }
    }
    else if (len > 1)
    {
        std::cout << "Multiple chars -------------\n";
        int i = 0, isDigit = 0, isNotDigit = 0, isPoint = 0, isF = 0;
        char checkIf_F = 'a';
        while (isspace(str[i])) // skip spaces on start
            i++;
        while (str[i])
        {
            if (isdigit(str[i]) == 0 && str[i] != '.' && str[i] != 'f' && str[i] != ' ')
            {
                isNotDigit++;
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
        
        while (str[i])
        {
            if (isprint(str[i]) && str[i] != ' ')
            {
                std::cout << str[i] << " !!! Error, invalid input, found chars after space!\n";
                return 1;
                // break ;
            }
            i++;
        }


        std::cout << "   all together: " << isNotDigit + isPoint + isF + isDigit << "\n";
        if ( (isNotDigit + isPoint + isF + isDigit) == 1)
        {
            std::cout << "Must be char: " << str << "\n"; 
            std::cout << "Must be char: " << checkIf_F << "\n"; 
        }

        std::cout << "Check if F: " << checkIf_F << "\n"; 

        // check if all good
        if (isPoint == 0 && isNotDigit == 0 && isF == 0)
        {
            std::cout << "Must be integer: " << str << "\n";
        }
        else if (isPoint == 1 && isNotDigit == 0 && isF == 0 && isDigit >= 1)
        {
            std::cout << "Must be double: " << str << "\n";
        }
        else if (isPoint == 1 && isNotDigit == 0 && isF == 1 && checkIf_F == 'f')
        {
            std::cout << "Must be float: " << str << "\n";
        }
        else   
        {
            std::cout << "Error: last char is not f and not digit!\n";
        }    


        
        std::cout << "------------- digits:     " << isDigit << "\n";
        std::cout << "------------- non-digits: " << isNotDigit << "\n";
        std::cout << "              points:     " << isPoint << "\n";
        std::cout << "              fs:         " << isF << "\n";
        

    }
    

    return 0;
}

