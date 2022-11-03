

// int checkNrDigits(int limit)
// {
//     int i = 0;
//     std::cout << " first i=" << i << ",  limit " << limit << "\n";
//     while (limit != 0)
//     {
//         limit = limit / 10;
//         //std::cout << " ---- i=" << i << ",  limit " << limit << "\n";
//         i++;
//     }
//     return (i);
// }

// // int max 2147483647
// int check_overflow(std::string str, int limit)
// {
//     // count nr digits
//     int lenStr = strlen(str.c_str());
//     int lenLim = checkNrDigits(limit);

//     std::cout << "check overflow\n";
//     std::cout << "      lenStr " << lenStr << "\n";
//     std::cout << "      lenLim " << lenLim << "\n";

//     if (lenStr > lenLim)
//     {
//         std::cout << "      OVERFLOW INT [" << str << "]\n";
//         return (1);
//     }
//     else if (lenStr == lenLim)
//     {
//         // Compare all digits except the last one, then compare the last one separately
//         std::string firstSubStr = str.substr(0, lenStr - 1);
//         std::string  lastSubStr = str.substr(lenStr - 1, lenStr);
//         std::cout << "      same lenght, firstSubstr [" << firstSubStr << "]\n";
//         std::cout << "      same lenght, lastSubstr  [" <<  lastSubStr << "]\n";
            
//         if (atoi(firstSubStr.c_str()) > abs(limit / 10))
//         {
//             std::cout << "      Error: same lenght, FirstSubstr, OVERFLOW [" << str << "]\n";
//             return (1);
//         }
//         else if (atoi(firstSubStr.c_str()) == abs(limit / 10))
//         {
//             if (atoi(lastSubStr.c_str()) > abs(limit % 10))
//             {    
//                 std::cout << "      Error: same lenght, LastSubstr, OVERFLOW [" << str << "]\n";
//                 return (1);
//             }
//         }
//     }
//     return (0);
// }