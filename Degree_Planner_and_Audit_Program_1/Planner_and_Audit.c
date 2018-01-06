//
// Created by matth on 1/2/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Planner_and_Audit.h"
//#include "CourseEntry.h"

#define FILEPATHSIZE 250
#define NUMBER_OF_SESSIONS 12
#define MAX_CLASSES 8
#define EE_DEGREE_HOURS 125.00

FILE *infile;
FILE *copyfile;
char filePath[FILEPATHSIZE];
char filePathC[FILEPATHSIZE];
char pFilePath[FILEPATHSIZE];
char pFilePathC[FILEPATHSIZE];

/**
 * getPath gets file path mfilen.
 * @param mfilen file path/file name
 * @param type type of path given (OfficialCoursework or PlanningCoursework)
 */
void getPath(char mfilen[], int type)
{
    if(type == 1)
        strncpy(filePath, mfilen, 300);
    else if(type == 2)
        strncpy(pFilePath, mfilen, 300);
    else
    {
        printf("PATH Type Error. Not 1 or 2. src: GETPATH funct.\n");
        exit(1);
    }
}

/**
 * readFile opens a FILE using path filePath and authority r, read.
 * @param filePath file path/file name
 */
void readFile(char * filePath)
{
    //char mfileName[150] = "C:\\Users\\matth\\CLionProjects\\Degree_Planner_and_Audit_Program_1\\OfficialCoursework.txt";
        infile = fopen(filePath, "r+");
        if(infile == NULL)
        {
            printf("fopen failed. File pointer NULL err - %s.\n", filePath);
            exit(0);
        }
}

/**
 * appendFile opens a FILE using path filePath and authority a, append.
 * @param filePath file path/file name
 */
void appendFile(char * filePath)
{
    infile = fopen(filePath, "a");
    if(infile == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", filePath);
        exit(0);
    }
}

/**
 * writeFile creates a FILE with the same pathname (+C appended to end of filepath before .txt).
 * @param filePath file path/file name
 * @param option option for which file path
 *  option 1 - filePath/filePathC, option 2 - pFilePath/pFilePathC
 */
void writeFile(char * inFilePath, char * copyFilePath)
{
    //filePath should be rewritten from filePath to filePath -xOfficialCourseworkx.txt- -> -OfficialCourseworkC.txt-
    char * strPointer;
    strncpy(copyFilePath, inFilePath, FILEPATHSIZE);
    strPointer = strstr(copyFilePath, ".txt");
    strncpy(strPointer, "C.txt", 5);
    copyfile = fopen(copyFilePath, "w");
    if(copyfile == NULL)
    {
        printf("fopen failed. File pointer NULL err - %s.\n", inFilePath);
        exit(0);
    }
}

/**
 * closeFile closes FILE.
 */
void closeFile()
{
    fclose(infile);
}

/**
 * closeWriteFile closes the FILE copyfile and renames it to original file.
 * @param inFilePath file path either filePath or pFilePath
 * @param copyFilePath file path either filePathC or pFilePathC
 */
void closeWriteFile(char * inFilePath, char * copyFilePath)
{
    fclose(copyfile);
    if(remove(inFilePath) != 0)
    {
        printf("File deletion error. infile\n");
        exit(1);
    }
    else
    {
        if(rename(copyFilePath, inFilePath) != 0)
        {
            printf("File rename error. copyfile\n");
            exit(1);
        }
    }
}

/**
 * displayCoursework prints to stdout the contents in file.
 */
void displayCoursework()
{
    readFile(filePath);
    int i = 0;
    char line[50];
    printf("Course:\t\tLetter:\t\tCredit Hours:\n");
    while(fscanf(infile, "%s", line) == 1)
    {
        printf("%s\t\t", line);
        if((i+1)%3 == 0)
            printf("\n");
        i++;
    }
    closeFile();
    //char line[50];
    //getline(line, sizeof(line), infile);
    //while(fgets(line, sizeof(line), infile) != NULL)
    //fputs(line, stdout);
    //printf("%s\n", line);
}

/**
 * addCourse writes to file a valid course with a name, a letter grade, and a credit hour.
 * @param courseName char array of name of course
 * @param letterGrd char array of letter grade received
 * @param creditHr char array of credit hours for course
 * @return int 1 if parameters are valid inputs and courseName is not a duplicate in the file or 0 else.
 */
int addCourse(char courseName[], char letterGrd[], char creditHr[])
{
    appendFile(filePath);
    //char line[50];
    //while(fgets(line, sizeof(line), infile) != NULL);
    //remove \n
    size_t noNewline = strcspn(courseName, "\n");
    courseName[noNewline] = '\0';
    noNewline = strcspn(letterGrd, "\n");
    letterGrd[noNewline] = '\0';
    noNewline = strcspn(creditHr, "\n");
    creditHr[noNewline] = '\0';
    if(fprintf(infile, "%s\t\t%s\t\t%s\n", courseName, letterGrd, creditHr) > 0)
    {
        closeFile();
        return 1;
    }
    else
    {
        closeFile();
        return 0;
    }
}

/**
 * removeCourse removes from file a valid course with a courseName.
 * @param courseName char array of name of course
 * @return int 1 if parameters are valid inputs and courseName exists in file or 0 else.
 */
int removeCourse(char courseName[])
{
    int check = 0;
    char * strPointer, line[50];
    //remove \n
    size_t noNewline = strcspn(courseName, "\n");
    courseName[noNewline] = '\0';

    //implementation of writing to new file
    readFile(filePath);
    writeFile(filePath, filePathC);
    while(fgets(line, sizeof(line), infile) != NULL)
    {
        strPointer = strstr(line, courseName);
        if(strPointer != NULL)
            check = 1;
        else
            fputs(line, copyfile);
    }
    //if(check == 0)
    //    printf("No course found.\n");
    closeFile();
    closeWriteFile(filePath, filePathC);
    return check;
}

/**
 * editCourse checks file for a given courseName and if it exists in file changes the letter grade and credit hour.
 * @param courseName char array of name of course
 * @param letterGrd char array of letter grade received
 * @param creditHr char array of credit hours for course
 * @return int 1 if parameters are valid inputs and courseName exists in file or 0 else.
 */
int editCourse(char courseName[], char letterGrd[], char creditHr[])
{
    int check = 0;
    char * strPointer, buff[50];
    //remove \n
    size_t noNewline = strcspn(courseName, "\n");
    courseName[noNewline] = '\0';
    noNewline = strcspn(letterGrd, "\n");
    letterGrd[noNewline] = '\0';
    noNewline = strcspn(creditHr, "\n");
    creditHr[noNewline] = '\0';

    //implementation of writing to new file
    readFile(filePath);
    writeFile(filePath, filePathC);
    while(fgets(buff, sizeof(buff), infile) != NULL)
    {
        strPointer = strstr(buff, courseName);
        if(strPointer != NULL)
        {
            fprintf(copyfile, "%s\t\t%s\t\t%s\n", courseName, letterGrd, creditHr);
            check = 1;
        }
        else
            fputs(buff, copyfile);
    }
    //if(check == 0)
    //    printf("No course found.\n");
    closeFile();
    closeWriteFile(filePath, filePathC);
    return check;
}

/**
 * getGPA gets the cumulative GPA from all courses in the file.
 * @return double cumulative GPA
 */
double getGPA()
{
    int hours = 0;
    char buff[10], letterGrd[4], creditHr[3];
    double letterVal, GPA = 0.0;
    readFile(filePath);
    while(fscanf(infile, "%s%s%s", buff, letterGrd, creditHr) != EOF)
    {
        letterVal = getLetterVal(letterGrd);
        hours = atoi(creditHr);
        GPA += hours * letterVal;
    }
    closeFile();
    return GPA;
}

/**
 * getLetterVal translate a char array letter grade (i.e. a-, c+) into a corresponding GPA value.
 * based on https://registrar.utexas.edu/students/grades
 * @param letterGrade letter grade
 * @return letter value
 */
double getLetterVal(char letterGrade[])
{
    char letterResult[2];
    memcpy(letterResult, letterGrade, 2);
    int switchResult = 0;
    double result;
    //ASCII value manipulation of letter grade to create unique int switch cases
    if(strstr(letterResult, "CR") != NULL)
        switchResult = 1;
    else if(letterResult[1] == 45)
        switchResult = letterResult[0] + letterResult[1] + 10;
    else if(letterResult[1] == 43)
        switchResult = letterResult[0] + letterResult[1];
    else
        switchResult = letterResult[0];

    switch(switchResult)
    {
        case 1: //CR
            result = 0.00;
            break;
        case 65: //A
            result = 4.00;
            break;
        case 120: //A-
            result = 3.67;
            break;
        case 109: //B+
            result = 3.33;
            break;
        case 66: //B
            result = 3.00;
            break;
        case 121: //B-
            result = 2.67;
            break;
        case 110: //C+
            result = 2.33;
            break;
        case 67: //C
            result = 2.00;
            break;
        case 122: //C-
            result = 1.67;
            break;
        case 111: //D+
            result = 1.33;
            break;
        case 68: //D
            result = 1.00;
            break;
        case 123: //D-
            result = 0.67;
            break;
        case 70: //F
            result = 0.00;
            break;
        default:
            printf("Switch case error. A letter grade for a course in the file is unsupported.\n");
            exit(1);
    }
    return result;
}

/**
 * getHours gets total hours from coursework in infile.
 * @return int hours total hours of coursework taken
 */
int getHours()
{
    int hours = 0;
    char buff[10], letterGrd[4], creditHr[3];
    readFile(filePath);
    while(fscanf(infile, "%s%s%s", buff, letterGrd, creditHr) != EOF)
    {
        if(strstr(letterGrd, "CR") == NULL)
            hours = hours + atoi(creditHr);
    }
    closeFile();
    return hours;
}

/**
 * getCompleteRate gets the completion rate of the ***Electrical and Computer Engineering*** diploma at UT from file.
 * @return double completion rate of diploma.
 */
double getCompleteRate()
{
    double hours = 0.0, completeRate = 0.0;
    char buff[10], letterGrd[4], creditHr[3];
    readFile(filePath);
    while(fscanf(infile, "%s%s%s", buff, letterGrd, creditHr) != EOF)
    {
        hours = hours + atoi(creditHr);
    }
    closeFile();
    completeRate = hours * 100.0 / EE_DEGREE_HOURS;
    return completeRate;
}

/**
 * displaySchedule prints to stdout the contents in file.
 * note: NUMBER_OF_SESSIONS must match the number of sessions present in the PlanningCoursework.txt (i.e. +Fall 2018)
 * MAX_CLASSES must be larger than the max number of classes per session in the PlanningCoursework.txt.
 * valid input: EE302 / EE 302 / M 408 D - course identifier should not be longer than 8 characters (\0 appended).
 *  no + delimiter should be present besides at the front of each session name.
 * EOF value must be present at the last line of the text file.
 */
void displaySchedule()
{
    readFile(pFilePath);

    int row = 0, column = -1;
    char buff[15], scheduleArray[NUMBER_OF_SESSIONS][MAX_CLASSES][9];
    //populating 3d array of elements from file
    while(fgets(buff, sizeof(buff), infile) != NULL)
    {
        //remove \n
        size_t noNewline = strcspn(buff, "\n");
        buff[noNewline] = '\0';
        //if +(semester) found, reset row and add column
        if(buff[0] == '+')
        {
            //first column gaurd, +Fall2017
            if(column != -1)
            {
                //clear rows in column
                for(row; row < MAX_CLASSES; row++)
                    strcpy(&scheduleArray[column][row][0], "\0");
            }
            column++;
            row = 0;
        }
        //if EOF line found, finish clearing rows of last array column
        else if (strncmp(buff, "EOF", 3) == 0)
        {
            for(row; row < MAX_CLASSES; row++)
                strcpy(&scheduleArray[column][row][0], "\0");
        }
        //else populate with current line in file
        else
        {
            strcpy(&scheduleArray[column][row][0], buff);
            row++;
        }
    }
    closeFile();
    //formatted print of first half of array
    printf("F17\tS18\tSu18\tF18\tS19\tSu19\n");
    for(row = 0; row < MAX_CLASSES; row++)
    {
        for(column = 0; column < (NUMBER_OF_SESSIONS - 6); column++)
        {
            strcpy(buff, &scheduleArray[column][row][0]);
            printf("%s\t", buff);
        }
        printf("\n");
    }
    //format print of second third of array
    printf("Su19\tF19\tS20\tF20\tS21\tSu21\n");
    for(row = 0; row < MAX_CLASSES; row++)
    {
        for(column = 6; column < (NUMBER_OF_SESSIONS); column++)
        {
            strcpy(buff, &scheduleArray[column][row][0]);
            printf("%s\t", buff);
        }
        printf("\n");
    }
    /**
    //formatted print of first third of array
    printf("F17\t\tS18\t\tSu18\t\tF18\n");
    for(row = 0; row < MAX_CLASSES; row++)
    {
        for(column = 0; column < (NUMBER_OF_SESSIONS - 8); column++)
        {
            strcpy(buff, &scheduleArray[column][row][0]);
            printf("%s\t\t", buff);
        }
        printf("\n");
    }
    //format print of second third of array
    printf("S19\t\tSu19\t\tF19\t\tS20\t\t\n");
    for(row = 0; row < MAX_CLASSES; row++)
    {
        for(column = 4; column < (NUMBER_OF_SESSIONS - 4); column++)
        {
            strcpy(buff, &scheduleArray[column][row][0]);
            printf("%s\t\t", buff);
        }
        printf("\n");
    }
    //format print last third of array
    printf("Su20\t\tF20\t\tS21\t\tSu21\n");
    for(row = 0; row < MAX_CLASSES; row++)
    {
        for(column = 8; column < NUMBER_OF_SESSIONS; column++)
        {
            strcpy(buff, &scheduleArray[column][row][0]);
            printf("%s\t\t", buff);
        }
        printf("\n");
    }
     **/
}

/**
 * addPCourse adds a course with a given name and hour to a listing of a certain semester and year within PlanningCoursework.txt.
 * @param courseName name of course (i.e., EE302)
 * @param semester
 * @return 1 if addPCourse is successful. 0 if not.
 */
int addPCourse(char courseName[], char semester[])
{
    int check = 0;
    char * strPointer, buff[50];

    size_t noNewline = strcspn(courseName, "\n");
    courseName[noNewline] = '\0';
    noNewline = strcspn(semester, "\n");
    semester[noNewline] = '\0';

    //search for whether course is found in file already. If found, output
    //error and exit function early.
    readFile(pFilePath);
    while(fgets(buff, sizeof(buff), infile) != NULL)
    {
        if(strstr(buff, courseName) != NULL)
        {
            printf("This course is already found in the file. Duplicate.");
            closeFile();
            return 0;
        }
    }
    closeFile();
    //get line from infile and check if semester. If semester found, print
    //semester and next line print courseName into copyfile. Else, print
    //line into copyfile.
    readFile(pFilePath);
    writeFile(pFilePath, pFilePathC);
    while(fgets(buff, sizeof(buff), infile) != NULL)
    {
        strPointer = strstr(buff, semester);
        if(strPointer != NULL)
        {
            fputs(buff, copyfile);
            fprintf(copyfile, "%s\n", courseName);
            check = 1;
        }
        else
            fputs(buff, copyfile);//fprintf(copyfile, "%s", buff);
    }
    //error handling
    if(check == 1)
    {
        closeFile();
        closeWriteFile(pFilePath, pFilePathC);
        return 1;
    }
    else
    {
        printf("Semester not found. Err.\n");
        closeFile();
        closeWriteFile(pFilePath, pFilePathC);
        return 0;
    }
}

/**
 * removePCourse removes courseName from PlanningCoursework.txt.
 * @param courseName name of course
 * @return int flag whether function is successful or not
 *  1 - success, 0 - failure, not found
 */
int removePCourse(char courseName[])
{
    int check = 0;
    char * strPointer, buff[50];
    //remove \n
    size_t noNewline = strcspn(courseName, "\n");
    courseName[noNewline] = '\0';

    //implementation of writing to new file
    readFile(pFilePath);
    writeFile(pFilePath, pFilePathC);
    while(fgets(buff, sizeof(buff), infile) != NULL)
    {
        strPointer = strstr(buff, courseName);
        //skip line containing courseName from being written into copyfile.
        if(strPointer != NULL)
            check = 1;
        else
            fputs(buff, copyfile);
    }
    closeFile();
    closeWriteFile(pFilePath, pFilePathC);
    return check;
}