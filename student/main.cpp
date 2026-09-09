#include <iostream>
#include "student.hpp"

int main()
{
    Student s1("Bapparaj", 20);

    Student s2 = s1; // copy constructor

    Student s3("Rahul", 25);

    s3 = s1; // copy assignment operator

    std::cout << "s1 " << s1.getName() << " " << s1.getAge() << '\n';
    std::cout << "s2 " << s2.getName() << " " << s2.getAge() << '\n';
    std::cout << "s3 " << s3.getName() << " " << s3.getAge() << '\n';

    return 0;
}