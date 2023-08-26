#include<stdio.h>
int main()
{
  int n,a=0,b=1,c=0;
  printf("Enter the Number upto which number you need fibanocci");
  scanf("%d",&n);
  while (a<=n)
  {
    c=a+b;
    printf("%d\n",a);
    a=b;
    b=c;
  }
  return 0;
}
