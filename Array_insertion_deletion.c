#include<stdio.h>
int main()
{
  int n,i,j,k,c,p,in,del,po;
  int a[100];
  printf("Enter the no.of elements in the array");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the %d number",i);
    scanf("%d",&a[i]);
  }
  printf("Enter 1 for insertion and 2 for deletion");
  scanf("%d",&c);
  if(c==1)
  {
    printf("Enter the position where element to be inserted");
    scanf("%d",&p);
    printf("Enter the number to be inserted");
    scanf("%d",&in);
    for(i=n;i>=p;i--)
    {
      a[i]=a[i-1];
    }
    a[p-1]=in;
     for(i=0;i<=n;i++)
  {
    printf("%d",a[i]);
  }
  }
  if(c==2)
  {
   printf("Enter the position where element to be deleted");
    scanf("%d",&po);
    for(i=po-1;i<n;i++)
    {
      a[i]=a[i+1];
    }
     for(i=0;i<n-1;i++)
  {
    printf("%d",a[i]);
  } 
  }
  }
