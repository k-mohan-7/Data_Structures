#include<stdio.h>
int main()
{
    int n,i,j,k,l,m;
    int a[100][100],b[100][100],c[100][100];
    printf("enter 2 for 2*2 matrix 3*3 for matrix");
    scanf("%d",&n);
    for(l=0;l<n;l++)
    {
        for(m=0;m<n;m++)
        {
            printf("Enter the %d %d element",l,m);
            scanf("%d",&a[l][m]);
        }
    }
     for(l=0;l<n;l++)
    {
        for(m=0;m<n;m++)
        {
            printf("Enter the %d %d element",l,m);
            scanf("%d",&b[l][m]);
        }
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
         for(k=0;k<n;k++)
         {
            c[i][j]+=((a[i][k])*(b[k][j]));
         }   
        }
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
