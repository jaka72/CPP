/* QUESTIONS:
	WHY THE = OVERLOAD FUNCTION RETURNS  *this  ???

	- Can we have more files_
*/


/////////////////////////////////////////////////////////
// RANDOM NEW STUFF /////////////////////////////////////

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
	// val[i] = 33;

    // So it saved 1 argument
	// Cannot return a reference of a local variable (from the same scope)




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