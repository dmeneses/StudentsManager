/* 
 * File:   student.h
 * Author: Daniela
 *
 * Created on February 26, 2013, 3:47 PM
 */

#ifndef STUDENT_H
#define	STUDENT_H

struct Student {
    Student(int id, const char* name, const char* lastname, char gender);
    ~Student();
    int getID();
    void printStudentName();
private:
    int id;
    char* name;
    char* lastName;
    char gender;
};

#endif	/* STUDENT_H */

