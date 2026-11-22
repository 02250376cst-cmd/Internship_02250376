#include <stdio.h>
#define SIZE 5

/* ---------- Stack ---------- */
typedef struct { int data[SIZE]; int top; } Stack;

void stack_init(Stack *s)    { s->top = -1; }
int  stack_isEmpty(Stack *s) { return s->top == -1; }
int  stack_isFull(Stack *s)  { return s->top == SIZE - 1; }

int stack_push(Stack *s, int v) {
    if (stack_isFull(s)) return 0;
    s->top++;
    s->data[s->top] = v;
    return 1;
}

int stack_pop(Stack *s, int *out) {
    if (stack_isEmpty(s)) return 0;
    *out = s->data[s->top];
    s->top--;
    return 1;
}

int stack_peek(Stack *s, int *out) {
    if (stack_isEmpty(s)) return 0;
    *out = s->data[s->top];
    return 1;
}

/* ---------- Circular queue ---------- */
typedef struct { int data[SIZE]; int front, count; } Queue;

void queue_init(Queue *q)    { q->front = 0; q->count = 0; }
int  queue_isEmpty(Queue *q) { return q->count == 0; }
int  queue_isFull(Queue *q)  { return q->count == SIZE; }

int enqueue(Queue *q, int v) {
    if (queue_isFull(q)) return 0;
    q->data[(q->front + q->count) % SIZE] = v;
    q->count++;
    return 1;
}

int dequeue(Queue *q, int *out) {
    if (queue_isEmpty(q)) return 0;
    *out = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    q->count--;
    return 1;
}

/* ---------- Tests ---------- */
int main(void) {
    Stack s; Queue q; int x;
    stack_init(&s); queue_init(&q);

    printf("pop on empty stack -> %d (expect 0)\n", stack_pop(&s, &x));
    for (int i = 1; i <= SIZE; i++) stack_push(&s, i * 10);
    printf("push on full stack -> %d (expect 0)\n", stack_push(&s, 99));
    stack_pop(&s, &x); printf("pop -> %d (expect 50)\n", x);

    for (int i = 1; i <= SIZE; i++) enqueue(&q, i);
    dequeue(&q, &x); dequeue(&q, &x);
    enqueue(&q, 6); enqueue(&q, 7);   /* forces wrap-around */
    dequeue(&q, &x); printf("dequeue -> %d (expect 3)\n", x);
    return 0;
}