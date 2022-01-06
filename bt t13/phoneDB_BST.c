#include"phoneDB_BST.h"
#define Max 50

treeType root = NULL;
keyType phone[Max];

void import_from_datfile(){
    FILE *fp;
    int irc;

    if((fp = fopen("PhoneDB.dat","rb")) == NULL){
        printf("Can not open!\n");
    }

    irc = fread(phone,sizeof(keyType), Max, fp);

    fclose(fp);

    printf("List has %d node\n", irc);

    for(int i = 0; i < irc; i++){
        insertNode(phone[i], &root);
    }
}

void import_from_textfile(){
    FILE *fp;
    int irc;

    if((fp = fopen("phoneDB.txt","r")) == NULL){
        printf("Can not open!\n");
    }

    int i = 0;
    while((fscanf(fp, "%s %s %f %s",phone[i].model_name, phone[i].memory, &phone[i].screen, phone[i].price)) != EOF){
        i++;
    };

    irc = i;
    fclose(fp);

    printf("List has %d node\n", irc);

    for(int i = 0; i < irc; i++){
        insertNode(phone[i], &root);
    }
}

void add(){
    keyType add;
    add = readNode();
    insertNode(add, &root);
    printf("\nData has been added!\n");
}

void searching(){
    char name[40];
    printf("Enter model name to search:");
    scanf("%s", name);
    treeType T;
    T = search(name, root);
    if(T == NULL) printf("Can not find!\n");
    else{
        printf("\nResult:\n");
        printf("%-30s %-20s %-10.2f %-3s\n",
            T->key.model_name,
            T->key.memory,
            T->key.screen,
            T->key.price);
    }
}

void Save(FILE *filename,treeType root){
    if(root != NULL){
        Save(filename, root->left);
        fwrite(root, sizeof(treeType),1, filename);
        Save(filename, root->right);
    }
}

void save(){
    FILE *fout;
    if((fout = fopen("PhoneDB.dat","wb")) == NULL){
        printf("Can not write!\n");
    }

    Save(fout,root);

    fclose(fout);
    printf("\nData has been written!\n");
}

void display(){
    int i=1;
    LNR(root);
}

void delete_(){
    keyType del;
    char name[40];
    printf("Enter model name to delete:");
    scanf("%s", name);
    treeType T;
    T = search(name, root);
    del = T->key;
    deleteNode(del, &root);

    printf("\nData has been deleted!\n");
}

void update(){
    char name[40];
    printf("Enter model name :");
    scanf("%s", name);
    treeType T;
    T = search(name, root);
    if(T == NULL) printf("Can not find!\n");
    else{ 
        deleteNode(T->key, &root);
        keyType tmp;
        tmp = readNode();
        insertNode(tmp, &root);
    }

    printf("\nData have been updated!\n");
}

void menu(){
    i=1;
    printf("\n        Menu\n");
    printf("1.Import from text file.\n");
    printf("2.Import fromt dat file\n");
    printf("3.Add phone model\n");
    printf("4.Delete\n");
    printf("5.Update\n");
    printf("6.Searching\n");
    printf("7.Displaying\n");
    printf("8.Save data to phoneDB.dat\n");
    printf("9.Quit\n");
    printf("Choose:");
    int x;
    scanf("%d", &x);
    switch(x){
        case 1:
            import_from_textfile();
            menu();
            break;
        case 2:
            import_from_datfile();
            menu();
            break;
        case 3:
            add();
            menu();
            break;
        case 4:
            delete_();
            menu();
            break;
        case 5:
            update();
            menu();
            break;
        case 6:
            searching();
            menu();
            break;
        case 7:
            display();
            menu();
            break;
        case 8:
            save();
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