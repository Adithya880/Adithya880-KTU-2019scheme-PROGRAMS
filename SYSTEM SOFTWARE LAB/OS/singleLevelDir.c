// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
typedef struct dir{
    char dname[20];
    int n;
    char name[10][15];
}dir;

int strCmp(dir d,char name[]){
    for(int i=0;i<d.n;i++){
        if(strcmp(d.name[i],name)==0)
            return 1;
    }
    return 0;
}

void display(dir d,int n){
    int i;
    printf("\nDirectory %s:",d.dname);
    for(i=0;i<d.n;i++){
        printf("\n%d.%s",i+1,d.name[i]);
    }
}

void main() {
    int i=0,n;
    dir d;
    printf("\nEnter directory name:");
    scanf("%s",d.dname);
    printf("\nEnter no: of files:");
    scanf("%d",&d.n);
    //d.name=(char **)malloc(n* sizeof(char*));
    printf("\nEnter file names:");
    while(i<d.n){
        printf("\nFile %d:",i+1);
        char name[15];
        scanf("%s",name);
        //d.name[i]=(char *)malloc(20* sizeof(char));
        if(strCmp(d,name)==0){
        strcpy(d.name[i++],name);
        }
        else
        printf("\nFile already exists");
    }
    display(d,n);
}