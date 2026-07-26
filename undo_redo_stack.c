#include <stdio.h>
#include <string.h>

#define MAX 100


typedef struct  Stack{
    char data[MAX][50];
    int top;
} Stack;

Stack undoStack = {.top = -1};
Stack redoStack = {.top = -1};

int isEmpty(Stack s){
    if(s.top == -1){
        return 1;
    }
    return 0;
}
int isFull(Stack s){
    if(s.top == MAX -1){
        return 1;
    }
    return 0 ;
}

void push(Stack *s,char chracter[50] ){
    if(isFull(*s)){
        return;
    }
    (*s).top++;
    strcpy((*s).data[(*s).top] , chracter);
}
char *pop(Stack *s){ // 10 20 30 40 50
    if(isEmpty(*s)){
        return NULL;
    }
    char *newNum = (*s).data[(*s).top];;
    (*s).top--;
    return newNum;
}

int main(void) {

    push(&undoStack, "Name1");
    push(&redoStack, "Name2");
    push(&undoStack, "Name3");
    push(&redoStack, "Name4");
    push(&undoStack, "Name5");
    
    printf("%s\n", pop(&undoStack));
    printf("%s\n" ,pop(&redoStack));


    return 0;
}
