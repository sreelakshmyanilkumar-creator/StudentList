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


#endif // LINKEDLIST_H