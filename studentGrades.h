/* 
 * File:   grade.h
 * Author: Daniela
 *
 * Created on February 26, 2013, 6:08 PM
 */

#ifndef GRADE_H
#define	GRADE_H

struct StudentGrades {
    StudentGrades(int studentID);
    ~StudentGrades();
    int getID();
    void addGrade(int grade);
    void printGrades(int minimunPassGrade);
private:
    int studentID;
    int* grades;
    int gradesCount;
    int maxSize;
    void redefine();
};

#endif	/* GRADE_H */

