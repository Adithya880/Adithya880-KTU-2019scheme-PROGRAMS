// Online C compiler to run C program online
#include <stdio.h>
#define max 10
typedef struct file{
    int index,id,size;
    int blocks[max];
}file;

int k=0;
int bl[50];

void display(file f[],int n){
    int i,j;
    printf("\nFILES\tINDEX\tBLOCKS");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t",f[i].id,f[i].index);
        for(j=0;j<f[i].size;j++){
          printf("%d ",f[i].blocks[j]);
        }
    }
}

int checkBlock(int id){
    int i;
    for(i=0;i<k;i++){
       if(bl[i]==id)
       return 1;
    }
    return 0;
}

void main() {
    int n,i;
    printf("\nEnter the no: of files:");
    scanf("%d",&n);
    file f[n];
    printf("\neNTER file details:\n");
    for(i=0;i<n;i++){
        int count=0,index;
        f[i].id=i+1;
        printf("File %d",f[i].id);
        printf("\nEnter indexed block:");
        scanf("%d",&index);
        if(checkBlock(index)==0){
            f[i].index=index;
            bl[k++]=f[i].index;
        }
        else{
            printf("Already occupied!");
            printf("\nEnter indexed block:");
            scanf("%d",&index);
            f[i].index=index;
            bl[k++]=f[i].index;
        }
        printf("\nEnter file length:");
        scanf("%d",&f[i].size);
        printf("\nEnter block numbers:");
        while(count<f[i].size){
            int id;
            printf("\nBlock %d:",count+1);
            scanf("%d",&id);
            if(checkBlock(id)==0){
            bl[k++]=id;
            f[i].blocks[count++]=id;
            }
            else
            printf("Already occupied!");
        }
    }

    display(f,n);
}