#include<stdio.h>
#include<stdlib.h>
#include "parser.h"
#define MAX_READ 30000
char buffer[MAX_READ], *read;
int test=0,total_lines_count=0;

void print_at_command_data(){
    printf("AT_COMMANDS read:\n");
    for(int i=0;i<at_command_data.line_count;i++)
            printf("%s\n",at_command_data.data[i]);
    // total_lines_count+=at_command_data.line_count;
    // printf("Current line: %d\n",total_lines_count);
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

    int unusual_flags[20];
    int unusual_flags_hardcoded[15]={0,0,0,1,1,0,0,0,0,0,0,1,0,1,0}, position=0; 
    // array hardcodat cu flag-uri de comenzi atipice + pozitia in array
    
    if(argc>=3)
    {
        for(int i=2;i<argc;i++)  // in cazul in care oferim flag-urile ca parametru de comanda
            unusual_flags[i-2]=atoi(argv[i]); // acestea vor fi stocate in array
    }
    else
    {
        for(int i=0;i<15;i++)
            unusual_flags[i]=unusual_flags_hardcoded[i]; // in lipsa parametrilor de comanda
    }                                                    // se copiaza flag-urile hardocate

    char c,ch;
    c= fgetc(fp);
    int ok=1; // flag care opreste programul in caz de eroare neasteptata
    reset_data();
    STATE_MACHINE_RETURN_VALUE status=at_command_parse(c,unusual_flags[position]);
    
    while(ok)
    {   
        //print_at_command_data();
        if(c==EOF || ch==EOF)ok=0;
        switch (status)
        {
            case STATE_MACHINE_NOT_READY:
            { 
                c=fgetc(fp);
                ch=c;
                status=at_command_parse(c,unusual_flags[position]);
                break;
            }
            case STATE_MACHINE_READY_OK:
            {
                
                print_at_command_data();
                printf("Ready OK!\n");
                reset_data();
                //c=fgetc(fp);
                position++; // trecem la flagul pentru comanda urmatoare
                status=at_command_parse(ch,unusual_flags[position]);
                break;
            }

            case STATE_MACHINE_READY_TOO_MANY_LINES:
            {
                print_at_command_data();
                printf("The maximum number of lines is excedeed\n");
                reset_data(); //desi functia da eroare(din cauza depasirii celor 100
                status=at_command_parse(ch,unusual_flags[position]); // de linii) programul continua parsarea
                //ok=0;
                break;
            }

            case STATE_MACHINE_READY_WITH_ERROR:
            {
                print_at_command_data();
                printf(" READY WITH ERROR!!!\n");
                reset_data();
                status=at_command_parse(ch,unusual_flags[position]);
                //ok=0;
                position++;
                break;
            }
            case STATE_MACHINE_NOT_READY_ERROR:
            {
                print_at_command_data();
                printf("Unexpected ERROR!!");
                ok=0;
                break;
            }
        }
    }   
    fclose(fp);
    return 0;
}