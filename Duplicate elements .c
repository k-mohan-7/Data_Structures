#include<stdio.h>
int main()
{
    int n,i,s,t,j,c,e,a[100];
    printf("Enter the number of elements required");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("entere %d num",i+1);
        scanf("%d",&a[i]);
    }
    printf("The Duplicate elements are:\n");
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                c++;
            }
        }
        if(c>=1)
        {
            printf("%d\n",a[i]);
        }
    }
   
}
