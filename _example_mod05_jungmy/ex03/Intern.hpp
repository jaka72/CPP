/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:50:44 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:50:45 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Intern
{
public:
	Intern(void);
	virtual ~Intern(void);
	Intern(const Intern &_target);
	Intern &operator=(const Intern &_target);

	Form *makeForm(std::string _formName, std::string _fromTarget);

	class UnknownForm : public std::exception {
	public:
		const char *what(void) const throw();
	};

private:
	Form *forms[3];


};

#endif
