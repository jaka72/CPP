#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
//		std::string		_type; 		// MAYBE NOT NEEDED, ITS INHERITED FROM Animal
		Brain			*_brain;	//  A POINTER TO OBJECT

	public:

		// Constructors
		Cat();
		//Cat(std::string &type); // not sure to leave the &
		Cat(const Cat &cat);

		// Destructor
		~Cat();

		// Overload operators
		Cat &operator= (const Cat &cat);

		// Public member functions
		void makeSound(void) const;

		// Setter
		void setIdea(int n, std::string idea);

		void setType(std::string type);


		// Getter
		void getIdea(int n) const;

};

#endif
