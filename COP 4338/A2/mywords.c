#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c = 0; 
	int cflag=0, fflag=0, sflag=0;
	int i = 0, wCount = 0, count = 0, max = 1000; 
	char *fname, *check;
	char string;
	char words[max];
	static char usage[] = "usage: mywords [-cs] [-f substring] filename\n";
	FILE* spCmd;

	while ((c = getopt(argc, argv, "csf:")) != -1)
		switch (c) {
		case 'c':
			cflag = 1;
			break;
		case 's':
			sflag = 1;
			break;
		case 'f':
			fflag = 1;
			fname = optarg;
			break;
		}
	
	if(cflag == 1)
	{
		spCmd = fopen(argv[optind], "r");
		if (spCmd == NULL)
			{
				printf("Error opening file!\n");
				exit(1);
			}
		while ((string=getc(spCmd)) != EOF)
     	{
            if(string == ' ' || string == '\t' || string == '\n' || string == '\0')
			{
				++wCount;
			}
		}

		printf("%d\n",wCount);
		fclose(spCmd);   
	}
	
	
	exit(0);
}
