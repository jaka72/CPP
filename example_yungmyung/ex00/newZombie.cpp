/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:50:59 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 19:51:37 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 *  < 목표 >
 *  - 좀비 생성
 *  - 좀비 이름 설정
 *  - 코드의 다른 위치에서 사용하도록 반환
 */

// THIS WHOLE FUNCTION SEEMS REDUNDANT,
// BUT IT IS REQUIRED BY THE SUBJECT

Zombie* newZombie(std::string name)
{
	//Zombie *new_one;	// CAN THIS BE SHORTENED, AND WITHOUT THE STAR ??
	
	//new_one = new Zombie(name);
	
	//return new_one;
	return new Zombie(name);	// new -> THIS ALLOCATES MEMORY
}
