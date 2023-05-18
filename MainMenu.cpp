#pragma once 
#include "MainMenu.h"
MainMenu::MainMenu() : Queue(new PriorityQueue()) {}

MainMenu::~MainMenu() {
    delete Queue;
}

void MainMenu::Run() {
    bool exit = false;
    while (!exit) {
        int choice = 0;
        std::cout << "-------------- MENU --------------" << std::endl;
        std::cout << "Enter a number: " << std::endl
            << "1. Add DevelopmentTask" << std::endl
            << "2. Add Defect" << std::endl
            << "3. Delete Last Item" << std::endl
            << "4. Show" << std::endl
            << "5. Delete All" << std::endl
            << "6. Save To File" << std::endl
            << "7. Load From File" << std::endl
            << "8. Sort" << std::endl
            << "9. Count Defect From Component" << std::endl
            << "10. Exit." << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            AddDevelopmentTask();
            system("cls");
            break;
        case 2:
            system("cls");
            AddDefect();
            system("cls");
            break;
        case 3:
            system("cls");
            LastItemDelete();
            break;
        case 4:
            system("cls");
            Show();
            break;
        case 5:
            system("cls");
            AllDelete();
            break;
        case 6:
            system("cls");
            SaveToFile();
            break;
        case 7:
            system("cls");
            LoadFromFile();
            break;
        case 8:
            system("cls");
            Sort();
            break;
        case 9:
            system("cls");
            CountDefectFromComponent();
            break;
        case 10:
            exit = true;
            break;
        default:
            system("cls");
            std::cout << "Error, try again." << std::endl;
            std::cin.clear();
            break;
        }
    }

    std::cout << "Thank you!" << std::endl;
}

void MainMenu::AddDevelopmentTask() {
    DevelopmentTask* task = new DevelopmentTask();
    std::cin >> *task;
    Queue->push(task);
}

void MainMenu::AddDefect() {
    Defect* defect = new Defect();
    std::cin >> *defect;
    Queue->push(defect);
}

void MainMenu::LastItemDelete() {
    Queue->pop();
}

void MainMenu::Show() {
    Queue->print();
}

void MainMenu::AllDelete() {
    Queue->Clear();
}

void MainMenu::SaveToFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    Queue->inFile(filename);
}

void MainMenu::LoadFromFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;
    Queue->fromFile(filename);
}

void MainMenu::Sort() {
    Queue->sort();
}

void MainMenu::CountDefectFromComponent() {
    int component = 0;
    std::cout << "Enter component: ";
    std::cin >> component;
    int count = Queue->countDefectsFromComponent(component);
    std::cout << "Number of defects from component " << component << ": " << count << std::endl;
}
