#include <stdio.h>
#include <stdlib.h> 


/* structure representing a node of a linked list. The node can store term of a polynomial */ 

struct polynode
{
    float coeff;
    int exp;
    struct polynode *link;
};

/*adds a term to a polynomial */ 
void poly_append(struct polynode **q, float x, int y)
{
    struct polynode *temp;
    temp = *q;

    /* creates a new node if the list is empty */
    if (*q == NULL)
    {
        *q=malloc(sizeof(struct polynode));
        temp = *q;
    }
    else
    {
        /*traverse the entire linked list */ 
        while (temp-> link != NULL) 
            temp = temp-> link;
        /*create new nodes at intermediate stages */
        temp -> link = malloc(sizeof(struct polynode)); 
        temp = temp-> link;
    }
    /assign coefficient and exponent/
    temp-> coeff = x;
    temp->exp=y;
    temp-> link = NULL;
}


/* displays the contents of linked list representing a polynomial */ 
void display_poly(struct polynode *q)
{
    
    if(q==NULL){
        return;
    }
    /*traverse till the end of the linked list */ 
    while (q!= NULL)
    {
        printf("%.1f x^%d : ",q-> coeff, q-> exp); 
        q=q-> link;
    }
    // printf("\b\b\b"); /* erases the last colon */
}


/*adds two polynomials */
void poly_add (struct polynode *x, struct polynode *y, struct polynode **s)
{
    struct polynode *z;
    /*if both linked lists are empty */
    if (x == NULL && y == NULL){ 
        return;
    }
    
    /* traverse till one of the list ends */ 
    while (x!= NULL && y != NULL)
    {
    /* create a new node if the list is empty */
        if (*s== NULL)
        {
            *s=malloc(sizeof(struct polynode));
            z = *s;
        }
        /*create new nodes at intermediate stages */
        else
        {
            z-> link = malloc(sizeof(struct polynode)); 
            z=z-> link;
        }
        /* store a term of the larger degree polynomial */
        if (x -> exp <y -> exp)
        {
            z-> coeff = y -> coeff;
            z-> exp = y -> exp;
            y=y-> link; /*go to the next node */
        }
        else
        {
            if (x -> exp >y-> exp)
            {
                z-> coeff=x-> coeff;
                z-> exp = x -> exp;
                x=x-> link; /* go to the next node */
            }
            else
            {
                /* add the coefficients, when exponents are equal */ 
                if (x -> exp == y -> exp)
                {
                    /*assigning the added coefficient */ 
                    z-> coeff=x-> coeff+y-> coeff; 
                    z->exp=x-> exp; 
                    /*go to the next node */
                    x=x-> link;
                    y=y-> link;
                }
            }
        }
    }


    /* assign remaining terms of the first polynomial to the result */
    while (x != NULL)
    {
        if ( *s == NULL)
        {
            *s = malloc(sizeof(struct polynode));
            z=*s;
        } 
        else
        {
            z-> link = malloc(sizeof(struct polynode));
            z=z-> link;
        }
        /* assign coefficient and exponent */
        z-> coeff=x-> coeff; 
        z-> exp = x -> exp;
        x=x-> link; /* go to the next node */
    }
    /* assign remaining terms of the second polynomial to the result */
    while (y != NULL)
    {
        if (*s== NULL)
        {
            *s=malloc(sizeof(struct polynode));

    //page no 13

            z=*s;
        }
        else
        {
            z-> link = malloc(sizeof(struct polynode)); 
            z = z -> link;
        }
        
        /* assign coefficient and exponent */
        z-> coeff = y -> coeff; 
        z-> exp = y -> exp;
        y = y -> link; 
        /* go to the next node */
    }

    z-> link = NULL; /* assign NULL at end of resulting linked list */
}

/*adds a term to the polynomial in the descending order of the exponent */ 
// void padd (float c, int e, struct polynode **s)
// {
//     struct polynode *r, *temp = *s;
//     /* if list is empty or if the node is to be inserted before the first node */ 
//     if (*s == NULL || e > (*s)->exp)
//     {
//         *s = r = malloc(sizeof(struct polynode)); 
//         (*s) -> coeff = c;
//         (*s) -> exp = e;
//         (*s) -> link = temp;

//     }
//     else
//     {
//         /traverse the entire linked list to search the position to insert a new node/
//         while (temp != NULL)
//         {
//             if (temp -> exp == e)
//             {
//                 temp -> coeff += c;
//                 return;
//             }
//             if (temp->exp > e && ( temp -> link -> exp <e ||temp -> link == NULL))
//             {
//                 r = malloc(sizeof(struct polynode));
//                 r -> coeff = c;
//                 r -> exp=e; 
//                 r-> link=temp -> link;
//                 temp -> link = r; 
//                 return;
//             }
//             temp = temp -> link; /* go to next node */
//         }
//         r -> link = NULL;
//         temp -> link = r;
//     }
// }

// /* multiplies the two polynomials */
// void poly_multiply (struct polynode *x, struct polynode *y, struct polynode **m)
// {
//     struct polynode *y1; 
//     float coeff1, exp1;
    
//     y1 = y; /* point to the starting of the second linked list */

//     if (x == NULL && y == NULL) 
//         return;

//     /* if one of the list is empty */ 
//     if (x == NULL) 
//         *m=y; 
//     else
//     {

//         if (y == NULL) 
//             *m = x; 
//         else /*if both linked lists exist */
//         {
//             /* for each term of the first list */
//             while (x!= NULL)
//             {
//                 /* multiply each term of the second linked list with a term of the first linked list */
//                 while (y != NULL)
//                 {
//                     coeff1 = x -> coeff* y -> coeff; 
//                     exp1 = x -> exp + y -> exp; 
//                     y = y -> link;
//                     /* add the new term to the resultant polynomial */ 
//                     padd (coeff1, exp1, m);
//                     poly_append(m,coeff1,exp1);
                    
                    
//                 }
//                 y = y1; /* reposition the pointer to the starting of the second linked list */ 
//                 x=x-> link; /* go to the next node */
//             }
//         }
//     }
// }       



void main(){
    struct polynode *first, *second, *total, *multiply; 
    int i=0;
    first=second=total=multiply=NULL;


    // /* empty linked lists */
    poly_append( &first, 1.4, 5);
    poly_append( &first, 1.5, 4); 
    poly_append( &first, 1.7, 2);
    poly_append( &first, 1.8, 1);
    poly_append( &first, 1.9, 0);

    
    display_poly (first);

    poly_append( &second, 1.5, 6);
    poly_append( &second, 2.5, 5);
    poly_append( &second, -3.5, 4);
    poly_append( &second, 4.5, 3); 
    poly_append(&second, 6.5, 1);

    printf("\n");
    display_poly (second);

    /*draws a dashed horizontal line */

    printf("\n"); 
    while (i++<79)
        printf("-"); 
    printf("\n\n");

    poly_add (first, second, &total);
    display_poly (total); /* displays the resultant polynomial */

    printf("\n");

    poly_multiply(first,second,&multiply);
    display_poly(multiply);
}
