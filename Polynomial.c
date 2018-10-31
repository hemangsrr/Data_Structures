// Title : POLYNOMIAL ADDITION
// Name : Hemang Mohan
// Roll No. 28
// 25/09/2018




 
#include<stdio.h>
#include<stdlib.h>
 

typedef struct polynomial {
    int coeff;
    int exp;
    struct polynomial * next;
} poly;
 

void poly_Display(poly *);
void poly_Add(poly **, poly *, poly *);
 

int main(void) {
    int ch;
    do {
        poly * poly1, * poly2, * poly3;
 
        printf("\nCreate 1st expression\n");
        poly_Create(&poly1);
        printf("\n\nStored the 1st expression");
        poly_Display(poly1);
 
        printf("\nCreate 2nd expression\n");
        poly_Create(&poly2);
        printf("\n\nStored the 2nd expression");
        poly_Display(poly2);
 
        poly_Add(&poly3, poly1, poly2);
        poly_Display(poly3);
 
        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}
 
void poly_Create(poly ** node) {
    int flag;
    int coeff, exp;
    poly * tmp_node;
    tmp_node = (poly *) malloc(sizeof(poly)); 
    *node = tmp_node;
    do {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter exp:");
        scanf("%d", &exp);
        tmp_node->exp = exp;
        tmp_node->next = NULL;
 
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        if(flag) {
            tmp_node->next = (poly *) malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
 

void poly_Display(poly * node) {
    printf("\n\n\nThe polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->exp);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}
 

void poly_Add(poly ** result, poly * poly1, poly * poly2) {
    poly * tmp_node;
    tmp_node = (poly *) malloc(sizeof(poly));
    tmp_node->next = NULL;
    *result = tmp_node; 
 

    while(poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            tmp_node->exp = poly1->exp;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            tmp_node->exp = poly2->exp;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            tmp_node->exp = poly1->exp;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
 
        if(poly1 && poly2) {
            tmp_node->next = (poly *) malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
 

    while(poly1 || poly2) {
        tmp_node->next = (poly *) malloc(sizeof(poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(poly1) {
            tmp_node->exp = poly1->exp;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            tmp_node->exp = poly2->exp;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
 
    printf("\n\nAddition Complete");
}
