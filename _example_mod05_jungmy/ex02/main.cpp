/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjung <mjung@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 17:34:43 by mjung         #+#    #+#                 */
/*   Updated: 2022/10/27 18:17:42 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentPardonForm.hpp"

int main(void)
{
	try
	{
//		Bureaucrat human("oliver",149);
//		ShrubberyCreationForm myTree("mjung");
		// RobotomyRequestForm robotomy("tommy");
		// PresidentPardonForm pardon("nice dog");

		// // 사람 등급 출력
		// std::cout << human << std::endl;

		//  // 각각의 폼에 대한 정보 출력
		// std::cout << robotomy << std::endl;
		// std::cout << myTree << std::endl;
		// std::cout << pardon << std::endl;

		// // 각각의 폼에 싸인 시도
		// myTree.beSigned(human);
		// robotomy.beSigned(human);
		// pardon.beSigned(human);

		// // 각각의 폼에 싸인이 되었는지 확인
		// human.signForm(myTree);
		// human.signForm(robotomy);
		// human.signForm(pardon);

		// // 싸인이 되어있고, 실행등급이 충분하다면 실행
		// // 권한 부족시 예외 처리
		// myTree.execute(human);
		// robotomy.execute(human);
		// pardon.execute(human);



		// jaka
		Bureaucrat bur("Bur1", 2);
		// ShrubberyCreationForm myTree("myfile");

		PresidentPardonForm pardon1("Myname");


		std::cout << "-----------------------After init shrubform\n";


		pardon1.beSigned(bur);
		pardon1.execute(bur);
		
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
