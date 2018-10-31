// Title : POLYNOMIAL ADDITION
// Name : Hemang Mohan
// Roll No. 28
// 25/09/2018




 
#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
	int coeff, exp;
	struct node *next;
};
 
struct node *hPtr1, *hPtr2, *hPtr3;

struct node * buildNode(int coeff, int exp) 
{
	struct node *ptr = (struct node *) malloc(sizeof (struct node));
	ptr->coeff = coeff;
	ptr->exp = exp;
	ptr->next = NULL;
	return ptr;
}
 
 
void polynomial_insert(struct node ** myNode, int coeff, int exp) 
{
	struct node *lPtr, *pPtr, *qPtr = *myNode;
	lPtr = buildNode(coeff, exp);
   
 
	if (*myNode == NULL || (*myNode)->exp < exp) 
	{
		*myNode = lPtr;
		(*myNode)->next = qPtr;
		return;
	}
   

	while (qPtr) 
	{
		pPtr = qPtr;
		qPtr = qPtr->next;
		if (!qPtr) 
		{
			pPtr->next = lPtr;
			break;
		} 
		else if ((exp < pPtr->exp) &&       (exp > qPtr->exp))   
		{
			lPtr->next = qPtr;
			pPtr->next = lPtr;
			break;
		}
	}
	return;
}



void polynomial_add(struct node **poly1, int coeff, int exp) 
{
	struct node *x = NULL, *temp = *poly1;
	
	if (*poly1 == NULL || (*poly1)->exp < exp) 
	{
	*poly1 = x = buildNode(coeff, exp);
	(*poly1)->next = temp;
	} 
	else
	{
		while (temp) 
		{
			if (temp->exp == exp) 
			{
				temp->coeff = temp->coeff + coeff;
				return;
			}
    
			if (temp->exp > exp && (!temp->next || temp->next->exp < exp)) 
			{
				x = buildNode(coeff, exp);
				x->next = temp->next;
				temp->next = x;
				return;
			}
			temp = temp->next;
		}
		x->next = NULL;
		temp->next = x;
	}
}
  
  
void polynomial_multiply(struct node **poly1, struct node *poly2, struct node *poly3) 
{
	struct node * temp;
	int coeff, exp;

	temp = poly3;

	if (!poly2 && !poly3)
		return;

	if (!poly2) 
	{
		*poly1 = poly3;
	} 
	else if (!poly3) 
	{
		*poly1 = poly2;
	} 
	else
	{
		while (poly2) 
		{
			while (poly3) 
			{
				coeff = poly2->coeff * poly3->coeff;
				exp = poly2->exp + poly3->exp;
				poly3 = poly3->next;
				
				polynomial_add(poly1, coeff, exp);
			}
			poly3 = temp;
			poly2 = poly2->next;
		}
	}
	return;
}
   

struct node * polynomial_deleteList(struct node *ptr)
{
	struct node *temp;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	return NULL;
}


void display(struct node *ptr) 
{
	int i = 0;
	int flag=0;
	while (ptr) 
	{
		if(ptr->exp != 0 || ptr->exp != 1 )
		{
			if(ptr->coeff > 0 && flag==0 )
			{
				printf("%dx^%d", ptr->coeff,ptr->exp);
				flag++;
			}
			else if (ptr->coeff > 0 && flag==1 )
				printf(" + %dx^%d", ptr->coeff,ptr->exp);
			else if(ptr->coeff < 0)
				printf("%dx^%d", ptr->coeff,ptr->exp);
		}
		else if (ptr->exp == 0)
		{
			if(ptr->coeff > 0 && flag==0 )
			{
				printf("%d", ptr->coeff);
				flag++;
			}
			else if (ptr->coeff > 0 && flag==1 )
				printf(" + %d", ptr->coeff);
			else if(ptr->coeff < 0)
				printf("%d", ptr->coeff);
		}
		else if( ptr->exp == 1 )
		{
			if(ptr->coeff > 0 && flag==0 )
			{
				printf("%dx", ptr->coeff);
				flag++;
			}
			else if (ptr->coeff > 0 && flag==1 )
				printf(" + %dx", ptr->coeff);
			else if(ptr->coeff < 0)
				printf("%dx", ptr->coeff);
		}
		ptr = ptr->next;
		i++;
	}
	printf("\n");
	return;
}
   
void main (int argc, char *argv[]) 
{
	int coeff, exp, i, n;
	int count;
	
	printf("-------------------------------------------------\n");
	printf("       Multiplication of Two Polynomials\n");
	printf("-------------------------------------------------\n\n");
	printf("\nEnter the number of terms in the multiplicand:");
	scanf("%d",&count);
	
	for(i=0;i<count;i++)
	{
		printf("\nEnter the coeff part:");
		scanf("%d", &coeff);
		printf("Enter the exp part:");
		scanf("%d",&exp);
		polynomial_insert(&hPtr1, coeff, exp);
	}
	
	printf("\nEnter the number of terms in the multiplier:");
	scanf("%d",&count);
	
	for(i=0;i<count;i++)
	{
		printf("\nEnter the coeff part:");
		scanf("%d", &coeff);
		printf("Enter the exp part:");
		scanf("%d",&exp);
		polynomial_insert(&hPtr2, coeff, exp);
	}
		
	printf("\n\n-------------------------------------------------\n");
	printf("\nPolynomial Expression 1: ");
	display(hPtr1);
	printf("\nPolynomial Expression 2: ");
	display(hPtr2);
	printf("-------------------------------------------------\n");
	polynomial_multiply(&hPtr3, hPtr1, hPtr2);
     
	printf("\n\nResultant polynomial\n");
	display(hPtr3);
     
	printf("-------------------------------------------------\n\n");
	hPtr1 = polynomial_deleteList(hPtr1);
	hPtr2 = polynomial_deleteList(hPtr2);
	hPtr3 = polynomial_deleteList(hPtr3);

}
