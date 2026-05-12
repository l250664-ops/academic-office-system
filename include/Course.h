#pragma once

#include "Assessment.h"
#include <string>
using namespace std;

class Course {
protected:
    string courseID;
    string title;
    string teacherID;
    string courseType;
    float finalGrade;

    string enrolledStudentIDs[50];
    int studentCount;

    Assessment* assessments[10];
    int assessmentCount;

    float examWeightage;
    float assignmentWeightage;
    float quizWeightage;

public:
    Course(string id, string t, string tid, string type);

    string getCourseID() const;
    string getTitle() const;
    string getTeacherID() const;
    string getCourseType() const;
    int getStudentCount() const;
    string getEnrolledStudentID(int index) const;

    void enrollStudent(string studentID);
    bool isStudentEnrolled(string studentID) const;
    bool isFull() const;

    void addAssessment(Assessment* a);
    void loadWeightages(string filename);

    virtual float calculateFinalGrade() const = 0;
    virtual int getExamDuration() const = 0;
    virtual void displayInfo() const = 0;

    float getExamWeightage() const;
    float getAssignmentWeightage() const;
    float getQuizWeightage() const;

    virtual ~Course();
};

class CoreCourse : public Course {
public:
    CoreCourse(string id, string t, string tid);
    float calculateFinalGrade() const override;
    int getExamDuration() const override;
    void displayInfo() const override;
};

class ElectiveCourse : public Course {
public:
    ElectiveCourse(string id, string t, string tid);
    float calculateFinalGrade() const override;
    int getExamDuration() const override;
    void displayInfo() const override;
};

class LabCourse : public Course {
public:
    LabCourse(string id, string t, string tid);
    float calculateFinalGrade() const override;
    int getExamDuration() const override;
    void displayInfo() const override;
};
