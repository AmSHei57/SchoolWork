

#include <stdio.h>
#include <string.h>

int main()
{
char character;
int integer;
float floatnum;
char string[50];

char* pcharacter;
int* pinteger;
float* pfloatnum;
char* pstring;

printf("Enter a single character ");
scanf("%c", &character);
printf("Enter an integer ");
scanf("%d", &integer);
printf("Enter a floating point number ");
scanf("%f", &floatnum);
printf("Enter a string ");
scanf("%s", &string);

pcharacter = &character;
pinteger = &integer;
pfloatnum = &floatnum;
pstring = string;

printf("Character: %c\n", *pcharacter);
printf("Integer: %d\n", *pinteger);
printf("String: %s\n", pstring);
printf("Floating point: %f\n", *pfloatnum);

printf("Character: %p\n", pcharacter);
printf("Integer: %p\n", pinteger);
printf("String: %p\n", pstring);
printf("Floating point: %p\n", pfloatnum);
 



 
  return 0;
}
