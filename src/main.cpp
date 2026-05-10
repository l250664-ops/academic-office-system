#include "../include/AcademicEntity.h"
#include "../include/Student.h"
#include "../include/Teacher.h"
using namespace std;

int main() {
    // Test Regular Student
    RegularStudent s1("S001", "Fatima", "fatima@uni.edu", 3.5);
    s1.displayProfile();

    // Test Scholarship Student
    ScholarshipStudent s2("S002", "Ali", "ali@uni.edu", 2.0, 2.5);
    s2.displayProfile();
    cout << "Status: " << s2.getStatus() << endl;

    // Test Exchange Student
    ExchangeStudent s3("S003", "Sara", "sara@uni.edu", 75.0);
    s3.evaluate();
    s3.displayProfile();

    // Test Teacher
    Teacher t1("T001", "Dr. Ahmed", "ahmed@uni.edu");
    t1.addFeedback(4.5, "Great teacher!");
    t1.displayProfile();

    return 0;
}