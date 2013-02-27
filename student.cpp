#include "student.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Student::Student(int id, const char* name, const char* lastname, char gender) {
    this->id = id;
    this->name = (char*) malloc((strlen(name) + 1) * sizeof (char));
    strcpy(this->name, name);
    this->lastName = (char*) malloc((strlen(lastname) + 1) * sizeof (char));
    strcpy(this->lastName, lastname);
    this->gender = gender;
}

Student::~Student() {
    free(this->name);
    free(this->lastName);
}

int Student::getID(){
    return id;
}

void Student::printStudentName() {
    printf("%s %s", name, lastName);
}
