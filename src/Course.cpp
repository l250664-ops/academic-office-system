#include "../include/Course.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Course::Course(string id, string t, string tid, string type)
    : courseID(id), title(t), teacherID(tid), courseType(type),
    finalGrade(0), studentCount(0), assessmentCount(0),
    examWeightage(0), assignmentWeightage(0), quizWeightage(0) {
}

string Course::getCourseID() const {
    return courseID;
}
string Course::getTitle() const {
    return title;
}
string Course::getTeacherID() const {
    return teacherID;
}
string Course::getCourseType() const {
    return courseType;
}
int Course::getStudentCount() const {
    return studentCount;
}

string Course::getEnrolledStudentID(int index) const {
    return enrolledStudentIDs[index];
}

void Course::enrollStudent(string studentID) {
    if (studentCount < 50) {
        enrolledStudentIDs[studentCount] = studentID;
        studentCount++;
    }
    else {
        cout << "Course is full!" << endl;
    }
}

bool Course::isStudentEnrolled(string studentID) const {
    for (int i = 0; i < studentCount; i++) {
        if (enrolledStudentIDs[i] == studentID)
            return true;
    }
    return false;
}

bool Course::isFull() const { return studentCount >= 50; }

void Course::addAssessment(Assessment* a) {
    if (assessmentCount < 10) {
        assessments[assessmentCount] = a;
        assessmentCount++;
    }
}

void Course::loadWeightages(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Warning: weightages.txt not found. Using defaults." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        float exam, assignment, quiz;
        char delim;

        getline(ss, type, '|');
        ss >> exam >> delim >> assignment >> delim >> quiz;

        while (!type.empty() && type[0] == ' ') type = type.substr(1);
        while (!type.empty() && type.back() == ' ') type.pop_back();

        if (type == courseType) {
            examWeightage = exam;
            assignmentWeightage = assignment;
            quizWeightage = quiz;
            break;
        }
    }
    file.close();
}

Course::~Course() {
    for (int i = 0; i < assessmentCount; i++) {
        delete assessments[i];
    }
}

CoreCourse::CoreCourse(string id, string t, string tid)
    : Course(id, t, tid, "Core") {
    loadWeightages("weightages.txt");
}

float CoreCourse::calculateFinalGrade() const {
    float total = 0;
    for (int i = 0; i < assessmentCount; i++) {
        total += assessments[i]->calculateScore();
    }
    return total;
}

int CoreCourse::getExamDuration() const { return 3; }

void CoreCourse::displayInfo() const {
    cout << "\n--- Core Course ---" << endl;
    cout << "ID       : " << courseID << endl;
    cout << "Title    : " << title << endl;
    cout << "Teacher  : " << teacherID << endl;
    cout << "Exam     : " << examWeightage << "%" << endl;
    cout << "Assignment: " << assignmentWeightage << "%" << endl;
    cout << "Quiz     : " << quizWeightage << "%" << endl;
    cout << "Duration : " << getExamDuration() << " hours" << endl;
    cout << "Students : " << studentCount << endl;
}

ElectiveCourse::ElectiveCourse(string id, string t, string tid)
    : Course(id, t, tid, "Elective") {
    loadWeightages("weightages.txt");
}

float ElectiveCourse::calculateFinalGrade() const {
    float total = 0;
    for (int i = 0; i < assessmentCount; i++) {
        total += assessments[i]->calculateScore();
    }
    return total;
}

int ElectiveCourse::getExamDuration() const { return 2; }

void ElectiveCourse::displayInfo() const {
    cout << "\n--- Elective Course ---" << endl;
    cout << "ID       : " << courseID << endl;
    cout << "Title    : " << title << endl;
    cout << "Teacher  : " << teacherID << endl;
    cout << "Exam     : " << examWeightage << "%" << endl;
    cout << "Assignment: " << assignmentWeightage << "%" << endl;
    cout << "Quiz     : " << quizWeightage << "%" << endl;
    cout << "Duration : " << getExamDuration() << " hours" << endl;
    cout << "Students : " << studentCount << endl;
}

LabCourse::LabCourse(string id, string t, string tid)
    : Course(id, t, tid, "Lab") {
    loadWeightages("weightages.txt");
}

float LabCourse::calculateFinalGrade() const {
    float total = 0;
    for (int i = 0; i < assessmentCount; i++) {
        total += assessments[i]->calculateScore();
    }
    return total;
}

int LabCourse::getExamDuration() const { return 0; }

void LabCourse::displayInfo() const {
    cout << "\n--- Lab Course ---" << endl;
    cout << "ID       : " << courseID << endl;
    cout << "Title    : " << title << endl;
    cout << "Teacher  : " << teacherID << endl;
    cout << "Assignment: " << assignmentWeightage << "%" << endl;
    cout << "Quiz     : " << quizWeightage << "%" << endl;
    cout << "Duration : No final exam" << endl;
    cout << "Students : " << studentCount << endl;
}

float Course::getExamWeightage() const {
    return examWeightage; 
}
float Course::getAssignmentWeightage() const {
    return assignmentWeightage; 
}
float Course::getQuizWeightage() const { 
    return quizWeightage; 
}