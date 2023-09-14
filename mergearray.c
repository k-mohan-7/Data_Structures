#include<stdio.h>
int main()
{
    int n,i,j,k,n1,n2,a1[100],a2[100],m[100];
    printf("Enter the size of 1st array");
    scanf("%d",&n1);
    printf("Enter the size of 2nd array");
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
    {
        printf("Enter the 1st array %d element",i+1);
        scanf("%d",&a1[i]);
    }
    for(i=0;i<n2;i++)
    {
        printf("Enter the 2nd array %d element",i+1);
        scanf("%d",&a2[i]);
    }
    n=n1+n2;
    for(i=0;i<n1;i++)
    {
        m[i]=a1[i];
    }
    for(i=0;i<n1;i++)
    {
        m[n1+i]=a2[i];
    }
    printf("merged array:\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",m[i]);
    }
}
