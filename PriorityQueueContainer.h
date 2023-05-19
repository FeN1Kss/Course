#pragma once 
#include "Defect.h"
#include "DevelopmentTask.h"


class PriorityQueue {
private:
    struct Node {
        Task* task;
        Node* next;
    };

    Node* head;

public:
    PriorityQueue();
    ~PriorityQueue();

    void push(Task* task);
    void pop();
    bool IsEmpty();
    void print() const;
    void inFile(const std::string& filename) const;
    void fromFile(const std::string& filename);
    void sort();
    void Clear();
    int countDefectsFromComponent(const int component) const;
};
