#include <iostream>
// #include <string>
// #include <string_view>

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

    bool operator== (const Car& c1, const Car& c2);
    // friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_model == c2.m_model);
}

bool Car::operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_model != c2.m_model);
}

int main()
{
    Car corolla{ 44 };
    Car camry{ 44 };

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";
	else
        std::cout << "a Corolla and Camry are not the same.\n";

    return 0;
}
