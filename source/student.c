/*student file*/

#include "student.h"
#include "common.h"
#include "linkedlist.h"
#include "menu.h"

/*To add student*/

bool studentAdd(student* pstInfo)
    {
        bool blRet = TRUE;

        printf("Enter student name: ");
        if(scanf(" %49s", pstInfo->pucname) == 1)
            {
                printf("Student name: %s\n", pstInfo->pucname);
            }
        else
            {
                printf("Invalid input for student name.\n");
                blRet = FALSE;
        }

        printf("Enter student Address: ");
        if(scanf(" %99s", pstInfo->pucaddress) == 1)
            {
                printf("Student address: %s\n", pstInfo->pucaddress);
            }
        else
            {
                printf("Invalid input for student address.\n");
                blRet = FALSE;
            }

        printf("Enter roll number: ");
        scanf("%hhu", &pstInfo->ucrollNumber);
        printf("Roll number: %d\n", pstInfo->ucrollNumber);

        printf("Enter marks for %d subjects:\n", MAX_SUBJECTS);
        for(uint8_t i = 0; i < MAX_SUBJECTS; i++)
            {
                printf("Subject %d: ", i + 1);
                scanf("%hhu", &pstInfo->ucmarks[i]);
                printf("Subject %d marks: %d\n", i + 1, pstInfo->ucmarks[i]);
            }

        if(studentCalcSum(pstInfo, &pstInfo->ulsumMarks) == TRUE &&
           studentCalcAverage(pstInfo, &pstInfo->ucaverageMarks) == TRUE &&
           studentCalcGrades(pstInfo, pstInfo->ucgrades) == TRUE)
            {
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;
    }

/*To calculate sum of marks*/

bool studentCalcSum(student* pstInfo, uint32* pulSum)
    {
        bool blRet = FALSE;

        if(pstInfo != NULL && pulSum != NULL)
            {
                uint32 sum = 0;
                for(uint8_t i = 0; i < MAX_SUBJECTS; i++)
                    {
                        sum += pstInfo->ucmarks[i];
                    }
                *pulSum = sum;
                blRet = TRUE;
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To calculate grades of each subject*/

bool studentCalcGrades(student* pstInfo, uint8* pucSum)
    {
        bool blRet = FALSE;

        if(pstInfo != NULL && pucSum != NULL)
            {
                for(uint8_t count = 0; count < MAX_SUBJECTS; count++)
                    {
                        if(pstInfo->ucmarks[count] >= 90)
                            {
                                pstInfo->ucgrades[count] = 'A';
                            }
                        else if(pstInfo->ucmarks[count] >= 80)
                            {
                                pstInfo->ucgrades[count] = 'B';
                            }
                        else if(pstInfo->ucmarks[count] >= 70)
                            {
                                pstInfo->ucgrades[count] = 'C';
                            }
                        else if(pstInfo->ucmarks[count] >= 60)
                            {
                                pstInfo->ucgrades[count] = 'D';
                            }
                        else
                            {
                                pstInfo->ucgrades[count] = 'F';
                            }
                    }
                blRet = TRUE;
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To calculate avarage mark*/

bool studentCalcAverage(student* pstInfo, float* pfAvg)
    {
        bool blRet = FALSE;

        if(pstInfo != NULL && pfAvg != NULL)
            {
                uint32 ucsum = 0;
                for(uint8_t count = 0; count < MAX_SUBJECTS; count++)
                    {
                        ucsum += pstInfo->ucmarks[count];
                    }
                *pfAvg = (float)(ucsum / MAX_SUBJECTS);
                blRet = TRUE;
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To get total number of students*/

bool studentGetCount(uint32* pulCount)
    {
        bool blRet = FALSE;
        uint32 count = 0;
        const Node* currentNode = studentHeadNode;

        if(pulCount != NULL)
            {
                while(currentNode != NULL)
                    {
                        count++;
                        currentNode = currentNode->pstNext;
                    }
                *pulCount = count;
                blRet = TRUE;
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*Average marks of each students*/

bool studentGetAvgMarksOfSubjects(uint8_t* pucTotalAvg)
    {
        bool blRet = FALSE;
        Node* currentNode = studentHeadNode;
        uint32_t totalMarks[MAX_SUBJECTS] = {0};

        if(pucTotalAvg != NULL)
            {
                uint32_t studentCount = 0;
                if (studentHeadNode == NULL)
                    {
                        printf("List is empty.\n");
                        return TRUE;
                    }

                while(currentNode != NULL)
                    {
                        printf("Name : %s, Averagemark : %f\n",
                        currentNode->stInfo.pucname, 
                        currentNode->stInfo.ucaverageMarks);
                        pucTotalAvg[studentCount] = 
                                    (uint8_t)currentNode->stInfo.ucaverageMarks;
                        currentNode = currentNode->pstNext;
                        studentCount++;
                    }

            blRet = TRUE;
        }
    else
        {
            printf("invalid input\n");
            blRet = FALSE;
        }

    return blRet;
}

/*To delete linked list by name*/

bool studentDeleteByName(uint8* pucName)
    {
        bool blRet = FALSE;

        if(linkedListDeleteByName(&studentHeadNode, pucName))
            {
                blRet = TRUE;
            }

        return blRet;
    }

/*To delete linked list by roll number*/

bool studentDeleteByRoll(uint32 ulRoll)
    {
        bool blRet = FALSE;

        if(linkedListDeleteByRoll(&studentHeadNode, &ulRoll))
            {
                linkedListNodePrint(studentHeadNode);
                blRet = TRUE;
            }

        return blRet;
    }

/*To delete all students data*/

bool studentDeleteAll(void)
    {  
        bool blRet = FALSE;

        if(linkedListDeleteAll(&studentHeadNode))
            {
                blRet = TRUE;
            }

        return blRet;
    }