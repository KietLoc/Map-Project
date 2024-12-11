// Map Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <iostream>
#include "Schedule.h"

int main() {
    Schedule schedule;
    std::ifstream inputFile("schedule.csv");

    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    schedule.initSchedule(inputFile);
    inputFile.close();

    int choice;
    std::string subject, catalog, lastName;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print Schedule\n";
        std::cout << "2. Find by Subject\n";
        std::cout << "3. Find by Subject and Catalog\n";
        std::cout << "4. Find by Instructor Last Name\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.print();
            break;
        case 2:
            std::cout << "Enter subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        case 3:
            std::cout << "Enter subject: ";
            std::cin >> subject;
            std::cout << "Enter catalog: ";
            std::cin >> catalog;
            schedule.findBySubjectAndCatalog(subject, catalog);
            break;
        case 4:
            std::cout << "Enter instructor last name: ";
            std::cin >> lastName;
            schedule.findByInstructorLastName(lastName);
            break;
        case 5:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
