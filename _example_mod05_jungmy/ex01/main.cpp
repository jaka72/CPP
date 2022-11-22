/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:47:57 by mjung             #+#    #+#             */
/*   Updated: 2021/12/16 20:47:58 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		// 예외 처리 예제
		{
//			Form project1("project 1", 1000, -3);
//			Form project1("project 1", 10000, 5);
		}

		// 일반 예제 1
		{
			// 관료 생성
			Bureaucrat human("Olivia", 3);
			std::cout << human << std::endl;

			// 결제 폼 작성
			Form project1("project 1", 3, 3);

			// 결제를 받는다.
			project1.beSigned(human);

			// 결제를 출력한다.
			human.signForm(project1);

			// Form에 대한 정보 출력
			std::cout << project1 << std::endl;
		}

		// 일반 예제 2
//		{
//			// 관료 생성
//			Bureaucrat human("Olivia", 3);
//			std::cout << human << std::endl;
//
//			// 결제 폼 작성
//			Form project1("project 1", 3, 2);
////			Form project1("project 1", 1, 3);
//
//			// 결제를 받는다.
//			project1.beSigned(human);
//
//			// 결제를 출력한다.
//			human.signForm(project1);
//
//			// Form에 대한 정보 출력
//			std::cout << project1 << std::endl;
//		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
