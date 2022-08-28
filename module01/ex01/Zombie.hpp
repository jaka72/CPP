#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
        std::string name_prive;
    
    public:

        void    announce();
        void    set_name(std::string name)
        {
            name_prive = name;
        }

        std::string    get_name()
        {
            std::cout << name_prive << "\n";
            return name_prive;
        }

        // Zombie(std::string name)
        // {
        //     name_prive = name;
        // }

        Zombie()    // CONSTRUCTOR IS NOT NECESSARY APPARENTLY
        {           // THERE HAS TO BE A SEPARATE FUNCTION TO SET THE NAME
                    // FOR EACH ELEMENT. YOU CANNOT AUTOMATICALY GIVE SAME NAME TO
                    // EACH ELEMENT OF THE ARRAY (VIA AN ARGUMENT), LIKE IN THE CASE WHEN
                    // THERE IS NO ARRAY, BUT ONLY 1 INSTANCE (ex00)
            std::cout << "Called constructor.\n";
            //get_name("Joco");
        }

       ~Zombie(void)
       {
            std::cout << name_prive << " destroyed\n";
       }
};

Zombie *zombieHorde(int N, std::string name);

#endif