#include "../include/Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(string id, string n, string e) : AcademicEntity(id, n, e), courseCount(0), feedbackCount(0), averageFeedback(0.0) {
}

void Teacher::assignCourse(string courseID) {
    if (courseCount < 10) {
        assignedCourses[courseCount] = courseID;
        courseCount++;
    }
    else {
        cout << "Cannot assign more than 10 courses." << endl;
    }
}

void Teacher::listAssignedCourses() const {
    if (courseCount == 0) {
        cout << "No courses assigned." << endl;
        return;
    }
    for (int i = 0; i < courseCount; i++) {
        cout << "  " << i + 1 << ". " << assignedCourses[i] << endl;
    }
}

void Teacher::addFeedback(float rating, string comment) {
    if (rating < 1 || rating > 5) {
        cout << "Invalid rating. Must be between 1 and 5." << endl;
        return;
    }
    if (feedbackCount < 100) {
        ratings[feedbackCount] = rating;
        comments[feedbackCount] = comment;
        feedbackCount++;
        averageFeedback = calculateAverageFeedback();
        cout << "Feedback submitted successfully." << endl;
    }
    else {
        cout << "Feedback limit reached." << endl;
    }
}

float Teacher::calculateAverageFeedback() const {
    if (feedbackCount == 0) return 0.0;
    float total = 0;
    for (int i = 0; i < feedbackCount; i++) {
        total += ratings[i];
    }
    return total / feedbackCount;
}

float Teacher::getAverageFeedback() const { return averageFeedback; }

void Teacher::displayFeedback() const {
    cout << "\n--- Feedback for " << name << " ---" << endl;
    if (feedbackCount == 0) {
        cout << "No feedback yet." << endl;
        return;
    }
    for (int i = 0; i < feedbackCount; i++) {
        cout << "  Rating  : " << ratings[i] << "/5" << endl;
        cout << "  Comment : " << comments[i] << endl;
        cout << endl;
    }
    cout << "Average Score: " << averageFeedback << "/5" << endl;
}

int Teacher::getCourseCount() const {
    return courseCount;
}

string Teacher::getAssignedCourse(int index) const {
    return assignedCourses[index];
}

void Teacher::displayProfile() const {
    cout << "\n--- Teacher Profile ---" << endl;
    cout << "ID              : " << ID << endl;
    cout << "Name            : " << name << endl;
    cout << "Email           : " << email << endl;
    cout << "Avg Feedback    : " << averageFeedback << "/5" << endl;
    cout << "Courses Assigned: " << endl;
    listAssignedCourses();
}