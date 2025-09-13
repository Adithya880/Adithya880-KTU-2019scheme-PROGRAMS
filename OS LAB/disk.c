#include <stdio.h>
#include <stdlib.h>

void fcfs(int req[], int n, int h) {
    int i, thm = 0, head = h;
    for (i = 0; i < n; i++) {
        thm += abs(head - req[i]);
        
        head = req[i];
        if(i==0)
        printf("%d-> ",h);
        printf("%d-> ",req[i]);
    }
    printf("\nTotal Head Movement: %d\n", thm);
}

void sorting(int a[],int n)
{
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int search(int a[],int n,int h)
{
       for(int i=0;i<n;i++){
           if(a[i]==h)
           return i;
       }
       return -1;
}

void scan(int req[],int n,int h,int m)
{
    int i,pos,c,d,thm=0;
    int temp[100]; // large enough buffer
    for (i = 0; i < n; i++) 
    temp[i] = req[i];
    temp[n] = 0;
    temp[n+1] = h;
    temp[n+2] = m - 1;
    n+=3;
    sorting(temp,n);
    pos=search(temp,n,h);
    printf("\n1.Right\n2.Left\n");
    scanf("%d",&c);
    if (c == 1) {
        for (i = pos; i < n - 1; i++) {
            printf("%d->", temp[i]);
            thm += abs(temp[i] - temp[i + 1]);
        }
        printf("%d", temp[n - 1]);
        thm+=abs(temp[n-1]-temp[pos-1]);
        for (i = pos - 1; i > 1; i--) {
            printf("->%d", temp[i]);
            thm += abs(temp[i] - temp[i - 1]);
        }
        printf("%d->", temp[1]);
    } 
    else {
        for (i = pos; i > 0; i--) {
            printf("%d->", temp[i]);
            thm += abs(temp[i] - temp[i - 1]);
        }
        printf("%d", temp[0]);
        thm+=abs(temp[0]-temp[pos+1]);
        for (i = pos + 1; i < n - 2; i++) {
            printf("->%d", temp[i]);
            thm += abs(temp[i] - temp[i + 1]);
        }
        printf("->%d", temp[n-2]);
    }
    printf("\nTotal Head Movement: %d\n", thm);
   
}

void cscan(int req[],int n,int h,int m)
{
    int i,pos,c,d,thm=0;
    int temp[100]; // large enough buffer
    for (i = 0; i < n; i++) 
    temp[i] = req[i];
    temp[n] = 0;
    temp[n+1] = h;
    temp[n+2] = m - 1;
    n+=3;
    sorting(temp,n);
    pos=search(temp,n,h);
    printf("\n1.Right\n2.Left\n");
    scanf("%d",&c);
    if (c == 1) {
        for (i = pos; i < n - 1; i++) {
            printf("%d->", temp[i]);
            thm += abs(temp[i] - temp[i + 1]);
        }
        printf("%d", temp[n - 1]);
        thm+=abs(temp[n-1]-temp[0]);
        
        for (i = 0; i !=pos-1; i++) {
            printf("->%d", temp[i]);
            thm += abs(temp[i] - temp[i + 1]);
            
        }
        printf("->%d", temp[pos-1]);
    } 
    else {
        for (i = pos; i > 0; i--) {
            printf("%d->", temp[i]);
            thm += abs(temp[i] - temp[i - 1]);
        }
        printf("%d", temp[0]);
        thm+=abs(temp[0]-temp[n-1]);
        
        for (i = n-1; i!=pos+1; i--) {
            printf("->%d", temp[i]);
            thm += abs(temp[i] - temp[i - 1]);
        }
        printf("->%d", temp[pos+1]);
    }
    printf("\nTotal Head Movement: %d\n", thm);
   
}

int main() {
    int choice;
    int n, h, i,m;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
    scanf("%d", &req[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &h);
    printf("Enter max value: ");
    scanf("%d", &m);


    do
    {
        printf("\n=== DISK SCHEDULING MENU ===\n");
        printf("1. FCFS\n");
        printf("2.SCAN\n");
        printf("3.CSCAN\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:fcfs(req,n,h);
                    break;
            case 2:scan(req,n,h,m);
                    break;
            case 3:cscan(req,n,h,m);
                    break;
            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while(choice!=4);
    return 0;
}
