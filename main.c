#include<stdio.h>
#include<stdlib.h>
#include "parser.h"
#define MAX_READ 30000
char buffer[MAX_READ], *read;
int test=0;

void print_at_command_data(){
    printf("AT_COMMANDS read:\n");
    for(int i=0;i<at_command_data.line_count;i++)
            printf("%s\n",at_command_data.data[i]);
}

void reset_data(){
    //for(int i; i<100; i++)
        //at_command_data.data[i][0]='\0';
    at_command_data.node=0;
    at_command_data.line_count=0;
}
int main(int argc, char* argv[]){
    FILE *fp;
    fp=fopen(argv[1],"rb");
    // int n = fread(buffer, 1, MAX_READ, fp), status;
    // buffer[n] = '\0';
    char c,ch;
    c= fgetc(fp);
    int ok=1;
    reset_data();
    STATE_MACHINE_RETURN_VALUE status=at_command_parse(c);
    
    while(ok)// citim cate un caracter din fisier
    {   
       // print_at_command_data();
        if(c==EOF)ok=0;
        switch (status)
        {
            case STATE_MACHINE_NOT_READY:
            { 
                c=fgetc(fp);
                ch=c;
                status=at_command_parse(c);
                break;
            }
            case STATE_MACHINE_READY_OK:
            {
                printf("Ready OK!\n");
                print_at_command_data();
                reset_data();
                //c=fgetc(fp);
                status=at_command_parse(ch);
                break;
            }
            case STATE_MACHINE_READY_WITH_ERROR:
            {
                printf("ERROR!!!\n");
                ok=0;
                break;
            }
        }
    }   
    fclose(fp);
    return 0;
}