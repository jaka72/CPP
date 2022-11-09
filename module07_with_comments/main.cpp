/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/09 19:18:40 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


// THE FUNCTION swap() IS ALREADY INCLUDED SOMEWHERE IN std::
// OR IN iostream ????, WORKS WITH ALL TYPES
// BUT IF YOU OVERRIDE IT WITH A TEMPLATE swap()
// IT WILL NOT USE THE TEMPLATE, WHEN YOU GIVE IT STRINGS


class ClassA
{
    private:
    
    public:
        int x;
        std::string s;
        bool operator== (const ClassA &src) const
        {
                std::cout << "From comparisson operator ==\n";
                if (this->x == src.x && this->s == src.s)
                    return (true);
                return (false);
                
        } 
};


template <typename T>
void    swap(T &a, T &b)
{
    std::cout << "My swap:";
    
    T temp = a;
    a = b;
    b = temp;

    // if (a == b)
    //     std::cout << "   Compare:    a is equal to b.\n";
    // else
    //     std::cout << "   Compare:    a is NOT equal to b.\n";
}

template <typename T>
T   min(T &a, T &b)
{
    if (a <= b)
        return (a);
    return (b);
}

template <typename T>
T   max(T &a, T &b)
{
    if (a >= b)
        return (a);
    return (b);
}

int main()
{
    {
        char a = 'x', b = 'y';
        std::cout << "         a: " << a << ", b: " << b << "\n";
        ::swap(a, b);
        std::cout << " a: " << a << ", b: " << b << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
    }
        std::cout << "- - - - - - - - - - - - - - - - - - - \n";
    {
        int a = 3, b = 7;
        std::cout << "         a: " << a << ", b: " << b << "\n";
        ::swap(a, b);
        std::cout << " a: " << a << ", b: " << b << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
    }
        std::cout << "- - - - - - - - - - - - - - - - - - - \n";

    {
        float a = 3.3f, b = 7.7f;
        std::cout << "         a: " << a << ", b: " << b << "\n";
        ::swap(a, b);
        std::cout << " a: " << a << ", b: " << b << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
    }
        std::cout << "- - - - - - - - - - - - - - - - - - - \n";

    {
        double a = 11.11, b = 55.55;
        std::cout << "         a: " << a << ", b: " << b << "\n";
        ::swap(a, b);
        std::cout << " a: " << a << ", b: " << b << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
    }
        std::cout << "- - - - - - - - - - - - - - - - - - - \n";
    
    {
        std::string a = "wine";
        std::string b = "beer";

        std::cout << "         a: " << a << ", b: " << b << "\n";
        ::swap(a, b);
        std::cout << " a: " << a << ", b: " << b << "\n";
        std::cout << "Min: " << min(a, b) << "\n";
        std::cout << "Max: " << max(a, b) << "\n";
    }
        std::cout << "- - - - - - - - - - - - - - - - - - - \n";

   
    {
        ClassA first, second;
        first.x = 44;
        second.x = 99;
        first.s = "tulip";
        second.s = "rose";

        std::cout << "                first.x: " << first.x << ", second.x: " << second.x << "\n";
        std::cout << "                first.s: " << first.s << ", second.s: " << second.s << "\n";
        ::swap(first, second);
        std::cout << "        first.x: " << first.x << ", second.x: " << second.x << "\n";
        std::cout << "                first.s: " << first.s << ", second.s: " << second.s << "\n";
        std::cout << "Min x: " << min(first.x, second.x) << "\n";
        std::cout << "Max x: " << max(first.x, second.x) << "\n";
        std::cout << "Min s: " << min(first.s, second.s) << "\n";
        std::cout << "Max s: " << max(first.s, second.s) << "\n";
    }
    return 0;
}