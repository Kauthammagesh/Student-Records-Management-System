#include "student.h"

void stud_load()
{
    FILE *fp = fopen("student.csv", "r");
    if (fp == NULL)
    {
        printf("No Previous Records Found\n");
        return;
    }

    char buffer[100];

    fgets(buffer, sizeof(buffer), fp);

    node *newnode;
    node *temp = head;

    while (1)
    {
        newnode = (node *)malloc(sizeof(node));

        if (newnode == NULL)
        {
            printf("Memory allocation Failed\n");
            fclose(fp);
            return;
        }

        int result = fscanf(fp, " %d,%49[^,],%f",
                            &newnode->roll,
                            newnode->name,
                            &newnode->percentage);

        if (result != 3)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        if (newnode->roll >= roll)
        {
            roll = newnode->roll + 1;
        }
    }

    fclose(fp);

    printf("Previous Record Loaded Successfully");
}