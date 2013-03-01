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
    Course* c = new Course(5, 51);
    Student* a = new Student(1, "Juan", "Perez", 'm');
    c->registerStudent(a);
    Student* b = new Student(2, "Lilo", "Loa", 'm');
    c->registerStudent(b);
    Student* d = new Student(3, "Alan", "Benitez", 'm');
    c->registerStudent(d);
    Student* e = new Student(4, "Jhon", "Vega", 'm');
    c->registerStudent(e);
    
    c->printStudentsList();
    
    int ids[4] = {1, 2, 3, 4};
    int grades[4] = {60, 45, 89, 19};
    c->takeExam(ids, 4, grades);
    
    int ids2[4] = {1, 2, 3, 4};
    int grades2[4] = {80, 20, 78, 6};
    c->takeExam(ids2, 4, grades2);
    
    int ids3[4] = {1, 2, 3, 4};
    int grades3[4] = {67, 30, 10, 9};
    c->takeExam(ids3, 4, grades3);
    
    c->printStudentsGrades();
    return 0;
}

