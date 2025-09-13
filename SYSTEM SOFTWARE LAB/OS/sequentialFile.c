// Online C compiler to run C program online
#include <stdio.h>

typedef struct block{
    int allocated,id,no;
}block;

typedef struct file{
    int start,size,id;
}file;

int fileAllocation(block b[],int n1,file f[],int ci)
{
    int i;
    for(i=0;i<n1;i++){
        if(b[i].id==f[ci].start && b[i].allocated==0){
            for(int j=0;j<f[ci].size;j++){
                if(b[i+j].allocated==1){
                    return 0;
                }
            }
            for(int j=0;j<f[ci].size;j++){
            b[i+j].allocated=1;
            b[i+j].no=f[ci].id;
            }
            return 1;
        }
        else
        continue;
    }
    return 0;
}

void display(block b[],int n1,file f[],int n2){
    int i,flag=0;
    for(i=0;i<n2;i++){
        printf("\nFile %d",f[i].id);
        for(int j=0;j<n1;j++){
            if(b[j].no==f[i].id){
            printf("\t%d",b[j].id);
            }
        }
    }
}

void main() {
    int n1,n2,i;
    printf("\nEnter block number");
    scanf("%d",&n1);
    block b[n1];
     for(i=0;i<n1;i++){
        b[i].allocated=0;
        b[i].id=i+1;
        b[i].no=0;
    }
    
    printf("\nEnter the no: of files:");
    scanf("%d",&n2);
    file f[n2];
    printf("\neNTER file details:\n");
    for(i=0;i<n2;i++){
        f[i].id=i+1;
        printf("File %d",f[i].id);
        printf("\nEnter starting address:");
        scanf("%d",&f[i].start);
        printf("\nEnter length:");
        scanf("%d",&f[i].size);
        if((fileAllocation(b,n1,f,i))==1)
        printf("\nSuccessfully allocated");
        else
        printf("\nNot allocated");
    }
    display(b,n1,f,n2);
}  