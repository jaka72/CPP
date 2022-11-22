/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:48:40 by mjung             #+#    #+#             */
/*   Updated: 2021/12/16 20:20:46 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);

	virtual ~Bureaucrat();

	Bureaucrat(const Bureaucrat &target);

	Bureaucrat &operator=(const Bureaucrat &target);

	std::string getName() const;
	unsigned getGrade() const;
	void setIncreaseGrade();    // 등급을 높인다
	void setDecreaseGrade();    // 등급을 낮춘다

	class GradeTooHighException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what(void) const throw();
	};

private:
	const std::string name_ ;
	int grade_;

};

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref);

#endif
