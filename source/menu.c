/*menu file*/

/*Includes*/

#include <stdio.h>
#include "menu.h"
#include "student.h"
#include "common.h"
#include "linkedlist.h"

/*Global variables*/

const STUDENT_HANDLER studentHandler[] =
    {
    {STUDENT_ADD, menuAddStudent},
    {STUDENT_LIST, menuListStudent},
    {STUDENT_DELETE, menuDeleteStudent},
    {STUDENT_OVERVIEW, menuStudentOverview}
   };

const LIST_HANDLER listHandler[] =
    {
    {SEARCH_NAME, menuListSearchByName},
    {SORT_NAME, menuListSortByName},
    {SORT_ROLLNUMBER, menuListSortByRoll}
    //{SORT_RANK, menuListSortByRank}
   };

const DELETE_HANDLER deleteHandler[] =
    {
    {DELETE_NAME, menuDeleteByName},
    {DELETE_ROLL, menuDeleteByRoll},
    {DELETE_ALL, menuDeleteAll}
   };
const OVERVIEW_HANDLER overviewHandler[] =
    {
    {STUDENT_COUNT, menuStudentCount},
    {AVERAGE_MARKS, menuAverageMarks}
   };

Node* studentHeadNode = NULL;

/*Main Menu*/

bool menuMain(void)
    {
        bool blRet = TRUE;
        uint8_t menuOption = 0;
        uint8_t menuOptionsMaxCount = 0;
        uint8_t count = 0;

        /*Listing main menu*/

        while(1)
            {
                printf("Welcome to the Student Data base\n");
                printf("Please select an option:\n");
                printf("1. Add a student\n");
                printf("2. List all students\n");
                printf("3. Delete a student\n");
                printf("4. Student Overview\n");

                /*Get user input*/

                printf("Enter your choice: ");
                scanf("%hhu", &menuOption);
                printf("menuOption: %hhu\n", menuOption);

                menuOptionsMaxCount = 
                            sizeof(studentHandler)/sizeof(studentHandler[0]);

                if(menuOption < 1 || menuOption > menuOptionsMaxCount)
                    {
                        printf("Invalid option...\n");
                        blRet = FALSE;
                    }
                else
                   {
                        for(count = 0; count < menuOptionsMaxCount; count++)
                            {
                                if(studentHandler[count].menuOptions == 
                                   menuOption)
                                    {
                                        blRet = studentHandler[count].func();
                                    }
                            }
                }
            }

        return blRet;
    }

/*Show how many students are added, their average marks.*/

bool menuStudentOverview(void)
    {
        bool blRet = TRUE;
        uint8_t menuOption = 0;
        uint8_t menuOptionsMaxCount = 0;
        uint8_t count = 0;

 
        printf("Student Overview\n");
        printf("Please select an option:\n");
        printf("1. Show total number of students\n");
        printf("2. Show average marks of each subject\n");

        /*Get user input*/

        printf("Enter your choice: ");
        scanf("%hhu", &menuOption);
        printf("menuOption: %hhu\n", menuOption);

        menuOptionsMaxCount = 
                            sizeof(overviewHandler)/sizeof(overviewHandler[0]);

        if(menuOption < 1 || menuOption > menuOptionsMaxCount)
            {
                printf("Invalid option...\n");
                blRet = FALSE;
            }
        else
            {
                for(count = 0; count < menuOptionsMaxCount; count++)
                    {
                        if(overviewHandler[count].menuOptions == 
                                   menuOption)
                            {
                                blRet = overviewHandler[count].func();
                            }
                    }
                    
                blRet = TRUE;
            }

            return blRet;
    }

/*// Ask name, roll number, Marks of 10 subjects, student Address(Dyanamic size)
, calc sum of marks, average, grades of each and Rank*/

bool menuAddStudent(void)
    {
        bool blRet = FALSE;
        student* pstInfo = (student*)malloc(sizeof(student));

        if(studentAdd(pstInfo))
            {
                printf("pstInfo.name: %s\n", pstInfo->pucname);
                printf("pstInfo.address: %s\n", pstInfo->pucaddress);
                printf("pstInfo.rollNumber: %d\n", pstInfo->ucrollNumber);
                printf("pstInfo.marks: %d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n", 
                       pstInfo->ucmarks[0],
                       pstInfo->ucmarks[1],
                       pstInfo->ucmarks[2],
                       pstInfo->ucmarks[3],
                       pstInfo->ucmarks[4],
                       pstInfo->ucmarks[5],
                       pstInfo->ucmarks[6],
                       pstInfo->ucmarks[7],
                       pstInfo->ucmarks[8],
                       pstInfo->ucmarks[9]);

                if(linkedListNodeAddbeginning(&studentHeadNode, pstInfo))
                    {
                        linkedListNodePrint(studentHeadNode);
                        free(pstInfo);
                        blRet = TRUE;
                    }
                        
                else
                    {
                        blRet = FALSE;
                    }
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;
    }

/*menu to list student*/

bool menuListStudent(void)
    {
        bool blRet = TRUE;
        uint8_t menuOption = 0;
        uint8_t menuOptionsMaxCount = 0;
        uint8_t count = 0;
        
        printf("Select option to List Student Data\n");
        printf("Please select an option:\n");
        printf("1. Search by Name\n");
        printf("2. Sort by Name\n");
        printf("3. Sort by Rollnumber\n");
        printf("4. Sort by Rank\n");

        /*Get user input*/

        printf("Enter your choice: ");
        scanf("%hhu", &menuOption);
        printf("menuOption: %hhu\n", menuOption);

        menuOptionsMaxCount = sizeof(listHandler)/sizeof(listHandler[0]);

        if(menuOption < 1 || menuOption > menuOptionsMaxCount)
            {
                printf("Invalid option...\n");
                blRet = FALSE;
            }
        else
            {
                for(count = 0; count < menuOptionsMaxCount; count++)
                    {
                        if(listHandler[count].menuOptions == menuOption)
                            {
                                blRet = listHandler[count].func();
                            }
                    }
            }

        return blRet;
    }

/*Search by Name*/

bool menuListSearchByName(void)
    {
        bool blRet = FALSE;

        if(linkedListNodeSearchByName(studentHeadNode))
            {
                blRet = TRUE;
            }

        return blRet;
    }

/*Sort by Name*/
bool menuListSortByName(void)
    {
        bool blRet = FALSE;

        if(linkedListNodeSortByName(studentHeadNode))
            {
                linkedListNodePrint(studentHeadNode);
                blRet = TRUE;
            }

        return blRet;
    }

/*Sort by Rollnumber*/

bool menuListSortByRoll(void)
    {
        bool blRet = FALSE;

            if(linkedListNodeSortByRoll(studentHeadNode))
            {
                linkedListNodePrint(studentHeadNode);
                blRet = TRUE;
            }

        return blRet;
    }

/* To delete a student*/

bool menuDeleteStudent(void)
    {
        bool blRet = FALSE;
        uint8_t menuOption = 0;
        uint8_t menuOptionsMaxCount = 0;
        uint8_t count = 0;
        
        printf("Select option to Delete Student Data\n");
        printf("Please select an option:\n");
        printf("1. Delete by Name\n");
        printf("2. Delete by Roll number\n");
        printf("3. Delete all students\n");

        /*Get user input*/

        printf("Enter your choice: ");
        scanf("%hhu", &menuOption);
        printf("menuOption: %hhu\n", menuOption);

        menuOptionsMaxCount = sizeof(deleteHandler)/sizeof(deleteHandler[0]);

        if(menuOption < 1 || menuOption > menuOptionsMaxCount)
            {
                printf("Invalid option...\n");
                blRet = FALSE;
            }
        else
            {
                for(count = 0; count < menuOptionsMaxCount; count++)
                    {
                        if(deleteHandler[count].menuOptions == menuOption)
                            {
                                blRet = deleteHandler[count].func();
                            }
                    }

                    blRet = TRUE;
            }

        return blRet;
    }

/*To delete by name*/

bool menuDeleteByName(void)
    {
        bool blRet = FALSE;
        char pucName[MAX_NAME_LENGTH] = {0};

        if(studentDeleteByName(pucName))
            {
                linkedListNodePrint(studentHeadNode);
                blRet = TRUE;
            }

        return blRet;
    }

/*To delete by rollnumber*/

bool menuDeleteByRoll(void)
    {
        bool blRet = FALSE;
        uint32 ulRoll = 0;

        if(studentDeleteByRoll(&ulRoll))
            {
                linkedListNodePrint(studentHeadNode);
                blRet = TRUE;
            }

        return blRet;
    }

/*To delete all students data */

bool menuDeleteAll(void)
    {
        bool blRet = FALSE;

        if(studentDeleteAll())
            {
                blRet = TRUE;
            }

        return blRet;
    }

/*To show total number of students*/

bool menuStudentCount(void)
    {
        bool blRet = FALSE;
        uint32 ulCount = 0;

        if(studentGetCount(&ulCount))
            {
                printf("Total number of students: %u\n", ulCount);
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;
    }

/*To show average marks of each subject*/

bool menuAverageMarks(void)
    {
        bool blRet = FALSE;
        uint8_t pucAvgMarks[MAX_SUBJECTS] = {0};

        if(studentGetAvgMarksOfSubjects(pucAvgMarks))
            {
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;
    }