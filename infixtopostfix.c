#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
struct stack
{
    char ele;
    struct stack *next;
};

void push(int);
int pop();


struct stack *top =NULL;

int main()
{
    char infix[20],postfix[20];
    int i=0,j=0;
   
    printf("enter infix expression");
    scanf("%s",infix);
   
    while(infix[i] !='\0')
    {
        if(isalnum(infix[i]))
        postfix[j++] = infix[i];
        else
        {
            if(top ==NULL)
            push(infix[i]);
           
            else
            {
                while(top != NULL && (precedence(top->ele)>= precedence(infix[i])))
                postfix[j++]=pop();
                push(infix[i]);
            }
        }
        i++;
    }
    while(top != NULL)
    postfix[j++] = pop();
   
    postfix[j] ='\0';
    printf("%s",postfix);
   
    return 0;
}

int precedence(char x)
{
    switch(x)
    {
        case '^': return 4;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 0;
       
        default: return 0;
    }
}

void push(int x)
{
    int item;
    struct stack *temp;
    temp=(struct stack *)malloc(sizeof(struct stack));
    temp->ele =x;
   
    if(top ==NULL)
    {
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

int pop()
{
    struct stack *tmp;
    char item;
   
    if(top ==NULL)
    printf("empty stack");
   
    else if(top->next == NULL)
    {
        tmp = top;
        item = top->ele;
        top = NULL;
        free(tmp);
    }
    else
    {
        tmp =top;
        item = top->ele;
        top = top->next;
        free(tmp);
    }
   
    return item;
}

