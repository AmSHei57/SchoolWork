#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct node{ char* string; struct node* next; };
struct bucket{ int minInitial; int maxInitial; int numWords; struct node* chainHead; };

#define NUMBUCKS 8
int main()
{

     char word[50];
     int i;
     struct bucket list[NUMBUCKS] =
                         { 'a', 'b', 0,NULL,
                          'c', 'c', 0, NULL,
                          'd', 'f', 0,NULL,
                          'g', 'k', 0, NULL,
                          'l', 'o', 0, NULL,
                          'p', 'r', 0, NULL,
                          's', 's', 0, NULL,
                          't', 'z', 0, NULL };
    while(1){

        printf("Enter a word or quit to exit:");
        scanf("%s",word);
        if (strcmp(word,"quit") == 0)
           break;
        for (i = 0; i<NUMBUCKS; i++){
            if ( word[0] >= list[i].minInitial && word[0] <= list[i].maxInitial){
                 struct node *p = (struct node *)malloc(sizeof(struct node));
                 p->string = (char *)malloc(sizeof(char));
                 p->next = NULL;
                 strcpy(p->string,word);
                 if (list[i].chainHead == NULL){
                    list[i].chainHead = p;
                 }
                 else {
                    struct node *q;
                    q = list[i].chainHead;
                    if (strcmp(word,q->string) <= 0){
                        p->next = q;
                        list[i].chainHead = p;
                    }
                    else {
                       while (q->next->next != NULL && strcmp(word,q->next->string) > 0)
                             q = q->next;
                       if (q->next->next == NULL)
                          q->next->next = p;
                       else {
                          p->next = q->next->next;
                          q->next = p;
                       }
                   }    
                 }
            }
        }
    }
    for (i = 0; i<NUMBUCKS; i++){
        //printf("[%c,%c] : ",list[i].minInitial, list[i].maxInitial);
        struct node *p = list[i].chainHead;
        while(p != NULL){
           printf("%s\n",p->string);
           p = p->next;
        }
        //printf("\n");
    }
   
    return 0;
}
