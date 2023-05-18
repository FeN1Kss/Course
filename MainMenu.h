#pragma once 
#include "PriorityQueueContainer.h"


class MainMenu {
public:
    MainMenu();
    ~MainMenu();
    void Run();

private:
    void AddDevelopmentTask();
    void AddDefect();
    void LastItemDelete();
    void Show();
    void AllDelete();
    void SaveToFile();
    void LoadFromFile();
    void Sort();
    void CountDefectFromComponent();

    PriorityQueue* Queue;
};
