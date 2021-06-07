/*
 * The first C program.
 *
 * Compile (and link) the code using: 
 *    % gcc helloworld.c -o helloworld
 * Run it as:
 *    % ./helloworld
 */

#include <stdio.h>
#include <string.h>
struct DOB
	{
		int month;
		int day;
		int year;
	};
struct STUDENT
 {
	char firstName[30];
	char lastName[30];
	char studentID[7];
	struct DOB dob;
	int studentStanding;
	float currentGpa;
 };
int main()
{
 
 struct STUDENT stu;
 strcpy(stu.firstName,"Amin");
 strcpy(stu.lastName,"Sheikhnia");
 strcpy(stu.studentID,"5771314");
 stu.dob.month = 10;
 stu.dob.day = 8;
 stu.dob.year = 1998;
 stu.studentStanding = 3;
 stu.currentGpa = 3.3;
 struct STUDENT* ptr;
 ptr = &stu;

 
 printf("Direct Selection");
 printf("Name: %s %s\n", stu.firstName, stu.lastName);
 printf("Studnet ID: %s\n", stu.studentID);
 printf("DOB %d/%d/%d\n", stu.dob.month,stu.dob.day,stu.dob.year);
 if(stu.studentStanding == 1)
 {
	 printf("Standing: Freshman\n");
 }
 else if(stu.studentStanding == 2)
 {
	 printf("Standing: Softmore\n");
 }
  else if(stu.studentStanding == 3)
 {
	 printf("Standing: Junior\n");
 }
 else if(stu.studentStanding == 4)
 {
	 printf("Standing: Senior\n");
 }
 printf("GPA: %.2f\n", stu.currentGpa);
 
 printf("\n");
 printf("Indirect Selection");
 printf("Name: %s %s\n", ptr->firstName, ptr->lastName);
 printf("Studnet ID: %s\n", ptr->studentID);
 printf("DOB %d/%d/%d\n", ptr->dob.month,ptr->dob.day,ptr->dob.year);
 if(ptr->studentStanding == 1)
 {
	 printf("Standing: Freshman\n");
 }
 else if(ptr->studentStanding == 2)
 {
	 printf("Standing: Softmore\n");
 }
  else if(ptr->studentStanding == 3)
 {
	 printf("Standing: Junior\n");
 }
 else if(ptr->studentStanding == 4)
 {
	 printf("Standing: Senior\n");
 }
 printf("GPA: %.2f\n", ptr->currentGpa);
 
 
  return 0;
}
