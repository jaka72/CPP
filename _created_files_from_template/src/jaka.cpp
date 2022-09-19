#include "jaka.hpp"

// ----------------------------- Constructors ------------------------------ //
jaka::jaka( void )
{
	_var = 0;
	_JAKA_AUTO(32, "Default Constructor") << std::endl;
}

jaka::jaka( const jaka& copy )
{
	_var = copy.get_var();
	_JAKA_AUTO(32, "Copy Constructor") << std::endl;
}

jaka::jaka( int var ) : _var(var)
{	
	_JAKA_AUTO(32, "Fields Constructor") << std::endl;
}

// ------------------------------ Destructor ------------------------------- //
jaka::~jaka( void )
{
	_JAKA_AUTO(31, "Destructor called") << std::endl;
}
// ------------------------------- Operators ------------------------------- //

jaka & jaka::operator=( const jaka& assign )
{
	_var = assign.get_var();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	jaka::get_var( void ) const
{
	_JAKA_AUTO(33, "Getter") << std::endl;
	return _var;
}

void	jaka::set_var( int input )
{
	_JAKA_AUTO(34, "Setter") << "| old(" << _var << ") new(" << input << ") "<< std::endl;
	_var = input;
}

// --------------------------------- Methods ------------------------------- //

