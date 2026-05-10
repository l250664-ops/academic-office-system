#include "../include/DatabaseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

DatabaseManager::DatabaseManager() {
    studentsFile = "students.txt";
    teachersFile = "teachers.txt";
    coursesFile = "courses.txt";
    venuesFile = "venues.txt";
    sectionsFile = "sections.txt";
}

// ---- STUDENT ----
void DatabaseManager::saveStudent(Student* s) {
    ofstream file(studentsFile, ios::app);
    if (!file) { cout << "Error opening students file." << endl; return; }
    file << s->getID() << " | " << s->getName() << " | "
        << s->getStudentType() << " | " << s->calculateGPA() << endl;
    file.close();
}

void DatabaseManager::loadStudents(Student* students[], int& count) {
    ifstream file(studentsFile);
    if (!file) { cout << "No students file found." << endl; return; }
    string line;
    count = 0;
    while (getline(file, line) && count < 50) {
        stringstream ss(line);
        string id, name, type, gpaStr;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, gpaStr);

        auto trim = [](string s) {
            while (!s.empty() && s[0] == ' ') s = s.substr(1);
            while (!s.empty() && s.back() == ' ') s.pop_back();
            return s;
            };
        id = trim(id); name = trim(name);
        type = trim(type); gpaStr = trim(gpaStr);

        float gpa = stof(gpaStr);

        if (type == "Regular")
            students[count++] = new RegularStudent(id, name, "", gpa);
        else if (type == "Scholarship")
            students[count++] = new ScholarshipStudent(id, name, "", gpa, 2.5);
        else if (type == "Exchange")
            students[count++] = new ExchangeStudent(id, name, "", gpa);
    }
    file.close();
}
// ---- TEACHER ----
void DatabaseManager::saveTeacher(Teacher* t) {
    ofstream file(teachersFile, ios::app);
    if (!file) { cout << "Error opening teachers file." << endl; return; }
    file << t->getID() << " | " << t->getName() << " | "
        << t->getEmail() << " | " << t->getAverageFeedback() << endl;
    file.close();
}

void DatabaseManager::loadTeachers(Teacher* teachers[], int& count) {
    ifstream file(teachersFile);
    if (!file) { cout << "No teachers file found." << endl; return; }
    string line;
    count = 0;
    while (getline(file, line) && count < 20) {
        stringstream ss(line);
        string id, name, email, feedback;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, feedback);

        auto trim = [](string s) {
            while (!s.empty() && s[0] == ' ') s = s.substr(1);
            while (!s.empty() && s.back() == ' ') s.pop_back();
            return s;
            };
        id = trim(id); name = trim(name);
        email = trim(email);

        teachers[count++] = new Teacher(id, name, email);
    }
    file.close();
}
