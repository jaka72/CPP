#include <iostream>
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Hokus.hpp"
#include "Dummy.hpp"
#include "colors.h"


int main()
{
	std::cout << "Start main\n";
	Warlock richard("Richard", "the Titled");

   Dummy bob;
   Dummy alice;
   Fwoosh* fwoosh = new Fwoosh();
   Hokus* hokus = new Hokus();

   richard.learnSpell(fwoosh);
   richard.learnSpell(hokus);

   richard.introduce();
   richard.launchSpell("Fwoosh", bob);
   richard.launchSpell("Hokus", alice);

   richard.forgetSpell("Fwoosh");
   richard.launchSpell("Fwoosh", bob);



   delete fwoosh;
   delete hokus;
}



// ~$ ./a.out | cat -e
// Richard: This looks like another boring day.$
// Richard: I am Richard, the Titled!$
// Target Practice Dummy has been fwooshed!$
// Richard: My job here is done!$
