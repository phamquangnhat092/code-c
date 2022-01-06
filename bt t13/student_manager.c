#include"student_BST.h"
#define max 50

keyType student[max];
treeType root = NULL;

void import_from_text(){
    FILE *fin;
    int i = 0;

    if((fin = fopen("student.txt", "r")) == NULL){
        printf("Can not read!\n");
    }

    while((fscanf(fin,"%s",student[i].name)) != EOF){
        i++;
    }
    fclose(fin);

    int num = i;
    for(int i = 0; i < num; i++){
        insertNode(student[i], &root);
    }

    printf("\nList has %d students\n", i);
    printf("Data has been written!\n");

}
void display(){
    LNR(root);
}

void searching(){
    char name[20];
    printf("Enter student name to search:");
    scanf("%s", name);
    treeType T;
    T = search(name, root);
    if(T == NULL) printf("Can not find!\n");
    else{
        printf("\nResult:\n");
        printf(" %-40s \n",
            T->key.name);
    }
}

void menu(){
    i=1;
    printf("\n        Menu\n");
    printf("1.Import from text file\n");
    printf("2.Display\n");
    printf("3.Search\n");
    printf("4.Quit\n");
    printf("Choose:");
    int x;
    scanf("%d", &x);
    switch(x){
        case 1:
            import_from_text();
            menu();
            break;
        case 2:
            display();
            menu();
            break;
        case 3:
            searching();
            menu();
            break;
        default:
            freeTree(root);
            break;
    }
}

int main(){
    menu();
    return 0;
}
