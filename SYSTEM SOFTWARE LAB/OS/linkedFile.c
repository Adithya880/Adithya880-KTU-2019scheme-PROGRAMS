// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

typedef struct block{
    struct block* next;
    int id;
}block;

typedef struct file{
    int start,id,size,end;
    block* header;
}file;

int k=0;
int bl[50];

block* getblock(int id){
    block* new=(block*)malloc(sizeof(block));
    if(new==NULL){
        printf("\nMemory allocation failed");
        return NULL;
    }
    else{
        new->next=NULL;
        new->id=id;
        return new;
    }
}

block* insertEnd(block* start,int id){
    block* new=getblock(id);
    if(start==NULL)
    return new;
    block* temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new;
    return start;
}

int search(int bl[],int key){
    int i;
    for(i=0;i<k;i++){
        if(bl[i]==key)
        return 1;
    }
    return 0;
}

void fileAllocation(file f[],int i){
    int j;
    //block* start=NULL;
    printf("\nEnter block numbers:");
    int count = 0;
    while(count < f[i].size) {
        int id;
        printf("\nBlock %d:",count+1);
        scanf("%d", &id);
        if(search(bl, id)) {
            printf("Already occupied!");
            continue;  // Do not increase count
        }
    
        // Insert block only if it's not duplicate
        f[i].header = insertEnd(f[i].header, id);
        
        if(count == 0) f[i].start = id;
        if(count == f[i].size - 1) f[i].end = id;
    
        bl[k++] = id;
        count++;  // Count only valid entries
        printf("\nFILE ALLOCATED\n");
    }

}

void display(file f[],int n){
    int i,j;
    printf("FILES\tSTART\tEND\tLENGTH\t\tBLOCKS");
    for(i=0;i<n;i++){
        printf("\n%d\t %d\t %d\t%d\t\t",f[i].id,f[i].start,f[i].end,f[i].size);
        block* temp=f[i].header;
        while(temp!=NULL){
            printf("%d ",temp->id);
            temp=temp->next;
            if(temp!=NULL)
            printf("->");
        }
    }
}

void main() {
    int n,i;
    printf("\nEnter the no: of files:");
    scanf("%d",&n);
    file f[n];
    
    printf("\neNTER file details:\n");
    for(i=0;i<n;i++){
        f[i].id=i+1;
        f[i].header=NULL;
        printf("\nFile %d",f[i].id);
        printf("\nEnter file length:");
        scanf("%d",&f[i].size);
        fileAllocation(f,i);
    }
    display(f,n);
} 
 