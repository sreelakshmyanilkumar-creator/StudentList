#include <stdio.h>
#include "menu.h"
#include "student.h"
#include "common.h"
#include "linkedlist.h"

const STUDENT_HANDLER studentHandler[] =
    {
    {STUDENT_ADD, menuAddStudent},
    {STUDENT_LIST, menuListStudent}
   // {STUDENT_DELETE, menuDeleteStudent}
   };

const LIST_HANDLER listHandler[] =
    {
    {SEARCH_NAME, menuListSearchByName},
    {SORT_NAME, menuListSortByName},
    {SORT_ROLLNUMBER, menuListSortByRoll},
    {SORT_RANK, menuListSortByRank}
   };

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

                /*Get user input*/

                printf("Enter your choice: ");
                scanf("%d", &menuOption);
                printf("menuOption: %d\n", menuOption);

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
        bool blRet = FALSE;

        blRet = TRUE;

        return blRet;
    }

/*// Ask name, roll number, Marks of 10 subjects, student Address(Dyanamic size)
, calc sum of marks, average, grades of each and Rank*/

bool menuAddStudent(void)
    {
        bool blRet = FALSE;
        student pstInfo = {0};
        Node* studentHeadNode = NULL;

        if(studentAdd(&pstInfo))
            {
                if(linkedListNodeAddbeginning(&studentHeadNode, &pstInfo))
                    {
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
        scanf("%d", &menuOption);
        printf("menuOption: %d\n", menuOption);

        menuOptionsMaxCount = sizeof(ListHandler)/sizeof(ListHandler[0]);

        if(menuOption < 1 || menuOption > menuOptionsMaxCount)
            {
                printf("Invalid option...\n");
                blRet = FALSE;
            }
        else
            {
                for(count = 0; count < menuOptionsMaxCount; count++)
                    {
                        if(ListHandler[count].menuOptions == menuOption)
                            {
                                blRet = ListHandler[count].func();
                            }
                    }
            }

        return blRet;
    }
