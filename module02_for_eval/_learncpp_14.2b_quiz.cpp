#include <iostream>

class Fraction
{
	private:
		int numer;
		int	denom;

	public:
		Fraction(int nu = 0, int de = 1) : numer{nu}, denom{de} {};

		void print()
		{
			std::cout << numer << "/" << denom << '\n';
		}

		friend Fraction operator*(int i, const Fraction &f);


};

Fraction operator*(int i, const Fraction &f)
{
	int a { i * f.numer};
	return {a, f.denom};
}


int main()
{
	Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    Fraction f3;
    f3.print();

	Fraction f4{ 5 * f1 };
    f4.print();
	
	return 0;
}