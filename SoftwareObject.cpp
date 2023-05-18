#pragma once 
#include "Software.h"

Task::Task()  {}

Task::Task(const std::string& _name, const std::string& _description, int _priority, bool _isCompleted)
    : name(_name), description(_description), priority(_priority), isCompleted(_isCompleted) {}

Task::~Task() {}

std::string Task::getName() const {
    return name;
}

std::string Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

bool Task::getIsCompleted() const {
    return isCompleted;
}

void Task::setName(const std::string& _name) {
    name = _name;
}

void Task::setDescription(const std::string& _description) {
    description = _description;
}

void Task::setPriority(int _priority) {
    priority = _priority;
}

void Task::setIsCompleted(bool _isCompleted) {
    isCompleted = _isCompleted;
}

void Task::show(std::ostream& obj) const {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Priority: " << priority << std::endl;
    std::cout << "IsCompleted: " << isCompleted << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, Task& obj)
{
    obj.show(out);
    return out;
}
std::istream& operator>>(std::istream& in, Task& obj)
{
	std::string Name, Description;
	int priority;
	bool isCompleted;

	std::cout << "Name: ";
	std::cin >> Name;
	obj.setName(Name);

	std::cout << "Description: ";
	std::cin >> Description;
	obj.setDescription(Description);



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
