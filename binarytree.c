#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
};

struct tree * create(int);
void inorder(struct tree *);

struct tree *create(int d)
{
    struct tree *new;
    new=(struct tree *)malloc(sizeof(struct tree));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void inorder(struct tree *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d,",root->data);
    inorder(root->right);
}

void main()
{
    struct tree *root,*n1,*n2,*n3,*n4,*n5,*n6;
    root=create(1);
    n1=create(2);
    n2=create(3);
    n3=create(4);
    n4=create(5);
    n5=create(6);
    n6=create(7);
    
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4;
    n3->left=n6;
    n2->left=n5;
    
    printf("Inorder tree traversal : ");
    inorder(root);
    
}
