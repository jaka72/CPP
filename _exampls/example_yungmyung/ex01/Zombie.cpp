/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:53:41 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:14:10 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// 좀비의 이름을 포함한 디버깅 메시지를 소멸자에 추가한다.
void Zombie::announce(void)
{
	std::cout << "<" << name_private << "> " << "BraiiiiiiinnnzzzZ" << std::endl;
}

void Zombie::setname_orig(std::string name_orig)
{
	name_private = name_orig;
}

// 소멸자
Zombie::~Zombie(void)
{
	std::cout << "[" << name_private << "] " << "die." << std::endl;
}
