#include <stdio.h>
#include <stdbool.h>

int p, r;
void printTable(int all[][r], int max[][r], int need[][r], int avail[][r]) {
  
    printf("Process\tAllocation\t\tMax\t\t\tNeed\t\t\tAvailable\n");
    for (int i = 0; i < p; i++) {
        printf("P%d\t", i + 1);
        for (int j = 0; j < r; j++) printf("%d  ", all[i][j]); // Allocation
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", max[i][j]); // Max
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", need[i][j]); // Need
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", avail[i][j]); // Available for each process
        printf("\n");
    }
}
void isSafe(int all[][r],int max[][r],int need[][r],int avail[][r])
{
    int i,j;
    int work[r];
    bool finish[p];
    
    for(i=0;i<r;i++)
    work[i]=avail[0][i];
    
    for(i=0;i<p;i++)
    finish[i]=false;
    
    int count=0,safe[p];
    while(count<p)
    {
        bool found=false;
        
        for(i=0;i<p;i++)
        {
            if(!finish[i])
            {   
                bool ce=true;
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        ce=false;
                        break;
                    }
                }
                
                if(ce)
                {
                    for (j = 0; j < r; j++)
                    work[j]+=all[i][j];
                    
                    safe[count++]=i;
                    finish[i]=true;
                    found=true;
                    
                    for (j = 0; j < r; j++)
                    avail[count][j]=work[j];
                }
                
            }
        }
        
        if(!found){
        printf("\nNot safe");
        return;
        }
    }
    printTable(all, max, need, avail);
    // Print safe sequence
    printf("\nSystem is in a safe state.\nSafe Sequence: ");
    for (i = 0; i < p; i++) {
        printf("P%d ", safe[i] + 1);
    }
    printf("\n");
}

void request(int all[][r],int max[][r],int need[][r],int avail[][r])
{
    int req[r],reqid,i,j;
    printf("\nRequest:");
    printf("\nforr process?:");
    scanf("%d",&reqid);
    printf("\nRequest resources:");
    for(i=0;i<r;i++)
    scanf("%d",&req[i]);
    reqid--;
    for(j=0;j<r;j++)
    {
        if(req[j]>need[reqid][j])
        {
            printf("\nRequest cannot be satisfied");
            return;
        }
        if(req[j]>avail[0][j])
        {
            printf("\nRequest cannot be satisfied");
            return;
        }
    }
    
   for(j=0;j<r;j++)
   {
       all[reqid][j]+=req[j];
       avail[0][j]-=req[j];
   }
   for(i=0;i<p;i++)
        for(j=0;j<r;j++)
        need[i][j]=max[i][j]-all[i][j];
   printf("\nIs request safe?\n");
    isSafe(all,max,need,avail);
}

int main() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int inst[r], all[p][r], max[p][r];

    printf("Enter the available resources:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &inst[i]);
    }

    printf("Enter the allocation of resources:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter the maximum demand of resources:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    int sum[r],need[p][r],avail[p+1][r];
    
    for(i=0;i<r;i++)
    sum[i]=0;
    for(i=0;i<r;i++)
        for(j=0;j<p;j++)
        sum[i]+=all[j][i];
        
    for(i=0;i<r;i++)
    avail[0][i]=inst[i]-sum[i];
    
    for(i=0;i<p;i++)
        for(j=0;j<r;j++)
        need[i][j]=max[i][j]-all[i][j];
        
    isSafe(all, max, need,avail);
    request(all,max,need,avail);
    return 0;
}