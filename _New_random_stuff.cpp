

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


