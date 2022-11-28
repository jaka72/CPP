#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string tom{ "Tom" };
  std::string berta{ "Berta" };

//std::vector<std::reference_wrapper<const std::string>> names{ tom, berta }; // these strings are stored by reference, not value
  std::vector<std::reference_wrapper<      std::string>> names{ tom, berta }; // these strings are stored by reference, not value

  std::string jim{ "Jim" };
  std::string jaka{ "Jaka" };
  std::string martas{ "Martas" };

  names.push_back(jim);
  names.push_back(jaka);
  names.push_back(martas);

  for (auto name : names)
  {
    name.get() += " Beam";  // Use the get() member function to get the referenced string.
    std::cout << name.get() << '\n'; // Jim Beam
  }


  return 0;
}