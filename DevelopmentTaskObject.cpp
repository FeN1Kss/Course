#pragma once 
#include "DevelopmentTask.h"
//---------------------------------------
//Конструктор
DevelopmentTask::DevelopmentTask() 
{}
//---------------------------------------
//Конструктор з параметрами
DevelopmentTask::DevelopmentTask(const std::string _name, const std::string _description, const int _priority, const bool _isCompleted, const std::string _assignee) : assignee(_assignee)
{}
//---------------------------------------
//Деструктор
DevelopmentTask::~DevelopmentTask()
{}
//---------------------------------------
//Сетер
void DevelopmentTask::setAssigneey(const std::string _assignee)
{
	assignee = _assignee;
}
//---------------------------------------
//Гетер
std::string DevelopmentTask::getAssignee(void) const
{
	return assignee;
}
//---------------------------------------
//Оператор перевантаження вводу з консолі
std::istream& operator>>(std::istream& in, DevelopmentTask& obj)
{
	std::string Name, Description, Assignee;
	int priority;
	bool isCompleted;

	std::cout << "Name: ";
	std::cin >> Name;
	obj.setName(Name);

	std::cout << "Description: ";
	std::cin >> Description;
	obj.setDescription(Description);

	std::cout << "Assignee: ";
	std::cin >> Assignee;
	obj.setAssigneey(Assignee);

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
void DevelopmentTask::show(std::ostream& obj) const {
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Priority: " << priority << std::endl;
	std::cout << "Assignee: " << assignee << std::endl;
	std::cout << "IsCompleted: " << isCompleted << std::endl;
	std::cout << "------------------------------------" << std::endl;
}
//---------------------------------------
//Оператор перевантаження виводу з консолі
std::ostream& operator<<(std::ostream& out, DevelopmentTask& obj)
{
	obj.show(out);
	return out;
}
