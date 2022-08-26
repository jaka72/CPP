#include <iostream>

class Zombie
{
    private:
        std::string name_prive;

    public:
        void announce()
        {
            // std::cout << name_prive << "\n";
            std::cout << "Announce " << name_prive << "\n";
        }
        Zombie(std::string name)
        {
            std::cout << "Called constructor\n";
            name_prive = name;
        }
        ~Zombie(void)
        {
            std::cout << "Called Destructor\n";
        }

};

// void Zombie::announce(void)
// {
//     // std::cout << name_prive << "\n";
//     std::cout << "Announce" << "\n";
// }

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie *zmb;
    zmb = newZombie(name);
    zmb->announce();
    delete zmb;
}

int main(void)
{
    //Zombie zombie_1("Joseph");

    randomChump("Joseph");
}
