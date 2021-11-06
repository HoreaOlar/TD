#include<stdio.h>
#include<stdlib.h>
#include "parser.h"
#define MAX_READ 30000
char buffer[MAX_READ];

void print_at_command_data(){
    printf("AT_COMMANDS read:\n");
    for(int i=0;i<at_command_data.line_count;i++)
            printf("%s\n",at_command_data.data[i]);
}
int main(int argc, char* argv[]){
    FILE *fp;
    fp=fopen(argv[1],"rb");
    int n= fread(buffer, 1, MAX_READ, fp);
    buffer[n]='\0';
    int status=at_command_parse(buffer);
    print_at_command_data();
    if(status==2){
        printf("NOT OK!\n");
    }
    else if(status==1)
    {
        printf("OK!\n");
        
    }
    
    

    fclose(fp);
    return 0;
}