#include<stdio.h>
int ins(int a[],int n)
{
  int i,j,k;
  for(i=1;i<n;i++)
  {
    k=a[i];
    j=i-1;
    while(j>=0&&a[j]>k)
    {
      a[j+1]=a[j];
      j--;
      
    }
    a[j+1]=k;
  }
}
int main()
{
  int n,i,j,t,k,e;
  int a[100];
  printf("Enter the no.of elements in the array");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the %d number",i);
    scanf("%d",&a[i]);
  }
   ins(a,n);
   for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  }
