#include<stdio.h>
#include"student.h"
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define NMAX 208

int main(){
    int option;
    do{
        printf("\n1. Check student list.\n2.Add student(s) to list.\n3.Find student by name.\n4.Exit.\n\nEnter your option: ");
        scanf("%d", &option);
        switch(option){
        case 1:
            listStudent();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            findStudent();
            break;
        case 4:
            return 0;
        default:
            printf("\nERROR: Invalid option!\n");
            break;
        }
    }while(option != 4);
    return 0;
}

void prtloop(char c, int n){
    for(int i = 0; i < n; i++) printf("%c", c);
}

void prtTableH(){
    printf("\n%c", 218);
    prtloop(196, 32);
    printf("%c", 194);
    prtloop(196, 10);
    printf("%c\n", 191);
    printf("%c %-30s %c %-8s %c\n", 179, "Student's Name", 179, "Score", 179);
    printf("%c", 195);
    prtloop(196, 32);
    printf("%c", 197);
    prtloop(196, 10);
    printf("%c\n", 180);
}

void prtTableT(){
    printf("%c", 192);
    prtloop(196, 32);
    printf("%c", 193);
    prtloop(196, 10);
    printf("%c\n", 217);
}

void prtStudentLine(Student x){
    printf("%c %-30s %c %-8.2f %c\n", 179, x.name, 179, x.score, 179);
    printf("%c", 195);
    prtloop(196, 32);
    printf("%c", 197);
    prtloop(196, 10);
    printf("%c\n", 180);
}

void listStudent(){
    prtTableH();
    FILE *data = fopen("SV2021.dat", "r");
    int tmp;
    while((tmp = fgetc(data)) != EOF){
        char stmp[NMAX];
        Student a;
        strcpy(a.name, "\0");
        strcpy(stmp, "\0");
        while(tmp != '\n'){
            if(!isdigit(tmp) && tmp != '.') strcat(a.name, &tmp);
            if(isdigit(tmp) || tmp == '.') strcat(stmp, &tmp);
            tmp = fgetc(data);
        }
        a.score = atof(stmp);
        prtStudentLine(a);
    }
    if(feof(data)) fclose(data);
    prtTableT();
}

void addStudent(){
    int n;
    printf("\nEnter number of students you want to add to the list: ");
    scanf("%d", &n);
    FILE *add = fopen("SV2021.dat", "a");
    for(int i = 0; i < n; i++){
        Student a;
        printf("Enter name and of student No.%d: ", i+1);
        fflush(stdin);
        gets(a.name);
        printf("Enter score of student %s: ", a.name);
        scanf("%lf", &a.score);
        fprintf(add, "%s %.2f\n", a.name, a.score);
    }
    printf("\nSuccessfully add %d student(s)!\n", n);
    fclose(add);
}

void findStudent(){
    char find[NMAX];
    printf("\nEnter name of student whom you want to search: ");
    fflush(stdin);
    gets(find);
    if(find == NULL) printf("Invalid name!");
    else{
        printf("There are all students with the name %s:\n", find);
        prtTableH();
        FILE *search = fopen("SV2021.dat", "r");
        int tmp;
        while((tmp = fgetc(search)) != EOF){
            char stmp[NMAX];
            Student a;
            strcpy(a.name, "\0");
            strcpy(stmp, "\0");
            while(tmp != '\n'){
                if(!isdigit(tmp) && tmp != '.') strcat(a.name, &tmp);
                if(isdigit(tmp) || tmp == '.') strcat(stmp, &tmp);
                tmp = fgetc(search);
            }
            a.score = atof(stmp);
            char *p = strstr(a.name, find);
            if(p) prtStudentLine(a);
        }
        if(feof(search)) fclose(search);
        prtTableT();
    }
}
