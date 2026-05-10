#pragma once
#include <string>
using namespace std;

class Venue {
private:
    string roomID;
    int capacity;
    bool hasComputers;

public:
    Venue(string id, int cap, bool computers);
    string getRoomID() const;
    int getCapacity() const;
    bool getHasComputers() const;
    void displayVenueInfo() const;
    ~Venue() {}
};
