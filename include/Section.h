#pragma once
#include <string>
using namespace std;

class Section {
private:
    string sectionID;
    string courseID;
    string teacherID;
    string venueID;
    string timeSlot;

public:
    Section(string sid, string cid, string tid, string vid, string slot);
    string getSectionID() const;
    string getCourseID() const;
    string getTeacherID() const;
    string getVenueID() const;
    string getTimeSlot() const;
    void setVenueID(string vid);
    void setTimeSlot(string slot);
    void displayInfo() const;
    ~Section() {}
};
