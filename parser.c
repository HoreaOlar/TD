#include "parser.h"

STATE_MACHINE_RETURN_VALUE at_command_parse(u_int8_t char_crt){
	static u_int8_t stare=0;
	while(1)
	{
		switch(stare)
		{
			case 0:
			{
				if(char_crt == 13)
				{
					stare=1;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 1:
			{
				if(char_crt == 10)
				{
					stare=2;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 2:
			{
				if(char_crt == 'E')
				{
					stare=25;
					return STATE_MACHINE_NOT_READY;
				}
				else if(char_crt == '+')
				{
					stare=7;
					return STATE_MACHINE_NOT_READY;
				}
				else if(char_crt == 'O')
				{
					stare=3;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 3:
			{
				if(char_crt == 'K')
				{
					stare=4;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 4:
			{
				if(char_crt == 13)
				{
					stare = 5;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 5:
			{
				if(char_crt == 10)
				{
					stare=6;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 6:
			{
				return STATE_MACHINE_READY_OK;
			}
			case 7:
			{
				stare=8;
				return STATE_MACHINE_NOT_READY;
			}
			case 8:
			{
				if(char_crt >= 31 && char_crt <= 126)
				{
					stare=8;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					stare=17;
					return STATE_MACHINE_NOT_READY;
				}
			}
			case 17:
			{
				if(char_crt == 13)
				{
					stare=18;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 18:
			{
				if(char_crt == 10)
				{
					stare=19;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 19:
			{
				if(char_crt == '+')
				{
					stare=7;
					return STATE_MACHINE_NOT_READY;
				}
				else if(char_crt == 13)
				{
					stare=23;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 23:
			{
				if(char_crt == 10)
				{
					stare=24;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 24:
			{
				if(char_crt == 'O')
				{
					stare=20;
					return STATE_MACHINE_NOT_READY;
				}
				else if(char_crt == 'E'){
					stare=25;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 20:
			{
				if(char_crt == 'K')
				{
					stare=21;
					return STATE_MACHINE_NOT_READY;
				}
				else 
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 21:
			{
				if(char_crt == 13)
				{
					stare=22;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 22:
			{
				if(char_crt == 10)
				{
					stare=6;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 25:
			{
				if(char_crt == 'R')
				{
					stare=26;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 26:
			{
				if(char_crt == 'R')
				{
					stare=27;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 27:
			{
				if(char_crt == 'O')
				{
					stare=28;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 28:
			{
				if(char_crt == 'R')
				{
					stare=29;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 29:
			{
				if(char_crt == 13)
				{
					stare=30;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 30:
			{
				if(char_crt == 10)
				{
					stare=31;
					return STATE_MACHINE_NOT_READY;
				}
				else
				{
					return STATE_MACHINE_READY_WITH_ERROR;
				}
			}
			case 31:
			{
				return STATE_MACHINE_READY_WITH_ERROR;
			}
		}
	}
}