
#include "../include/Student.h"
#include <iostream>
using namespace std;

Student::Student(string id, string n, string e)
    : AcademicEntity(id, n, e), courseCount(0) {
}

void Student::enrollCourse(string courseID) {
    if (courseCount < 10) {
        enrolledCourses[courseCount] = courseID;
        courseCount++;
    }
    else {
        cout << "Cannot enroll in more than 10 courses." << endl;
    }
}

void Student::listEnrolledCourses() const {
    if (courseCount == 0) {
        cout << "No courses enrolled." << endl;
        return;
    }
    for (int i = 0; i < courseCount; i++) {
        cout << "  " << i + 1 << ". " << enrolledCourses[i] << endl;
    }
}

int Student::getCourseCount() const {
    return courseCount;
}

string Student::getEnrolledCourse(int index) const {
    return enrolledCourses[index];
}

RegularStudent::RegularStudent(string id, string n, string e, float g) : Student(id, n, e), gpa(g) {
}

float RegularStudent::calculateGPA() const {
    return gpa;
}

void RegularStudent::setGPA(float g) {
    gpa = g;
}

void RegularStudent::viewTranscript() const {
    cout << "\n--- Transcript: " << name << " ---" << endl;
    cout << "Type   : Regular Student" << endl;
    cout << "GPA    : " << gpa << endl;
    cout << "Courses: " << endl;
    listEnrolledCourses();
}

void RegularStudent::displayProfile() const {
    cout << "\n--- Profile ---" << endl;
    cout << "ID    : " << ID << endl;
    cout << "Name  : " << name << endl;
    cout << "Email : " << email << endl;
    cout << "Type  : Regular Student" << endl;
    cout << "GPA   : " << gpa << endl;
}

string RegularStudent::getStudentType() const {
    return "Regular";
}

ScholarshipStudent::ScholarshipStudent(string id, string n, string e, float g, float minG) : Student(id, n, e), gpa(g), minGPA(minG), status("Good Standing") {
}

float ScholarshipStudent::calculateGPA() const {
    return gpa;
}

void ScholarshipStudent::setGPA(float g) {
    gpa = g;
    if (gpa < minGPA)
        status = "Probation";
    else
        status = "Good Standing";
}

string ScholarshipStudent::getStatus() const {
    return status;

}

void ScholarshipStudent::viewTranscript() const {
    cout << "\n--- Transcript: " << name << " ---" << endl;
    cout << "Type   : Scholarship Student" << endl;
    cout << "GPA    : " << gpa << endl;
    cout << "Status : " << status << endl;
    cout << "Courses: " << endl;
    listEnrolledCourses();
}

void ScholarshipStudent::displayProfile() const {
    cout << "\n--- Profile ---" << endl;
    cout << "ID     : " << ID << endl;
    cout << "Name   : " << name << endl;
    cout << "Email  : " << email << endl;
    cout << "Type   : Scholarship Student" << endl;
    cout << "GPA    : " << gpa << endl;
    cout << "Status : " << status << endl;
}

string ScholarshipStudent::getStudentType() const {
    return "Scholarship";
}

ExchangeStudent::ExchangeStudent(string id, string n, string e, float s) : Student(id, n, e), score(s), result("Not Evaluated") {
}

float ExchangeStudent::calculateGPA() const {
    return 0;
}

void ExchangeStudent::setScore(float s) {
    score = s;
}

void ExchangeStudent::evaluate() {
    if (score >= 50)
        result = "Pass";
    else
        result = "Fail";
}

string ExchangeStudent::getResult() const {
    return result;
}

void ExchangeStudent::viewTranscript() const {
    cout << "\n--- Transcript: " << name << " ---" << endl;
    cout << "Type   : Exchange Student" << endl;
    cout << "Score  : " << score << endl;
    cout << "Result : " << result << endl;
    cout << "Courses: " << endl;
    listEnrolledCourses();
}

void ExchangeStudent::displayProfile() const {
    cout << "\n--- Profile ---" << endl;
    cout << "ID     : " << ID << endl;
    cout << "Name   : " << name << endl;
    cout << "Email  : " << email << endl;
    cout << "Type   : Exchange Student" << endl;
    cout << "Score  : " << score << endl;
    cout << "Result : " << result << endl;
}

string ExchangeStudent::getStudentType() const {
    return "Exchange";
}
