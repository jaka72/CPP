/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/10 01:00:48 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class T>
class Array
{
    private:

    public:
        // SHOULD PROBABLY GO TO PRIVATE
        T               *arr;
        unsigned int    _size;
        
        // 1)
        Array()
        {
            arr = new T[0];
        };
        
        // 2)
        Array(unsigned int n)
        {
            _size = n;
            arr = new T[n];
            //arr[0] = 99;
        };
        
        ~Array()
        {
            delete []arr;
        }
        
        // 7)
        unsigned int size()
        {
            return (this->_size);
        }

        // 3) A
        // copy constructor - must be deep copy!

        // 3) B
        // assignment operator= overload

        // 5)
        // subscript operator[] overload, with catching exception when out of bounds

        
};







int main()
{
    
    {
        Array <int>arr1(3);

        std::cout << "arr1.arr[0]:  " << arr1.arr[0] << '\n';
        arr1.arr[0] = 11;
        std::cout << "arr1.arr[0]:  " << arr1.arr[0] << '\n';
        std::cout << "Array size: " << arr1.size() << "\n";
    }

    {
        Array <std::string>arr1(5);

        std::cout << "arr1.arr[0]:  " << arr1.arr[0] << '\n';
        arr1.arr[0] = "cookie";
        arr1.arr[1] = 97; // ?? Converts to char 'a'
        std::cout << "arr1.arr[0]:  " << arr1.arr[0] << '\n';
        std::cout << "arr1.arr[1]:  " << arr1.arr[1] << '\n';
        std::cout << "Array size: " << arr1.size() << "\n";

    }



    return 0;
}