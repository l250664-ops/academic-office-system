#include "../include/AcademicEntity.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Course.h"
#include "../include/Assessment.h"
#include "../include/Venue.h"
#include "../include/Section.h"
#include "../include/DatabaseManager.h"
#include "../include/Scheduler.h"
#include <iostream>
using namespace std;

Student* students[50];
Teacher* teachers[20];
Course* courses[20];
Venue* venues[20];
Section* sections[50];
int studentCount = 0, teacherCount = 0, courseCount = 0;
int venueCount = 0, sectionCount = 0;

DatabaseManager db;

void showMainMenu() {
    cout << "\n============================" << endl;
    cout << "  Academic Office System" << endl;
    cout << "============================" << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Teacher Management" << endl;
    cout << "3. Course Management" << endl;
    cout << "4. Scheduling" << endl;
    cout << "5. Grading" << endl;
    cout << "6. Exit" << endl;
    cout << "============================" << endl;
    cout << "Enter choice: ";
}

int main() {
   
    db.loadStudents(students, studentCount);
    db.loadTeachers(teachers, teacherCount);
    db.loadCourses(courses, courseCount);
    db.loadVenues(venues, venueCount);
    db.loadSections(sections, sectionCount);

    cout << "Data loaded successfully." << endl;

    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: cout << "Student Management - Coming soon" << endl; break;
        case 2: cout << "Teacher Management - Coming soon" << endl; break;
        case 3: cout << "Course Management - Coming soon" << endl; break;
        case 4: cout << "Scheduling - Coming soon" << endl; break;
        case 5: cout << "Grading - Coming soon" << endl; break;
        case 6: cout << "Goodbye!" << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}