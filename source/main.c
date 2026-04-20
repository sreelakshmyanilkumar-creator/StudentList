/*main file */

#include <stdio.h>
#include "menu.h"
#include "common.h"

/* Main function to start the program */

int main(main)
    {
        int blRet = FALSE;
        bool blMenuRet = FALSE;
        
        blMenuRet = menuMain();

        if(blMenuRet == TRUE)
            {
                printf("Program executed successfully.\n");
                blRet = SUCCESS;

            }
        else
            {
                printf("Program execution failed.\n");
                blRet = FAILURE;
            }
        
        return blRet;
    }