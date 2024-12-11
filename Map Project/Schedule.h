#pragma once
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "ScheduleItem.h"

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    void initSchedule(std::ifstream& inputFile);
    void addEntry(const ScheduleItem& item);
    void print() const;
    void printHeader() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructorLastName(const std::string& lastName) const;
};