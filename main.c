#include<stdio.h>
#include<stdlib.h>
#include "parser.h"

int main(int argc, char* argv[]){
    FILE *fp;
    fp=fopen(argv[1],"rb");
    char c;
    while((c=fgetc(fp))!=0)
    {
        STATE_MACHINE_RETURN_VALUE ret = at_command_parse(c);
        if(ret==STATE_MACHINE_READY_OK)
        {
            printf("OK!");
            break;
        }
        else if(ret==STATE_MACHINE_READY_WITH_ERROR)
        {
            printf("Not OK!");
            break;
        }
    }
    fclose(fp);
    return 0;
}