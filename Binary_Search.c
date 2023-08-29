#include<stdio.h>
int bin(int a[],int l,int r,int k)
{
  if(l>r)
  {
    return-1;
  }
  int m=(l+r)/2;
  if(a[m]==k)
  {
    return m;
  }
  if(k<m)
  {
    return bin(a,l,m-1,k);
  }
  else
  {
  return bin(a,m+1,r,k);
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
    printf("\nEnter the element to be searched");
    scanf("%d",&k);
    e=bin(a,0,n-1,k);
    if(e!=-1)
    {
    printf("\nelement found at %d  position",e+1);
    }
    else
    {
      printf("element is not found");
    }
  }
