#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    
    char *stringMemory = NULL;
    stringMemory = (char*)calloc(4, (sizeof(char)));
    
    //Use a copy of stringMemory to modify the address for each chars
    char *stringMemoryTemp = stringMemory;
    
    char ch = '\0';
    
    //keep the size of stringMemory and increment 4bytes if needed (stringmemory + memoryByte = last address available)
    int memoryByte = (4 *(sizeof(char)));

    
    printf("Please enter one Name: ");
    
    //get the name from the console
    while((ch = getchar()) !='\n'){

        /*keep a gap of 4bytes between the size of stringMemoryStart (malloc) end the total chars entererd by user
        Make a realloc to add 2bytes to stringMemory */
        if(stringMemoryTemp == (stringMemory + memoryByte)){
            
            //Realloc to get more 4bytes in memory
            stringMemory = (char*)realloc(stringMemory, (memoryByte + 4));
            
            //getback to the last address to stringMemoryTemp
            stringMemoryTemp = (stringMemory + memoryByte);
            memoryByte += 4;

        }
        
        //save the char on memory
        *stringMemoryTemp = ch;
        
        //go to next address in memory
        ++stringMemoryTemp;
        
    }
    
    //add Null char at the end of the string
    *stringMemoryTemp = '\0';
    
    //Print the result
    printf("\nThe name you entered is: %s\n", (stringMemory));
    
    /*Clean the memory*/
    free(stringMemory);
    stringMemory = NULL;
    stringMemoryTemp = NULL;
    
    return 0;
}
