#include "parser.h"

STATE_MACHINE_RETURN_VALUE at_command_parse(char* c){
	static u_int8_t node=0;
	u_int8_t lines=0;
	u_int8_t line_size=0;
	u_int8_t data_index;
	char *start=0;
	while(c!=0)
	{	
		if(lines>=AT_COMMAND_MAX_LINES && line_size >= AT_COMMAND_MAX_LINE_SIZE)
		{
			at_command_data.status=STATE_MACHINE_READY_WITH_ERROR;
			return at_command_data.status;
		}
		while(1)
		{	
			char char_crt = *c;
			switch(node)
			{
				case 0:
				{
					if(char_crt == 13)
					{
						node=1;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 1:
				{
					if(char_crt == 10)
					{
						node=2;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 2:
				{
					if(char_crt == 'E')
					{
						node=25;
						c++;
					}
					else if(char_crt == '+')
					{
						node=7;
						start=c;
						c++;
						line_size++;
					}
					else if(char_crt == 'O')
					{
						node=3;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 3:
				{
					if(char_crt == 'K')
					{
						node=4;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 4:
				{
					if(char_crt == 13)
					{
						node = 5;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 5:
				{
					if(char_crt == 10)
					{
						node=6;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 6:
				{
					at_command_data.status=STATE_MACHINE_READY_OK;
					return at_command_data.status;
				}
				case 7:
				{
					node=8;
					break;
				}
				case 8:
				{
					if(char_crt >= 31 && char_crt <= 126)
					{
						node=8;
						c++;
						line_size++;
					}
					else if(char_crt == 13)
					{
						node=18;
						c++;
					}
					else 
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 18:
				{	
					if(char_crt == 10)
					{
						node=19;
						memset(at_command_data.data[data_index],'\0',AT_COMMAND_MAX_LINE_SIZE);
						memcpy(at_command_data.data[data_index++],start,line_size);
						printf("String copied:%s\n",at_command_data.data[data_index-1]);
						line_size=0;
						lines++;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 19:
				{	
					
					if(char_crt == '+')
					{
						node=7;
						start=c;
						c++;
						line_size++;
					}
					else if(char_crt == 13)
					{
						node=23;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 23:
				{
					if(char_crt == 10)
					{
						node=24;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 24:
				{
					if(char_crt == 'O')
					{
						node=20;
						c++;
					}
					else if(char_crt == 'E'){
						node=25;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 20:
				{
					if(char_crt == 'K')
					{
						node=21;
						c++;
					}
					else 
					{
					    at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 21:
				{
					if(char_crt == 13)
					{
						node=22;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 22:
				{
					if(char_crt == 10)
					{
						node=6;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 25:
				{
					if(char_crt == 'R')
					{
						node=26;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 26:
				{
					if(char_crt == 'R')
					{
						node=27;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 27:
				{
					if(char_crt == 'O')
					{
						node=28;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 28:
				{
					if(char_crt == 'R')
					{
						node=29;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 29:
				{
					if(char_crt == 13)
					{
						node=30;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 30:
				{
					if(char_crt == 10)
					{
						node=31;
						c++;
					}
					else
					{
						at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
						return at_command_data.status;
					}
					break;
				}
				case 31:
				{
					at_command_data.status = STATE_MACHINE_READY_WITH_ERROR;
					return at_command_data.status;
				}
			}
			at_command_data.line_count=lines;
		}
	}
	return at_command_data.status;

}