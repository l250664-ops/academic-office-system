
#pragma once

#include "AcademicEntity.h"
#include <string>
using namespace std;

class Student : public AcademicEntity {
protected:
    string enrolledCourses[10];
    int courseCount;

public:
    Student(string id, string n, string e);

    void enrollCourse(string courseID);
    void listEnrolledCourses() const;
    int getCourseCount() const;
    string getEnrolledCourse(int index) const;

    virtual float calculateGPA() const = 0;
    virtual void viewTranscript() const = 0;
    virtual string getStudentType() const = 0;

    virtual ~Student() {}
};

class RegularStudent : public Student {
private:
    float gpa;

public:
    RegularStudent(string id, string n, string e, float g);

    float calculateGPA() const override;
    void viewTranscript() const override;
    void displayProfile() const override;
    string getStudentType() const override;

    void setGPA(float g);
};

class ScholarshipStudent : public Student {
private:
    float gpa;
    float minGPA;
    string status;

public:
    ScholarshipStudent(string id, string n, string e, float g, float minG);

    float calculateGPA() const override;
    void viewTranscript() const override;
    void displayProfile() const override;
    string getStudentType() const override;

    string getStatus() const;
    void setGPA(float g);
};

class ExchangeStudent : public Student {
private:
    float score;
    string result;

public:
    ExchangeStudent(string id, string n, string e, float s);

    float calculateGPA() const override;
    void evaluate();
    void viewTranscript() const override;
    void displayProfile() const override;
    string getStudentType() const override;

    string getResult() const;
    void setScore(float s);
};