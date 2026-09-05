#include <iostream>
#include <string>

class CallBack
{
public:
    void onSuccess(std::string message)
    {
        std::cout << "Success: " << message << std::endl;
    }

    void onError(std::string error)
    {
        std::cout << "Error: " << error << std::endl;
    }
};

void calculate(int x, int y, CallBack &callback)
{
    int sum = x + y;

    std::cout << "Sum is " << sum << std::endl;

    if (sum > 10)
    {
        callback.onSuccess("Sum is greater than 10.");
    }
    else
    {
        callback.onError("Sum is not greater than 10.");
    }
}

int main()
{
    CallBack *callback = new CallBack();

    calculate(6, 89, *callback);

    delete callback;

    return 0;
}