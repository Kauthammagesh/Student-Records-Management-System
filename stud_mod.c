#include "student.h"

void stud_mod()
{
    if (head == NULL)
    {
        printf("Oops! No Student Records Available\n");
        return;
    }

    char ch;
choose:
    printf("Modify Student Record by\n");
    printf("Roll Number - [R/r]\n");
    printf("Name        - [N/n]\n");
    printf("Enter your Choice: \n");
    scanf(" %c", &ch);

    if ((ch == 'R') || (ch == 'r'))
    {
        stud_rmodify();
    }
    else if ((ch == 'N') || (ch == 'n'))
    {
        stud_nmodify();
    }
    else
    {
        printf("Invalid selection! Choose the Correct Choice: ");
        goto choose;
    }
}

void stud_rmodify()
{
    node *temp = head;
    char ch;
    int mroll;

    printf("Enter the Roll Number of the Student to Modify: \n");
    scanf("%d", &mroll);

    int found = 0;

    while (temp != NULL)
    {
        if (temp->roll == mroll)
        {

            printf("Current Details of the Selected Student \n");
            printf(" Roll No     : %d\n", temp->roll);
            printf(" Name        : %s\n", temp->name);
            printf(" Percentage  : %f\n", temp->percentage);

            printf("\n");
            printf("Modify -------------\n");
            printf("Name       - [N/n]\n");
            printf("Percentage - [P/p]\n");
            printf("Go Back    - [G/g]\n");
            scanf(" %c", &ch);

            if ((ch == 'N') || (ch == 'n'))
            {
                char mname[50];
                printf("Enter the Name: ");
                scanf(" %49[^\n]", mname);
                strcpy(temp->name, mname);
            }
            else if ((ch == 'P') || (ch == 'p'))
            {
                float mpercentage;
                printf("Enter the Percentage: ");
                scanf("%f", &mpercentage);
                temp->percentage = mpercentage;
            }
            else if ((ch == 'G') || (ch == 'g'))
            {
                return;
            }
            else
            {
                printf("Invalid Selection! Choose the Valid Option\n");
            }

            found = 1;
        }
        temp = temp->next;
    }

    if (found == 0)
    {
        printf("Studend Record Not Found!\n");
    }
}

void stud_nmodify()
{
    char mname[50];
    int count = 0;
    node *temp = head;
    printf("Enter the Name to Search and Modify: ");
    scanf(" %49[^\n]", mname);

    while (temp != NULL) // count how many same name
    {
        if (strcmp(mname, temp->name) == 0)
        {
            count++;
        }
        temp = temp->next;
    }
    if (count == 0) // count=0
    {
        printf("Name not Found\n");
        return;
    }

    if (count > 1) // Multiple Same Name
    {
        printf("Multiple students have the same name!\n");
        printf("Use the Roll Number to modify the correct record\n");
        printf("\n");
        printf("-----------------------------------------------------\n");
        printf("%-15s %-20s %-15s\n", "Roll No", "Name", "Percentage");
        printf("-----------------------------------------------------\n");

        temp = head;

        while (temp != NULL)
        {
            if (strcmp(mname, temp->name) == 0)
            {
                printf("%-15d %-20s %-15f\n", temp->roll, temp->name, temp->percentage);
            }
            temp = temp->next;
        }

        printf("\n");
        printf("Choose the roll number from the above Records to Modify\n");
        stud_rmodify();
        return;
    }
    temp = head;

    while (strcmp(mname, temp->name) != 0) // No Multiple Name
    {
        temp = temp->next;
    }

    printf("Current Details of the Selected Student \n");
    printf(" Roll No     : %d\n", temp->roll);
    printf(" Name        : %s\n", temp->name);
    printf(" Percentage  : %f\n", temp->percentage);

    char mch;
    printf("Modify--------------\n");
    printf("Name       - [N/n]\n");
    printf("Percentage - [P/p]\n");
    printf("Go Back    - [G/g]\n");
    scanf(" %c", &mch);

    if ((mch == 'N') || (mch == 'n'))
    {
        char mnname[50];
        printf("Enter the Name: ");
        scanf(" %49[^\n]", mnname);
        strcpy(temp->name, mnname);
    }
    else if ((mch == 'P') || (mch == 'p'))
    {
        float mnpercentage;
        printf("Enter the Percentage: ");
        scanf("%f", &mnpercentage);
        temp->percentage = mnpercentage;
    }
    else if ((mch == 'G') || (mch == 'g'))
    {
        return;
    }
    else
    {
        printf("Invalid Selection! Choose the Valid Option\n");
    }

    printf("\n");
    printf("Modified Successfully\n");
}