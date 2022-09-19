#ifndef JAKA_HPP
# define JAKA_HPP

# include <iostream>

class jaka
{
	public:
// ----------------------------- Constructors ------------------------------ //
		jaka( void );	// Default Constructor
		jaka( int var );	// Fields Constructor
		jaka( const jaka& copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~jaka( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		jaka & operator=( const jaka& assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		int		get_var( void ) const;
		void	set_var( int input );

// --------------------------------- Methods ------------------------------- //
		int		is_equal( const jaka comp );

private:
	int	_var;

};

// TRY TO TWEAK THE BASH CODE TO GET THE NICELY 
//	INDENTED OUTPUT LIKE THIS BELOW

//#	define NO_DEBUG
#	ifndef NO_DEBUG
#		ifndef _ARG
#			define _ARG(arg) #arg << "(" << arg << ") "
#		endif /* _ARG */

#		define _JAKA_ARGS "[ARGS] " << _ARG(_var)
#		define _JAKA_AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m" \
			<< "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
			<< "\e[0m" << _JAKA_ARGS
#	else
#		define _JAKA_AUTO(x, y) ""
#		define _JAKA_ARGS ""
#		define _ARG ""
#	endif /* NO_DEBUG */
#endif /* JAKA_HPP */
