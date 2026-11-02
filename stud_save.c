#include "student.h"

void stud_save()
{
    FILE *fp = fopen("student.csv", "w");
    node *temp = head;

    if (fp == NULL)
    {
        printf("Unable to open or create student.csv file");
        return;
    }

    fprintf(fp, "Roll No, Name, Percentage\n");

    while (temp != NULL)
    {
        fprintf(fp, "%d,%s,%.2f\n", temp->roll, temp->name, temp->percentage);
        temp = temp->next;
    }
    fclose(fp);

    printf("Records Saved to Student.csv Successfully\n");
}
