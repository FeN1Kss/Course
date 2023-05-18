#pragma once 
#include "Software.h"
class DevelopmentTask : public Task {
private:
    std::string assignee;

public:
    DevelopmentTask();
    DevelopmentTask(std::string _name, std::string _description, int _priority, bool _isCompleted, std::string _assignee);

    void setAssigneey(std::string _assignee);
    std::string getAssignee() const;
    void show(std::ostream& obj) const override;
    ~DevelopmentTask();

    friend std::istream& operator >> (std::istream& in, DevelopmentTask& obj);
    friend std::ostream& operator << (std::ostream& out, DevelopmentTask& obj);
};
