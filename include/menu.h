#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "student.h"

typedef enum
    {
    STUDENT_ADD = 1,
    STUDENT_LIST,
    STUDENT_DELETE
    }MENU_OPTIONS;

typedef struct STUDENT_HANDLER
{
    MENU_OPTIONS menuOptions;
    bool (*func) (void);
}STUDENT_HANDLER;

/* Displays  "main menu"*/

bool menuMain(void);			

// Main Menu
bool menuStudentOverview(void);
bool menuAddStudent(void);		// Ask name, roll number, Marks of 10 subjects, student Address(Dyanamic size), calc sum of marks, average, grades of each and Rank
bool menuListStudent(void);		// Print the students names based on "List Student menu"
bool menuDeleteStudent(void);	// Remove the students based on "Delete Student menu"

// List Student Menu
bool menuListSearchByName(void);	// Ask name, and show result
bool menuListSortByName(void);		// Show all student list sorted by Name(Alphabetically)
bool menuListSortByRoll(void);		// Show all student list sorted by Roll number
bool menuListSortByRank(void);		// Show all student list sorted by Rank

// Delete Student Menu
bool menuDeleteByName(void);		// Ask name, and delete student
bool menuDeleteByRoll(void);		// Ask Roll, and delete student
bool menuDeleteAll(void);			// Delete all


#endif // MENU_H