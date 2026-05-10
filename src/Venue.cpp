#include "../include/Venue.h"
#include <iostream>
using namespace std;

Venue::Venue(string id, int cap, bool computers) : roomID(id), capacity(cap), hasComputers(computers) {
}

string Venue::getRoomID() const {
    return roomID;
}

int Venue::getCapacity() const {
    return capacity;
}

bool Venue::getHasComputers() const {
    return hasComputers;
}

void Venue::displayVenueInfo() const {
    cout << "Room ID: " << roomID << " | Capacity: " << capacity;
    if (hasComputers)
        cout << " | Has Computers: Yes" << endl;
    else
        cout << " | Has Computers: No" << endl;
}