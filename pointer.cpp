#include <iostream>
#include <string>

class Employ;

enum EmployType
{
	GENAREALL,
	UPPER_CLASS,
	MASTER
};

class Calculate
{
public:
	int setUpSalary(Employ *em);
	double increaseSalary(Employ *em);
	static double incrementRates[];
	double incrementRate(EmployType type)
	{
		return incrementRates[type];
	}
};

class Employ
{
	int salary = 0;
	bool itsFirstTimeStUpSalary = true;
	EmployType employType;

	static int employCount;

	friend int Calculate::setUpSalary(Employ *em);
	friend double Calculate::increaseSalary(Employ *em);

public:
	std::string name;
	int age;

	Employ(EmployType type)
	{
		employCount++;
		this->employType = type;
	}

	void setUpdSalary()
	{
		this->itsFirstTimeStUpSalary = false;
	}

	static void setUpEmploy(Employ *em)
	{
		std::cout << "Enter Employ Name : ";
		std::cin >> em->name;

		std::cout << "Enter Employ age : ";
		std::cin >> em->age;
	}

	static void printEmploy(const Employ *em)
	{
		std::cout << std::endl
				  << "------------------------User INfo---------------------------" << std::endl;
		std::cout << "Employ name :- " << em->name << std::endl;
		std::cout << "Employ Age :- " << em->age << std::endl;
		std::cout << "Employ Salary :- " << em->salary << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}
};

int Employ ::employCount = 0;

double Calculate::incrementRates[] = {
	2.5,
	5.5,
	10.7,
	15.0};

	
int Calculate::setUpSalary(Employ *em)
{

	if (!em->itsFirstTimeStUpSalary)
	{
		std::cout << "All ready setUp Salary" << std::endl;
		return -1;
	}

	std::cout << "Enter Employ Salary : ";
	std::cin >> em->salary;
	em->setUpdSalary();
	return 0;
}

double Calculate::increaseSalary(Employ *em)
{
	double employTypeIncrementRate = Calculate::incrementRate(em->employType);

	if (employTypeIncrementRate == 0)
	{
		std::cout << "[Error] Invalid Employ" << std::endl;

		return false;
	}

	em->salary = em->salary * employTypeIncrementRate;

	std::cout << "Employ Salary Increment by " << employTypeIncrementRate << " : " << em->salary << std::endl;

	return true;
}

int main()
{

	Employ em1(EmployType::GENAREALL);

	Calculate cl;

	Employ::setUpEmploy(&em1);
	Employ::printEmploy(&em1);

	cl.setUpSalary(&em1);

	Employ::printEmploy(&em1);

	cl.increaseSalary(&em1);

	Employ::printEmploy(&em1);

	return 0;
}
