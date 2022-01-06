#include<stdio.h>
#include<string.h>
int vn_strcmp(char name1[], char name2[]){
    
    char *s1 = NULL, *s2 = NULL;

    char name1_tmp[20];
    char name2_tmp[20];

    strcpy(name2_tmp, name2);
    strcpy(name1_tmp, name1);

    char first_name1[15];
    char first_name2[15];

    s1 = strtok(name1_tmp,"_");

    while(s1 != NULL){
        strcpy(first_name1, s1);
        s1 = strtok(NULL,"_");
    }

    s2 = strtok(name2_tmp,"_");
    while(s2 != NULL){
        strcpy(first_name2, s2);
        s2 = strtok(NULL,"_");
    }
    
    if(strcmp(first_name1, first_name2) > 0) return 1;
    else if(strcmp(first_name1, first_name2) < 0) return -1;
    else{
        return 0;
    }
}
int main(){
     char a[40],b[40];
     printf("Nhap chuoi 1: "); gets(a);
     printf("Nhap chuoi 2: "); gets(b);
     if (vn_strcmp(a , b) < 0) printf("%s\n%s", a,b);
     else if (vn_strcmp(a , b) > 0) printf("%s\n%s",b,a);
     else printf("fuck");
     char* s = strtok(a,"_");
     char c[40];
     char d[40]; strcpy(d,s);
    while(s != NULL){
        strcpy(c, s);
        s = strtok(NULL,"_");
    } printf("\n%s %s", d, c);
     return 0;
}