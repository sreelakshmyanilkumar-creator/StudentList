#include <stdio.h>
#include "menu.h"


/* Main function to start the program */
int main()
    {
        int blRet = FALSE;
        
        blRet = menuMain();

        if(blRet == TRUE)
            {
                printf("Program executed successfully.\n");

            }
        else
            {
                printf("Program execution failed.\n");
            }
        
        return blRet;
    }