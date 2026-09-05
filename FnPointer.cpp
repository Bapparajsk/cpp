#include <iostream>
#include <string>

typedef void (*callBack)(std::string);

void printHay(std::string name)
{
    std::cout << "Hay " << name << std::endl;
}

void calculate(int &x, callBack)
{
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += i;
    }

    std::cout << "Sum is " << sum << std::endl;

    callBack("Bappa");
}

int main()
{
    int x = 0;

    // void (*callBack)(std::string);

    std::cout << "Enter a Number" << std::endl;
    std::cin >> x;

    // callBack = printHay;

    calculate(x, printHay);
}