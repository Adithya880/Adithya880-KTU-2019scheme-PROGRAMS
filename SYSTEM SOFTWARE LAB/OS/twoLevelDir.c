// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
typedef struct dir{
    char user[20],dname[20],name[10][15];;
    int n;
}dir;

int strCmp(dir d[],int ci,char name[]){
    for(int i=0;i<d[ci].n;i++){
        if(strcmp(d[ci].name[i],name)==0)
            return 1;
    }
    return 0;
}

void display(dir d[],int u){
    for(int i=0;i<u;i++){
        printf("\nUser %d: %s",i+1,d[i].user);
        printf("\n\tDirectory %s:",d[i].dname);
        for(int j=0;j<d[i].n;j++){
        printf("\n\t\t%d.%s",j+1,d[i].name[j]);
        }
    }
    
    
}

void main() {
    int i,n,u;
    printf("\nEnter no: of users:");
    scanf("%d",&u);
    dir d[u];
    for(i=0;i<u;i++){
        printf("\nName of user %d:",i+1);
        scanf("%s",d[i].user);
        printf("\nEnter directory name:");
        scanf("%s",d[i].dname);
        printf("\nEnter no: of files in %s:",d[i].dname);
        scanf("%d",&d[i].n);
        printf("\nEnter file names:");
        int count=0;
        while(count<d[i].n){
            printf("\nFile %d:",count+1);
            char name[15];
            scanf("%s",name);
            //d.name[i]=(char *)malloc(20* sizeof(char));
            if(strCmp(d,i,name)==0){
            strcpy(d[i].name[count++],name);
            }
            else
            printf("\nFile already exists");
        }
    }
    
    
    //d.name=(char **)malloc(n* sizeof(char*));
    
    display(d,u);
}