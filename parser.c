#include "parser.h"

STATE_MACHINE_RETURN_VALUE at_command_parse(char char_crt, int unusual_flag){
	if(at_command_data.line_count >= AT_COMMAND_MAX_LINE_SIZE)
	{
		return STATE_MACHINE_READY_TOO_MANY_LINES;
	}	
	// printf("Current node: %d\n",at_command_data.node);
	// printf("at_command_parse character: %c\n",char_crt);
	switch(at_command_data.node)
	{
		
		case 0:
		{	
			if(char_crt == 13)
			{
				at_command_data.node=1;
				return STATE_MACHINE_NOT_READY;
			}
			else if (char_crt == '+')
			{
				at_command_data.node=7;
				return STATE_MACHINE_NOT_READY;
			}
			
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 1:
		{
			if(char_crt == 10)
			{
				at_command_data.node=2;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 2:
		{
			if(char_crt == 'E')
			{
				at_command_data.node=25;
				return STATE_MACHINE_NOT_READY;
			}
			else if(char_crt == '+')
			{
				at_command_data.node=7;
				return STATE_MACHINE_NOT_READY;
			}
			
			else if(char_crt == 'O')
			{
				at_command_data.node=3;
				return STATE_MACHINE_NOT_READY;
			}
			else if(char_crt >= 31 && char_crt <= 126 && unusual_flag == 1)
			{
				at_command_data.node=8;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 3:
		{
			if(char_crt == 'K')
			{
				at_command_data.node=4;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 4:
		{
			if(char_crt == 13)
			{
				at_command_data.node = 5;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 5:
		{
			if(char_crt == 10)
			{
				at_command_data.node=6;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 6:
		{
			return STATE_MACHINE_READY_OK;
		}
		case 7:
		{
			at_command_data.node=8;
			at_command_data.data[at_command_data.line_count][0] = char_crt;
			at_command_data.data[at_command_data.line_count][1] = '\0';
			return STATE_MACHINE_NOT_READY;
		}
		case 8:
		{
			if(char_crt >= 31 && char_crt <= 126)
			{
				at_command_data.node=8;
				//save character
				int i;

				for( i=0; at_command_data.data[at_command_data.line_count][i]!='\0'; i++)
				{}
				if(i<AT_COMMAND_MAX_LINE_SIZE-1)
				{
					at_command_data.data[at_command_data.line_count][i] = char_crt;
					at_command_data.data[at_command_data.line_count][i+1] = '\0';
					//printf("")
					return STATE_MACHINE_NOT_READY;
				}
				else
					return STATE_MACHINE_NOT_READY_ERROR;
				
			}
			else if(char_crt == 13)
			{
				at_command_data.node=18;
				return STATE_MACHINE_NOT_READY;
			}
			else 
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 18:
		{	
			if(char_crt == 10)
			{
				at_command_data.node=19;
				// save string
				at_command_data.line_count++; // de investigat
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 19:
		{	
			
			if(char_crt == '+')
			{
				at_command_data.node=7;
				return STATE_MACHINE_NOT_READY;
			}
			else if(char_crt == 13)
			{
				at_command_data.node=23;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 23:
		{
			if(char_crt == 10)
			{
				at_command_data.node=24;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 24:
		{
			if(char_crt == 'O')
			{
				at_command_data.node=20;
				return STATE_MACHINE_NOT_READY;
			}
			else if(char_crt == 'E'){
				at_command_data.node=25;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 20:
		{
			if(char_crt == 'K')
			{
				at_command_data.node=21;
				return STATE_MACHINE_NOT_READY;
			}
			else 
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 21:
		{
			if(char_crt == 13)
			{
				at_command_data.node=22;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 22:
		{
			if(char_crt == 10)
			{
				at_command_data.node=6;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 25:
		{
			if(char_crt == 'R')
			{
				at_command_data.node=26;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 26:
		{
			if(char_crt == 'R')
			{
				at_command_data.node=27;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 27:
		{
			if(char_crt == 'O')
			{
				at_command_data.node=28;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 28:
		{
			if(char_crt == 'R')
			{
				at_command_data.node=29;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 29:
		{
			if(char_crt == 13)
			{
				at_command_data.node=30;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 30:
		{
			if(char_crt == 10)
			{
				at_command_data.node=31;
				return STATE_MACHINE_NOT_READY;
			}
			else
			{
				return STATE_MACHINE_NOT_READY_ERROR;
			}
			break;
		}
		case 31:
		{
			return STATE_MACHINE_READY_WITH_ERROR;
		}
	}
}