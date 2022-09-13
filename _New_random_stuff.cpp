/* QUESTIONS:


	Why are there needed both variants of the function min(), one with "const", 
	and one without "const"?
			static Fixed &min(Fixed &f1, Fixed &f2);
			static const Fixed &min(const Fixed &f1, const Fixed &f2);
	Because the >function is already with const: 
			bool operator> (const Fixed &fixed) const;
	So the first variant can never be used??? Becase the 2nd arg is always const.


	WHY THE = OVERLOAD FUNCTION RETURNS  *this  ???

	- Can we have more files_ for the project, then stated in subject?

	IS THERE ANY DIFFERENCE, WHERE ARE THESE const ??
	- bool	Fixed::operator< (      Fixed fixed) const
	- bool	Fixed::operator< (const Fixed fixed) 
	- bool	Fixed::operator< (const Fixed fixed) const
	- bool	const Fixed::operator< (const Fixed fixed) const
		etc ...


Cornelli
nsterk
corina
rutger
laura
nduijf
hman
jbedaux

*/


/////////////////////////////////////////////////////////
// RANDOM NEW STUFF /////////////////////////////////////

/*	The word "const" at different places:

		AT END:
		Box print(Box &bx) const;
			Then call on some object: bx2.print(bx1);
				Things in object bx2 wont be changed

		AT ARG:
		Box print(const Box &bx);	The arg won't be changed


		IN FRONT:
		const Box print(Box &b);
		"CONST" before a function means that the return parameter is 
		const, which only really makes sense if you return a reference 
		or a pointer.
		
		ALL THREE ALSO POSSIBLE:
		const Box print(const Box &b) const;

*/



/*  ->THIS    *THIS   			???
	A function can return *this. 
	The overloaded increment and decrement operators return the current
	implicit object so multiple operators can be “chained” together. ???

*/




/*	RETURNING A CLASS OBJECT:
	When initialising an int, it can have an if statement inside
	the brackets:   int x { 33 }  OR
					int x { a < b ? c : d }

	This function must return a class object. Its constructor
	takes 2 args. So when returning, it can be like this:
					return { a, b }
*/
MinMax operator+(const MinMax& m1, const MinMax& m2)
{
	int min{ m1.min < m2.min ? m1.min : m2.min };

	int max{ m1.max > m2.max ? m1.max : m2.max };

	return { min, max };
}


/*	INITIALISATION LIST
	A colon after the function name, ie: int add() : a = 33 { ... }
	This is useful if there is a const prive member. It can't be
	initialised in the function body, only in the init. list.

*/



// WHAT IS THE DIFFERENCE? IT LOOKS LIKE THIS IS BOTH THE SAME:
    Weapon wp1("Chainsaw");
    Weapon wp2 = Weapon("Hammer");



// A REFERENCE -------------------------------------------------------------------------------

/* A REFERENCE can be returned from a function.
This function can then be on the left side of the = operator:
*/
    double &setValue(int i)
    {
        return arr[i];   	// return a reference to the i-th element
	}
    setValue(1) = 33;		// Change the 2nd element to 33
	// same as: arr[i] = 33;

    // So it saved 1 argument
	// Cannot return a reference of a local variable (from the same scope)
	
	// L0OKS LIKE B0TH VARIANTS ARE WORKING:
	//      no &								with &
	Digit Digit::operator++()   /* OR */	Digit &Digit::operator++()
	{										{
		++m_digit;								++m_digit;
		return *this;							return *this;
	}										}


// BIT SHIFTING -------------------------------------------------------------
	/*
		The decimal number is multiplied or divided by 2, 4, 8, 16 ...etc
				ie:	10 << 1 = 20		80 >> 1 = 40
					10 << 2 = 40		80 >> 2 = 20
					10 << 3 = 80		80 >> 3 = 10

		2^8  ==  1 << 8  = 256

		If division has fractional part, the fracs are deleted:
					10 >> 2 == 10 / 4 =  2.5 ==> 2
	*/