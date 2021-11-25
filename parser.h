#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define AT_COMMAND_MAX_LINES 100
#define AT_COMMAND_MAX_LINE_SIZE 100

typedef struct{
	u_int8_t data[AT_COMMAND_MAX_LINES][AT_COMMAND_MAX_LINE_SIZE];
	u_int8_t line_count;
	u_int8_t node;
}AT_COMMAND_DATA;

AT_COMMAND_DATA at_command_data;

typedef enum{
	STATE_MACHINE_NOT_READY,
	STATE_MACHINE_NOT_READY_ERROR,
	STATE_MACHINE_READY_OK,
	STATE_MACHINE_READY_WITH_ERROR,
	STATE_MACHINE_READY_TOO_MANY_LINES
}STATE_MACHINE_RETURN_VALUE;

STATE_MACHINE_RETURN_VALUE at_command_parse(char char_crt, int unusual_flag);