#include <iostream>

void test_outside(void)
{
    std::cout << "Called function test_outside, when destroying\n";
}

class Zombie
{
    private:
        std::string prive_name;
        void test_prive(void)
        {
            std::cout << "Called function test_prive\n";
        }
    public:
        void test1(void)
        {
            std::cout << "Called function test1\n";
        }
        Zombie(std::string name)
        {
            std::cout << "Called constructor\n";  
            prive_name = name;
            test1();
            test_prive();
        }
        ~Zombie(void)
        {
            std::cout << "Called destructor\n";  
            test_outside();
        }
        void    announce(int x)
        {
            std::cout << "Called announce() " << prive_name << x << "\n";
            test_prive();
        
        }
};


Zombie    *newZombie(std::string name)
{
    return new Zombie(name);
}

void    randomChump(std::string name)
{
    Zombie *zb1;
    zb1 = newZombie(name);
    zb1->announce(33);
//  zb1->test_prive();   // NOT ACCESSIBLE!
    delete zb1;
}

int main(void)
{
    // std::string name;
    randomChump("Martina");
}