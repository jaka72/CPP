#include <iostream>

#include <cassert>

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction() // default constructor
    {
         m_numerator = 0;
        //  m_denominator = 1;
         m_denominator;
    }

    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
       m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fraction frac1; // calls Fraction() default constructor
    Fraction frac2{}; // calls Fraction() default constructor
    std::cout << frac1.getNumerator() << '/' << frac1.getDenominator() << '\n';
    std::cout << frac2.getNumerator() << '/' << frac2.getDenominator() << '\n';

    return 0;
}
