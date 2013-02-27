#include <stdlib.h>
#include <stdio.h>
#include "course.h"

Course::Course(short capacity, char minimunPassGrade) {
    this->capacity = capacity;
    this->minimunPassGrade = minimunPassGrade;
    this->registeredStudents = 0;
    students = (Student**) calloc(capacity, sizeof (Student*));
    grades = (StudentGrades**) calloc(capacity, sizeof (StudentGrades*));
}

Course::~Course() {
    for (int i = 0; i < registeredStudents; i++) {
        delete students[i];
    }

    free(students);
}

bool Course::isRegistered(int studentID) {
    int i = 0;
    bool registered = false;
    while (i < registeredStudents && !registered) {
        if (this->students[i]->getID() == studentID) {
            registered = true;
        }
        i++;
    }
    return registered;
}

bool Course::registerStudent(Student* student) {
    if (!student) return false;
    if (registeredStudents == capacity) return false;
    if (isRegistered(student->getID())) return false;

    students[registeredStudents] = student;
    grades[registeredStudents] = new StudentGrades(student->getID());
    registeredStudents++;
    return true;
}

void Course::addGrade(int id, int grade) {
    int i = 0;
    bool found = false;
    while (i < registeredStudents && !found) {
        if (this->grades[i]->getID() == id) {
            found = true;
            this->grades[i]->addGrade(grade);
        }
        i++;
    }
}

void Course::takeExam(int* ids, int idsCount, int* grades) {
    while (idsCount--) {
        addGrade(*ids, *grades);
        ids++;
        grades++;
    }
}

void Course::printStudentsList() {
    for (int i = 0; i < registeredStudents; i++) {
        printf("%d.- ", i + 1);
        this->students[i]->printStudentName();
        printf("\n");
    }
}

void Course::printStudentsGrades() {
    for (int i = 0; i < registeredStudents; i++) {
        printf("%d.- ", i + 1);
        this->students[i]->printStudentName();
        this->grades[i]->printGrades(minimunPassGrade);
        printf("\n");
    }
}

