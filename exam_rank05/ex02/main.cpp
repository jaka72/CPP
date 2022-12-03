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

      Warlock richard("Richard", "foo");
      richard.setTitle("Hello, I'm Richard the Warlock!");
      richard.introduce();
      BrickWall model1;

      Polymorph* polymorph = new Polymorph();
      TargetGenerator tarGen;

      tarGen.learnTargetType(&model1); // CAN LEARN, BECAUSE model WAS CREATED ABOVE
      richard.learnSpell(polymorph);

      Fireball*   fireball = new Fireball();
      Fwoosh*     fwoosh   = new Fwoosh();



      richard.learnSpell(fireball);
      richard.learnSpell(fwoosh);


      // It can only return a target, which exists in the target.vector
      //    (which has been learned)
      ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall"); // NEEDS DELETE!


      // It can only launch a spell, which has been LEARNED previously
      //    (if it has not been learned, it will return NULL, no effect is printed)
      richard.launchSpell("Polymorph", *wall);
      richard.launchSpell("Fireball", *wall);
      richard.launchSpell("Fwoosh", *wall);
      richard.launchSpell("Fwoosh", model1);

      delete polymorph;
      delete fireball;
      delete wall;
}



// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$
// Richard: My job here is done!$
