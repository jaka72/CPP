/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/02 17:55:19 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 13:48:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
	
		Fixed const _x;
		Fixed const _y;

	public:

		// Default constructor
		Point();

		// Parameterized constr
		Point(const float x, const float y);

		// Copy contructor
		Point (const Point &orig);

		// Destructor
		~Point();

		// Copy assignment overload for the =
		Point &operator= (const Point &orig);

		// Getters
		const Fixed &get_x() const;
		const Fixed &get_y() const;


		// Member functions
		// Calculate the area of the 3 points
		float area(Point p1, Point p2, Point p3);

		// Check if point is in the triangle
		bool bsp(Point const a, Point const b, Point const c, Point const point);

};
