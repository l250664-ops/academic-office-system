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
// ---- VENUE ----
void DatabaseManager::saveVenue(Venue* v) {
    ofstream file(venuesFile, ios::app);
    if (!file) { cout << "Error opening venues file." << endl; return; }
    file << v->getRoomID() << " | " << v->getCapacity() << " | "
        << v->getHasComputers() << endl;
    file.close();
}

void DatabaseManager::loadVenues(Venue* venues[], int& count) {
    ifstream file(venuesFile);
    if (!file) { cout << "No venues file found." << endl; return; }
    string line;
    count = 0;
    while (getline(file, line) && count < 20) {
        stringstream ss(line);
        string id, cap, comp;
        getline(ss, id, '|');
        getline(ss, cap, '|');
        getline(ss, comp);

        auto trim = [](string s) {
            while (!s.empty() && s[0] == ' ') s = s.substr(1);
            while (!s.empty() && s.back() == ' ') s.pop_back();
            return s;
            };
        id = trim(id);

        venues[count++] = new Venue(id, stoi(trim(cap)), stoi(trim(comp)));
    }
    file.close();
}

// ---- SECTION ----
void DatabaseManager::saveSection(Section* s) {
    ofstream file(sectionsFile, ios::app);
    if (!file) { cout << "Error opening sections file." << endl; return; }
    file << s->getSectionID() << " | " << s->getCourseID() << " | "
        << s->getTeacherID() << " | " << s->getVenueID() << " | "
        << s->getTimeSlot() << endl;
    file.close();
}

void DatabaseManager::loadSections(Section* sections[], int& count) {
    ifstream file(sectionsFile);
    if (!file) { cout << "No sections file found." << endl; return; }
    string line;
    count = 0;
    while (getline(file, line) && count < 50) {
        stringstream ss(line);
        string sid, cid, tid, vid, slot;
        getline(ss, sid, '|');
        getline(ss, cid, '|');
        getline(ss, tid, '|');
        getline(ss, vid, '|');
        getline(ss, slot);

        auto trim = [](string s) {
            while (!s.empty() && s[0] == ' ') s = s.substr(1);
            while (!s.empty() && s.back() == ' ') s.pop_back();
            return s;
            };

        sections[count++] = new Section(trim(sid), trim(cid),
            trim(tid), trim(vid), trim(slot));
    }
    file.close();
}

// ---- COURSE ----
void DatabaseManager::saveCourse(Course* c) {
    ofstream file(coursesFile, ios::app);
    if (!file) { cout << "Error opening courses file." << endl; return; }
    file << c->getCourseID() << " | " << c->getTitle() << " | "
        << c->getTeacherID() << " | " << c->getCourseType() << endl;
    file.close();
}

void DatabaseManager::loadCourses(Course* courses[], int& count) {
    ifstream file(coursesFile);
    if (!file) { cout << "No courses file found." << endl; return; }
    string line;
    count = 0;
    while (getline(file, line) && count < 20) {
        stringstream ss(line);
        string id, title, tid, type;
        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, tid, '|');
        getline(ss, type);

        auto trim = [](string s) {
            while (!s.empty() && s[0] == ' ') s = s.substr(1);
            while (!s.empty() && s.back() == ' ') s.pop_back();
            return s;
            };
        id = trim(id); title = trim(title);
        tid = trim(tid); type = trim(type);

        if (type == "Core")
            courses[count++] = new CoreCourse(id, title, tid);
        else if (type == "Elective")
            courses[count++] = new ElectiveCourse(id, title, tid);
        else if (type == "Lab")
            courses[count++] = new LabCourse(id, title, tid);
    }
    file.close();
}

// ----Assessment----
void DatabaseManager::saveAssessment(string sectionID, string type, float rawScore, float maxScore) {
    ofstream file("assessments.txt", ios::app);
    if (!file) { cout << "Error opening assessments file." << endl; return; }
    file << sectionID << " | " << type << " | " << rawScore << " | " << maxScore << endl;
    file.close();
}