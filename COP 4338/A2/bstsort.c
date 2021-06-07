/*
Name: Amin Sheikhnia, PID: 5771314

This program will take arguments from the command line or a file and will put them into a 
BST, thus sorting them. After that the arguments are either printed to the screen or to a file.

usage:  bstsort [-c] [-o output_file_name] [input_file_name]

“I affirm that I wrote this program myself without any help form any
other people or sources from the Internet.”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This struct is the node of the BSTSort.
//This structure contains a string and a left and right node.
typedef struct node
{
	int count;
	char *string;
	struct node* left;
	struct node* right;
}node;

//This funtcion makes a new node. It allocates memory for the new node
//and its contents. It then initializes the nodes to NULL;
node* newNode(char *word)
{
	node* n = (node*)malloc(sizeof(node));
	n->string = (char*)malloc(strlen(word)+1); 
	n->left = NULL;
	n->right = NULL;
	n->count = 1;
	strcpy(n->string,word);
	return n;
}

//This function adds a string to the BST. If the program is asked to do case sensitive,
//this will make it so that case matters where the string will go in the tree.
void addToBST(node **root, char word[100] ,int caseSensitive)
{
	node *current;
	int compareWords;
	char lower[100];
	int i;
	
	if(*root == NULL)
	{
		*root = newNode(word);
	}
	else
	{
		current = *root;
		while(current != NULL)
		{
			if(caseSensitive == 0)
			{
				for(i = 0; i < strlen(word);i++)
				{
					lower[i] = tolower(word[i]); 
				}
				compareWords = compare(lower,current->string);
			}
			else
			{
				compareWords = compare(word,current->string);
			}
		
			if(compareWords == 0)
			{
				current->count++;
				return;
			}
			else if(compareWords < 0)
			{
				if(current->left == NULL)
				{
					current->left = newNode(word);
					return;
				}
				current = current->left;
			}
			else
			{
				if(current->right == NULL)
				{
					current->right = newNode(word);
					return;
				}
				current = current->right;
			}
		}
	}	
}

//This function prints the BST in order.
//Meaning it goes all the way to the left of the tree, prints and then prints all the way back to the root
//than it goes all the way to right and starts printing back from there.
void printInOrder(FILE *output, node *n)
{
   if(n == NULL)
   {
       return;
   }
   printInOrder(output, n->left);
   fprintf(output, "%s count:%d\n", n->string, n->count);
   printInOrder(output, n->right);
}

//This function frees each of the nodes and the strings within them.
void freeNodeString(node *root)
{
   if(root == NULL)
   {
       return;
   }
   freeNodeString(root->left);
   freeNodeString(root->right);
   free(root->string);
   free(root);
}

//This function is a custom strcmp method.	
//Compares 2 strings and gives a 0 if the same,
//a -1 when the second is greater than the first,
//and a 1 when the second is less than the first.
int compare(char *s1, char *s2)
{
    int i = 0;   
    char str1;
	char str2;  
	
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        str1 = s1[i];     
        str2 = s2[i];	  
		
        if(str1 != str2)
        {
			return str1-str2;
            i++;     
        }
	
        if(s1[i] == '\0' && s2 != '\0')
        {
			return s2[i];
        }
        else if(s1 != '\0' && s2 == '\0')
        { 
			return s1[i];
        }
        else  
        {
            return 0;  
        }
    }
}

int main(int argc, char **argv)
{
	//Here are the variables necessary to take arguments from the command line
	//to use them in the program.
	extern char *optarg;
	extern int optind;
	int c = 0; 
	int cflag = 0, oflag = 0;
	node *root = NULL;
	FILE* input = stdin;
	FILE* output = stdout;
	char *inputFName;
	char *outputFName;
	char string[100];
	
	//This is the usage of the program used to dictate how the command line looks.
	static char usage[] = " bstsort [-c] [-o output_file_name] [input_file_name]\n";
	
	//This switch statement shows whether a field has been used or not.
	while ((c = getopt(argc, argv, "co:")) != -1)
		switch (c) 
		{
		case 'c':
			cflag = 1;
			break;
		case 'o':
			oflag = 1;
			outputFName = optarg;
			break;
		}
	inputFName = argv[optind];
	
	//This if statement is for when there is no output file.
	//It can get from stdin or a file and can print to stdout;
	if(oflag == 0)
	{
		if(inputFName == NULL)
		{
			printf("Execution of the program ends with ctrl­-d\n");
			while(fgets(string,100,input))
			{
				addToBST(&root,string,cflag);
			}
			printInOrder(output,root);
			freeNodeString(root);
		}
		else
		{
			input = fopen(inputFName, "r");
			while (fgets(string,100,input) != NULL)
     		{
				addToBST(&root,string,cflag);
			}
			fclose(input);
			printInOrder(output,root);
			freeNodeString(root);
		}
	}
	
	//This if statement is for when there is an output file.
	//It can get from stdin or a file and can print to stdout or file;
	if(oflag == 1)
	{
		output = fopen(outputFName, "w");
		if(output == NULL)
		{
			printf("There is not output file");
			fprintf(stderr, usage, argv[0]);
			exit(1);
		}
		if(inputFName == NULL)
		{
			printf("Execution of the program ends with ctrl­-d\n");
			while(fgets(string,100,input))
			{
				addToBST(&root,string,cflag);
			}
			printInOrder(output,root);
			fclose(output);
			freeNodeString(root);
		}
		else
		{
			input = fopen(inputFName, "r");
			while (fgets(string,100,input) != NULL)
     		{
				addToBST(&root,string,cflag);
			}
			fclose(input);
			printInOrder(output,root);
			fclose(output);
			freeNodeString(root);
		}
	}
	return 0;
}

