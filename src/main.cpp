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
    cout  << endl;
    cout << "  Academic Office System" << endl;
    cout  << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Teacher Management" << endl;
    cout << "3. Course Management" << endl;
    cout << "4. Scheduling" << endl;
    cout << "5. Grading" << endl;
    cout << "6. Exit" << endl;
    cout  << endl;
    cout << "Enter choice: ";
}

void studentMenu() {
    int choice;
    do {
        cout << "\nStudent Management:" << endl<<endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string id, name, email, type;
            float gpa;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Email: "; cin >> email;
            cout << "Enter Type (Regular/Scholarship/Exchange): "; cin >> type;

            if (type == "Regular") {
                cout << "Enter GPA: "; cin >> gpa;
                students[studentCount] = new RegularStudent(id, name, email, gpa);
            }
            else if (type == "Scholarship") {
                float minGPA;
                cout << "Enter GPA: "; cin >> gpa;
                cout << "Enter Minimum GPA: "; cin >> minGPA;
                students[studentCount] = new ScholarshipStudent(id, name, email, gpa, minGPA);
            }
            else if (type == "Exchange") {
                float score;
                cout << "Enter Score: "; cin >> score;
                students[studentCount] = new ExchangeStudent(id, name, email, score);
            }
            else {
                cout << "Invalid type!" << endl;
                continue;
            }
            db.saveStudent(students[studentCount]);
            studentCount++;
            cout << "Student added successfully!" << endl;

        }
        else if (choice == 2) {
            if (studentCount == 0) {
                cout << "No students found." << endl;
            }
            else {
                for (int i = 0; i < studentCount; i++) {
                    students[i]->displayProfile();
                }
            }
        }
        else if (choice == 3) {
            string id;
            cout << "Enter Student ID: "; cin >> id;
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->getID() == id) {
                    students[i]->displayProfile();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found." << endl;
        }
    } while (choice != 4);
}

void teacherMenu() {
    int choice;
    do {
        cout << "\nTeacher Management:" <<endl<< endl;
        cout << "1. Add Teacher" << endl;
        cout << "2. View All Teachers" << endl;
        cout << "3. Add Feedback for Teacher" << endl;
        cout << "4. View Teacher Feedback" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string id, name, email;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Email: "; cin >> email;
            teachers[teacherCount] = new Teacher(id, name, email);
            db.saveTeacher(teachers[teacherCount]);
            teacherCount++;
            cout << "Teacher added successfully!" << endl;

        }
        else if (choice == 2) {
            if (teacherCount == 0) {
                cout << "No teachers found." << endl;
            }
            else {
                for (int i = 0; i < teacherCount; i++) {
                    teachers[i]->displayProfile();
                }
            }
        }
        else if (choice == 3) {
            string id;
            cout << "Enter Teacher ID: "; cin >> id;
            bool found = false;
            for (int i = 0; i < teacherCount; i++) {
                if (teachers[i]->getID() == id) {
                    float rating;
                    string comment;
                    cout << "Enter Rating (1-5): "; cin >> rating;
                    cin.ignore();
                    cout << "Enter Comment: "; getline(cin, comment);
                    teachers[i]->addFeedback(rating, comment);
                    cout << "Feedback added!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Teacher not found." << endl;

        }
        else if (choice == 4) {
            string id;
            cout << "Enter Teacher ID: "; cin >> id;
            bool found = false;
            for (int i = 0; i < teacherCount; i++) {
                if (teachers[i]->getID() == id) {
                    teachers[i]->displayFeedback();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Teacher not found." << endl;
        }
    } while (choice != 5);
}

void courseMenu() {
    int choice;
    do {
        cout << "\nCourse Management:" <<endl<< endl;
        cout << "1. Add Course" << endl;
        cout << "2. View All Courses" << endl;
        cout << "3. Enroll Student in Course" << endl;
        cout << "4. View Enrolled Students" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string id, title, tid, type;
            cout << "Enter Course ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            cout << "Enter Teacher ID: "; cin >> tid;
            cout << "Enter Type (Core/Elective/Lab): "; cin >> type;

            if (type == "Core")
                courses[courseCount] = new CoreCourse(id, title, tid);
            else if (type == "Elective")
                courses[courseCount] = new ElectiveCourse(id, title, tid);
            else if (type == "Lab")
                courses[courseCount] = new LabCourse(id, title, tid);
            else {
                cout << "Invalid type!" << endl;
                continue;
            }
            db.saveCourse(courses[courseCount]);
            courseCount++;
            cout << "Course added successfully!" << endl;

        }
        else if (choice == 2) {
            if (courseCount == 0) {
                cout << "No courses found." << endl;
            }
            else {
                for (int i = 0; i < courseCount; i++) {
                    courses[i]->displayInfo();
                }
            }
        }
        else if (choice == 3) {
            string sid, cid;
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Course ID: "; cin >> cid;
            bool found = false;
            for (int i = 0; i < courseCount; i++) {
                if (courses[i]->getCourseID() == cid) {
                    if (courses[i]->isFull()) {
                        cout << "Course is full!" << endl;
                    }
                    else if (courses[i]->isStudentEnrolled(sid)) {
                        cout << "Student already enrolled!" << endl;
                    }
                    else {
                        courses[i]->enrollStudent(sid);
                        // Also enroll in student object
                        for (int j = 0; j < studentCount; j++) {
                            if (students[j]->getID() == sid) {
                                students[j]->enrollCourse(cid);
                                break;
                            }
                        }
                        cout << "Student enrolled successfully!" << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Course not found." << endl;

        }
        else if (choice == 4) {
            string cid;
            cout << "Enter Course ID: "; cin >> cid;
            bool found = false;
            for (int i = 0; i < courseCount; i++) {
                if (courses[i]->getCourseID() == cid) {
                    cout << "Enrolled Students in " << courses[i]->getTitle() << ":" << endl;
                    if (courses[i]->getStudentCount() == 0) {
                        cout << "No students enrolled." << endl;
                    }
                    else {
                        for (int j = 0; j < courses[i]->getStudentCount(); j++) {
                            cout << "  " << j + 1 << ". " << courses[i]->getEnrolledStudentID(j) << endl;
                        }
                    }
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Course not found." << endl;
        }
    } while (choice != 5);
}

void schedulerMenu() {
    int choice;
    do {
        cout << "\nScheduling:" <<endl<< endl;
        cout << "1. Add Venue" << endl;
        cout << "2. Add Section" << endl;
        cout << "3. Auto Assign Venues" << endl;
        cout << "4. View Schedule" << endl;
        cout << "5. Save Schedule to File" << endl;
        cout << "6. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string id;
            int cap;
            int comp;
            cout << "Enter Room ID: "; cin >> id;
            cout << "Enter Capacity: "; cin >> cap;
            cout << "Has Computers? (1=Yes 0=No): "; cin >> comp;
            venues[venueCount] = new Venue(id, cap, comp);
            db.saveVenue(venues[venueCount]);
            venueCount++;
            cout << "Venue added successfully!" << endl;

        }
        else if (choice == 2) {
            string sid, cid, tid, vid, slot;
            cout << "Enter Section ID: "; cin >> sid;
            cout << "Enter Course ID: "; cin >> cid;
            cout << "Enter Teacher ID: "; cin >> tid;
            cout << "Enter Venue ID: "; cin >> vid;
            cout << "Enter Time Slot: "; cin.ignore(); getline(cin, slot);
            sections[sectionCount] = new Section(sid, cid, tid, vid, slot);
            db.saveSection(sections[sectionCount]);
            sectionCount++;
            cout << "Section added successfully!" << endl;

        }
        else if (choice == 3) {
            Scheduler scheduler;
            for (int i = 0; i < sectionCount; i++)
                scheduler.addSection(sections[i]);
            for (int i = 0; i < venueCount; i++)
                scheduler.addVenue(venues[i]);
            scheduler.assignVenues();
            cout << "Venues assigned successfully!" << endl;

        }
        else if (choice == 4) {
            Scheduler scheduler;
            for (int i = 0; i < sectionCount; i++)
                scheduler.addSection(sections[i]);
            scheduler.displaySchedule();

        }
        else if (choice == 5) {
            Scheduler scheduler;
            for (int i = 0; i < sectionCount; i++)
                scheduler.addSection(sections[i]);
            scheduler.saveSchedule("schedule.txt");
        }
    } while (choice != 6);
}

void gradingMenu() {
    int choice;
    do {
        cout << "\nGrading:" << endl;
        cout << "1. Add Assessment to Course" << endl;
        cout << "2. Calculate Final Grade for Student" << endl;
        cout << "3. View Student Transcript" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string cid, sid, type;
            float raw, max, weightage;
            cout << "Enter Course ID: "; cin >> cid;
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Assessment Type (Exam/Quiz/Assignment): "; cin >> type;
            cout << "Enter Raw Score: "; cin >> raw;
            cout << "Enter Max Score: "; cin >> max;
            cout << "Enter Weightage: "; cin >> weightage;

            bool courseFound = false;
            for (int i = 0; i < courseCount; i++) {
                if (courses[i]->getCourseID() == cid) {
                    Assessment* a = nullptr;
                    if (type == "Exam")
                        a = new Exam(raw, max, weightage);
                    else if (type == "Quiz")
                        a = new Quiz(raw, max, weightage);
                    else if (type == "Assignment")
                        a = new Assignment(raw, max, weightage);
                    else {
                        cout << "Invalid type!" << endl;
                        break;
                    }
                    courses[i]->addAssessment(a);
                    db.saveAssessment(cid, type, raw, max);
                    float grade = courses[i]->calculateFinalGrade();
                    for (int j = 0; j < studentCount; j++) {
                        if (students[j]->getID() == sid) {
                            students[j]->addGrade(cid, grade);

                            // Auto calculate and update GPA
                            float totalGrade = 0;
                            for (int k = 0; k < students[j]->getGradeCount(); k++) {
                                totalGrade += students[j]->getGradeScore(k);
                            }
                            float newGPA = (totalGrade / students[j]->getGradeCount()) / 25.0;

                            // Update GPA based on student type
                            RegularStudent* rs = dynamic_cast<RegularStudent*>(students[j]);
                            if (rs) rs->setGPA(newGPA);

                            ScholarshipStudent* ss = dynamic_cast<ScholarshipStudent*>(students[j]);
                            if (ss) ss->setGPA(newGPA);

                            cout << "\n*** BIG RED BUTTON ***" << endl;
                            cout << "Assessment added! Auto-calculated grade: " << grade << "%" << endl;
                            cout << "GPA automatically updated to: " << newGPA << endl;
                            break;
                        }
                    }
                    courseFound = true;
                    break;
                }
            }
            if (!courseFound) cout << "Course not found." << endl;

        }
        else if (choice == 2) {
            string sid, cid;
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Course ID: "; cin >> cid;
            for (int i = 0; i < courseCount; i++) {
                if (courses[i]->getCourseID() == cid) {
                    float grade = courses[i]->calculateFinalGrade();
                    
                    for (int j = 0; j < studentCount; j++) {
                        if (students[j]->getID() == sid) {
                            students[j]->addGrade(cid, grade);
                            cout << "Final Grade for " << students[j]->getName()
                                << " in " << courses[i]->getTitle()
                                << ": " << grade << "%" << endl;
                            break;
                        }
                    }
                    break;
                }
            }

        }
        else if (choice == 3) {
            string sid;
            cout << "Enter Student ID: "; cin >> sid;
            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i]->getID() == sid) {
                    students[i]->viewTranscript();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found." << endl;
        }
    } while (choice != 4);
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
        case 1: studentMenu(); 
            break;
        case 2: teacherMenu();
            break;
        case 3: courseMenu(); 
            break;
        case 4: schedulerMenu(); 
            break;
        case 5: gradingMenu(); 
            break;
        case 6: cout << "Goodbye!" << endl; break;
        default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}