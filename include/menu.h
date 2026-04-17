#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "student.h"
#include "linkedlist.h"
#include "common.h"

typedef enum
    {
    STUDENT_ADD = 1,
    STUDENT_LIST,
    STUDENT_DELETE,
    STUDENT_OVERVIEW
    }MENU_OPTIONS;

typedef enum
    {
    SEARCH_NAME = 1,
    SORT_NAME,
    SORT_ROLLNUMBER,
    SORT_RANK
    }LIST_OPTIONS;

typedef enum
    {
    DELETE_NAME = 1,
    DELETE_ROLL,
    DELETE_ALL
    }DELETE_OPTIONS;

typedef enum
    {
    STUDENT_COUNT = 1,
    AVERAGE_MARKS
    }OVERVIEW_OPTIONS;

typedef struct STUDENT_HANDLER
{
    MENU_OPTIONS menuOptions;
    bool (*func) (void);
}STUDENT_HANDLER;

typedef struct LIST_HANDLER
{
    LIST_OPTIONS menuOptions;
    bool (*func) (void);
}LIST_HANDLER;

typedef struct DELETE_HANDLER
{
    DELETE_OPTIONS menuOptions;
    bool (*func) (void);
}DELETE_HANDLER;

typedef struct OVERVIEW_HANDLER
{
    OVERVIEW_OPTIONS menuOptions;
    bool (*func) (void);
}OVERVIEW_HANDLER;

extern Node* studentHeadNode;

/* Displays  "main menu"*/

bool menuMain(void);

// Main Menu
bool menuStudentOverview(void);
bool menuAddStudent(void);
bool menuListStudent(void);
bool menuDeleteStudent(void);

// List Student Menu
bool menuListSearchByName(void);
bool menuListSortByName(void);
bool menuListSortByRoll(void);
bool menuListSortByRank(void);

// Delete Student Menu
bool menuDeleteByName(void);
bool menuDeleteByRoll(void);
bool menuDeleteAll(void);

//Overview Menu
bool menuStudentCount(void);
bool menuAverageMarks(void);


#endif // MENU_H