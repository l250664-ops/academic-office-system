
#include "../include/Assessment.h"
#include <iostream>

Assessment::Assessment(string t, float raw, float max, float w) : type(t), rawScore(raw), maxScore(max), weightage(w) {
}

string Assessment::getType() const {
    return type;
}
float Assessment::getRawScore() const {
    return rawScore;
}
float Assessment::getMaxScore() const {
    return maxScore;
}
float Assessment::getWeightage() const {
    return weightage;
}
void Assessment::setRawScore(float raw) {
    rawScore = raw;
}

Exam::Exam(float raw, float max, float w) : Assessment("Exam", raw, max, w) {
}

float Exam::calculateScore() const {
    return (rawScore / maxScore) * weightage;
}

void Exam::display() const {
    cout << "Exam | Score: " << rawScore << "/" << maxScore
        << " | Weightage: " << weightage << "%" << endl;
}

Quiz::Quiz(float raw, float max, float w)
    : Assessment("Quiz", raw, max, w) {
}

float Quiz::calculateScore() const {
    return (rawScore / maxScore) * weightage;
}

void Quiz::display() const {
    cout << "Quiz | Score: " << rawScore << "/" << maxScore
        << " | Weightage: " << weightage << "%" << endl;
}

Assignment::Assignment(float raw, float max, float w)
    : Assessment("Assignment", raw, max, w) {
}

float Assignment::calculateScore() const {
    return (rawScore / maxScore) * weightage;
}

void Assignment::display() const {
    cout << "Assignment | Score: " << rawScore << "/" << maxScore
        << " | Weightage: " << weightage << "%" << endl;
}