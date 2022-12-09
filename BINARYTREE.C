#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
};

void insert(struct tree *,int);
void search(struct tree *,int);
void inorder(struct tree *);

void main()
{
    int ch,d,y;
    struct tree *root;
    do
    {
      printf("Enter choice : \n1.Insert \n.2.Search \n3.Inorder traversal");
      scanf("%d",&ch);
      switch(ch);
      {
          case 1:
          printf("\nEnter data");
          scanf("%d",&d);
          insert(root,d);
          break;
          
          case 2:
          printf("\nEnter data to be searched : ");
          scanf("%d",&d);
          search(root,d);
          break;
          
          case 3:
          printf("\nInorder tree traversal");
          inorder(root);
          break;
      }
      printf("Do you wish to continue(0/1)");
      scanf("%d",&y);
    }while(y==1);
    
}
