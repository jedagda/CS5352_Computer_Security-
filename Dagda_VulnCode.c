/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    char buffer[12];

    /* The following statement has a buffer overflow problem */ 
    strcpy(buffer, str);
    /*find address of buffer */
   // printf("buffer: 0x%x\n", buffer);

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    
    /*print address */
    //printf("str: 0x%x\n", str);
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);

    printf("Returned Properly\n");
    return 1;
}
