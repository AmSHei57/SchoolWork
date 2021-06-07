
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int check(char *a)
{
	if((a[strlen(a)-1] == 'v') && (a[strlen(a)-2]== 's'))
	{
		return 2;
	}
	else if((a[strlen(a)-2] == 'l') && (a[strlen(a)-3]== 't'))
	{
		return 3;
	}
	else if((a[strlen(a)-2] == 'r') && (a[strlen(a)-3]== 't'))
	{
		return 4;
	}
	else if((a[strlen(a)-2] == 'c') && (a[strlen(a)-3]== 't'))
	{
		return 5;
	}
	else
	{
		return 0;
	}
}

void csvtotl5(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " ,";
	int j;
	int i, num = 0, dcount = 0;
	while(fgets(data,100,input) != NULL)
	{
		for(i=0;i<strlen(data);i++)		
		{
			if(data[i]==',')
			{
				num++;
			}
		}
		
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			if(strlen(ptr)<5)
			{
				if(5-(strlen(ptr))==1)
				{
					fprintf(output,"%s ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==2)
				{
					fprintf(output,"%s  ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==3)
				{
					fprintf(output,"%s   ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==4)
				{
					fprintf(output,"%s    ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
			}
			else if(strlen(ptr)>5)
			{
				int dif = strlen(ptr) - 5;
				fprintf(output,"%s", (ptr+dif));
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
				
			}
			else
			{
				fprintf(output,"%s", ptr);
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
			}
		}
	}
}
void csvtotr9(FILE *input, FILE *output)
{
	
}
void csvtotc9(FILE *input, FILE *output)
{

}
void tl5tocsv(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " | ";
	int j;
	while(fgets(data,100,input) != NULL)
	{
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			fprintf(output,"%s,", ptr);
		    ptr = strtok(NULL, delim);
		}
	}
}
void tl5totr9(FILE *input, FILE *output)
{
	
}
void tl5totc9(FILE *input, FILE *output)
{

}
void tr9tocsv(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " | ";
	int j;
	while(fgets(data,100,input) != NULL)
	{
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			fprintf(output,"%s,", ptr);
		    ptr = strtok(NULL, delim);
		}
	}
}
void tr9totl5(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " |";
	int j;
	int i, num = 0, dcount = 0;
	while(fgets(data,100,input) != NULL)
	{
		for(i=0;i<strlen(data);i++)		
		{
			if(data[i]==',')
			{
				num++;
			}
		}
		
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			if(strlen(ptr)<5)
			{
				if(5-(strlen(ptr))==1)
				{
					fprintf(output,"%s ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==2)
				{
					fprintf(output,"%s  ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==3)
				{
					fprintf(output,"%s   ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==4)
				{
					fprintf(output,"%s    ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
			}
			else if(strlen(ptr)>5)
			{
				int dif = strlen(ptr) - 5;
				fprintf(output,"%s", (ptr+dif));
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
				
			}
			else
			{
				fprintf(output,"%s", ptr);
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
			}
		}
	}
}
void tr9totc9(FILE *input, FILE *output)
{

}
void tc9tocsv(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " | ";
	int j;
	while(fgets(data,100,input) != NULL)
	{
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			fprintf(output,"%s,", ptr);
		    ptr = strtok(NULL, delim);
		}
	}
}
void tc9totl5(FILE *input, FILE *output)
{
	char data[100];
	char delim[] = " |";
	int j;
	int i, num = 0, dcount = 0;
	while(fgets(data,100,input) != NULL)
	{
		for(i=0;i<strlen(data);i++)		
		{
			if(data[i]==',')
			{
				num++;
			}
		}
		
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			if(strlen(ptr)<5)
			{
				if(5-(strlen(ptr))==1)
				{
					fprintf(output,"%s ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==2)
				{
					fprintf(output,"%s  ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==3)
				{
					fprintf(output,"%s   ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==4)
				{
					fprintf(output,"%s    ", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						fprintf(output,"|");
						dcount++;
					}
				}
			}
			else if(strlen(ptr)>5)
			{
				int dif = strlen(ptr) - 5;
				fprintf(output,"%s", (ptr+dif));
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
				
			}
			else
			{
				fprintf(output,"%s", ptr);
				ptr = strtok(NULL, delim);
				if(dcount<num)
				{
					fprintf(output,"|");
					dcount++;
				}
			}
		}
	}
}
void tc9totr9(FILE *input, FILE *output)
{

}
int main(int argc, char *argv[])
{
char* in[100];
char* out[100];
char* iaddress;
char* oaddress;

iaddress = argv[1];
FILE* input = fopen(iaddress,"r");
if (input == NULL)
{
	printf("Error opening file!\n");
	exit(1);
}
oaddress = argv[2];
FILE* output = fopen(oaddress, "w");

if((check(iaddress)==2)&&(check(oaddress)==3))
{
	csvtotl5(input,output);
}
else if((check(iaddress)==2)&&(check(oaddress)==4))
{
	csvtotr9(input,output);
}
else if((check(iaddress)==2)&&(check(oaddress)==5))
{
	csvtotc9(input,output);
}
else if((check(iaddress)==3)&&(check(oaddress)==2))
{
	tl5tocsv(input,output);
}
else if((check(iaddress)==3)&&(check(oaddress)==4))
{
	tl5totr9(input,output);
}
else if((check(iaddress)==3)&&(check(oaddress)==5))
{
	tl5totc9(input,output);
}
else if((check(iaddress)==4)&&(check(oaddress)==2))
{
	tr9tocsv(input,output);
}
else if((check(iaddress)==4)&&(check(oaddress)==3))
{
	tr9totl5(input,output);
}
else if((check(iaddress)==4)&&(check(oaddress)==5))
{
	tr9totc9(input,output);
}
else if((check(iaddress)==5)&&(check(oaddress)==2))
{
	tc9tocsv(input,output);
}
else if((check(iaddress)==5)&&(check(oaddress)==3))
{
	tc9totl5(input,output);
}
else if((check(iaddress)==5)&&(check(oaddress)==4))
{
	tc9totr9(input,output);
}

fclose(input);
fclose(output);

return 0;
}
