#include "student.h"

void stud_show()
{
    node *temp = head;

    if (!temp)
    {
        printf("No Records has been found!");
        return;
    }
    printf("\n-----------------------------------------------------\n");
    printf("%-15s %-20s %-15s", "Roll No", "Name", "Percentage");
    printf("\n-----------------------------------------------------\n");

    while (temp != 0)
    {
        printf("%-15d %-20s %-15f\n", temp->roll, temp->name, temp->percentage);
        temp = temp->next;
    }

    printf("\n-----------------------------------------------------\n");
}
