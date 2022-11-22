/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:48:48 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:36:43 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// throw() : 예외를 던지지 않은 함수
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]\nGrade 1 is the highest grade, so you can't raise your grade any more.");
}

// throw() : 예외를 던지지 않은 함수
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]\nThe grade 150 is the lowest, so you can't lower the grade any more.");
}

Bureaucrat::Bureaucrat()
{
	grade_ = 0;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name_(_name), grade_(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();

	else if (_grade > 150)
		throw GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &target) : name_(target.name_)
{
	grade_ = target.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
	grade_ = target.grade_;
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return (name_);
}

unsigned Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::setIncreaseGrade()
{
	if (grade_ > 1)
		grade_--;
	else if (grade_ == 1)
		throw GradeTooHighException();
}

void Bureaucrat::setDecreaseGrade()
{
	if (grade_ < 150)
		grade_++;
	else if (grade_ == 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {

	if (form.getIsSigned() == 1)
	{
		std::cout << name_ << " signs " << form.getFormName() << std::endl;
	}
	else
	{
		std::cout << name_ << " cannot sign " << form.getFormName() << " because ";

		if (grade_ > form.getExecuteGrade() && grade_ > form.getRequiredGrade())
			std::cout << "all grade is low.";
		else if (grade_ > form.getExecuteGrade())
			std::cout << "execute grade is low.";
		else if (grade_ > form.getRequiredGrade())
			std::cout << "required grade is low.";
		else
			std::cout << name_ << " didn't receive the payment.";
		std::cout << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	if (grade_ >= form.getExecuteGrade())
	{
		std::cout << name_ << " cannot sign " << form.getFormName() << " because ";
		std::cout << "execute grade is low.";
	}
	else
	{
		std::cout << name_ << " executes " << form.getFormName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
	outputStream << ref.getName() << ", grade : " << ref.getGrade();
	return (outputStream);
}

