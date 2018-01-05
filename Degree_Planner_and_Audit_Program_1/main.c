#include <stdio.h>
#include <string.h>
#include "Planner_and_Audit.h"
#include <windows.h>
//#include "CourseEntry.h"

/**
 * Degree Planner and Audit Program.
 * IO, File access, naming convention, modularity practice.
 * Some concepts based off of the University of Texas' Interactive Degree Audit.
 *
 * c programming language.
 * Matthew Yu
 * 1/2/18
 * V1
 */

/**
 * TODO:
 * implementation of PlanningCoursework.txt, multiple file management
 * implementation of option: plan coursework
 * bug checks
 * error handling checks
 */
#define INP_BUFF  50
#define PATH_BUFF 150

int main()
{
    char input[INP_BUFF], courseworkFileName[PATH_BUFF], planningFileName[PATH_BUFF];
    //char mfileName[150] = "C:\\Users\\matth\\CLionProjects\\Degree_Planner_and_Audit_Program_1\\OfficialCoursework.txt";
    GetFullPathNameA("OfficialCoursework.txt", PATH_BUFF, courseworkFileName, NULL);
    getPath(courseworkFileName, 1);
    //printf("PATH = %s", courseworkFileName);

    GetFullPathNameA("PlanningCoursework.txt", PATH_BUFF, planningFileName, NULL);
    getPath(planningFileName, 2);
    //printf("\nPlanning Coursework PATH = %s", planningFileName);

    printf("\nHello, World!\n");
    while(1)
    {
        printf("______________________________________________\n");
        printf("Welcome to Degree Planner and Audit Program.  \n\n");
        printf("Index:                                    Type\n");
        printf("Add/Revise Coursework ---------------------- 1\n");
        printf("Plan Coursework ---------------------------- 2\n");
        printf("Check GPA ---------------------------------- 3\n");
        printf("Check completion rate ---------------------- 4\n");
        printf("Exit application --------------------------- 5\n");
        printf("______________________________________________\n\n");
        printf("Enter option here: ");
        while(1)
        {
            fgets(input, INP_BUFF, stdin);
            if(strcmp(input, "1\n") != 0 && strcmp(input, "2\n") != 0 && strcmp(input, "3\n") != 0 && strcmp(input, "4\n") != 0 && strcmp(input, "5\n") != 0)
                printf("Invalid input. Enter a number 1-5.\n");
            else
                break;
        }
        if(strcmp(input, "1\n") == 0) //Add/Revise Coursework
        {
            while(1)
            {
                printf("____________________________________________\n");
                printf("Add/Revise Coursework.                      \n\n");
                printf("Index:                                    Type\n");
                printf("See available Coursework ------------------- 1\n");
                printf("Add course --------------------------------- 2\n");
                printf("Remove course ------------------------------ 3\n");
                printf("Edit course -------------------------------- 4\n");
                printf("Exit window -------------------------------- 5\n");
                printf("____________________________________________\n\n");
                while(1)
                {
                    fgets(input, INP_BUFF, stdin);
                    if(strcmp(input, "1\n") != 0 && strcmp(input, "2\n") != 0 && strcmp(input, "3\n") != 0 && strcmp(input, "4\n") != 0 && strcmp(input, "5\n") != 0)
                        printf("Invalid input. Enter a number 1-5.\n");
                    else
                        break;
                }
                if(strcmp(input, "1\n") == 0) //See Available Coursework
                    displayCoursework();
                else if(strcmp(input, "2\n") == 0) //Add Course to Coursework
                {
                    char letterGrd[4], creditHr[3];
                    printf("Enter course name. (i.e., EE306)\n");
                    fgets(input, INP_BUFF, stdin);
                    printf("Enter letter grade. (i.e., \"B-\")\n");
                    fgets(letterGrd, sizeof(letterGrd), stdin);
                    printf("Enter credit hours. (first digit of course name)\n");
                    fgets(creditHr, sizeof(creditHr), stdin);
                    if(addCourse(input, letterGrd, creditHr) == 1)
                        displayCoursework();
                    else
                        printf("Error. addCourse method -> fprintf had <=0 elements found.\n");
                }
                else if(strcmp(input, "3\n") == 0) //Remove Course from Coursework
                {
                    printf("Enter course name. (i.e., EE306)\n");
                    fgets(input, INP_BUFF, stdin);
                    if(removeCourse(input) == 1)
                        displayCoursework();
                    else
                        printf("Error. No course found.\n");
                }
                else if(strcmp(input, "4\n") == 0) //Edit Course in Coursework
                {
                    char letterGrd[4], creditHr[3];
                    printf("Enter course name. (i.e., EE306)\n");
                    fgets(input, INP_BUFF, stdin);
                    printf("Enter letter grade. (i.e., \"B-\")\n");
                    fgets(letterGrd, sizeof(letterGrd), stdin);
                    printf("Enter credit hours. (first digit of course name)\n");
                    fgets(creditHr, sizeof(creditHr), stdin);
                    if(editCourse(input, letterGrd, creditHr) == 1)
                        displayCoursework();
                    else
                        printf("Error. No course found.\n");
                }
                else //Exit Window
                    break;
            }

        }
        else if(strcmp(input, "2\n") == 0) //Plan Coursework
        {
            while(1)
            {
                printf("____________________________________________\n");
                printf("Plan Coursework.                            \n\n");
                printf("Index:                                    Type\n");
                printf("See Planned Coursework Schedule ------------ 1\n");
                printf("Add course --------------------------------- 2\n");
                printf("Remove course ------------------------------ 3\n");
                printf("Exit window -------------------------------- 4\n");
                printf("____________________________________________\n\n");
                while (1)
                {
                    fgets(input, INP_BUFF, stdin);
                    if (strcmp(input, "1\n") != 0 && strcmp(input, "2\n") != 0 && strcmp(input, "3\n") != 0 && strcmp(input, "4\n") != 0)
                        printf("Invalid input. Enter a number 1-4.\n");
                    else
                        break;
                }
                if (strcmp(input, "1\n") == 0) //See Planned Coursework Schedule
                    displaySchedule();
                else if (strcmp(input, "2\n") == 0) //Add Course to Schedule
                {
                    char semester[15], creditHr[3], year[5];
                    printf("Enter course name. (i.e., EE306)\n");
                    fgets(input, INP_BUFF, stdin);
                    printf("Enter credit hours. (first digit of course name)\n");
                    fgets(creditHr, sizeof(creditHr), stdin);
                    printf("Enter Semester predicted to take course. (from 'Fall 2017' to 'Spring 2021')\n");
                    scanf("%s %s", semester, year);
                    if (addPCourse(input, creditHr, semester, year) == 1)
                        displaySchedule();
                    else
                        printf("Error. addCourse method -> fprintf had <=0 elements found.\n");
                }
                else if (strcmp(input, "3\n") == 0) //Remove Course from Schedule
                {
                    printf("Enter course name. (i.e., EE306)\n");
                    fgets(input, INP_BUFF, stdin);
                    if (removePCourse(input) == 1)
                        displaySchedule();
                    else
                        printf("Error. No course found.\n");
                }
                else //Exit Window
                    break;
            }
        }
        else if(strcmp(input, "3\n") == 0) //Check GPA
        {
            double GPA;
            int hours;
            GPA = getGPA();
            hours = getHours();
            printf("Your GPA is: %f cumulative, from %i hours of coursework.\n", GPA/hours, hours);
        }
        else if(strcmp(input, "4\n") == 0) //Check Completion Rate
        {
            double completionRate;
            completionRate = getCompleteRate();
            printf("Your completion rate is %f percent.\n", completionRate);
        }
        else if(strcmp(input, "5\n") == 0) //Exit Application
        {
            printf("Thank you for using the Degree Planner and Audit Program.\n");
            printf("Created 2018, Matthew Yu\n");
            break;
        }
        else //Error Input
            printf("Err. Input out of defined bounds.\n");
    }
    return 0;
}
