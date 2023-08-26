#include<stdio.h>
int main()
{
  int n,i,f=1;
  printf("Enter the Number upto which number you need fibanocci");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    f*=i;
  }
  printf("%d",f);
  return 0;
}
