#include "Schedule.h"
void Schedule::initSchedule(std::ifstream& inputFile) {
    std::string line;
    std::getline(inputFile, line); // Discard header

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string subject, catalog, section, component, session, instructor;
        int units, totalEnrollment, capacity;

        std::getline(ss, subject, ',');
        std::getline(ss, catalog, ',');
        std::getline(ss, section, ',');
        std::getline(ss, component, ',');
        std::getline(ss, session, ',');
        ss >> units;
        ss.ignore();
        ss >> totalEnrollment;
        ss.ignore();
        ss >> capacity;
        ss.ignore();
        std::getline(ss, instructor, ',');

        ScheduleItem item(subject, catalog, section, component, session, units, totalEnrollment, capacity, instructor);
        addEntry(item);
    }
}

void Schedule::addEntry(const ScheduleItem& item) {
    scheduleMap[item.getKey()] = item;
}

void Schedule::print() const {
    printHeader();
    for (const auto& entry : scheduleMap) {
        entry.second.print();
    }
}

void Schedule::printHeader() const {
    std::cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor" << std::endl;
}

void Schedule::findBySubject(const std::string& subject) const {
    printHeader();
    for (const auto& entry : scheduleMap) {
        if (entry.second.getSubject() == subject) {
            entry.second.print();
        }
    }
}

void Schedule::findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const {
    printHeader();
    for (const auto& entry : scheduleMap) {
        if (entry.second.getSubject() == subject && entry.second.getCatalog() == catalog) {
            entry.second.print();
        }
    }
}

void Schedule::findByInstructorLastName(const std::string& lastName) const {
    printHeader();
    for (const auto& entry : scheduleMap) {
        if (entry.second.getInstructor().find(lastName) != std::string::npos) {
            entry.second.print();
        }
    }
}