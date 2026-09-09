#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
public:
    // constructor
    Student(const std::string &name, int age);

    // destructor
    ~Student();

    // copy constructor
    Student(const Student &st);

    // copy assignment operator
    Student &operator=(const Student &ehs);

    std::string getName() const;
    int getAge() const;

private:
    std::string *name;
    int *age;
};

#endif // STUDENT_HPP