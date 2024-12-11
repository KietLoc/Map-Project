#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string session;
    int units;
    int totEnrl;
    int capEnrl;
    std::string instructor;

public:
    // Constructor with default values
    ScheduleItem(std::string subj = "", std::string cat = "", std::string sect = "",
        std::string comp = "", std::string sess = "", int un = 0, int totE = 0,
        int capE = 0, std::string instr = "") :
        subject(subj), catalog(cat), section(sect), component(comp),
        session(sess), units(un), totEnrl(totE), capEnrl(capE), instructor(instr) {
    }

    // Getter functions
    std::string getSubject() const { return subject; }
    std::string getCatalog() const { return catalog; }
    std::string getSection() const { return section; }
    std::string getComponent() const { return component; }
    std::string getSession() const { return session; }
    int getUnits() const { return units; }
    int getTotalEnrollment() const { return totEnrl; }
    int getCapacityEnrollment() const { return capEnrl; }
    std::string getInstructor() const { return instructor; }

    void print() const {
        std::cout << *this << std::endl;  // Use the operator<< to print the object
    }

    // Comparison operators
    bool operator==(const ScheduleItem& other) const {
        return subject == other.subject && catalog == other.catalog && section == other.section;
    }

    bool operator!=(const ScheduleItem& other) const {
        return !(*this == other);
    }

    bool operator<(const ScheduleItem& other) const {
        return std::tie(subject, catalog, section) < std::tie(other.subject, other.catalog, other.section);
    }

    // Output function to display the data in CSV format
    friend std::ostream& operator<<(std::ostream& os, const ScheduleItem& item) {
        os << item.subject << ',' << item.catalog << ',' << item.section << ','
            << item.component << ',' << item.session << ',' << item.units << ','
            << item.totEnrl << ',' << item.capEnrl << ',' << item.instructor;
        return os;
    }
};

class Schedule {
private:
    std::map<std::tuple<std::string, std::string, std::string>, ScheduleItem> items;

public:
    // Function to initialize schedule from the file
    void initSchedule(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            return;
        }

        std::string line, word;
        std::getline(file, line); // Skip the first line with column headers

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::vector<std::string> record;

            while (std::getline(iss, word, ',')) {
                record.push_back(word);
            }

            if (record.size() >= 9) {
                // Ensure conversion from string to integer for units, totEnrl, and capEnrl
                ScheduleItem item(record[0], record[1], record[2], record[3], record[4],
                    std::stoi(record[5]), std::stoi(record[6]), std::stoi(record[7]), record[8]);
                addEntry(item);
            }
        }
    }

    // Add an entry to the map
    void addEntry(const ScheduleItem& item) {
        items[std::make_tuple(item.getSubject(), item.getCatalog(), item.getSection())] = item;
    }

    // Print the entire schedule
    void print() const {
        for (const auto& pair : items) {
            std::cout << pair.second << std::endl;
        }
    }

    // Print column headers
    void printHeader() const {
        std::cout << "Subject,Catalog,Section,Component,Session,Units,TotEnrl,CapEnrl,Instructor" << std::endl;
    }

    // Find all records by Subject
    void findBySubject(const std::string& subject) const {
        for (const auto& pair : items) {
            if (pair.second.getSubject() == subject) {
                pair.second.print();
            }
        }
    }

    // Find all records by Subject and Catalog
    void findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const {
        for (const auto& pair : items) {
            if (pair.second.getSubject() == subject && pair.second.getCatalog() == catalog) {
                pair.second.print();
            }
        }
    }

    // Find all records by Instructor
    void findByInstructor(const std::string& instructor) const {
        for (const auto& pair : items) {
            if (pair.second.getInstructor() == instructor) {
                pair.second.print();
            }
        }
    }
};

int main() {
    Schedule schedule;
    std::string filename = "SummerSchedule.txt";

    // Initialize the schedule with data from the file
    schedule.initSchedule(filename);

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Print the schedule\n";
        std::cout << "2. Find by Subject\n";
        std::cout << "3. Find by Subject and Catalog\n";
        std::cout << "4. Find by Instructor\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string subject, catalog, instructor;

        switch (choice) {
        case 1:
            schedule.printHeader();
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
            std::cout << "Enter instructor's last name: ";
            std::cin >> instructor;
            schedule.findByInstructor(instructor);
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
