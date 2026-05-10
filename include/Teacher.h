#pragma once

#include "AcademicEntity.h"
#include <string>
using namespace std;

class Teacher : public AcademicEntity {
private:
    string assignedCourses[10];
    int courseCount;

    float ratings[100];
    string comments[100];
    int feedbackCount;

    float averageFeedback;

public:
    Teacher(string id, string n, string e);

    void assignCourse(string courseID);
    void listAssignedCourses() const;

    void addFeedback(float rating, string comment);
    float calculateAverageFeedback() const;
    float getAverageFeedback() const;
    void displayFeedback() const;

    int getCourseCount() const;
    string getAssignedCourse(int index) const;

    void displayProfile() const override;

    ~Teacher() {}
};