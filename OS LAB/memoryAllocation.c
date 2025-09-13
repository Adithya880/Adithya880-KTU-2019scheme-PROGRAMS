#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int id,size,allocated,block;
}process;

typedef struct block{
    int id,size,occupied;
}block;

void clearProcess(process p[],int pr)
{
    int i;
    for(i=0;i<pr;i++)
        p[i].allocated=0;
}

void clearBlock(block b[],int n)
{
    int i;
    for(i=0;i<n;i++)
        b[i].occupied=0;
}

void display(process p[],int pr)
{
    int i;
    for(i=0;i<pr;i++)
    {   
        if(p[i].allocated==1)
        printf("\nProcess%d: Block%d\n",p[i].id,p[i].block);
        else
        printf("\nProcess%d: not allocated\n",p[i].id);
    }
}

void firstFit(block b[],process p[],int n,int pr)
{
    int i,j;
    clearProcess(p,pr);
    clearBlock(b,n);
    for(i=0;i<pr;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i].size<=b[j].size && b[j].occupied==0)
            {
              
                b[j].occupied=1;
                p[i].allocated=1;
                p[i].block=b[j].id;
                break;
            }
        }
    }
    display(p,pr);
}

void bestFit(block b[],process p[],int n,int pr)
{
    
    int i,j;
    clearProcess(p,pr);
    clearBlock(b,n);
    for(i=0;i<pr;i++)
    {
        int small=9999999,si=-1;
        for(j=0;j<n;j++)
        {
            if(b[j].size>=p[i].size && b[j].size<small && b[j].occupied==0)
            {
                small =b[j].size;
                si=j;
            }
        }
        if(si !=-1)
        {
                b[si].occupied=1;
                p[i].allocated=1;
                p[i].block=b[si].id;
        }
    }
    display(p,pr);
}

void worstFit(block b[],process p[],int n,int pr)
{
    int i,j;
    clearProcess(p,pr);
    clearBlock(b,n);
    for(i=0;i<pr;i++)
    {
        int large=0,li=-1;
        for(j=0;j<n;j++)
        {
            if(b[j].size>=p[i].size && b[j].size>large && b[j].occupied==0)
            {
                large=b[j].size;
                li=j;
            }
        }
        if(li !=-1)
        {
                b[li].occupied=1;
                p[i].allocated=1;
                p[i].block=b[li].id;
        }
    }
    display(p,pr);
}

void nextFit(block b[],process p[],int n,int pr)
{
    int i,j=0,completed;
    clearProcess(p,pr);
    clearBlock(b,n);
    
        for(i=0;i<pr;i++)
        {   completed=0;
            while(completed<n)
            {
                if(p[i].allocated==0&&b[j].occupied==0&&p[i].size<=b[j].size)
                {
                    p[i].allocated=1;
                    b[j].occupied=1;
                    p[i].block=b[j].id;
                    break;
                }
                completed++;
                j=(j+1)%n;
            }
            
        }
        
    
    display(p,pr);
}

void main()
{
    int i,j,c,pr,n;
    
    printf("\nEnter the no: of blocks of memory:");
    scanf("%d",&n);
    block b[n];
    printf("\nEnter block sizes:");
    for(i=0;i<n;i++){
    scanf("%d",&b[i].size);
    b[i].id=i+1;
    }
    
    printf("\nEnter the no: of processes:");
    scanf("%d",&pr);
    process p[pr];
    printf("\nEnter process sizes:");
    for(i=0;i<pr;i++){
    scanf("%d",&p[i].size);
    p[i].id=i+1;
    }

    do
    {
        printf("\n\nEnter your choice:\n");
        printf("1.First fit\n2.Best fit\n3.Worst fit\n4.Next fit\n5.Exit\n");
        scanf("%d",&c);  
        switch(c)
        {
            case 1: printf("\nFirst fit:\n");
                    firstFit(b,p,n,pr);
                    break;
            
            case 2: printf("\nBest fit:\n");
                    bestFit(b,p,n,pr);
                    break;
                    
            case 3:printf("\nWorst fit:\n");
                    worstFit(b,p,n,pr);
                    break;

            case 4:printf("\nNext fit:\n");
                   nextFit(b,p,n,pr);
                   break;
                    
            case 5:printf("\nExit");exit(0);
            
        }
    }
    while(c!=4);

}






