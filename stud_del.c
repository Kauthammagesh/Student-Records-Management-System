#include "student.h"

void stud_del()
{
    char ch;
choose:
    printf("--------- Delete through ---------\n");
    printf("Roll No[R/r] \t \t Name[N/n]\n");
    printf("----------------------------------\n");
    printf("Choose: ");
    scanf(" %c", &ch);

    if ((ch == 'R') || (ch == 'r'))
    {
        stud_rollDel();
    }
    else if ((ch == 'N') || (ch == 'n'))
    {
        stud_nameDel();
    }
    else
    {
        printf("Choose the right option \n");
        goto choose;
    }
}

void stud_rollDel()
{
    node *temp, *prevnode = 0;
    temp = head;

    if (head == NULL)
    {
        printf("\n");
        printf("Oops! No Student Records Available\n");
        return;
    }

    int droll;
    printf("Enter the Roll Number: ");
    scanf("%d", &droll);

    while (temp != NULL && temp->roll != droll)
    {
        prevnode = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Roll Number Not Found\n");
        return;
    }
    if (prevnode == NULL)
    {
        head = temp->next;
    }
    else
    {
        prevnode->next = temp->next;
    }

    free(temp);

    printf("Deleted the data successfully\n");
}

void stud_nameDel()
{
    char dname[50];
    node *temp = head;
    node *prevnode = 0;
    int count = 0;

    if (head == NULL)
    {
        printf("Oops! No Student Records Available\n");
        return;
    }

    printf("Enter the Name: ");
    scanf(" %49[^\n]", dname); //?

    while (temp != NULL)
    {
        if (strcmp(dname, temp->name) == 0)
        {
            count++;
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        printf("Name not Found\n");
        return;
    }

    if (count > 1)
    {
        printf("Multiple students have the same name!\n");
        printf("Use the Roll Number to Delete the correct record\n");
        printf("\n");
        printf("-----------------------------------------------------\n");
        printf("%-15s %-20s %-15s\n", "Roll No", "Name", "Percentage");
        printf("-----------------------------------------------------\n");

        temp = head;

        while (temp != NULL)
        {
            if (strcmp(dname, temp->name) == 0)
            {
                printf("%-15d %-20s %-15f\n", temp->roll, temp->name, temp->percentage);
            }
            temp = temp->next;
        }

        printf("\n");
        printf("Choose the roll number from the above Records to Delete\n");
        stud_rollDel();
        return;
    }

    temp = head;

    while (temp != NULL && strcmp(dname, temp->name) != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (prevnode == NULL)
    {
        head = temp->next;
    }
    else
    {
        prevnode->next = temp->next;
    }

    free(temp);

    printf("\n");
    printf("Deleted the entered record Successfully\n");
}