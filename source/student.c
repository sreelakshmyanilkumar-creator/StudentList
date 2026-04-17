#include "student.h"
#include "common.h"


bool studentAdd(student* pstInfo)
    {
        bool blRet = TRUE;

        printf("Enter student name: ");
        scanf("%s", pstInfo->pucname);

        printf("Enter roll number: ");
        scanf("%d", &pstInfo->ucrollNumber);

        printf("Enter marks for %d subjects:\n", MAX_SUBJECTS);
        for(uint8_t i = 0; i < MAX_SUBJECTS; i++)
            {
                printf("Subject %d: ", i + 1);
                scanf("%d", &pstInfo->ucmarks[i]);
            }
#if 0
        if(studentCalcSum(pstInfo, &pstInfo->sumMarks) == TRUE &&
           studentCalcAverage(pstInfo, &pstInfo->averageMarks) == TRUE &&
           studentCalcGrades(pstInfo, pstInfo->grades) == TRUE)
            {
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }
                #endif

        return blRet;
    }
