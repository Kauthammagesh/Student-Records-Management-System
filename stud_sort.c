#include "student.h"

void stud_sort()
{
    char ch;

    if (head == NULL)
    {
        printf("\n");
        printf("Oops! No students Records Available\n");
        return;
    }

    printf("Sort by\n");
    printf("Roll NO      -   [R/r]\n");
    printf("Name         -   [N/n]\n");
    printf("Percentage   -   [P/p]\n");
    printf("Choose: ");
    scanf(" %c", &ch);

    node *i, *j;
    node temp;

    if ((ch == 'R') || (ch == 'r'))
    {
        for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->roll > j->roll)
                {
                    temp.roll = i->roll;
                    strcpy(temp.name, i->name);
                    temp.percentage = i->percentage;

                    i->roll = j->roll;
                    strcpy(i->name, j->name);
                    i->percentage = j->percentage;

                    j->roll = temp.roll;
                    strcpy(j->name, temp.name);
                    j->percentage = temp.percentage;

                    stud_show();
                }
            }
        }
    }

    else if ((ch == 'N') || (ch == 'n'))
    {

        for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (strcmp(i->name, j->name) > 0)
                {
                    temp.roll = i->roll;
                    strcpy(temp.name, i->name);
                    temp.percentage = i->percentage;

                    i->roll = j->roll;
                    strcpy(i->name, j->name);
                    i->percentage = j->percentage;

                    j->roll = temp.roll;
                    strcpy(j->name, temp.name);
                    j->percentage = temp.percentage;

                    stud_show();
                }
            }
        }
    }
    else if ((ch == 'P') || (ch == 'p'))
    {
        for (i = head; i != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->percentage > j->percentage)
                {
                    temp.roll = i->roll;
                    strcpy(temp.name, i->name);
                    temp.percentage = i->percentage;

                    i->roll = j->roll;
                    strcpy(i->name, j->name);
                    i->percentage = j->percentage;

                    j->roll = temp.roll;
                    strcpy(j->name, temp.name);
                    j->percentage = temp.percentage;

                    stud_show();
                }
            }
        }
    }
    else
    {
        printf("Invalid Operation\n");
    }

    printf("\n");
    printf("Records Sorted Successfully");
}