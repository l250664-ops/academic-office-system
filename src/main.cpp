#include "../include/AcademicEntity.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
#include "../include/Assessment.h"
#include "../include/Course.h"
#include "../include/Venue.h"
#include "../include/Section.h"
#include <iostream>
using namespace std;

int main() {
    // Test Students
    RegularStudent s1("S001", "Fatima", "fatima@uni.edu", 3.5);
    s1.displayProfile();

    ScholarshipStudent s2("S002", "Ali", "ali@uni.edu", 2.0, 2.5);
    s2.displayProfile();

    ExchangeStudent s3("S003", "Sara", "sara@uni.edu", 75.0);
    s3.evaluate();
    s3.displayProfile();

    // Test Teacher
    Teacher t1("T001", "Dr. Ahmed", "ahmed@uni.edu");
    t1.addFeedback(4.5, "Great teacher!");
    t1.displayProfile();

    // Test Course
    CoreCourse c1("CS101", "Programming", "T001");
    c1.displayInfo();

    // Test Venue
    Venue v1("R101", 50, true);
    v1.displayVenueInfo();

    // Test Section
    Section sec1("SEC001", "CS101", "T001", "R101", "Monday 9AM");
    sec1.displayInfo();

    return 0;
}