#include<stdio.h>
int main()
{
  int n,i,j,t;
  int a[100];
  printf("Enter the no.of elements in the array");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the %d number",i);
    scanf("%d",&a[i]);
  }
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      if(a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }
  }
