#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "common.h"

#define MAX_NAME_LENGTH (50U)
#define MAX_ADDRESS_LENGTH (100U)
#define MAX_SUBJECTS (10U)
#define MAX_NUMBER_STUDENTS (100U)

/* Student structure definition */

typedef struct student
    {
        uint8_t ucrollNumber;
        uint8_t pucname[MAX_NAME_LENGTH];
        uint8_t ucmarks[MAX_SUBJECTS];
        uint16_t ulsumMarks;
        uint8_t ucgrades[MAX_SUBJECTS];
        uint8_t ucrank;
        float ucaverageMarks;
        uint8_t pucaddress[MAX_ADDRESS_LENGTH];
    }student;

/* Function prototypes for student management */

bool studentAdd(student* pstInfo);
bool studentCalcAverage(student* pstInfo, float* pfAvg);
bool studentCalcSum(student* pstInfo, uint32* pulSum);
bool studentCalcGrades(student* pstInfo, uint8* pucSum);
bool studentUpdateRank(void);

bool studentGetCount(uint32* pulCount);
bool studentGetAvgMarksOfSubjects(uint8* pucAvgMarks);

bool studentDeleteByName(uint8* pucName);
bool studentDeleteByRoll(uint32 ulRoll);
bool studentDeleteAll(void);

#endif // STUDENT_H