#include <stdio.h>
#include <mm_malloc.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack,*Stack;

int InitStack(Stack S)
{
    S->base = (int *)malloc(STACK_INIT_SIZE* sizeof(int));
    if(!S->base)
        return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}

int Push(Stack S,int e)
{
    if (S->top-S->base>=S->stacksize)
    {
        S->base = (int *)realloc(S->base,(S->stacksize+
                                          STACKINCREMENT)* sizeof(int ));
        if(!S->base)
            return 0;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++=e;
    return 1;
}

int Pop(Stack S,int &e)
{
    if (S->top == S->base)
        return 0;
    e=*--S->top;
    return 1;
}

int GetTop(Stack S,int &e)
{
    if (S->top == S->base)
        return 0;
    e = *(S->top-1);
    return 1;
}

int main()
{
    Stack new_s;
    int element;
    int i;
    if(!InitStack(new_s))
        exit(1);
    for(i=0;i<10;i++)
        Push(new_s,i);
    while(GetTop(new_s,element) == 1)
    {
        Pop(new_s,element);
        printf("%3d",element);
    }
    printf("\n");
    return 1;
}
