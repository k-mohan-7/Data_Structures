#include<stdio.h>
int main()
{
    int n,i,j,k,a[100];
    printf("Enter no.of Elements in a Set");
    scanf("%d",&n);
    for(i=0;i<n;i++)
{
    printf("Enter the %d element",i+1);
    scanf("%d",&a[i]);
}
printf("Even Numbers:\n");
for(i=0;i<n;i++)
{
    if(a[i]%2==0)
    {
      printf("%d\n",a[i]);
    }
}
printf("Odd Numbers:\n");
for(i=0;i<n;i++)
{
    if(a[i]%2!=0)
    {
      printf("%d\n",a[i]);
    }
}
}
