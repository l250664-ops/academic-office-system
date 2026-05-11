#include "../include/Scheduler.h"
#include <iostream>
#include <fstream>
using namespace std;

Scheduler::Scheduler() : sectionCount(0), venueCount(0), timeSlotCount(6) {
    timeSlots[0] = "Monday 8AM";
    timeSlots[1] = "Monday 11AM";
    timeSlots[2] = "Tuesday 8AM";
    timeSlots[3] = "Tuesday 11AM";
    timeSlots[4] = "Wednesday 8AM";
    timeSlots[5] = "Wednesday 11AM";
}

void Scheduler::addSection(Section* s) {
    if (sectionCount < 50) {
        sections[sectionCount++] = s;
    }
}

void Scheduler::addVenue(Venue* v) {
    if (venueCount < 20) {
        venues[venueCount++] = v;
    }
}

bool Scheduler::hasConflict(string venueID, string timeSlot, int upToIndex) {
    for (int i = 0; i < upToIndex; i++) {
        if (sections[i]->getVenueID() == venueID &&
            sections[i]->getTimeSlot() == timeSlot) {
            return true;
        }
    }
    return false;
}

string Scheduler::getNextAvailableSlot(string venueID, int fromIndex) {
    for (int i = 0; i < timeSlotCount; i++) {
        if (!hasConflict(venueID, timeSlots[i], fromIndex)) {
            return timeSlots[i];
        }
    }
    return "No slot available";
}

void Scheduler::assignVenues() {
    for (int i = 0; i < sectionCount; i++) {
        // Find first available venue
        for (int j = 0; j < venueCount; j++) {
            string slot = getNextAvailableSlot(venues[j]->getRoomID(), i);
            if (slot != "No slot available") {
                sections[i]->setVenueID(venues[j]->getRoomID());
                sections[i]->setTimeSlot(slot);
                cout << "Assigned: Section " << sections[i]->getSectionID()
                    << " -> Venue " << venues[j]->getRoomID()
                    << " at " << slot << endl;
                break;
            }
        }
    }
}

void Scheduler::displaySchedule() const {
    cout << "\n--- Exam Schedule ---" << endl;
    for (int i = 0; i < sectionCount; i++) {
        cout << "Section : " << sections[i]->getSectionID() << endl;
        cout << "Venue   : " << sections[i]->getVenueID() << endl;
        cout << "Time    : " << sections[i]->getTimeSlot() << endl;
        cout << endl;
    }
}

void Scheduler::saveSchedule(string filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Error saving schedule." << endl;
        return;
    }
    for (int i = 0; i < sectionCount; i++) {
        file << sections[i]->getSectionID() << " | "
            << sections[i]->getVenueID() << " | "
            << sections[i]->getTimeSlot() << endl;
    }
    file.close();
    cout << "Schedule saved to " << filename << endl;
}