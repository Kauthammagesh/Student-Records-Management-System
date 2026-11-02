#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int roll;

typedef struct student
{
    int roll;
    char name[50];
    float percentage;
    struct student *next;
} node;

extern node *head;

void stud_add();
void stud_del(void);
void stud_rollDel();
void stud_nameDel();
void stud_mod(void);
void stud_rmodify();
void stud_nmodify();
void stud_save();
void stud_load();
void stud_sort();
void stud_show();