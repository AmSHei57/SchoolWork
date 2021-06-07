#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int lflag=0, fflag=0, uflag=0;
	int i = 0; 
	char *fname;
	static char usage[] = "usage: writer [-lu] [-f filename]\n";
	FILE* spCmd;
	char name[] = "Amin Sheikhnia";

	while ((c = getopt(argc, argv, "luf:")) != -1)
		switch (c) {
		case 'l':
			lflag = 1;
			break;
		case 'u':
			uflag = 1;
			break;
		case 'f':
			fflag = 1;
			fname = optarg;
			break;
		}
	
	if((lflag == 1) && (fflag == 0))
	{
		for(i = 0; i < ((int)sizeof(name)); i++)
		{
			name[i] = tolower(name[i]);
		}
		printf("%s\n", name);
	}
	if((uflag == 1) && (fflag == 0))
	{
		for(i = 0; i < ((int)sizeof(name)); i++)
		{
			name[i] = toupper(name[i]);
		}
		printf("%s\n", name);
	}
	if((fflag == 1)&&(lflag==1))
	{
		spCmd = fopen(fname, "w");
		if (spCmd == NULL)
			{
				printf("Error opening file!\n");
				exit(1);
			}
		for(i = 0; i < ((int)sizeof(name)); i++)
		{
			name[i] = tolower(name[i]);
		}
		fprintf(spCmd,"%s\n", name);
		fclose(spCmd);
	}
	if((fflag == 1)&&(uflag==1))
	{
		spCmd = fopen(fname, "w");
		if (spCmd == NULL)
			{
				printf("Error opening file!\n");
				exit(1);
			}
		for(i = 0; i < ((int)sizeof(name)); i++)
		{
			name[i] = toupper(name[i]);
		}
		fprintf(spCmd,"%s\n", name);
		fclose(spCmd);
	}
	if(fflag == 1)
	{
		spCmd = fopen(fname, "w");
		if (spCmd == NULL)
			{
				printf("Error opening file!\n");
				exit(1);
			}
		fprintf(spCmd,"%s\n", name);
		fclose(spCmd);
	}
	if((lflag == 0) && (uflag == 0) && (fflag == 0))
	{
		printf("%s\n", name);
	}
	if((lflag == 1) && (uflag == 1))
	{
		printf("Error: Can't do both");
		exit(1);
	}
	exit(0);
}
