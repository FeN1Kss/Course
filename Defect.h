#pragma once
#include "Software.h"

class Defect : public Task {
private:
    int severity;
public:
    Defect();
    Defect(std::string _name, std::string _description, int _priority, bool _isCompleted, int _severity);

    void setSeverity(int _severity);
    int getSeverity() const;
    void show(std::ostream& obj) const override;
    ~Defect();

    friend std::istream& operator >> (std::istream& in, Defect& obj);
    friend std::ostream& operator << (std::ostream& out, Defect& obj);
};
