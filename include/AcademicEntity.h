#pragma once
#include 
using namespace std;

class AcademicEntity {
protected:
    string ID;
    string name;
    string email;
public:
    AcademicEntity(string id, string n, string e);
    string getID() const;
    string getName() const;
    string getEmail() const;
    void setName(string n);
    void setEmail(string e);
    virtual void displayProfile() const = 0;
    virtual ~AcademicEntity() {}
};