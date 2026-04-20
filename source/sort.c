/*sort file*/

#include <stdio.h>
#include "linkedlist.h"
#include "student.h"
#include "common.h"
#include "sort.h"

/*To sort by name*/

bool SortByName(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
        {
            Node* currentNode = pstlinkedlistHead;
            Node* nextNode = NULL;
            student temp = {0};

            while(currentNode != NULL)
                {
                    nextNode = currentNode->pstNext;

                    while(nextNode != NULL)
                        {
                            if(strncmp((char*)currentNode->stInfo.pucname, 
                            (char*)nextNode->stInfo.pucname, 
                            MAX_NAME_LENGTH) > 0)
                                {
                                    temp = currentNode->stInfo;
                                    currentNode->stInfo = nextNode->stInfo;
                                    nextNode->stInfo = temp;
                                }
                                nextNode = nextNode->pstNext;
                        }
                currentNode = currentNode->pstNext;

                }

        blRet = TRUE;
    }
    else
    {
        printf("invalid input.\n");
        blRet = FALSE;
    }
            
    return blRet;
}

/*To sort by roll number*/

bool SortByRoll(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
            {
                Node* currentNode = pstlinkedlistHead;
                Node* nextNode = NULL;
                student temp;

                while(currentNode != NULL)
                    {
                        nextNode = currentNode->pstNext;

                        while(nextNode != NULL)
                            {
                                if(currentNode->stInfo.ucrollNumber > 
                                nextNode->stInfo.ucrollNumber)
                                    {
                                        temp = currentNode->stInfo;
                                        currentNode->stInfo = nextNode->stInfo;
                                        nextNode->stInfo = temp;
                                    }

                                    nextNode = nextNode->pstNext;
                            }
                
                            currentNode = currentNode->pstNext;
                        }

                        blRet = TRUE;
            }
        else
            {
                printf("invalid input.\n");
                blRet = FALSE;
            }
            
        return blRet;
}

