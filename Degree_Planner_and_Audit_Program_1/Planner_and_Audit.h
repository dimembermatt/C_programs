//
// Created by matth on 1/2/2018.
//

#ifndef PLANNER_AND_AUDIT_H_
#define PLANNER_AND_AUDIT_H_

//file access
void getPath(char * mfilen, int type);
void readFile(char * fileName);
void appendFile(char * filePath);
void closeFile();
void writeFile(char * filePath, char * copyFilePath);
void closeWriteFile(char * inFilePath, char * copyFilePath);
void backup();

//Official Coursework functions
void displayCoursework();
int addCourse(char courseName[], char letterGrd[], char creditHr[]);
int removeCourse(char courseName[]);
int editCourse(char courseName[], char letterGrd[], char creditHr[]);
double getGPA();
double getLetterVal(char letterGrade[]);
int getHours();
double getCompleteRate();

//Schedule Planning functions
void displaySchedule();
int addPCourse(char courseName[], char semester[]);
int removePCourse(char courseName[]);
#endif //PLANNER_AND_AUDIT_H_
