#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {
    std::ifstream inputFile("StudentData.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<STUDENT_DATA> students;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string lastName, firstName;

        if (std::getline(ss, lastName, ',') && std::getline(ss, firstName)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    inputFile.close();

    // Output the students to verify
    for (const auto& student : students) {
        std::cout << student.lastName << ", " << student.firstName << std::endl;
    }

    return 0;
}
