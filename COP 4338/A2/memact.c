
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct fraction
 {
	int numerator;
	int denominator;
 }fraction;

int main()
{
fraction *frc;
char* character;
char* string;
int* integer;
float* floatingPoint;
int* arrayInt;
int i;

frc = (fraction*)malloc(sizeof(fraction));
character = (char*)malloc(sizeof(char));
string = (char*)calloc(100,sizeof(char));
integer = (int*)malloc(sizeof(int));
floatingPoint = (float*)malloc(sizeof(float));
arrayInt = (int*)calloc(100,sizeof(int));

(*frc).numerator = 1;
(*frc).denominator = 2;
arrayInt[0]= 3;
arrayInt[1] = 6;
arrayInt[2] = 8;
arrayInt[3] = 12;
arrayInt[4] = 5;
*strcpy(string,"Amin Sheikhnia");
*integer = 100;
*character = 'A';
*floatingPoint = 98.76;

printf("Character: %c\n", *character);
printf("Integer: %d\n", *integer);
printf("String: %s\n", string);
printf("Floating point: %.2f\n", *floatingPoint);
printf("Fraction: %d / %d\n",(*frc).numerator,(*frc).denominator);
printf("Array of integers: ");
for(i = 0; i<5;i++)
{
	printf("%d ", arrayInt[i]);
}
printf("\n");

free(frc);
free(character);
free(string);
free(integer);
free(floatingPoint);
free(arrayInt);

  return 0;
}
