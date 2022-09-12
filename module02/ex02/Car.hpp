#ifndef CAR_H
#define CAR_H

#include <iostream>




class Car
{
private:
    // std::string m_make;
    // std::string m_model;
	// int m_make;
    int m_model;
public:
    // Car(std::string make, std::string model) 
    Car(int model) 
		// : m_model{ model }
    {
		m_model = model;
    }

    //friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator< (const Car& c1, const Car& c2);
};


bool operator< (const Car& c1, const Car& c2)
{
    return (c1.m_model < c2.m_model);
}

#endif