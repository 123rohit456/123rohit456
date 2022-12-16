#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

struct abc
{
    char data;
    struct abc *left,*right;
};

struct abc *root;
struct abc *stack[20];
int top=-1;

void operand(char);
void push(struct abc *);
struct abc *pop();
void operator1(char);

void operand(char d)
{
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    push(new);
}

void operator1(char d)
{
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    new->data=d;
    new->right=pop();
    new->left=pop();
}

void push(struct abc *new)
{
    stack[++top]=new;
}

struct abc *pop()
{
    return stack[top--];
}

void main()
{   int i=0;
    char postfix[20]="ab+";
    while(postfix[i]!='\0')
    {
        if(isalnum(postfix[i]))
        {
            operand(postfix[i]);
        }
        else
        {
            operator1(postfix[i]);
            i++;
        }
    }
}
