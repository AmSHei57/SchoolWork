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
	struct node *current;
	current = *p;
	 for (i = 0; i<NUMBUCKS; i++)
	 {
            if (inString[0] >= list[i].minInitial && inString[0] <= list[i].maxInitial)
			{
                current = newNode(inString);
                if (list[i].chainHead == NULL)
				{
                   list[i].chainHead = current;
                }
                else 
				{
                    struct node *q;
                    q = list[i].chainHead;
                    if (strcmp(inString,q->string) <= 0)
				    {
                        current->next = q;
                        list[i].chainHead = current;
                    }
                    else 
					{
                       while (q->next->next != NULL && strcmp(inString,q->next->string) > 0)
                             q = q->next;
                       if (q->next->next == NULL)
                          q->next->next = current;
                       else 
					   {
                          current->next = q->next->next;
                          q->next = current;
                       }
                   }    
                 }
            }
        }
	
}

void print()
{
	int i;
	for (i = 0; i<NUMBUCKS; i++)
	{
        //printf("[%c,%c] : ",list[i].minInitial, list[i].maxInitial);
        struct node *p = list[i].chainHead;
        while(p != NULL){
           printf("%s",p->string);
           p = p->next;
        }
        //printf("\n");
    }
}

void freeNode(struct node *f)
{
   if(f == NULL)
   {
       return;
   }
   freeNode(f->next);
   freeNode(f->string);
   freeNode(f);
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
