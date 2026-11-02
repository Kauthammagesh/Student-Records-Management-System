#include "student.h"

node *head = NULL;
int roll = 101;
int main()
{
    char op;

    stud_load();

    while (1)
    {
        printf("\n");
        printf("**************************************\n");
        printf("******** Students Record Menu ********\n");
        printf("**************************************\n");
        printf("***     [A/a] Add a New Record     ***\n");
        printf("***     [D/d] Delete a Record      ***\n");
        printf("***     [S/s] Show the Record      ***\n");
        printf("***     [M/m] Modify a Record      ***\n");
        printf("***     [V/v] Save a Record        ***\n");
        printf("***     [T/t] Sort the Record      ***\n");
        printf("***     [E/e] Exit                 ***\n");
        printf("**************************************\n");
        printf("\n");

        printf("Enter the Options: ");
        scanf(" %c", &op);

        switch (op)
        {
        case 'A':
        case 'a':
            stud_add();
            break;
        case 'D':
        case 'd':
            stud_del();
            break;
        case 'S':
        case 's':
            stud_show();
            break;
        case 'M':
        case 'm':
            stud_mod();
            break;
        case 'V':
        case 'v':
            stud_save();
            break;
        case 'T':
        case 't':
            stud_sort();
            break;
        case 'E':
        case 'e':
        {
            char ch;
            printf(" Save and Exit          -  [S/s]\n");
            printf(" Exit without Saving    -  [E/e]\n");
            scanf(" %c", &ch);
            if (ch == 'S' || ch == 's')
            {
                stud_save();
                exit(0);
            }
            else if (ch == 'E' || ch == 'e')
            {
                exit(0);
            }
            else
            {
                printf("Invalid Options\n");
            }
            break;
        }
        default:
            printf("Enter the Valid Option\n");
            break;
        }
    }
}
