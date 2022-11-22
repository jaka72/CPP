/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:47:51 by mjung             #+#    #+#             */
/*   Updated: 2021/12/16 20:47:53 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// throw() : 예외를 던지지 않은 함수
const char* Form::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]\nGrade 1 is the highest grade, so you can't raise your grade any more.");
}

// throw() : 예외를 던지지 않은 함수
const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]\nThe grade 150 is the lowest, so you can't lower the grade any more.");
}

Form::Form()
{
	isSigned_ = 0;
	requiredGrade_ = 0;
	executedGrade_ = 0;
}

// 등급 설정에 대한 오류는 여기서만
Form::Form(std::string _FormName,int _requiredGrade, int _executedGrade)
{
	isSigned_ = 0;
	FormName_ = _FormName;
	if (_requiredGrade < 1 || _executedGrade < 1 )
		throw GradeTooHighException();
	else if (_requiredGrade > 150 || _executedGrade > 150 )
		throw GradeTooLowException();

	requiredGrade_ = _requiredGrade;
	executedGrade_ = _executedGrade;
}

Form::~Form()
{

}

Form::Form(const Form &target) {
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
}

Form &Form::operator=(const Form &target)
{
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
	return (*this);
}

std::string Form::getFormName() const
{
	return (FormName_);
}
bool Form::getIsSigned() const
{
	return (isSigned_);
}

int Form::getRequiredGrade() const
{
	return (requiredGrade_);
}

int Form::getExecuteGrade() const
{
	return (executedGrade_);
}

void Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= requiredGrade_ && target.getGrade() <= executedGrade_)
		isSigned_ = 1;
}

std::ostream& operator<<(std::ostream &outputStream, const Form &ref)
{
	outputStream <<
	"[ " << ref.getFormName() << " ]" << std::endl
	<< "Required grade : " << ref.getRequiredGrade()  << std::endl
	<< "Executed grade : " << ref.getExecuteGrade()  << std::endl;
	return (outputStream);
}

