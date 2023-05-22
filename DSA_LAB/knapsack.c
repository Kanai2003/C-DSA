#include<stdio.h>

int main(){
    
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    printf("\nEnter the no. of objects: ");
    scanf("%d", &num);

    printf("\nEnter the wts and profits of each object: \n ");
    for (i = 0; i < num; i++) {  
        printf("\nEnter the weight and profit of object [%d]:",i+1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    float indexs [num];
    
    float x[20],u, tp = 0;
    u = capacity;

    for (i = 0; i < num; i++)
        x[i] = 0.0;

    for (i = 0; i < num; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
            indexs[i] = 1.00;
        }
    }

    if (i < num)
        x[i] = u / weight[i];

    tp = tp + (x[i] * profit[i]);

    indexs[i] = x[i];
    for (i = 0; i < num; i++)
        printf("%f ", indexs[i]);

    printf("\nMaximum profit is: %f\n", tp);

    return 0;
}
