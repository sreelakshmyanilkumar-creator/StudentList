#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"
#include "common.h"

typedef struct Node
    {
        student stInfo;
        struct Node* pstNext;
    }Node;

bool linkedListNodeAddbeginning(Node** ppstlinkedlistHead, student* pstInfo);
bool linkedListNodePrint(Node* pstlinkedlistHead);
bool linkedListNodeSearchByName(Node* pstlinkedlistHead);
bool linkedListNodeSortByName(Node* pstlinkedlistHead);
bool linkedListNodeSortByRoll(Node* pstlinkedlistHead);
bool linkedListDeleteByName(Node** ppstlinkedlistHead, char* pucName);
bool linkedListDeleteByRoll(Node** ppstlinkedlistHead, uint32* ulRoll);
bool linkedListDeleteAll(Node** ppstlinkedlistHead);
bool linkedListGetCount(Node* pstlinkedlistHead, uint32* ulCount);
bool linkedListAverageMarks(Node* pstlinkedlistHead, uint8_t* pucAvgMarks);

#endif // LINKEDLIST_H