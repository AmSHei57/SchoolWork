#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUMBUCKS 8

struct bucket
{
	int minInitial;
	int maxInitial;
	int numWords;
	struct node* chainHead;
};

struct node
{
	char* string;
	struct node* next;
};

struct bucket list[NUMBUCKS] = 
{
	'a', 'b', 0, NULL,
	'c', 'c', 0, NULL,
	'd', 'f', 0, NULL,
	'g', 'k', 0, NULL,
	'l', 'o', 0, NULL,
	'p', 'r', 0, NULL,
	's', 's', 0, NULL,
	't', 'z', 0, NULL
};

struct node* newNode(char *ch)
{
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->string = (char*)malloc(strlen(ch)+1); 
	n->next = NULL;
	strcpy(n->string,ch);
	return n;
}

void addToBucket(struct node **p, char *inString)
{	
	int i;
	struct node *current = *p;
	for (i = 0; i<NUMBUCKS; i++)
	{
        if (inString[0] >= list[i].minInitial && inString[0] <= list[i].maxInitial)
		{
            current = newNode(inString);
            if (list[i].chainHead == NULL)
		    {
                list[i].chainHead = current;
				list[i].numWords++;
            }
			else
			{
				struct node *q = list[i].chainHead;
				current->next = q;
                list[i].chainHead = current;       
			}
	    }	
	}	
}
									    
struct node *getLastNode(struct node *n)
{
    while (n != NULL && n->next != NULL)
        n = n->next;
    return n;
}



void print()
{
	printf("\n");
	int i;
	for (i = 0; i<NUMBUCKS; i++)
	{
        struct node *p = list[i].chainHead;
        while(p != NULL)
		{
           printf("%s",p->string);
           p = p->next;
        }
    }
}

void freeNode(struct node *f)
{
   if(f == NULL)
   {
       return;
   }
   freeNode(f->next);
   free(f->string);
   free(f);
}

int main()
{
	int i;
	char chars[100];
	struct node *b = NULL;
	
	printf("Type a string of characters to sort:\n");
	while(fgets(chars,100,stdin))
	{
		addToBucket(&b,chars);
	}
	print();
	freeNode(b);
	
	return 0;
}
