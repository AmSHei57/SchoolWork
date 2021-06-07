
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int count;
	char *string;
	struct node* left;
	struct node* right;
}node;

node* newNode(char *word)
{
	node* n = (node*)malloc(sizeof(node));
	n->string = (char*)malloc(strlen(word)+1); 
	n->count = 1;
	strcpy(n->string,word);
	n->left = NULL;
	n->right = NULL;
	return n;
}


int main()
{
char b[] = "alice is bob's boss.";
char a[] = "david is a new hire.";
int c = compare(a,b);
int d = strcmp(a,b);
printf("%d\n",c);
printf("%d\n",d);

printf("dhdh\n");
  return 0;
}