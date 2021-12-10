#include <iostream>
#include "cellphone.hpp"

int main()
{
  // TODO
  // provide the function body for your "main" function here
  Cellphone cp ("Android", "555-555-5555");

  Speaker *spk = new Speaker ("Bose");


  cp.pair (spk);
  cp.display ();

  delete (spk);
  spk = NULL; 


  std::cout << std::endl;
  return 0;
}
