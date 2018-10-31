#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


struct Tree
{
	int info;
	struct Tree *lchild;
	struct Tree *rchild;
};

typedef struct Tree * node;
/*struct getNode( struct Tree *node)
{
	node = (struct Tree *) malloc(sizeof(struct Tree));
}*/

void buildTree(struct Tree *ptr, int data)
{
	struct Tree *lcptr, *rcptr;
	char choice[1];
	int newl, newr;
	
	if(ptr!=NULL)
	{
		ptr->info = data;
		printf("\n Node has left sub-tree? (Y/N) : ");
		scanf("%s", choice);
		if(choice[0]=='y' || choice[0] == 'Y')
		{
			printf("\n Enter Value of Node : ");
			scanf("%d", &newl);
			lcptr = (struct Tree *) malloc(sizeof(struct Tree));
			ptr->lchild = lcptr;
			buildTree(lcptr, newl);
		}
		else
		{
			lcptr = NULL;
			ptr->lchild = NULL;
			buildTree(lcptr, 0);
		}
		printf("\n Node has right sub-tree? (Y/N) : ");
		scanf("%s", choice);
		if(choice[0]=='y' || choice[0] == 'Y')
		{
			printf("\n Enter Value of Node : ");
			scanf("%d", &newr);
			rcptr = (struct Tree *) malloc(sizeof(struct Tree));
			ptr->rchild = rcptr;
			buildTree(rcptr, newr);
		}
		else
		{
			rcptr = NULL;
			ptr->rchild = NULL;
			buildTree(rcptr, 0);
		}
	}
}

node searchTree(struct Tree *ptr, int key)
{
	if(ptr->info != key)
	{
		if(ptr->lchild != NULL)
		{
			searchTree(ptr->lchild, key);
		}
		else
		{
			if(ptr->rchild != NULL)
			{
				searchTree(ptr->rchild, key);
			}
			else
			{
				return NULL;
			}
		}
	}
	else
	{
		return ptr;
	}
}

void insertNode( struct Tree *root, int key, int item)
{
	struct Tree *ptr;
	int l;
	char child[1];
	
	ptr = searchTree(root, key);
	
	if(ptr==NULL)
	{
		printf("\n Search is Unsuccessful : NO INSERTION\n");
		return;
	}
	
	if( ptr->lchild == NULL || ptr->rchild == NULL)
	{
		printf("\n Insert as Left Child or Right Child (L/R) ? :  ");
		scanf("%s", child);
		if(child[0] == 'L' || child[0] == 'l')
		{
			if(ptr->lchild == NULL)
			{
				ptr->lchild = (struct Tree *) malloc(sizeof(struct Tree));
				ptr->lchild->lchild = NULL;
				ptr->lchild->rchild = NULL;
				ptr->lchild->info = item;
			}
			else
				printf("\n Insertion Not Possible");
			return;
		}
		if(child[0] == 'R' || child[0] == 'r')
		{
			if(ptr->rchild == NULL)
			{
				ptr->rchild = (struct Tree *) malloc(sizeof(struct Tree));
				ptr->rchild->lchild = NULL;
				ptr->rchild->rchild = NULL;
				ptr->rchild->info = item;
			}
			else
				printf("\n Insertion Not Possible");
			return;
		}
	}
	else
		printf("\n Item cannot be inserted ");
}

void deleteNode(struct Tree *root, int Key)
{
	struct Tree *ptr;
	int flag;
	flag = 0;
	ptr = searchTree(root, Key);
	if(ptr != NULL)
	{
		if(ptr->lchild == NULL && ptr->rchild == NULL)
		{
			flag = 1;
			ptr->info = 0;
		}
		else
			printf("\n Node is not Leaf node...");
	}
	if(flag == 0)
		printf("\n Node does not Exist : No Deletion");
}

void displayTree(struct Tree *ptr)
{
	if(ptr != NULL && ptr->info != 0)
	{
		printf(" %d ", ptr->info);
		displayTree(ptr->lchild);
		displayTree(ptr->rchild);
	}
}

void main()
{
	struct Tree *root;
	int value_c, value_k, value_d, value_r, option;
	
	printf("\n\n Creating Tree...\n");
	root=(struct Tree *) malloc (sizeof(struct Tree));
	printf("\n Enter Value for Root Node : ");
	scanf("%d", &value_r);
	buildTree(root, value_r);
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
				insertNode(root, value_k, value_c);
				printf("\n Insertion Successfull...");
				break;
			case 2 :
				printf("\n Enter Value of node to delete : ");
				scanf("%d", &value_d);
				deleteNode(root, value_d);
				printf(" \n Deletion Successfull...");
				break;
			case 3 :
				printf("\n\n Tree is [Pre-Order Traversal] : \n");
				displayTree(root);
				break;
			case 4 :
				break;
			default :
				printf("\nInvalid Choice");
		}
	}while(option!=4);
}
