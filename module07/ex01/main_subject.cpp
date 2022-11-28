#include <iomanip>      // std::setw
#include "iter.hpp"


class Awesome
{
  private:
	int _n;
  
  public:
	Awesome( void ) : _n( 42 )
	{ 
		std::cout << "Default constr.\n";
		return;
	}

	Awesome( int i ) : _n( i )
	{ 
		std::cout << "Param. constr.\n";
		return;
	}
	
	int get( void ) const 
	{ return this->_n; }
};

std::ostream & operator<< ( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get(); 
	return o;
}



template< typename T >
void print( T const & x )
{
	std::cout << x << " ";
	return;
}




/////////////////////////////////////////////////////////////////////////////

int main()
{
  int		tab[] = { 0, 1, 2, 3, 4 };
  Awesome	tab2[5];		// Creates array of 5 objects Awesome, each hold a variable n = 42.
							// So the default constr. is called 5 times
							// You can only do this with the default constructor, but with param.
							// constructor, you need to use a later loop, to initialize all the
							// objects in the array

  iter( tab,  5, print<int> );
  iter( tab2, 5, print<Awesome> );


  return 0;
}
