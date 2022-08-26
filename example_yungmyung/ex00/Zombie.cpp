/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:51:51 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:11:43 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// 좀비의 이름을 포함한 디버깅 메시지를 소멸자에 추가한다.
void Zombie::announce(void)
{
	std::cout << "<" << name_private << "> " << "BraiiiiiiinnnzzzZ" << std::endl;
	//std::cout << "<" << name_orig << "> " << "BraiiiiiiinnnzzzZ" << std::endl;
}

// 생성자
// THIS IS THE SETTER, DEFINED OUTSIDE OF THE CLASS
// Zombie::Zombie(std::string name_orig)
// {
// 	name_private = name_orig;
// 	std::cout << "Constructor is called\n";
// }

// 소멸자
// 	THIS IS THE DESTRUCTOR, DEFINED OUTSIDE OF THE CLASS
// Zombie::~Zombie(void)
// {
// 	std::cout << "[" << name_private << "] " << "die." << std::endl;
// }
