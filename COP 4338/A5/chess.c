
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct square{
	int color;
	int piece;
}board[8][8];

void show()
{
	FILE* read = fopen("board.csv","r");
	if (read == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	char data[100];
	char delim[] = " ,";
	int j;
	int i, num = 0, dcount = 0;
	while(fgets(data,100,read) != NULL)
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
					printf("%s", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						printf(" |");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==2)
				{
					printf("%s", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						printf("  |");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==3)
				{
					printf("%s", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						printf("   |");
						dcount++;
					}
				}
				else if(5-(strlen(ptr))==4)
				{
					printf("%s", ptr);
					ptr = strtok(NULL, delim);
					if(dcount<num)
					{
						printf("    |");
						dcount++;
					}
				}
			}
		}
	}
	fclose(read);
	printf("\n");
}

void mv(char c[2])
{
	FILE* read = fopen("board.csv","r");
	if (read == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	char data[100];
	int p[100];
	char delim[] = " , ";
	int i=0,j=0,count=0,k=0;
	while(fgets(data,100,read) != NULL)
	{
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			p[k] = atoi(ptr);
		    ptr = strtok(NULL, delim);
			k++;
		}
		
	}
	
    k = 0;
	for (i = 0; i < 8; i++) 
	{
        for (j = 0; j < 8; j++) 
		{
            board[i][j].piece = p[k];
			k++;
        }
	}
	
	
	
	//move
	
	
	
	
	
	FILE* write = fopen("board.csv","w");
	
    for (i = 0; i < 8; i++) 
	{
        for (j = 0; j < 8; j++)
		{
            fprintf(write,"%d", board[i][j].piece);
			if(j<7)
			{
				  fprintf(write,",");
			}
        }
        fprintf(write,"\n");
    }
	
	fclose(read); 
	fclose(write); 
}

void cp(char c[2])
{
	FILE* read = fopen("board.csv","r");
	if (read == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	char data[100];
	int p[100];
	char delim[] = " , ";
	int i=0,j=0,count=0,k=0;
	while(fgets(data,100,read) != NULL)
	{
		char *ptr = strtok(data, delim);
		while(ptr != NULL)
		{
			p[k] = atoi(ptr);
		    ptr = strtok(NULL, delim);
			k++;
		}
		
	}
	
    k = 0;
	for (i = 0; i < 8; i++) 
	{
        for (j = 0; j < 8; j++) 
		{
            board[i][j].piece = p[k];
			k++;
        }
	}
	
	
	
	//capture
	
	
	
	
	
	FILE* write = fopen("board.csv","w");
	
    for (i = 0; i < 8; i++) 
	{
        for (j = 0; j < 8; j++)
		{
            fprintf(write,"%d", board[i][j].piece);
			if(j<7)
			{
				  fprintf(write,",");
			}
        }
        fprintf(write,"\n");
    }
	
	fclose(read); 
	fclose(write); 
}
int main(int argc, char *argv[])
{
	int mv_flag = 0, cp_flag = 0, show_flag = 0,i;
    char coor[2];
	
	for(i = 1; i < argc; i++)
	{
		if(strcmp(argv[i],"show") == 0)
		{
			show_flag = 1;
		}
		if(strcmp(argv[i],"mv") == 0)
		{
			mv_flag = 1;
			coor[0] = argv[i+1];
			coor[1] = argv[i+2];
		}
		if(strcmp(argv[i],"cp") == 0)
		{
			cp_flag = 1;
			coor[0] = argv[i+1];
			coor[1] = argv[i+2];
		}
	}
	 
	if(cp_flag == 1)
	{
		cp(coor);
	}
	if(mv_flag == 1)
	{
		mv(coor);
	}
	if(show_flag == 1)
	{
		show();
	}
	return 0;
}
