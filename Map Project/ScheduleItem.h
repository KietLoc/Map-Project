#pragma once
#include <string>
#include <iostream>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totalEnrollment;
    int capacity;
    std::string instructor;

public:
    ScheduleItem(std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string sess = "", int un = 0,
        int totEnrl = 0, int cap = 0, std::string instr = "");

    std::string getKey() const;
    std::string getSubject() const;
    std::string getCatalog() const;
    std::string getSection() const;
    std::string getInstructor() const;
    int getUnits() const;
    int getTotalEnrollment() const;
    int getCapacity() const;
    void print() const;
};
