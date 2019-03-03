#include <stdio.h>
#include <stdlib.h>//put condn if two tablets area equal take tABLET with less cost

int main()
{
    int n,b,d,i,k,j;
    printf("Test cases : ");
    scanf("%d",&n);
    int r[n];
    for( k=0;k<n;k++)
   {
       r[k]=0;
    printf("Budget : ");
    scanf("%d",&b);
    printf("Number of different tablets : ");
    scanf("%d",&d);
    int a[d][3];
        for(i=0;i<d;i++)
    {
         printf("enter tablet no %d width, height and price : ",i+1);
         for(j=0;j<3;j++)
         {
                 scanf("%d",&a[i][j]);
         }
         if(a[i][2]<=b)
         {
                if(r[k]<(a[i][0]*a[i][1]))
                    r[k]=a[i][0]*a[i][1];

         }
         printf("\n");
    }
      }
    for(i=0;i<n;i++)
    {
        if(r[i]>0)
            printf("%d\n",r[i]);
        else
            printf("can't buy a tablet\n");
    }
    return 0;
}
