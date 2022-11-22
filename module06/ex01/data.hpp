#ifndef DATA_H
#define DATA_H

#include <stdint.h>		// for type uintptr_t
// #include <cstdint>		// for type uintptr_t
#include <iostream>
#include "colors.h"



struct Data
{
	int			id;
	std::string name;
	Data		*next;
};

#endif
