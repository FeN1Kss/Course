#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class Task {
protected:
    std::string name;
    std::string description;
    int priority;
    bool isCompleted;

public:
    Task();
    Task(const std::string& _name, const std::string& _description, int _priority, bool _isCompleted);

    std::string getName() const;
    std::string getDescription() const;
    int getPriority() const;
    bool getIsCompleted() const;
    void setName(const std::string& _name);
    void setDescription(const std::string& _description);
    void setPriority(int _priority);
    void setIsCompleted(bool _isCompleted);
    virtual void show(std::ostream& obj) const;
    virtual ~Task();

    friend std::ostream& operator << (std::ostream& out, Task& obj);
    friend std::istream& operator >> (std::istream& in, Task& obj);
};
