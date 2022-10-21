/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:54:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 13:25:08 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string		_type;
		Brain			*_brain;

	public:

		// Constructor
		Cat();
		
		// Param. constr.
		Cat(std::string type);

		// Copy constructor
		Cat(const Cat &cat);

		// Destructor
		~Cat();

		// Overload operators
		Cat &operator= (const Cat &cat);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;
		void getIdea(int n) const;

		// Setter
		void setIdea(int n, std::string idea);
		void setType(std::string type);

};

#endif
