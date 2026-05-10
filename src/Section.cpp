#include "../include/Section.h"
#include <iostream>
using namespace std;

Section::Section(string sid, string cid, string tid, string vid, string slot): sectionID(sid), courseID(cid), teacherID(tid), venueID(vid), timeSlot(slot) {
}

string Section::getSectionID() const {
    return sectionID;
}

string Section::getCourseID() const {
    return courseID;
}

string Section::getTeacherID() const {
    return teacherID;
}

string Section::getVenueID() const {
    return venueID;
}

string Section::getTimeSlot() const {
    return timeSlot;
}

void Section::setVenueID(string vid) {
    venueID = vid;
}

void Section::setTimeSlot(string slot) {
    timeSlot = slot;
}

void Section::displayInfo() const {
    cout << "--- Section Information ---" << endl;
    cout << "Section ID : " << sectionID << endl;
    cout << "Course ID  : " << courseID << endl;
    cout << "Teacher ID : " << teacherID << endl;
    cout << "Venue ID   : " << venueID << endl;
    cout << "Time Slot  : " << timeSlot << endl;
}