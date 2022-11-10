/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/09 20:52:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


// THE FUNCTION swap() IS ALREADY INCLUDED SOMEWHERE IN std::
// OR IN iostream ????, WORKS WITH ALL TYPES
// BUT IF YOU OVERRIDE IT WITH A TEMPLATE swap()
// IT WILL NOT USE THE TEMPLATE, WHEN YOU GIVE IT STRINGS


// class ClassA
// {
//     private:
    
//     public:
//         int x;
//         std::string s;
//         bool operator== (const ClassA &src) const
//         {
//                 std::cout << "From comparisson operator ==\n";
//                 if (this->x == src.x && this->s == src.s)
//                     return (true);
//                 return (false);
//         } 
// };


// template <typename T>
// void    swap(T &a, T &b)
// {
//     std::cout << "My swap:";
    
//     T temp = a;
//     a = b;
//     b = temp;
// }

// template <typename T>
// T   min(T &a, T &b)
// {
//     if (a <= b)
//         return (a);
//     return (b);
// }

// template <typename T>
// T   max(T &a, T &b)
// {
//     if (a >= b)
//         return (a);
//     return (b);
// }

template <typename Z>
void    print_me(Z n)
{
    std::cout << n << "\n";
}



template <typename T, typename U, typename V, typename Z>

// void    iter(T *arr, U len, V fun(int))
void    iter(T *arr, U len, V (*fun)(Z n))
{
    int i = 0;
    
    while (i < len)
    {
        fun(arr[i]);
        i++;
    }    
}



int main()
{
    
    {
        int arrA[5] = {'a', 'b', 'c', 'd', 'e'};
        int arrB[5] = {11, 22, 33, 44, 55};
        
        // void (*fptr)(int) = &print_me;

        // iter(arr, 5, fptr);
        iter(arrA, 5, print_me);
        iter(arrB, 5, print_me);
    }

    
    return 0;
}