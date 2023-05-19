#pragma once 
#include "Defect.h"
//---------------------------------------
//Конструктор
Defect::Defect()
{}
//---------------------------------------
//Конструктор з параметрами
Defect::Defect(const std::string _name, const std::string _description, const int _priority, const bool _isCompleted, const int _severity) : severity(_severity)
{}
//---------------------------------------
//Деструктор
Defect::~Defect()
{}

//---------------------------------------
//Сетер
void Defect::setSeverity(const int _severity) { severity = _severity; }
//---------------------------------------
//Гетер
int Defect::getSeverity(void) const { return severity; }
//---------------------------------------
//Оператор перевантаження вводу з консолі
std::istream& operator>>(std::istream& in, Defect& obj)
{
	std::string Name, Description;
	int priority, severity;
	bool isCompleted;

	std::cout << "Name: ";
	std::cin >> Name;
	obj.setName(Name);

	std::cout << "Description: ";
	std::cin >> Description;
	obj.setDescription(Description);

	std::cout << "Severity: ";
	std::cin >> severity;
	obj.setSeverity(severity);

	std::cout << "Priority: ";
	std::cin >> priority;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect, try again: ";
		std::cin >> priority;
	}
	obj.setPriority(priority);

	std::cout << "IsCompleted(True - 1 or False - 0) : ";
	std::cin >> isCompleted;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect, try again: ";
		std::cin >> isCompleted;
	}
	obj.setIsCompleted(isCompleted);

	return in;
}
//---------------------------------------
//Вивід вмісту контейнеру
void Defect::show(std::ostream& obj) const {
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Priority: " << priority << std::endl;
	std::cout << "IsCompleted: " << isCompleted << std::endl;
	std::cout << "Severity: " << severity << std::endl;
	std::cout << "------------------------------------" << std::endl;
}
//---------------------------------------
//Оператор перевантаження виводу з консолі
std::ostream& operator<<(std::ostream& out, Defect& obj)
{
	obj.show(out);
	return out;
}
