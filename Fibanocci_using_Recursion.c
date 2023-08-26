#include<stdio.h>
int fibb(int n)
{
  if(n==0)
  {
    return 0;
  }
  else if(n==1)
  {
    return 1;
  }
  else{
    return(fibb(n-1)+fibb(n-2));
  }
}
int main()
{
  int n,i;
  printf("Enter the Number upto which number you need fibanocci");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("%d\n",fibb(i));
  }
  return 0;
}
