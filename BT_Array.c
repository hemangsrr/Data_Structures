#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define limit 64
#define level 6
 
int Tree[limit];

void buildTree(int loc, int data)
{
	int value, i=loc;
	int lc = i*2;
	int rc = (i*2)+1;
	char choice[1];
	if(i!=0)
	{
		Tree[i] = data;
		
		printf("\n Node %d has Left Sub Tree ? (Y/N) : ", i);
		scanf("%s", choice);
		
		if(choice[0] == 'y' || choice[0] == 'Y')
		{
			printf("\n Enter data of node : ");
			scanf("%d", &value);
			buildTree(lc, value);
		}
		else
		{
			//Tree[lc] = -1;
			buildTree(0,0);
		}
		
		printf("\n Node %d has Right Sub Tree ? (Y/N) : ", i);
		scanf("%s", choice);
		if(choice[0] == 'y' || choice[0] == 'Y')
		{
			printf("\n Enter data of node : ");
			scanf("%d", &value);
			buildTree(rc, value);
		}
		else
		{
			//Tree[rc] = -1;
			buildTree(0,0);
		}
	}
}

int searchTree(int start, int key)
{
	int i = start;
	if(Tree[i] != key)
	{
		if(2*i <= limit)
		{
			searchTree(2*i, key);
		}
		else
		{
			if((2*i)+1 <= limit)
			{
				searchTree((2*i)+1, key);
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return i;
	}
}

void insertNode(int key, int item)
{
	int l;
	char child[1];
	
	l = searchTree(1,key);
	
	if(l==0)
	{
		printf("\n Search is Unsuccessful : NO INSERTION\n");
		return;
	}
	
	if(Tree[2*l] == 0 || Tree[(2*l)+1] == 0)
	{
		printf("\n Insert as Left Child or Right Child (L/R) ? :  ");
		scanf("%s", child);
		if(child[0] == 'L' || child[0] == 'l')
		{
			if(Tree[2*l] == 0)
				Tree[2*l] = item;
			else
				printf("\n Insertion Not Possible");
			return;
		}
		if(child[0] == 'R' || child[0] == 'r')
		{
			if(Tree[(2*l)+1] == 0)
				Tree[(2*l)+1] = item;
			else
				printf("\n Insertion Not Possible");
			return;
		}
	}
	else
		printf("\n Item cannot be inserted ");
}

void displayTree(int i)
{
	if(i <= limit && Tree[i] != 0)
	{
		printf(" %d ", Tree[i]);
		displayTree(2*i);
		displayTree((2*i)+1);
	}
}
void deleteNode(int Key)
{
	int flag, l;
	flag = 0;
	l = searchTree(1, Key);
	if(l !=0)
	{
		if((Tree[2*l]==0) && (Tree[(2*l)+1]==0))
		{
			flag = 1;
			Tree[l] = 0;
		}
		else
			printf("\n Node is not Leaf node...");
	}
	if(flag == 0)
		printf("\n Node does not Exist : No Deletion");
}


void main()
{
	int option, root, value_k, value_c, value_d;
	
	printf("\n\n Binary Tree Using Array \n\n");
	printf("\n Creating Tree...");
	printf("\n Enter value of Root Node : ");
	scanf("%d", &root);
	buildTree(1, root);
	do
	{
		printf("\n_____---MENU---_____");
		printf("\n 1. Insert");
		printf("\n 2. Delete");
		printf("\n 3. Display");
		printf("\n 4. Exit");
		printf("\n Enter your Choice : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1 : 
				printf("\n Enter Value of Node to Insert : ");
				scanf("%d", &value_c);
				printf("\n Insert after Node of Value : ");
				scanf("%d", &value_k);
				insertNode(value_k, value_c);
				printf("\n Insertion Successfull...");
				break;
			case 2 :
				printf("\n Enter Value of node to delete : ");
				scanf("%d", &value_d);
				deleteNode(value_d);
				printf(" \n Deletion Successfull...");
				break;
			case 3 :
				printf(" \n\n The Tree is : \n");
				displayTree(1);
				break;
			case 4 :
				break;
			default :
				printf("\nInvalid Choice");
		}
	}while(option!=4);
}
