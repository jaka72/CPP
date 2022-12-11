
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  // Warlock const richard("Richard", "Mistress of Magma");
  // richard.introduce();
  // std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  // Warlock* jack = new Warlock("Jack", "the Long");
  // jack->introduce();
  // jack->setTitle("the Mighty");
  // jack->introduce();

  // delete jack;





  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  std::cout << "print spell effect: " << fwoosh->getEffects() << "\n";


  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");


  std::cout << "print spell effect, after erase: " << fwoosh->getEffects() << "\n";
  
  richard.launchSpell("Fwoosh", bob);




  return (0);
}