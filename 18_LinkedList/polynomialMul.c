#include <stdio.h>
#include <stdlib.h>

// Note: I have used 'NODE' as the pointer type, 
// and 'struct node' for the structure definition.

struct node { 
    int co;      // Coefficient
    int po;      // Power (Exponent)
    struct node *addr; // Pointer to the next node
}; 

typedef struct node *NODE; 

// Function Prototypes (Good practice in C)
NODE insertend(NODE start, int co, int po);
void display(NODE start);
NODE addterm(NODE res, int co, int po);
NODE multiply(NODE poly1, NODE poly2);

/**
 * @brief Inserts a new term (node) at the end of the polynomial list.
 */
NODE insertend(NODE start, int co, int po) 
{ 
    NODE temp, cur; 
    temp = (NODE)malloc(sizeof(struct node)); 
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->co = co; 
    temp->po = po; 
    temp->addr = NULL; 
    
    if (start == NULL) 
        return temp; 
    
    cur = start; 
    while (cur->addr != NULL) 
        cur = cur->addr; 
    
    cur->addr = temp; 
    return start; 
} 

/**
 * @brief Displays the polynomial in a readable format.
 */
void display(NODE start) 
{ 
    NODE temp; 
    if (start == NULL) 
    {
        printf("\n Polynomial Empty\n"); 
        return;
    }
    
    temp = start; 
    while (temp != NULL) // Loop until the last node
    { 
        // Print the term
        printf("%dx^%d", temp->co, temp->po); 

        // Add '+' sign only if it's not the last term
        if (temp->addr != NULL) 
            printf(" + "); 
        
        temp = temp->addr; 
    } 
    printf("\n"); 
} 

/**
 * @brief Adds a term (co*x^po) to the resultant polynomial (res).
 * If a term with the same power (po) exists, coefficients are added.
 * Otherwise, the term is inserted at the end.
 */
NODE addterm(NODE res, int co, int po) 
{ 
    // Optimization: Don't add terms with zero coefficient
    if (co == 0) return res;

    NODE cur = res; 
    
    // 1. Check for existing power (po) and add coefficients
    while (cur != NULL) 
    { 
        if (cur->po == po) 
        { 
            cur->co = cur->co + co; 
            return res; // Term added, return the head
        } 
        cur = cur->addr; 
    } 
    
    // 2. If the power doesn't exist, insert the new term at the end
    // (Note: The original code had a redundant 'if(cur==NULL)' which is 
    // always true here, as the loop terminates when cur=NULL)
    res = insertend(res, co, po); 
    
    return res; 
} 

/**
 * @brief Multiplies two polynomials (poly1 and poly2) and returns the resultant polynomial.
 */
NODE multiply(NODE poly1, NODE poly2) 
{ 
    NODE p1, p2, res = NULL; 
    
    // The multiplication uses nested loops, similar to manual polynomial multiplication.
    // Every term in poly1 is multiplied by every term in poly2.
    for (p1 = poly1; p1 != NULL; p1 = p1->addr) 
    { 
        for (p2 = poly2; p2 != NULL; p2 = p2->addr) 
        { 
            // New Coefficient = p1.co * p2.co
            int new_co = p1->co * p2->co;
            
            // New Power = p1.po + p2.po (Rule of exponents: x^a * x^b = x^(a+b))
            int new_po = p1->po + p2->po;
            
            // Add the resulting term to the resultant polynomial
            res = addterm(res, new_co, new_po); 
        } 
    } 
    return res; 
} 

int main() 
{ 
    NODE poly1 = NULL, poly2 = NULL, poly_res; 
    int co, po; 
    int i, n, m; 

    // --- Input Polynomial 1 ---
    printf("\n--- Polynomial 1 ---\n");
    printf("Read no of terms of first polynomial: "); 
    scanf("%d", &n); 
    for (i = 1; i <= n; i++) 
    { 
        printf(" Read CO and PO of %d term (e.g., 2 3 for 2x^3): ", i); 
        scanf("%d%d", &co, &po); 
        poly1 = insertend(poly1, co, po); 
    } 
    printf("\nFirst polynomial is: "); 
    display(poly1); 
    
    // --- Input Polynomial 2 ---
    printf("\n--- Polynomial 2 ---\n");
    printf("Read no of terms of second polynomial: "); 
    scanf("%d", &m); 
    for (i = 1; i <= m; i++) 
    { 
        printf(" Read CO and PO of %d term (e.g., 5 1 for 5x^1): ", i); 
        scanf("%d%d", &co, &po); 
        poly2 = insertend(poly2, co, po); 
    } 
    printf("\nSecond polynomial is: "); 
    display(poly2); 
    
    // --- Multiplication ---
    poly_res = multiply(poly1, poly2); 
    printf("\nResultant polynomial is: "); 
    display(poly_res); 
    
    // NOTE: For a complete solution, you should also free the memory 
    // of poly1, poly2, and poly_res before the program exits.
    
    return 0; 
}