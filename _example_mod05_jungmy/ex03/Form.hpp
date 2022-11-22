/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:47:55 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:36:22 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string _FormName, const std::string _FormTarget, int _requiredGrade, int _executedGrade);
	virtual ~Form();
	Form(const Form &target);
	Form &operator=(const Form &target);

	// 관료의 등급이 높으면 서명하는
	void beSigned(Bureaucrat &target);

	std::string getFormName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getRequiredGrade() const;
	int getExecuteGrade() const;
	virtual void execute(Bureaucrat const &executor) = 0;
	
	class GradeTooHighException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class IsnotSigned : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class LowGrade : public std::exception {
	public:
		const char *what(void) const throw();
	};

private:
	std::string formName_;
	std::string formTarget_;
	bool isSigned_;
	int requiredGrade_;
	int executedGrade_;
};

std::ostream& operator<<(std::ostream &outputStream, const Form &ref);


#endif
