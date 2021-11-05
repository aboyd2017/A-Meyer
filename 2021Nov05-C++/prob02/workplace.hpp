#ifndef __WORKPLACE_HPP__
#define __WORKPLACE_HPP__

#include <string>
#include <sstream>

//------------------------------
// constants
//------------------------------

const int NUMBER_OF_PROJECTS = 5;
const int MAX_TEAM_SIZE = 30;
const int MIN_SSN_VALUE = 100000000;
const int MAX_SSN_VALUE = 999999999;
const int INVALID_VALUE_ERROR_CODE = 1000;

//------------------------------
// Class Definitions
//------------------------------



//------------------------------
// Exception class definition
//------------------------------

class Exception
{
private:
  // Private member variables
  std::string _msg;
  int _except_code;

public:
  Exception(const std::string & message, const int & code)
  {
    _msg = message;
    _except_code = code;
  }

  void display() const
  {
    std::cout << "Error Code: " << _except_code << std::endl;
    std::cout << "Exception: " << _msg  << std::endl; 
  }

  std::string getMessage() const { return _msg; }
  int getCode() const { return _except_code; }

};




//------------------------------
// Person class definition
// this class has been declared for you
// you do not need to modify this class
//-------------------------

class Person
{
private:
  // Create private member variables
  std::string _name;
  int _ssn;

public:
  // Create non-default constructor
  Person(const std::string & name, int ssn);

  // Create accessors and mutators
  std::string getName() const { return _name; }
  int getSsn() const { return _ssn; }

  void setName(const std::string & name) { _name = name; }
  void setSsn(const int & ssn) { _ssn = ssn; }
};



//-------------------------
// Employee class definition
// this class has been declared for you
// you do not need to modify this class
//-------------------------

class Employee : public Person
{
private:
  std::string _project;
  int _dept_num;
  double _hours_per_week;
  double _annual_salary;

public:
  // Create non-default constructor
  Employee(const std::string & name, int ssn, const std::string & project,
           int dept, double hours, double salary);

  int getDeptNum() const { return _dept_num; }
  std::string getProject() const { return _project; }
  double getHoursPerWeek() const { return _hours_per_week; }
  double getAnnualSalary() const { return _annual_salary; }

  void setProject(const std::string & project);
  void setDeptNum(int dept_num) { _dept_num = dept_num; }
  void setHoursPerWeek(double hours) { _hours_per_week = hours; }
  void setAnnualSalary(double salary) { _annual_salary = salary; }

  void display() const;
};



//------------------------------
// Manager class definition
//------------------------------

class Manager : public Employee
{
private:
  Person _team_member;


public:
  Manager (const Employee & employee, const Person & person)  : 
    Employee (employee.getName(), employee.getSsn(), employee.getProject(),
              employee.getDeptNum(), employee.getHoursPerWeek(), 
              employee.getAnnualSalary()), _team_member(person)
  {
    //_team_member = person;
  }

  void displayTeam() const;

};




//------------------------------
// global function prototypes
//------------------------------

bool isValidSsn(const std::string & ssn);
bool isValidProject(const std::string & project);

#endif










