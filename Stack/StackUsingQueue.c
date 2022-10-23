# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define MAX 5
typedef struct queue {
    int arr[MAX];
    int front;
    int end;
}queue;

queue * init () {
    queue * q = (queue *) malloc(sizeof(queue));
    q->arr[0] = 0;
    q->front = -1;
    q->end = 0;
    return q;
} 

void enqueue (queue ** q, int val) {
    ((*q)->end)++;
    (*q)->arr[(*q)->end] = val;
}

int dequeue (queue ** q) {
    if ((*q)->front == (*q)->end) {
        return INT_MAX;
    }
    ((*q)->front)++;
    return (*q)->arr[(*q)->front];
}

void push (queue ** q, int val) {
    enqueue(q, val);
}
void display(queue * q) {
    printf("\n");
    for (int i = q->front + 1; i <= q->end; i++) {
        printf(" [%d] -> ", q->arr[i]);
    }
}

int pop (queue ** q) {
    queue * store = init();
    int end = (*q)->end;
    for (int i = (*q)->front + 1; i < end; i++) {
        enqueue(&store, dequeue(q));
    }
    int temp = dequeue(q);
    end = store->end;
    for (int i = store->front + 1; i <= end; i++) {
        enqueue(q, dequeue(&store));
    }
    free(store);
    return temp;
}


int main () {
    queue * q = init();
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    printf("\n%d popped ...",pop(&q));
    printf("\n%d popped ...",pop(&q));
    printf("\n%d popped ...",pop(&q));

    return 0;
}
