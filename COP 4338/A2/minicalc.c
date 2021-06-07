/*
Name: Amin Sheikhnia, PID: 5771314

This program will take arguments from the command line and will calculate the addition, multiplication, and 
the square of the arguments as the usage details.

usage: minicalc [-a num] [-m num] [-x] value\n

“I affirm that I wrote this program myself without any help form any
other people or sources from the Internet.”
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//Here are the variables necessary to take arguments from the command line
	//to use them in the program.
	extern char *optarg;
	extern int optind;
	int c = 0; 
	int aflag = 0, mflag = 0,xflag = 0,value = 0,num1_value = 0,num2_value = 0;
	float sum = 0.0, multiplied = 0.0, squared=0.0;
	char *num1 = "default_num1";
	char *num2= "default_num2";
	
	//This is the usage which shows what is necessary for the program to work.
	//-a is addition, -m is multiplication, -x is squaring the argument value.
	//Not all arguments are needed to be passed, besides value, in order for
	//the program to run, but at least one is necessary for any outputs.
	static char usage[] = "usage: %s [-a num] [-m num] [-x] value\n";
	
	//Here is where all the values of the command line are taken into 
	//the program.
	while ((c = getopt(argc, argv, "a:m:x")) != -1)
		switch (c) {
		case 'a':
			aflag = 1;
			num1 = optarg;
			break;
		case 'm':
			mflag = 1;
			num2 = optarg;
			break;
		case 'x':
			xflag = 1;
			break;
		}
		
	//These assignments make the characters into integers so that they could be 
	//calculated and displayed.
	value = atoi(argv[optind]);
	num1_value = atoi(num1);
	num2_value = atoi(num2);
	
	//Here is where the validation of if value is in between 1 and 50 inclusive.
	if((value < 1) || (value > 50))
	{
		printf("%d is not between 1 and 50 inclusive. Try again.\n", value);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	
	//Here validates whether there are more than one arguments in the command line.
	if ((optind+1) < argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */
		printf("optind=%d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: There are more than one argument\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	
	//Here when -x is called the value is squared and displayed.
	if(xflag==1)
	{
		squared = value * value;
		printf("%.2f\n", squared);
	}
	
	//Here when -m is called num2 is validated to see if it is between
	//1 and 10 inclusive and than it multiples value by num2 and then displays the result.
	if(mflag==1)
	{
		if((num2_value<1) || (num2_value>10))
		{
			printf("%d is not between 1 and 10 inclusive. Try again.\n", num2_value);
			exit(1);
		}
		else
		{
			multiplied = num2_value * value;
			printf("%.2f\n", multiplied);
		}
	}
	
	//Here when -a is called num1 is validated to see if it is between
	//1 and 500 inclusive and than it adds value by num1 and then displays the result.
	if(aflag==1)
	{
		if((num1_value<1) || (num1_value>500))
		{
			printf("%d is not between 1 and 500 inclusive. Try again.\n", num1_value);
			exit(1);
		}
		else
		{
			sum = num1_value + value;
			printf("%.2f\n", sum);
		}	
	}
	
	//Here value is displayed to show that it was the one that was used to calculate 
	//the values displayed.
	if (optind < argc)	/* these are the arguments after the command-line options */
		for (; optind < argc; optind++)
			printf("value: %s \n", argv[optind]);
	else {
		printf("no values left to process\n");
	}
	exit(0);
}
