#include <iomanip>
#include <iostream>
#include <string>
#include "workplace.hpp"


//-----------------------------------
// isValidSsn function definition
//-----------------------------------

bool isValidSsn (const std::string & ssn)
{
  if (ssn.length() == 9 && std::stoi(ssn) >= MIN_SSN_VALUE && 
      std::stoi(ssn) <= MAX_SSN_VALUE)
  {
    return true;
  }
  else
  {
    return false;
  }
}


//-----------------------------------
// isValidProject function definition
//-----------------------------------

bool isValidProject(const std::string & project)
{
  bool valid = false;

  std::string proj_arr[NUMBER_OF_PROJECTS] = {
      "Research", "Security", "Web Application", "Mobile Development",
      "Blockchain"};

  // TODO
  // complete the function according to the description above
  for (int i = 0; i < 5; ++i)
  {
    if (proj_arr[i] == project)
    {
      valid = true;
    }
  }

  return valid;
}



//-----------------------------------
// Person constructor definition
//-----------------------------------

Person::Person (const std::string & name, int ssn)
{
  if (!isValidSsn(std::to_string(ssn)))
  {
    // Create error message and throw exception
    std::stringstream ss;
    ss << "Invalid SSN " << ssn << " (Person constructor)";
    
    throw Exception(ss.str(), INVALID_VALUE_ERROR_CODE);
  }
  else
  {
    setName(name);
    setSsn(ssn);
  }
}



//-----------------------------------
// Employee constructor definition
//-----------------------------------

Employee::Employee (const std::string & name, int ssn, 
                    const std::string & project,
                    int dept, double hours, double salary) : Person (name, ssn)
{
  // Check the project
  if (!isValidProject(project))
  {
    // Create error message and throw error
    std::stringstream ss;
    ss << "Invalid Project " << project << " (Employee constructor)";

    throw Exception(ss.str(), INVALID_VALUE_ERROR_CODE);
  }
  else
  {
    // Set all the variables
    setProject(project);
    setDeptNum(dept);
    setHoursPerWeek(hours);
    setAnnualSalary(salary);
  }
}



//-----------------------------------
// Employee:setProject definition
//-----------------------------------

void Employee::setProject(const std::string & project)
{
  // Check the project
  if (!isValidProject(project))
  {
    // Create error message and throw error
    std::stringstream ss;
    ss << "Invalid Project " << project << " (in setProject function)";

    throw Exception(ss.str(), INVALID_VALUE_ERROR_CODE);
  }
  else
  {
    Employee::_project = project;
  }

}





// `Employee::display`
// you do not need to modify this function
// this function prints the team in the format:
// Manager:
// Name: <<name>>
// SSN: <<ssn>>
// Project: <<project>>
// Department Number: <<dept>>
// Hours Worked: <<hours per week>>
// Salary: <<annual salary>>
// Team: <<team member>>
// where the descriptios betwen << >> represent the associated data
// members note that you can call the "display" function in the Employee
// class to print much of the message above

void Employee::display() const
{
  std::cout << "Name: " << getName() << std::endl
            << "SSN: " << getSsn() << std::endl
            << "Project: " << _project << std::endl
            << "Department Number: " << _dept_num << std::endl
            << "Hours Worked: " << std::fixed << std::setprecision(1)
            << _hours_per_week << std::endl
            << "Salary: " << std::fixed << std::setprecision(2)
            << _annual_salary << std::endl;
}


// `Manager::displayTeam` for the Manager class
// you do not need to modify this function

void Manager::displayTeam() const
{
  std::cout << "Manager:" << std::endl;
  display();
  std::cout << "Team: " << _team_member.getName() << std::endl;
}
