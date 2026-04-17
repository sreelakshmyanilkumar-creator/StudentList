#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "student.h"
#include "common.h"

bool linkedListNodeAddbeginning(Node** ppstlinkedlistHead, student* pstInfo)
    {
        bool blRet = FALSE;

        if((pstInfo != NULL) && (ppstlinkedlistHead != NULL))
            {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->stInfo = *pstInfo;
                newNode->pstNext = *ppstlinkedlistHead;
                *ppstlinkedlistHead = newNode;
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;

}