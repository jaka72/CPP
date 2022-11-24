/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 19:30:20 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/24 19:58:02 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>
#include "colors.h"

// class Whatever
// {
// 	private:
	
// 	public:
// 		int			x;
// 		std::string s;

// 		bool operator== (const Whatever &src) const
// 		{
// 			std::cout << "From comparisson operator== \n";
// 			if (this->x == src.x && this->s == src.s)
// 				return (true);
// 			return (false);
// 		} 
// };


template <typename T>

void    swap(T &a, T &b)
{
	std::cout << GRE"My swap: " RES;
	T temp = a;
	a = b;
	b = temp;
}


template <typename T>

T   min(T &a, T &b)
{
	std::cout << GRE"My min:   " RES;
	if (a < b)
		return (a);
	return (b);
}


template <typename T>

T   max(T &a, T &b)
{
	std::cout << GRE"My max:   " RES;
	if (a > b)
		return (a);
	return (b);
}

#endif
