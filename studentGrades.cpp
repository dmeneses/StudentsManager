#include <stdio.h>
#include <stdlib.h>

#include "studentGrades.h"

StudentGrades::StudentGrades(int studentID) {
    this->studentID = studentID;
    maxSize = 2;
    gradesCount = 0;
    grades = (int*) calloc(maxSize, sizeof (int));
}

StudentGrades::~StudentGrades() {
    free(grades);
}

int StudentGrades::getID() {
    return studentID;
}

void StudentGrades::redefine() {
    maxSize = maxSize + 2;
    int* tempGrades = (int*) calloc(maxSize, sizeof (int));
    int* ptrGrades = grades - gradesCount;
    printf("Grades count: %d\n", gradesCount);
    
    for (int i = 0; i < gradesCount; i++) {
        *tempGrades = *ptrGrades;
        tempGrades++;
        ptrGrades++;
    }
    grades = grades - gradesCount;
    free(grades);
    grades = tempGrades;
}

void StudentGrades::addGrade(int grade) {
    if (gradesCount == maxSize) {
        redefine();
    }
    *grades = grade;
    grades++;
    gradesCount++;
}

void StudentGrades::printGrades(int minimunPassGrade) {
    if (gradesCount == 0) return;
    int* ptrGrades = grades - gradesCount;
    float average = 0;

    for (int i = 0; i < gradesCount; i++) {
        printf(" %d ", *ptrGrades);
        average += *ptrGrades;
        ptrGrades++;
    }

    average /= gradesCount;
    const char* state = average >= minimunPassGrade ? "Pass" : "Fail";
    printf(">> %f - %s ", average, state);
}
