#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char model[40];
    char memory[20];
    float screen;
    char price[10];
} product;

typedef struct node {
    product phone;
    node* next;
} node;

int n = 0, phone_status = 0;
void menu();
node *root = NULL, *cur = NULL;

void printNode(node *a) {
    printf("Current position:\n");
    printf(
        "%-35s %-20s %-10.2f %-3s\n",
        a->phone.model,
        a->phone.memory,
        a->phone.screen,
        a->phone.price);
}

void insertAtHead(product phone) {
   node *link = (node *)malloc(sizeof(node));
   strcpy(link->phone.model, phone.model);
   strcpy(link->phone.memory, phone.memory);
   strcpy(link->phone.price, phone.price);
   link->phone.screen = phone.screen;
   link->next = root;
   root = link;
   cur = root;
}

void insertAfterCur(product phone) {
    node *new_ = (node *)malloc(sizeof(product));
    new_->phone = phone;
    if (root == NULL)
    {
        root = new_;
        cur = root;
    }
    else if (cur == NULL)
        printf("Current is null!\n");
    else
    {
        new_->next = cur->next;
        cur->next = new_;
        cur = cur->next;
    }
}

void printList() {
    node *a = root;
    //bat dau tu 1
    int i = 0;
    printf("No   Model                               Memory               Screen     Price ($)\n");
    while (a != NULL)
    {
        printf(
            "%-4d %-35s %-20s %-10.2f %-3s\n",
            ++i,
            a->phone.model,
            a->phone.memory,
            a->phone.screen,
            a->phone.price
        );
        a = a->next;
    }
    printf("\n");
    menu();
}

void importFromTxt() {
    FILE *fin;
    if ((fin = fopen("PhoneDB.txt", "r")) == NULL) {
        printf("Cannot open file \'PhoneDB.txt\'\n");
        return;
    }
    n = 0;
    product tmp;
    while (fscanf(fin, "%s %s %f %s", tmp.model, tmp.memory, &tmp.screen, tmp.price) != EOF) {
        n++;
        insertAtHead(tmp);
    }
    fclose(fin);
    printf("Data has been imported successfully!\n");
    phone_status = 1;
    menu();
}

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
    printf("Data has been imported successfully!\n");
    fclose(fin);
    phone_status = 1;
    menu();
}

void searchModel() {
    char tmp_name[40];
    printf("Phone model name: ");
    scanf("%s", tmp_name);
    struct node *ptr = root;
    int i = 0, found = 0;
    printf("No   Model                               Memory               Screen     Price ($)\n");
    while (ptr != NULL) {
        if (strcmp(ptr->phone.model, tmp_name) == 0) {
            found = 1;
            printf(
                "%-4d %-35s %-20s %-10.2f %-3s\n",
                ++i,
                ptr->phone.model,
                ptr->phone.memory,
                ptr->phone.screen,
                ptr->phone.price
            );
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("Phone model is not found!\n");
    }
    menu();
}

void searchPrice() {
    float tmp_price;
    printf("Price ($): ");
    scanf("%f", &tmp_price);
    struct node *ptr = root;
    int i = 0, found = 0;
    printf("No   Model                               Memory               Screen     Price ($)\n");
    while (ptr != NULL) {
        if (atof(ptr->phone.price) < tmp_price) {
            found = 1;
            printf(
                "%-4d %-35s %-20s %-10.2f %-3s\n",
                ++i,
                ptr->phone.model,
                ptr->phone.memory,
                ptr->phone.screen,
                ptr->phone.price
            );
        }
        ptr = ptr->next;
    }
    if (!found) {
        printf("Phone model is not found!\n");
    }
    menu();
}

void exportToDat() {
    FILE *fout;
    if ((fout = fopen("PhoneDB.dat", "wb")) == NULL) {
        printf("Cannot open \"PhoneDB.dat\" for writing\n");
        return;
    }
    struct node *ptr = root;
    //start from the beginning
    int i = 0;
    while (ptr != NULL)
    {
        fwrite(&ptr->phone, sizeof(product), 1, fout);
        ptr = ptr->next;
    }
    fclose(fout);
    printf("Data has been written!");
    menu();
}

void Insert() {
    product tmp;
    printf("Input new model's information\n");
    printf("    - Model name (ex: Oppo_Reno_6): ");
    scanf("%s", tmp.model);
    printf("    - Memory (GB): ");
    scanf("%s", tmp.memory);
    printf("    - Screen (inch): ");
    scanf("%f", &tmp.screen);
    printf("    - Price ($): ");
    scanf("%s", tmp.price);
    printNode(cur);
    printf("Insert this new model:\n");
    printf("1. Before current position\n");
    printf("2. After current position\n");
    printf("3. Back to menu\n");
    printf("Your selection: ");
    int x;
    scanf("%d", &x);
    switch (x) {
        case 1:
            insertAtHead(tmp);
            break;
        case 2:
            insertAfterCur(tmp);
            break;
        default:
            menu();
    }
    printList();
    menu();
}

void menu(){
    printf("\n               Menu:\n");
    printf("1. Import from text file \"PhoneDB.txt\"\n");
    printf("2. Import from dat file \"PhoneDB.dat\"\n");
    printf("3. Display list\n");
    printf("4. Search phone by model\n");
    printf("5. Search phone whose price is under the value inputted\n");
    printf("6. Export to dat file \"PhoneDB.dat\"\n");
    printf("7. Insert\n");
    printf("8. Exit\n");
    if (!phone_status)
        printf("Data has not been imported!\n");
    else 
        printf("%d phones have been imported!\n", n);
    printf("Your selection: ");
    int x; scanf("%d", &x);
    switch (x) {
        case 1:
            importFromTxt();
            break;
        case 2:
            importFromDat();
            break;
        case 3:
            printList();
            break;
        case 4:
            searchModel();
            break;
        case 5:
            searchPrice();
            break;
        case 6:
            exportToDat();
            break;
        case 7:
            Insert();
            break;
        default:
            return;
    }
}

int main()
{
    menu();
    return 0;
}



    
