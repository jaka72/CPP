/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 13:38:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:28:39 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// Default constr
Point::Point() : _x(0), _y(0)
{	}

// Param. constr.
Point::Point(float const x, float const y) :  _x(x),  _y(y)
{
	// std::cout << "Constructor POINT\n";
}

// Destructor
Point::~Point()
{	
	// std::cout << "Destructor POINT\n";
}


// Copy contructor
Point::Point(const Point &orig) : _x(orig.get_x()), _y(orig.get_y())
{
//	this->_x = orig.get_x();	// NOT POSSIBLE !!!
//	this->_y = orig._y;			// NOT POSSIBLE !!!
//								// MUST BE COPIED IN THE COPY CONSTRUCTOR	
								// MUST USE A CUSTOM GETTER TO FETCH
								// THE VALUE FROM ANOTHER CLASS (Fixed)
}



// Getters
// THESE ARE EXTRA GETTERS, TO GRAB THE VALUE OF THE PRIVATE MEMBERS OF THE Point,
//		WHICH ARE OF CLASS Fixed. OTHERWISE THE OPERATOR = CANNOT DO THE OPERATION
//		OF COPYING A Point = Point,  BECAUSE IT CONTAINS MEMBERS OF CLASS  Fixed, _x AND _Y
const Fixed &Point::get_x() const
{
	return (this->_x);
}

const Fixed &Point::get_y() const
{
	return (this->_y);
}



// Copy assignment operator= overload
Point &Point::operator= (const Point &orig)
{
	if (this == &orig)
		return (*this);
	
//	this->_x = orig.get_x();
//	this->_y = orig._y;			// NOT POSSIBLE HERE
//								// MUST BE COPIED IN THE COPY CONSTRUCTOR	
								// MUST USE A CUSTOM GETTER TO FETCH
								// THE VALUE FROM ANOTHER CLASS (Fixed)
	return (*this);
}


// MEMBER FUNCTIONS

// Calculate the area of the 3 points
float Point::area(Point p1, Point p2, Point p3)
{
	float		x1 = p1.get_x().toFloat();
 	float		y1 = p1.get_y().toFloat();
	
	float		x2 = p2.get_x().toFloat();
	float		y2 = p2.get_y().toFloat();

	float		x3 = p3.get_x().toFloat();
	float		y3 = p3.get_y().toFloat();

	float area =  (x1 * (y2 - y3)
				 + x2 * (y3 - y1)
				 + x3 * (y1 - y2)) / 2.0;
	// std::cout << "   area: " << area <<"\n";
	area = abs(area);
	return area;
}


// Check if a point is in the triangle
bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point aa(a);
	Point bb(b);
	Point cc(c);
	Point p(point);
	
	float A  = area (aa, bb, cc);	// Calculate area of triangle ABC
	float A1 = area (p, bb, cc);	// Calculate area of triangle PBC
	float A2 = area (aa, p, cc);	// Calculate area of triangle PAC
	float A3 = area (aa, bb, p);	// Calculate area of triangle PAB

	
	std::cout << "Calculated areas: "<< "\n";
	std::cout << "   ABC = " << A << "\n";
	std::cout << "   PBC = " << A1 << "\n";
	std::cout << "   PAC = " << A2 << "\n";
	std::cout << "   PAB = " << A3 << "\n";
	std::cout << "   (ABC must be equal to A1 + A2 + A3) \n";
	
	return (A == A1 + A2 + A3);
}
