#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insert(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp ->data=x;
     temp->next=head;
     head=temp;
}
void print()
{
    struct node* temp=head;
    printf("The linked list is");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    head=NULL;
    int i,n,x;
    printf("Enter the no.of numbers");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter a number");
        scanf("%d",&x);
        insert(x);
        print();
    }
   return 0;
}
