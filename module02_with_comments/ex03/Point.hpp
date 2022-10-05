/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Point.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/02 17:55:19 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 12:09:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
	
		Fixed const _x;
		Fixed const _y;
//		int	test;


	public:

		Point();
		~Point();

		// Parameterized constr
		Point(const float x, const float y);

		// Copy contructor
		Point (const Point &orig);


		// Copy assignment overload for the =
		Point &operator= (const Point &orig);

		// Getters
		const Fixed &get_x() const;
		const Fixed &get_y() const;

		// Member functions
		// float area(Point &p1);
		float area(Point p1, Point p2, Point p3);

		bool bsp(Point const a, Point const b, Point const c, Point const point);


};

// Default constr
Point::Point() : _x(0), _y(0)
{	}

// Param. constr.
Point::Point(float const x, float const y) :
				_x(x), _y(y)
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

//	std::cout << "COPY CONSTR: get_x(): " << this->get_x() << "\n\n";

//	*this = orig;	// MAYBE NOT NEEDED
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



// Copy assignment overload for the =
Point &Point::operator= (const Point &orig)
{
	if (this == &orig)
		return (*this);
	
//	this->_x = orig.get_x();
//	this->_y = orig._y;			// NOT POSSIBLE !!!
//								// MUST BE COPIED IN THE COPY CONSTRUCTOR	
								// MUST USE A CUSTOM GETTER TO FETCH
								// THE VALUE FROM ANOTHER CLASS (Fixed)
	return (*this);
}








// float area(int x1, int y1, int x2, int y2, int x3, int y3)
// float Point::area(Point &p1)
float Point::area(Point p1, Point p2, Point p3)
{
	// Fixed	xxx1 = p1.get_x();
	// int xxx = xxx1.toInt();
	// std::cout << "   --- xxx: " << xxx <<"\n";
	
	float		x1 = p1.get_x().toFloat();
 	float		y1 = p1.get_y().toFloat();
	// int		x1 = p1.get_x().toInt();
 	// int		y1 = p1.get_y().toInt();
	//std::cout << "   --- x1: " << x1 <<"\n";
	//std::cout << "   --- y1: " << y1 <<"\n";
	
	float		x2 = p2.get_x().toFloat();
	float		y2 = p2.get_y().toFloat();

	float		x3 = p3.get_x().toFloat();
	float		y3 = p3.get_y().toFloat();



	float a =  (x1 * (y2 - y3)
			  + x2 * (y3 - y1)
			  + x3 * (y1 - y2)) / 2.0;
	std::cout << "   area: " << a <<"\n";
	a = abs(a);


	return a;
	// return (0.0);
}



// bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point aa(a);
	Point bb(b);
	Point cc(c);
	Point p(point);



	
	// /* Calculate area of triangle ABC */
	// float A = area (x1, y1, x2, y2, x3, y3);
	float A = area (aa, bb, cc);
	
	/* Calculate area of triangle PBC */
	float A1 = area (p, bb, cc);
	
	/* Calculate area of triangle PAC */
	float A2 = area (aa, p, cc);
	
	/* Calculate area of triangle PAB */
	float A3 = area (aa, bb, p);
		
	return (A == A1 + A2 + A3);

	// float		x1 = a.get_x().toFloat();
	// std::cout << "test: " << x1 << "\n";

	return (true);
}

