/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Conversion_checkIntOverflow.cpp                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 14:51:26 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/19 20:12:30 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"


int countDigits(int limit)
{
	int i = 0;
	while (limit != 0)
	{
		limit = limit / 10;
		i++;
	}
	return (i);
}

// int max 2147483647
// Compare all digits except the last one, then compare the last one separately
int checkIntOverflow(std::string str, int limit)
{
	int lenStr = strlen(str.c_str());
	int lenLim = countDigits(limit);

	if (lenStr > lenLim)		// string is longer than limit
		return (1);	
	else if (lenStr == lenLim)	// string is same length as limit
	{
		std::string firstSubStr = str.substr(0, lenStr - 1);
		std::string lastChar	= str.substr(lenStr - 1, lenStr);
		if (atoi(firstSubStr.c_str()) > abs(limit / 10))
			return (1);			// overflow
		else if (atoi(firstSubStr.c_str()) == abs(limit / 10))
		{
			if (atoi(lastChar.c_str()) > abs(limit % 10))
				return (1);		// overflow
		}
	}
	return (0);
}
