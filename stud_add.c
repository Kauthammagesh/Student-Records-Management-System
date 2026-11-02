#include "student.h"

void stud_add()
{
    node *newnode = (node *)malloc(sizeof(node));
    node *temp = head;

    printf("Enter the Name: ");
    scanf(" %[^\n]", newnode->name);

    printf("Enter the Percentage: ");
    if (scanf("%f", &newnode->percentage) != 1 || newnode->percentage < 0 || newnode->percentage > 100)
    {
        printf("\n");
        printf("Invalid Percentage\n");
        printf("\n");
        free(newnode);
        return;
    } // if percentage is <0 || >100

    newnode->roll = roll++;
    newnode->next = NULL;

    // add end

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {

        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Roll Number: %d\n", newnode->roll);

    printf("\n");
    printf("Record has been Added Successfully\n");
    printf("\n");
}
