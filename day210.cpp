#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<iostream>

int main()
{
    int i,j,n=5;
    // printf("\n enter n ");
    // scanf("%d",&n);
    
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=0;j<=n-1;j++)
        {
            if (j>=i)
            {
                printf("* ");
            }
            else
            printf("  ");
        }
        for(j=1;j<=n-i-1;j++)
        {
            printf("* ");
        }
        
    }
    //printf("\n");
    for(i=2;i<n;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if ((i+j)>=(n))
            {
                printf("* ");
            }
            else
            printf("  ");
        }
        for(j=2;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;

   
}