#pragma once
#include <string>
using namespace std;

class Assessment {
protected:
    string type;
    float rawScore;
    float maxScore;
    float weightage;

public:
    Assessment(string t, float raw, float max, float w);

    string getType() const;
    float getRawScore() const;
    float getMaxScore() const;
    float getWeightage() const;

    void setRawScore(float raw);

    virtual float calculateScore() const = 0;
    virtual void display() const = 0;

    virtual ~Assessment() {}
};

class Exam : public Assessment {
public:
    Exam(float raw, float max, float w);
    float calculateScore() const override;
    void display() const override;
};

class Quiz : public Assessment {
public:
    Quiz(float raw, float max, float w);
    float calculateScore() const override;
    void display() const override;
};

class Assignment : public Assessment {
public:
    Assignment(float raw, float max, float w);
    float calculateScore() const override;
    void display() const override;
};