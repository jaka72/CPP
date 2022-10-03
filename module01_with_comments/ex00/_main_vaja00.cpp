#include <iostream>

class Zombie
{
    private:
        std::string name_prive;

    public:
        Zombie(std::string name)
        {
            std::cout << "Called constructor\n";
            name_prive = name;
        }
        ~Zombie(void)
        {
            std::cout << "Called Destructor\n";
        }
        void announce()
        {
            // std::cout << name_prive << "\n";
            std::cout << "Announce " << name_prive << "\n";
        }

};

// void Zombie::announce(void)
// {
//     // std::cout << name_prive << "\n";
//     std::cout << "Announce" << "\n";
// }


// IF I UNDERSTAND CORRECTLY, HOW TO CREATE A NEW INSTANCE OF A CLASS
//  FIRST YOU NEED TO CREATE A POINTER: Zombie *zb1; (without arguments)
//  THEN YOU PUT A new instance(arguments) INTO THE POINTER


Zombie *newZombie(std::string name)
{
    Zombie *zb;
    zb = new Zombie(name);
    return (zb);

    // OR SIMPLIFIED:
//    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie *zb1;
    zb1 = newZombie(name);
    zb1->announce();
    delete zb1;
}

int main(void)
{
    //Zombie zombie_1("Joseph");

    randomChump("Joseph");
}
