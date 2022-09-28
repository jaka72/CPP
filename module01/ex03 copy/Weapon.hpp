/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:13:18 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 13:21:56 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
    
    private:
        std::string type;

    public:

        // Constructor
        Weapon(const std::string type);

        // Destructor
        ~Weapon();


        // Member functions
        void setType(const std::string &type_orig);


        const std::string& getType();
};

#endif
