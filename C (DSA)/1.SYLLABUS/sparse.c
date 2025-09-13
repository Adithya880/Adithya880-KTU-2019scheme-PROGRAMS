#include <stdio.h>

void main()
{
    int x,y,i,j,count=0;
    printf("\nEnter row size:");
    scanf("%d",&x);
    printf("\nEnter column size:");
    scanf("%d",&y);
    int a[x][y];
    printf("\nEnter matrix:\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe matrix is:\n");
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d\t",a[i][j]);
            if(a[i][j]!=0)
               count++;
        }
        printf("\n");
    }
    int s[count+1][3],k=1;
    s[0][0]=x;
    s[0][1]=y;
    s[0][2]=count;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(a[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("\nThe sparse matrix is:\n");
    for(i=0;i<=count;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    
    int ts[count+1][3];
    ts[0][0]=y;
    ts[0][1]=x;
    ts[0][2]=count;
    int temp0,temp1,temp2;
    for(i=1;i<=count;i++)
    {
        ts[i][0]=s[i][1];
        ts[i][1]=s[i][0];
        ts[i][2]=s[i][2];
    }
    
    for(i=1;i<=count;i++)
    {
        for(j=i+1;j<=count;j++)
        {
            if((ts[i][0]>ts[j][0]) || (ts[i][0]==ts[j][0] && ts[i][1]>ts[j][1]))
            {
                temp0=ts[i][0];
                temp1=ts[i][1];
                temp2=ts[i][2];
                
                ts[i][0]=ts[j][0];
                ts[i][1]=ts[j][1];
                ts[i][2]=ts[j][2];
                
                ts[j][0]=temp0;
                ts[j][1]=temp1;
                ts[j][2]=temp2;
            }
        }
    }
    printf("\nTransposed triplet representation:\n");
    for(i=0;i<=count;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",ts[i][j]);
        }
        printf("\n");
    }
    
    int trans[y][x];
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            trans[i][j]=0;
        }
    }
    for(i=1;i<=count;i++)
    {
        trans[ts[i][0]][ts[i][1]]=ts[i][2];
    }
    
    printf("\nTransposed matrix:\n");
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
}