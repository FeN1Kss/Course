#pragma once 
#include "PriorityQueueContainer.h"

PriorityQueue::PriorityQueue() : head(nullptr) {}

PriorityQueue::~PriorityQueue() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp->task;
        delete temp;
    }
}

void PriorityQueue::push(Task* task) {
    Node* newNode = new Node;
    newNode->task = task;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else if (task->getPriority() > head->task->getPriority()) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && task->getPriority() <= current->next->task->getPriority()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void PriorityQueue::pop() {
    if (head == nullptr) {
        std::cout << "Priority queue is empty." << std::endl;
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp->task;
        delete temp;
    }
}

void PriorityQueue::print() const {
    if (head == nullptr)
        std::cout << "Priority queue is empty." << std::endl;
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << *(current->task);
            current = current->next;
        }
    }
    std::cout << std::endl;
    return;
}

void PriorityQueue::inFile(const std::string& filename) const {
    if (head == nullptr) {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }
    std::ofstream file(filename);
    if (file.is_open()) {
        Node* current = head;
        while (current) {

            DevelopmentTask* devTask = dynamic_cast<DevelopmentTask*>(current->task);
            if (devTask) {
                file << "1 ";
                file << current->task->getName() << " ";
                file << current->task->getDescription() << " ";
                file << devTask->getAssignee() << " ";
                file << current->task->getPriority() << " ";
                file << current->task->getIsCompleted() << std::endl;
            }

            Defect* defect = dynamic_cast<Defect*>(current->task);
            if (defect) {
                file << "2 ";
                file << current->task->getName() << " ";
                file << current->task->getDescription() << " ";
                file << defect->getSeverity() << " ";
                file << current->task->getPriority() << " ";
                file << current->task->getIsCompleted() << std::endl;
            }
            std::cout << "Data saved to file successfully." << std::endl;
            current = current->next;
        }

        file.close();
    }
    else {
        std::cout << "Failed to open the file: " << filename << std::endl;
    }
}

void PriorityQueue::fromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream is(line);

            std::string name, assignee, description;
            int priority, severity, taskType;
            bool isCompleted;


            is >> taskType;

            if (taskType == 1) {
                if (!(is >> name >> description >> assignee >> priority >> isCompleted)) {
                    continue;
                }
                Task* task = new DevelopmentTask(name, description, priority, isCompleted, assignee);
                push(task);
            }

            else if (taskType == 2) {
                if (!(is >> name >> description >> severity >> priority >> isCompleted)) {
                    continue;
                }
                Task* task = new Defect(name, description, priority, isCompleted, severity);
                push(task);
            }
        }

        file.close();
        std::cout << "Data loaded from file successfully." << std::endl;
    }
    else {
        std::cout << "Failed to open the file: " << filename << std::endl;
    }
}

void PriorityQueue::sort() {
    if (head == nullptr) {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || current->task->getIsCompleted() > sorted->task->getIsCompleted()) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while (temp->next != nullptr && current->task->getIsCompleted() <= temp->next->task->getIsCompleted()) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
    std::cout << "Priority queue sorted." << std::endl;
}
void PriorityQueue::Clear()
{
    if (head == nullptr) {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }
    while (head != NULL)
        pop();
    std::cout << "Priority queue cleaned" << std::endl;
    return;
}
int PriorityQueue::countDefectsFromComponent(const int component) const {
    int count = 0;
    Node* current = head;
    while (current) {
        Defect* defect = dynamic_cast<Defect*>(current->task);
        if (defect && defect->getSeverity() == component) {
            count++;
        }

        current = current->next;
    }

    return count;

}
