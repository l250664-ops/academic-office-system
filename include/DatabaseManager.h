#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Venue.h"
#include "Section.h"
#include <string>
#include <fstream>
using namespace std;

class DatabaseManager {
private:
    string studentsFile;
    string teachersFile;
    string coursesFile;
    string venuesFile;
    string sectionsFile;

public:
    DatabaseManager();

    void saveStudent(Student* s);
    void loadStudents(Student* students[], int& count);

    void saveTeacher(Teacher* t);
    void loadTeachers(Teacher* teachers[], int& count);

    void saveCourse(Course* c);
    void loadCourses(Course* courses[], int& count);

    void saveVenue(Venue* v);
    void loadVenues(Venue* venues[], int& count);

    void saveSection(Section* s);
    void loadSections(Section* sections[], int& count);
};
