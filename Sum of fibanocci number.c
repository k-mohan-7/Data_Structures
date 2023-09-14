#include<stdio.h>
int main()
{
    int n,a=0,b=1,c=0,s=0;
    printf("Enter the number upto which you need fibanocii");
    scanf("%d",&n);
    printf("The Fibanocci numbers are:\n");
    while(a<=n)
    {
        c=a+b;
        s+=a;
        printf("%d\n",a);
        a=b;
        b=c;
    
    }
    printf("The sum of fibannoci series upto %d is %d",n,s);
}
