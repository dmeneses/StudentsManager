/* 
 * File:   course.h
 * Author: Daniela
 *
 * Created on February 26, 2013, 4:03 PM
 */

#include "student.h"
#include "studentGrades.h"
#ifndef COURSE_H
#define	COURSE_H

struct Course {
    Course(short capacity, char minimunPassGrade);

    ~Course();

    bool registerStudent(Student * student);

    void takeExam(int* ids, int idsCount, int* grades);

    void printStudentsList();

    void printStudentsGrades();

    bool isRegistered(int id);

private:
    void addGrade(int id, int grade);
    unsigned short capacity;
    unsigned short registeredStudents;
    Student** students;
    StudentGrades** grades;
    unsigned char minimunPassGrade;
};


#endif	/* COURSE_H */

