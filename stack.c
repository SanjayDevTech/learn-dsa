#include<stdio.h>
int stack[100];
int N = 100, top=-1;
void push(int data) {
    if(top >= N-1) {
        printf("Stack Overflow");
    } else {
        stack[++top] = data;
    }
}
int isEmpty() {
    if(top <= -1) {
        return 1;
    } else {
        return 0;
    }
}
int isFull() {
    if(top >= N-1) {
        return 1;
    } else {
        return 0;
    }
}
void display() {
    if(isEmpty()) {
        printf("Stack Empty");
        return 0;
    }
    for(int i = top; i >= 0; --i) {
        printf("%d ", stack[i]);
    }
}
int peek() {
    if(isEmpty()) {
        printf("Stack Empty");
        return 0;
    }
    return stack[top];
}
int pop() {
    if(isEmpty()) {
        printf("Stack Underflow");
        return 0;
    }
    return stack[top--];
}