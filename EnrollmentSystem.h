#pragma once

#ifndef ENROLLMENTSYSTEM_H
#define ENROLLMENTSYSTEM_H

class University;
class College;
class Course;
class CourseUnit;
class CourseUnitClass;
class Student;
class Tutor;
class Date;

#include <vector>
#include <string>
using namespace std;


class EnrollmentSystem
{
private:
	//MEMBER VARIABLES
	const unsigned int MAXIMUM_CREDITS;
	vector<University*> universitiesVector;

	//SORTING OPTIONS (POINTERS TO THE SORTING FUNCTIONS)
	bool(*universitySortOption)(University* l, University* r);
	bool(*collegeSortOption)(College* l, College* r);
	bool(*courseSortOption)(Course* l, Course* r);
	bool(*courseUnitSortOption)(CourseUnit* l, CourseUnit* r);
	bool(*courseUnitClassSortOption)(CourseUnitClass* l, CourseUnitClass* r);
	bool(*studentsSortOption)(Student* l, Student* r);
	bool(*professorsSortOption)(Tutor* l, Tutor* r);

		
public:
	//MEMBER FUNCTIONS
	EnrollmentSystem(unsigned int mc);
	void addUniversity(University* u) { universitiesVector.push_back(u); }
	void removeUniversity(University* u);

	//HANDLERS (COMMUNICATION WITH THE USER)
	friend bool addStudentHandler(EnrollmentSystem& s); //ADDS STUDENT TO COURSE
	friend bool removeStudentHandler(EnrollmentSystem& s); //REMOVES STUDENT FROM COURSE
	friend bool addProfessorHandler(EnrollmentSystem& s); //ADDS PROFESSOR TO COURSE UNIT (AND TO COURSE, IF NOT YET THERE)
	friend bool removeProfessorHandler(EnrollmentSystem& s); //REMOVES PROFESSOR FROM COURSE UNIT (AND FROM COURSE)
	friend bool addStudentToCourseUnitHandler(EnrollmentSystem& s); //ADDS STUDENT TO A COURSE UNIT
	friend bool removeStudentFromCourseUnitHandler(EnrollmentSystem& s); //REMOVES STUDENT FROM COURSE UNIT
	friend bool studentFinishedCourseUnitHandler(EnrollmentSystem& s);
	friend bool addUniversityHandler(EnrollmentSystem& s);
	friend bool removeUniversityHandler(EnrollmentSystem& s);
	friend bool addCollegeHandler(EnrollmentSystem& s);
	friend bool removeCollegeHandler(EnrollmentSystem& s);
	friend bool addCourseHandler(EnrollmentSystem& s);
	friend bool removeCourseHandler(EnrollmentSystem& s);
	friend bool addCourseUnitHandler(EnrollmentSystem& s);
	friend bool removeCourseUnitHandler(EnrollmentSystem& s);
	
	//LOAD/SAVE FROM FILES
	void loadStudents();
	void loadProfessors();
	void loadUniversities();
	void loadColleges();
	void loadCourses();
	void loadCourseUnits();
	void loadCourseUnitClasses();
	void saveStudents();
	void saveProfessors();
	void saveUniversities();
	void saveColleges();
	void saveCourses();
	void saveCourseUnits();
	void saveCourseUnitClasses();
	
	//SORT FUNCTIONS

	//GETS
	unsigned int getMaxCredits() const { return MAXIMUM_CREDITS; }
	vector<University*> getUniversities() const { return universitiesVector; }
	University* getUniversity(string &universityName);
	College* getCollege(string &collegeName);
	Course* getCourse(string &courseName);
	CourseUnit* getCourseUnit(string &courseUnitName);
	Student* getStudent(unsigned long long int &ID);
	Student* getStudent(string &name);
	Tutor* getProfessor(unsigned long long int &ID);
	Tutor* getProfessor(string &name);

};

#endif