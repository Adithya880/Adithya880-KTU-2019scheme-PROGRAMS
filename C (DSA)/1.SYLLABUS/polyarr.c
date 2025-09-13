#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct Poly 
{
    int coeff; 
    int exp;
} poly;

typedef struct PolyArray 
{
    poly a[max];
    int size;
} polyarr;


void input(polyarr* pa, int coeff, int exp) 
{
    for (int i = 0; i < pa->size; i++) 
    {
        if (pa->a[i].exp == exp) 
        {
            pa->a[i].coeff += coeff;
            return;
        }
    }
    pa->a[pa->size].coeff = coeff;
    pa->a[pa->size].exp = exp;
    pa->size++;
}

// Function to display a polynomial
void display(polyarr* pa) {
    for (int i = 0; i < pa->size; i++) 
    {   
        if (pa->a[i].exp == 0) 
        {   
            if(pa->a[i].coeff==0)
              printf("");
            else if(pa->a[i].coeff==1)
              printf("x");
            else
              printf("%d", pa->a[i].coeff);
        }
        else if (pa->a[i].exp == 1)
        {   
            if(pa->a[i].coeff==1)
              printf("x");
            else
              printf("%d*x", pa->a[i].coeff);
        } 
        else 
        {   
            if(pa->a[i].coeff==1)
              printf("x^%d",pa->a[i].exp);
              else
            printf("%d*x^%d", pa->a[i].coeff, pa->a[i].exp);
        }

        if (i < pa->size - 1) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials iteratively
void addPoly(polyarr* p1, polyarr* p2, polyarr* result1) {
    int i = 0, j = 0;

    while (i < p1->size && j < p2->size) 
    {
        if (p1->a[i].exp > p2->a[j].exp) 
        {
            input(result1, p1->a[i].coeff, p1->a[i].exp);
            i++;
        }
         else if (p1->a[i].exp < p2->a[j].exp) 
         {
            input(result1, p2->a[j].coeff, p2->a[j].exp);
            j++;
        }
         else 
         { // Same exponent, add coefficients
            input(result1, p1->a[i].coeff + p2->a[j].coeff, p1->a[i].exp);
            i++;
            j++;
        }
    }

    // Add remaining terms from Polynomial 1
    while (i < p1->size) 
    {
        input(result1, p1->a[i].coeff, p1->a[i].exp);
        i++;
    }

    // Add remaining terms from Polynomial 2
    while (j < p2->size) 
    {
        input(result1, p2->a[j].coeff, p2->a[j].exp);
        j++;
    }
}

void multPoly(polyarr* p1,polyarr *p2,polyarr* result2)
{
     for (int i = 0; i < p1->size; i++) 
     {
        for (int j = 0; j < p2->size; j++) 
        {
            input(result2, p1->a[i].coeff * p2->a[j].coeff, p1->a[i].exp + p2->a[j].exp);
        }
    }
}

void main() 
{
    polyarr p1 = {{}, 0};  // Initialize Polynomial 1
    polyarr p2 = {{}, 0};  // Initialize Polynomial 2
    polyarr result1 = {{}, 0};  // Initialize Resultant Polynomial
    polyarr result2 = {{}, 0};
    int n1, n2, coeff, exp;

    // Input for Polynomial 1
    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        input(&p1, coeff, exp);
    }

    // Input for Polynomial 2
    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        input(&p2, coeff, exp);
    }

    // Display the polynomials
    printf("\nPolynomial 1: ");
    display(&p1);

    printf("Polynomial 2: ");
    display(&p2);

    // Add the polynomials iteratively
    addPoly(&p1, &p2, &result1);
    multPoly(&p1,&p2,&result2);
    // Display the result
    printf("\nSum: ");
    display(&result1);
    
    printf("\nProduct: ");
    display(&result2);
}
