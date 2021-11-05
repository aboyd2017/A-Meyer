#include <iostream>
#include "workplace.hpp"

int main()
{
  try
  {
    Employee emp("Bill", 1, "Research", 2, 40.0, 35000);
    emp.display();
  }
  catch (const Exception & e)
  {
    e.display();
  }


  try
  {
    Employee emp("Fred", 123456789, "Nothing", 1, 20.0, 10000);
    emp.display();
  }
  catch (const Exception & e)
  {
    e.display();
  }


  try
  {
    Employee emp("Fred", 123456789, "Web Application", 1, 20.0, 10000);
    emp.setProject("Nothing");
    emp.display();
  }
  catch (const Exception & e)
  {
    e.display();
  }


  try
  {
    Employee emp("Bill", 111111111, "Mobile Development", 2, 40.0, 35000);
    Person per("Fred", 123456789);
    Manager mgr(emp, per);
    mgr.displayTeam();
  }
  catch (const Exception & e)
  {
    e.display();
  }


  return 0;
}













