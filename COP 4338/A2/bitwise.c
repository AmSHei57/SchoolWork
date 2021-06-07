
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{	
	unsigned int uInt;
	char rOrL[100];
	int shift;
	unsigned int temp;
	printf("Type an unsigned integer.\n");
	scanf("%d", &uInt);
	printf("Do you want to shift the to the right or the left?\n");
	scanf("%s",rOrL);
	printf("How many bits do you wanna shift?\n");
	scanf("%d",&shift);
	
	if((strcmp(rOrL,"right")== 0)|| (strcmp(rOrL,"Right")== 0))
	{
		 temp = uInt << shift;
	}
	else if((strcmp(rOrL,"left") == 0) || (strcmp(rOrL,"Left") == 0))
	{
		temp = uInt >> shift;
	}
	
   printf("%d\n",temp);
  
  
  return 0;
}
