/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:35 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/05 18:36:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>


class Fixed
{
	private:
		int					_fixedPointNumber;

		static const int	_fractionalBits = 8;

	public:
		// default constructor
			Fixed();
					
		// copy constructor
			Fixed(const Fixed& copy);

		// copy assignment operator overload
			Fixed& operator= (const Fixed& orig);

		// destructor
			~Fixed();

		// Setter
			void	setRawBits(int const raw);
		
		// Getter
			int 	getRawBits(void) const;
};

#endif
