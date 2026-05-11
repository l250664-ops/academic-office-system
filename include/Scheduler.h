#pragma once
#include "Section.h"
#include "Venue.h"
#include <string>
using namespace std;

class Scheduler {
private:
    Section* sections[50];
    Venue* venues[20];
    int sectionCount;
    int venueCount;
    string timeSlots[10];
    int timeSlotCount;

public:
    Scheduler();
    void addSection(Section* s);
    void addVenue(Venue* v);
    void assignVenues();
    bool hasConflict(string venueID, string timeSlot, int upToIndex);
    string getNextAvailableSlot(string venueID, int fromIndex);
    void displaySchedule() const;
    void saveSchedule(string filename) const;
};
