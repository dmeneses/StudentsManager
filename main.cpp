/* 
 * File:   main.cpp
 * Author: Daniela
 *
 * Created on February 26, 2013, 3:42 PM
 */

#include <cstdlib>
#include <string>

#include "student.h"
#include "course.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Student* a = new Student(1, "Juan", "Perez", 'm');
    Course* c = new Course(5, 51);

    c->registerStudent(a);
    Student* b = new Student(2, "Lilo", "Loa", 'm');
    c->registerStudent(b);
    Student* d = new Student(3, "Alan", "Benitez", 'm');
    c->registerStudent(d);
    c->printStudentsList();
    int ids[3] = {1, 2, 3};
    int grades[3] = {60, 45, 89};

    c->takeExam(ids, 3, grades);
    int ids2[3] = {1, 2, 3};
    int grades2[3] = {80, 20, 78};

    c->takeExam(ids2, 3, grades2);
    c->printStudentsGrades();
    return 0;
}

