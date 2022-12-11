#include <iostream>
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Hokus.hpp"
#include "Fireball.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "colors.h"


int main()
{
	std::cout << "Start main\n";
	// Warlock richard("Richard", "the Titled");

   // Dummy bob;
   // Dummy alice;
   // Fwoosh* fwoosh = new Fwoosh();
   // Hokus* hokus = new Hokus();

   // richard.learnSpell(fwoosh);
   // richard.learnSpell(hokus);

   // richard.introduce();
   // richard.launchSpell("Fwoosh", bob);
   // richard.launchSpell("Hokus", alice);

   // richard.forgetSpell("Fwoosh");
   // richard.launchSpell("Fwoosh", bob);

   // delete fwoosh;
   // delete hokus;


// ex02 ////////////////////////////////////////

      // ABOUT TargetGenerator
      // It can only learn a target, that has been previously created.
      //    Target can be created via class: BrickWall model1
      // BUT !!!
      // ATarget* wall = tarGen.createTarget("incospic... ")
      //     can only creta/return a target, that has been previously learned!      


      // CREATE WARLOCKS
      Warlock richard("Richard", "foo");
      richard.setTitle("Hello, I'm Richard the Warlock!");
      richard.introduce();


      // CREATE SPELLS
      Polymorph*  poly1       = new Polymorph();
      Fireball*   fireball    = new Fireball();
      Fwoosh*     fwoosh      = new Fwoosh();


      // WARLOCK NEEDS TO LEARN THE CREATED SPELLS (STORED INTO ITS OBJECT SPELLBOOK)
      richard.learnSpell(poly1);
      richard.learnSpell(fireball);
      richard.learnSpell(fwoosh);

      


      



      // CREATE TARGETS
      Fwoosh      woosh1;
      BrickWall   model1;



      // AFTER CREATING TARGETS, THESE CAN BE DUPLICATED VIA THE TARGET GENERATOR
      TargetGenerator tarGen;

      tarGen.learnTargetType(&model1); // THE EXISTING TARGETS CAN BE LEARNED BY THE GENERATOR
      
      // THEN, THE GENERATOR CAN RETURN A 'COPY' OF ANY TARGET, LEARNED IN ITS VECTOR
      ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall"); // NEEDS DELETE!
      // It can only return a target, which exists in the target.vector (which has been learned above)


      // It can only launch a spell, which has been LEARNED previously by the Warlock
      //    (if it has not been learned, it will return NULL, no effect is printed)
      richard.launchSpell("Polymorph", *wall);
      richard.launchSpell("Fireball", *wall);
      richard.launchSpell("Fwoosh", *wall);
      richard.launchSpell("Fwoosh", model1);


      richard.forgetSpell("Polymorph");
      richard.forgetSpell("Fireball");
      richard.forgetSpell("Fwoosh");

      tarGen.forgetTargetType("Inconspicuous Red-brick Wall");



      delete poly1;
      delete fireball;
      delete wall;
}



// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$
// Richard: My job here is done!$
