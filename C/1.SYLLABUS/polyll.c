#include <stdio.h>
#include <stdlib.h>

typedef struct Poly {
    struct Poly* next;
    int coeff;
    int exp;
} poly;

poly* getnode(int coeff, int exp) {
    poly* new = (poly*)malloc(sizeof(poly));
    if (!new) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new->coeff = coeff;
    new->exp = exp;
    new->next = NULL;
    return new;
}

poly* input() {
    int n, coeff, exp;
    poly *temp, *last = NULL, *current = NULL;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient of term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &exp);
        
        temp = getnode(coeff, exp);
        
        if (current == NULL)
            current = temp;
        else
            last->next = temp;
        
        last = temp;
    }
    
    return current;
}

poly* add(poly* p1, poly* p2) {
    poly *result = NULL, *last = NULL, *temp;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            temp = getnode(p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            temp = getnode(p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            temp = getnode(p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if (result == NULL)
            result = temp;
        else
            last->next = temp;
        
        last = temp;
    }
    
    while (p1 != NULL) {
        temp = getnode(p1->coeff, p1->exp);
        if (result == NULL)
            result = temp;
        else
            last->next = temp;
        last = temp;
        p1 = p1->next;
    }
    
    while (p2 != NULL) {
        temp = getnode(p2->coeff, p2->exp);
        if (result == NULL)
            result = temp;
        else
            last->next = temp;
        last = temp;
        p2 = p2->next;
    }
    
    return result;
}

poly* multiply(poly* p1, poly* p2) {
    poly *result = NULL, *temp1 = p1, *temp2;
    
    while (temp1 != NULL) {
        temp2 = p2;
        while (temp2 != NULL) {
            // Insert product term into result
            poly* temp = getnode(temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            result = add(result, temp);
            
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    
    return result;
}

void display(poly* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    poly* temp = head;
    while (temp != NULL) {
        if (temp->coeff == 1) {
            if (temp->exp == 0) {
                printf("1");
            } else if (temp->exp == 1) {
                printf("x");
            } else {
                printf("x^%d", temp->exp);
            }
        }
        else if (temp->coeff == -1) {
            if (temp->exp == 0) {
                printf("-1");
            } else if (temp->exp == 1) {
                printf("-x");
            } else {
                printf("-x^%d", temp->exp);
            }
        }
        else {
            if (temp->exp == 0) {
                printf("%d", temp->coeff);
            } else if (temp->exp == 1) {
                printf("%dx", temp->coeff);
            } else{
                printf("%dx^%d", temp->coeff, temp->exp);
            }
        }

        if (temp->next != NULL && temp->next->coeff > 0) {
            printf(" + ");
        }
        temp = temp->next;
    }

    printf("\n");
}


int main() {
    poly *p1, *p2, *resultAdd, *resultMul;
    
    printf("Enter first polynomial:\n");
    p1 = input();
    
    printf("Enter second polynomial:\n");
    p2 = input();
    
    printf("First Polynomial: ");
    display(p1);
    
    printf("Second Polynomial: ");
    display(p2);
    
    resultAdd = add(p1, p2);
    printf("Sum of Polynomials: ");
    display(resultAdd);
    
    resultMul = multiply(p1, p2);
    printf("Product of Polynomials: ");
    display(resultMul);
    
    return 0;
}

