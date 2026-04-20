/*linkedlist file*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linkedlist.h"
#include "student.h"
#include "common.h"

/*To print the linked list*/

bool linkedListNodePrint(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
            {
                const Node* currentNode = pstlinkedlistHead;

                while(currentNode != NULL)
                    {
                        printf("\n=========================================\n");
                        printf("             STUDENT RECORD                \n");
                        printf("===========================================\n");

                        // 1. Basic Info Row
                        printf("%-15s : %s\n", "Name", 
                            currentNode->stInfo.pucname);
                        printf("%-15s : %d\n", "Roll Number", 
                            currentNode->stInfo.ucrollNumber);
                        printf("%-15s : %s\n", "Address", 
                            currentNode->stInfo.pucaddress);

                        // 2. Academic Performance Row
                        printf("-------------------------------------------\n");
                        printf("%-15s : %-5u\n", 
                        "Total Marks",  currentNode->stInfo.ulsumMarks);

                        // Fix: Change %f to %.2f if average is float, or %d if
                        // it's uint8_t
                        printf("%-15s : %f\n", "Average", 
                            currentNode->stInfo.ucaverageMarks);

                        // 3. Subject Breakdown
                        printf("-------------------------------------------\n");
                        printf("Subject Marks: ");
                        for(int i = 0; i < 10; i++) 
                            {
                                printf("[%02d] ", 
                                    currentNode->stInfo.ucmarks[i]);
                            }
                        printf("\n=========================================\n");

                        currentNode = currentNode->pstNext;

                    }
                blRet = TRUE;
            }
        else
            {
                blRet = FALSE;
            }

        return blRet;
    }

/*To add node at the beginning of linked list*/

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
                printf("Invalid input to linkedListNodeAddbeginning.\n");
                blRet = FALSE;
            }

        return blRet;

}

/*To search by name*/

bool linkedListNodeSearchByName(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
            {
                Node* currentNode = pstlinkedlistHead;
                uint8_t searchName[MAX_NAME_LENGTH] = {0};

                printf("Enter the name to search: ");
                scanf(" %49s", searchName);

                while(currentNode != NULL)
                    {
                        if(strncmp((char*)currentNode->stInfo.pucname, 
                                    (char*)searchName, strlen(searchName)) == 0)
                            {
                                printf("\n=================================\n");
                                printf("         STUDENT RECORD            \n");
                                printf("===================================\n");

                                // 1. Basic Info Row
                                printf("%-15s : %s\n", "Name", 
                                currentNode->stInfo.pucname);
                                printf("%-15s : %d\n", "Roll Number", 
                                currentNode->stInfo.ucrollNumber);
                                printf("%-15s : %s\n", "Address", 
                                currentNode->stInfo.pucaddress);

                                // 2. Academic Performance Row
                                printf("-----------------------------------\n");
                                printf("%-15s : %-5u\n", 
                                "Total Marks",  currentNode->stInfo.ulsumMarks);

                                // Fix: Change %f to %.2f if average is float,
                                // or %d if it's uint8_t
                                printf("%-15s : %f\n", "Average", 
                                currentNode->stInfo.ucaverageMarks);

                                // 3. Subject Breakdown
                                printf("-----------------------------------\n");
                                printf("Subject Marks: ");
                                for(int i = 0; i < 10; i++) 
                                    {
                                        printf("[%02d] ", 
                                        currentNode->stInfo.ucmarks[i]);
                                    }
                                    printf("\n=============================\n");
                                    blRet = TRUE;
                                    break;
                            }
                            
                        currentNode = currentNode->pstNext;
                    }
            }
        else
            {
                printf("Invalid input to linkedListNodeSearchByName.\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To sort by name*/

bool linkedListNodeSortByName(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
            {
                if(SortByName(pstlinkedlistHead))
                    {
                        blRet = TRUE;
                    }
                else
                    {
                        printf("Sorting by name failed.\n");
                        blRet = FALSE;
                    }
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To sort by roll number*/

bool linkedListNodeSortByRoll(Node* pstlinkedlistHead)
    {
        bool blRet = FALSE;

        if(pstlinkedlistHead != NULL)
            {
                if(SortByRoll(pstlinkedlistHead))
                    {
                        blRet = TRUE;
                    }
                else
                    {
                        printf("Sorting by roll number failed.\n");
                        blRet = FALSE;
                    }
            }
        else
            {
                printf("invalid input\n");
                blRet = FALSE;
            }

        return blRet;
    }

/*To delete linkedlist by name*/

bool linkedListDeleteByName(Node** ppstlinkedlistHead, char* pucName)
    {
        bool blRet = FALSE;
        Node* currentNode = NULL;
        Node* prevNode = NULL;
    
    	if (ppstlinkedlistHead == NULL || *ppstlinkedlistHead == NULL)
    	    {
        	    printf("Invalid input or empty list\n");
        	    blRet = FALSE;
    	    }
        else
            {
                currentNode = *ppstlinkedlistHead;
    	        printf("Enter the name to delete: ");
    	        scanf(" %49s", pucName);

                while (currentNode != NULL)
                    {
                        if (strncmp((char*)currentNode->stInfo.pucname, 
                        (char*)pucName, MAX_NAME_LENGTH) == 0)
                            {
                                if (prevNode == NULL) 
                                    {
                                        *ppstlinkedlistHead = 
                                        currentNode->pstNext;
                                    }
                                else 
                                    {
                                        prevNode->pstNext = 
                                        currentNode->pstNext;
                                    }

                                free(currentNode);
                                blRet = TRUE;
                                break;
                            }

                        prevNode = currentNode;
                        currentNode = currentNode->pstNext;
                    }
            }
            
            return blRet;
}

/*To delete linked list by rollnumber*/

bool linkedListDeleteByRoll(Node** ppstlinkedlistHead, uint32* ulRoll)
    {
        bool blRet = FALSE;
        Node* currentNode = NULL;
        Node* prevNode = NULL;
    
    	if (ppstlinkedlistHead == NULL || *ppstlinkedlistHead == NULL)
    	    {
        	    printf("Invalid input or empty list\n");
        	    blRet = FALSE;
    	    }
        else
            {
                currentNode = *ppstlinkedlistHead;
    	        printf("Enter the roll number to delete: ");
    	        scanf("%u", ulRoll);

                while (currentNode != NULL)
                    {
                        if (currentNode->stInfo.ucrollNumber == *ulRoll)
                            {
                                if (prevNode == NULL) 
                                    {
                                        *ppstlinkedlistHead = 
                                        currentNode->pstNext;
                                    }
                                else 
                                    {
                                        prevNode->pstNext = 
                                        currentNode->pstNext;
                                    }

                                free(currentNode);
                                blRet = TRUE;
                                break;
                            }

                        prevNode = currentNode;
                        currentNode = currentNode->pstNext;
                    }
            }
            
            return blRet;
}


/*To delete all nodes in the linked list*/

bool linkedListDeleteAll(Node** ppstlinkedlistHead)
{
    bool blRet = FALSE;
    Node* currentNode = NULL;
    Node* nextNode = NULL;

    if (ppstlinkedlistHead == NULL || *ppstlinkedlistHead == NULL)
    {
        printf("Invalid input or empty list\n");
        blRet = FALSE;
    }
    else
    {
        currentNode = *ppstlinkedlistHead;
    
        while(currentNode != NULL)
        {
            nextNode = currentNode->pstNext;
            free(currentNode);
            currentNode = nextNode;
        }

        *ppstlinkedlistHead = NULL; 
        blRet = TRUE;
    }

    return blRet;
}
