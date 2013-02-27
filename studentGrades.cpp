#include <stdio.h>
#include <stdlib.h>

#include "studentGrades.h"

StudentGrades::StudentGrades(int studentID) {
    this->studentID = studentID;
    maxSize = 10;
    gradesCount = 0;
    grades = (int*) calloc(maxSize, sizeof(int));
}

StudentGrades::~StudentGrades() {

}

int StudentGrades::getID(){
    return studentID;
}

void StudentGrades::redefine(){
    
}

void StudentGrades::addGrade(int grade){
    if(gradesCount == maxSize) {
        redefine();
    }
    *grades = grade;
    grades++;
    gradesCount++;
}

void StudentGrades::printGrades(int minimunPassGrade) {
    if (gradesCount == 0) return;
    int* ptrGrades = grades - gradesCount;
    int average = 0;

    for (int i = 0; i < gradesCount; i++) {
        printf(" %d ", *ptrGrades);
        average += *ptrGrades;
        ptrGrades++;
    }

    average /= gradesCount;
    const char* state = average >= minimunPassGrade ? "Pass" : "Fail";
    printf(">> %d ", average);
    printf("= %s ", state);
}
