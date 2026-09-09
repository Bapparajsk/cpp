#include <iostream>
#include <string>
#include "student.hpp"

// constructor
Student::Student(const std::string &name, int age)
{
    std::cout << "Student created" << std::endl;

    this->name = new std::string(name);
    this->age = new int(age);
}

// destructor
Student::~Student()
{
    std::cout << "Student destroyed" << std::endl;

    if (this->name != nullptr)
        delete name;

    if (this->age != nullptr)
        delete age;
}

// copy constructor
Student::Student(const Student &st)
{
    std::cout << "Student copied" << std::endl;

    this->name = new std::string(*st.name);
    this->age = new int(*st.age);
}

// copy assignment operator
Student &Student::operator=(const Student &ehs)
{
    std::cout << "Assignment operator" << std::endl;

    if (this == &ehs)
    {
        return *this;
    }

    delete name;
    delete age;

    name = new std::string(*ehs.name);
    age = new int(*ehs.age);

    return *this;
}

// get age
int Student::getAge() const
{
    return *this->age;
}

// get name
std::string Student::getName() const
{
    return *this->name;
}