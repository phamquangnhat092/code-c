#include "GenSLL.h"
int n = 0, phone_status = 0;
void menu();

void importFromDat() {
    FILE *fin;
    if ((fin = fopen("PhoneDB.dat", "rb")) == NULL) {
        printf("Cannot open file \'PhoneDB.dat\'\n");
        return;
    }
    n = 0;
    product tmp;
    while (fread(&tmp, sizeof(product), 1, fin)) {
        n++;
        insertAfterCur(tmp);
    }
    fclose(fin);
    phone_status = 1;
    menu();
}

void search_movetofront() {
    char tmp_name[40];
    printf("Phone model name: ");
    scanf("%s", tmp_name);
    node *ptr = root;
    int i = 0, found = 0;
    printf("No   Model                          Memory               Screen     Price ($)\n");
    while (ptr != NULL) {
        if (strcmp(ptr->phone.model_name, tmp_name) == 0) {
            found = 1;
            displaynode(ptr, i++);
            product tmp = ptr->phone;
            ptr->phone = root->phone;
            root->phone = tmp;
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf(" Phone model is not found\n");
    }
    menu();
}

void search_transpose() {
    char tmp_name[40];
    printf("Phone model name: ");
    scanf("%s", tmp_name);
    node *ptr1 = root;
    node *ptr2 = root->next;
    int i = 0, found = 0;
    printf("No   Model                          Memory               Screen     Price ($)\n");
    if (strcmp(root->phone.model_name, tmp_name) == 0) {
        found = 1;
        displaynode(root, i++);
    }
    while (ptr2 != NULL) {
        product tmp = ptr1->phone;
        if (strcmp(ptr2->phone.model_name, tmp_name) == 0) {
            found = 1;
            displaynode(ptr2, i++);
            ptr1->phone = ptr2->phone;
            ptr2->phone = tmp;
        }
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    if (!found) {
        printf(" Phone model is not found\n");
    }
    menu();
}

void searchByModel() {
    printf("Strategies:\n");
    printf("1. Move to front\n");
    printf("2. Transpose\n");
    printf("Your selection: ");
    int x; scanf("%d", &x);
    switch (x) {
        case 1:
            searchByModel_movetofront();
            break;
        case 2:
            searchByModel_transpose();
            break;
        default:
            menu();
    }
}

void exportToDat() {
    FILE *fout;
    if ((fout = fopen("PhoneDB.dat", "wb")) == NULL) {
        printf(" Cannot open \"PhoneDB.dat\" for writing\n");
        return;
    }
    node *ptr = root;
    //start from the beginning
    while (ptr != NULL)
    {
        fwrite(&ptr->phone, sizeof(product), 1, fout);
        ptr = ptr->next;
    }
    fclose(fout);
    printf(" Data has been written!");
    menu();
}

void manualInsert() {
    product tmp;
    tmp = readnode();
    printf(" Current node:\n");
    displaynode(cur, 0);
    printf(" -- Insert this new model:\n");
    printf("1. Before current position\n");
    printf("2. After current position\n");
    printf("3. Back to menu\n");
    printf("Your selection: ");
    int x;
    scanf("%d", &x);
    switch (x) {
        case 1:
            insertBeforeCur(tmp);
            break;
        case 2:
            insertAfterCur(tmp);
            break;
        default:
            menu();
    }
    n++;
    menu();
}

void insert() {
    printf("There are %d phones in the list\n", n);
    printf("Insert at position: ");
    int x;
    do {
        scanf("%d", &x);
        if (x >= 0) break;
        printf(" Invalid position!\n");
    } while (1==1);
    product tmp;
    tmp = readnode();
    insertAtPosition(root, tmp, x);
    n++;
    menu();
}

void delete_(int x) {
    if (x == 1) {
        printf("There are %d phones in the list\n", n);
        printf("Delete at position: ");
        int x;
        do {
            scanf("%d", &x);
            if (x >= 0 && x < n) break;
            printf(" Invalid position!\n");
        } while (1==1); 
        deleteAtPosition(root, x);
    }
    if (x == 2) {
        printf(" Current node: \n");
        displaynode(cur, 0);
        deleteAtCur(root, cur);
        printf(" Current node has been deleted!\n");
    }
    if (x == 3) {
        deleteAtHead();
        printf(" First node has been deleted!\n");
    }
    n--;
    menu();
}

void divide() {
    printf("Sublist 1\n");
    int n1, n2;

    do {
        printf(" Start position [0, %d]: ", n-1);
        scanf("%d", &n1);
        printf(" Number of elements: ");
        scanf("%d", &n2);
    } while (n1 >= n || n1 < 0 ||n1 + n2 > n || n1 + n2 <= 1);
    node* r;
    r = split(root, n1, n2);
    printf(" Sublist 1 whose start position is %d\n", n1);
    travel(r);
    printf(" Sublist 2 pointed by \"root\" pointer\n");
    travel(root);
    n -= n2;
    menu();
}

void reverse() {
    printf("List has been reversed!\n");
    root = list_reverse(root);
    travel(root);
    menu();
}

void menu(){
    printf("\nMenu:\n");
    printf("1. Import from dat file \"PhoneDB.dat\"\n");
    printf("2. Display list\n");
    printf("3. Add new phone\n");
    printf("4. Insert at position\n");
    printf("5. Delete at position\n");
    printf("6. Delete current\n");
    printf("7. Delete first\n");
    printf("8. Search\n");
    printf("9. Divide and Extract\n");
    printf("10. Reverse List\n");
    printf("11. Save to file\n");
    printf("12. Quit\n");
    if (!phone_status)
        printf(" Database has not been imported!\n");
    else 
        printf(" List has %d phones!\n", n);
    printf("Your selection: ");
    int x; scanf("%d", &x);
    switch (x) {
        case 1:
            importFromDat();
            break;
        case 2:
            travel(root);
            menu();
            break;
        case 3:
            manualInsert();
            break;
        case 4:
            insert();
            break;
        case 5:
            delete_(1);
            break;
        case 6:
            delete_(2);
            break;
        case 7:
            delete_(3);
            break;
        case 8:
            searchByModel();
            break;
        case 9:
            divide();
            break;
        case 10:
            reverse();
            break;
        case 11:
            exportToDat();
            break;
        default:
            freeList();
            return;
    }
}

int main()
{
    menu();
    return 0;
}



    
