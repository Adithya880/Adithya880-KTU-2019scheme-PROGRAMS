#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct files{
    char name[15];
}files;

typedef struct dir{
    char name[15];
    files f[10];
    struct dir* subdir[10];
    int sdn,n;
}dir;

int addFile(dir* d){
    char name[15];
    printf("\nEnter directory name to add files:");
    scanf("%s",name);
    if(strcmp(d->name,name)==0){
        printf("\nEnter no: of files:");
        scanf("%d",&d->n);
        for(int i=0;i<d->n;i++){
            printf("\nFile %d:",i+1);
            scanf("%s",d->f[i].name);
        }
        return 1;
    }

    for(int i=0;i<d->sdn;i++){
        if(addFile(d->subdir[i]))
        return 1;
    }
    return 0;
}

dir* addDir(){
    dir* new=(dir*)malloc(sizeof(dir));
    printf("\nDirectory name:");
    scanf("%s",new->name);
    new->n=0;
    new->sdn=0;
    return new;
}

dir* addSubdir(dir* d){
    char parent[15];
    printf("\nEnter directory name to add sub-directory:");
    scanf("%s",parent);
        if(strcmp(d->name,parent)==0){
            
        dir* child=addDir();
        d->subdir[d->sdn++]=child;
        printf("\nSub-directory created");
        return child;
        }
    
    for(int i=0;i<d->sdn;i++){
        if(d->subdir[i]!=NULL)
        addSubdir(d->subdir[i]);
    }
}

void display(dir* root){
    dir* d=root;
    
    for(int j=0;j<d->sdn;j++){
        printf("\t\tsubdir %s\n",d->subdir[j]->name);
        if(d->subdir[j]->n==0)
            printf("\t\t\tNo files");
        else{
            for(int k=0;k<d->subdir[j]->n;k++){
                printf("\t\t\tfile %s\n",d->subdir[j]->f[k].name);
            }
        }
    display(d->subdir[j]);
    }
    
}


void menu(){
    int choice;
    dir* root = addDir();   // Only once, for root

do {
    printf("\n1. Add Subdirectory\n2. Add Files\n3. Display\n4. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: 
            addSubdir(root);   // Ask where to add, then add using addDir()
            break;
        case 2:
            addFile(root);     // Ask where to add file
            break;
        case 3:printf("root %s\n",root->name);display(root);
            break;
    }
} while (choice != 4);

}

void main(){
    menu();
}