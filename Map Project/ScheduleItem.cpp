#include "ScheduleItem.h"
ScheduleItem::ScheduleItem(std::string subj, std::string cat, std::string sec,
    std::string comp, std::string sess, int un,
    int totEnrl, int cap, std::string instr)
    : subject(subj), catalog(cat), section(sec), component(comp), session(sess),
    units(un), totalEnrollment(totEnrl), capacity(cap), instructor(instr) {
}

std::string ScheduleItem::getKey() const {
    return subject + "_" + catalog + "_" + section;
}

std::string ScheduleItem::getSubject() const {
    return subject;
}

std::string ScheduleItem::getCatalog() const {
    return catalog;
}

std::string ScheduleItem::getSection() const {
    return section;
}

std::string ScheduleItem::getInstructor() const {
    return instructor;
}

int ScheduleItem::getUnits() const {
    return units;
}

int ScheduleItem::getTotalEnrollment() const {
    return totalEnrollment;
}

int ScheduleItem::getCapacity() const {
    return capacity;
}

void ScheduleItem::print() const {
    std::cout << subject << "\t" << catalog << "\t" << section << "\t"
        << component << "\t" << session << "\t" << units << "\t"
        << totalEnrollment << "\t" << capacity << "\t" << instructor << std::endl;
}