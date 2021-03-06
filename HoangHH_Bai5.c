#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 50

/* Input number of students to add */
void inputNumber(float *number);
/* Input student's info */
void insertStudent(float *numbers, char *student[MAX][MAX], uint8_t add);
/* Display all students's info */
void showStudent(char *student[MAX][MAX], uint8_t number);
/* Find student by searching for ID */
void findStudent(char *student[MAX][MAX], uint8_t number);
/* Check if input ID exists */
uint8_t checkID(char *s1, char *s2);
/* Remove student */
void removeStudent(char *student[MAX][MAX], float *number);
/* Program's interface */
void menu();
/* Find length of a char array */
uint8_t strlength(char *s);
/* Convert float to char array */
void convert(uint8_t f, char* s);

int main()
{
    uint8_t userChoice;
    float number = 0;
    char *student[MAX][MAX];
    A:
    menu();
    scanf("%d", &userChoice);
    system("cls");
    switch(userChoice)
    {
        case 1:
        {
            float add;
            inputNumber(&add);
            system("cls");
            insertStudent(&number, student, add);
            system("cls");
            char choice;
            printf("Press 'Y' if you wish to continue or N to exit program\n");
            scanf("%s", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                system("cls");
                goto A;
            }
            if (choice == 'n' || choice == 'N')
            {
                system("cls");
                exit(1);
            }
            break;
        }
        case 2:
        {
            removeStudent(student, &number);
            char choice;
            printf("Press 'Y' if you wish to continue or N to exit program\n");
            scanf("%s", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                system("cls");
                goto A;
            }
            if (choice == 'n' || choice == 'N')
            {
                system("cls");
                exit(1);
            }
            break;
        }
        case 3:
        {
            showStudent(student, number);
            char choice;
            printf("Press 'Y' if you wish to continue or N to exit program\n");
            scanf("%s", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                system("cls");
                goto A;
            }
            if (choice == 'n' || choice == 'N')
            {
                system("cls");
                exit(1);
            }
            break;
        }
        case 4:
        {
            findStudent(student, number);
            char choice;
            printf("Press 'Y' if you wish to continue or N to exit program\n");
            scanf("%s", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                system("cls");
                goto A;
            }
            if (choice == 'n' || choice == 'N')
            {
                system("cls");
                exit(1);
            }
            break;
        }
        case 5:
        {
            exit(1);
            break;
        }
    }
    return 0;
}

void convert(uint8_t f, char* s)
{
    if (0 <= f && f <= 9)
    {
        switch(f)
        {
            case 0:
            {
                s[0] = '0';
                break;
            }
            case 1:
            {
                s[0] = '1';
                break;
            }
            case 2:
            {
                s[0] = '2';
                break;
            }
            case 3:
            {
                s[0] = '3';
                break;
            }
            case 4:
            {
                s[0] = '4';
                break;
            }
            case 5:
            {
                s[0] = '5';
                break;
            }
            case 6:
            {
                s[0] = '6';
                break;
            }
            case 7:
            {
                s[0] = '7';
                break;
            }
            case 8:
            {
                s[0] = '8';
                break;
            }
            case 9:
            {
                s[0] = '9';
                break;
            }
        }
        s[1] = '\0';
    }
    if (10 <= f && f <= 99)
    {
        uint8_t a, b;
        a = f/10;
        b = f - 10 * a;
        switch(a)
        {
            case 0:
            {
                s[0] = '0';
                break;
            }
            case 1:
            {
                s[0] = '1';
                break;
            }
            case 2:
            {
                s[0] = '2';
                break;
            }
            case 3:
            {
                s[0] = '3';
                break;
            }
            case 4:
            {
                s[0] = '4';
                break;
            }
            case 5:
            {
                s[0] = '5';
                break;
            }
            case 6:
            {
                s[0] = '6';
                break;
            }
            case 7:
            {
                s[0] = '7';
                break;
            }
            case 8:
            {
                s[0] = '8';
                break;
            }
            case 9:
            {
                s[0] = '9';
                break;
            }
        }
        switch(b)
        {
            case 0:
            {
                s[1] = '0';
                break;
            }
            case 1:
            {
                s[1] = '1';
                break;
            }
            case 2:
            {
                s[1] = '2';
                break;
            }
            case 3:
            {
                s[1] = '3';
                break;
            }
            case 4:
            {
                s[1] = '4';
                break;
            }
            case 5:
            {
                s[1] = '5';
                break;
            }
            case 6:
            {
                s[1] = '6';
                break;
            }
            case 7:
            {
                s[1] = '7';
                break;
            }
            case 8:
            {
                s[1] = '8';
                break;
            }
            case 9:
            {
                s[1] = '9';
                break;
            }
        }
        s[2] = '\0';
    }
    if (100 <= f && f <= 999)
    {
        uint8_t a, b, c;
        a = f/100;
        b = (f%100)/10;
        c = f - 100 * a - 10 * b;
        switch(a)
        {
            case 0:
            {
                s[0] = '0';
                break;
            }
            case 1:
            {
                s[0] = '1';
                break;
            }
            case 2:
            {
                s[0] = '2';
                break;
            }
            case 3:
            {
                s[0] = '3';
                break;
            }
            case 4:
            {
                s[0] = '4';
                break;
            }
            case 5:
            {
                s[0] = '5';
                break;
            }
            case 6:
            {
                s[0] = '6';
                break;
            }
            case 7:
            {
                s[0] = '7';
                break;
            }
            case 8:
            {
                s[0] = '8';
                break;
            }
            case 9:
            {
                s[0] = '9';
                break;
            }
        }
        switch(b)
        {
            case 0:
            {
                s[1] = '0';
                break;
            }
            case 1:
            {
                s[1] = '1';
                break;
            }
            case 2:
            {
                s[1] = '2';
                break;
            }
            case 3:
            {
                s[1] = '3';
                break;
            }
            case 4:
            {
                s[1] = '4';
                break;
            }
            case 5:
            {
                s[1] = '5';
                break;
            }
            case 6:
            {
                s[1] = '6';
                break;
            }
            case 7:
            {
                s[1] = '7';
                break;
            }
            case 8:
            {
                s[1] = '8';
                break;
            }
            case 9:
            {
                s[1] = '9';
                break;
            }
            
    }
        switch(c)
        {
            case 0:
            {
                s[2] = '0';
                break;
            }
            case 1:
            {
                s[2] = '1';
                break;
            }
            case 2:
            {
                s[2] = '2';
                break;
            }
            case 3:
            {
                s[2] = '3';
                break;
            }
            case 4:
            {
                s[2] = '4';
                break;
            }
            case 5:
            {
                s[2] = '5';
                break;
            }
            case 6:
            {
                s[2] = '6';
                break;
            }
            case 7:
            {
                s[2] = '7';
                break;
            }
            case 8:
            {
                s[2] = '8';
                break;
            }
            case 9:
            {
                s[2] = '9';
                break;
            }
        }
        s[3] = '\0';
    }
}
uint8_t strlength(char *s)
{
    uint8_t i, length;
    for (i = 0; s[i] != '\0'; ++i)
    {
        length = i;
    }
    length += 1;
    return length;
}
void menu()
{
    printf("1. Add N students\n");
    printf("2. Remove 1 student using ID\n");
    printf("3. Display all students's infomation\n");
    printf("4. Find student using ID\n");
    printf("5. Exit\n");
}
void removeStudent(char *student[MAX][MAX], float *number)
{
    uint8_t check = 0, i, pos;
    char *find = (char*) malloc(20 * sizeof(char));
    printf("Enter ID: ");
    scanf("%s", find);
    /* Check if that student exists */
    for(i = 0; i < *number; ++i)
    {
        if(checkID(find, student[i][2]) == 1)
        {
            check = 1;
            pos = i;
            break;
        }
    }
    /* Student not found */
    if(check == 0)
    {
        printf("Student not found!\n");
    }
    /* Student found */
    if(check == 1)
    {
        for (i = pos; i < *number; ++i)
        {
            student[i][0] = student[i + 1][0];
            student[i][1] = student[i + 1][1];
            student[i][2] = student[i + 1][2];
            student[i][3] = student[i + 1][3];
        }
        (*number)--;
    }
}
uint8_t checkID(char *s1, char *s2)
{
    uint8_t n1, n2, count = 0, i;
    n1 = strlength(s1);
    n2 = strlength(s2);
    /* Two array of different length => Not equal */
    if (n1 != n2)
    {
        return 0;
    }
    if(n1 == n2)
    {
        /* Check if all elements of 2 arrays are the same */
        for(i = 0; i < n1; ++i)
        {
            if(s1[i] == s2[i])
            {
                count++;
            }
        }
        if (count == n1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void findStudent(char *student[MAX][MAX], uint8_t number)
{
    uint8_t check = 0, i, pos;
    char *find = (char*) malloc(20 * sizeof(char));
    printf("Enter ID: ");
    scanf("%s", find);
    for (i = 0; i < number; ++i)
    {
        if(checkID(find, student[i][2]) == 1)
        {
            check = 1;
            pos = i;
        }
    }
    if(check == 0)
    {
        printf("Student not found!\n");
    }
    if(check == 1)
    {
        printf("     Name                   Age      ID       Mark\n");
        printf("--------------------------------------------------\n");
        printf("%-29s", student[pos][0]);
        printf("%-5s", student[pos][1]);
        printf("%-10s", student[pos][2]);
        printf("%s", student[pos][3]);
        printf("\n");
    }
}
void showStudent(char *student[MAX][MAX], uint8_t number)
{
    uint8_t i;
    if (number == 0)
    {
        printf("NO DATA\n");
    }
    else
    {
        printf("     Name                   Age      ID       Mark\n");
        printf("--------------------------------------------------\n");
        for (i = 0; i < number; ++i)
        {
            printf("%-29s", student[i][0]);
            printf("%-5s", student[i][1]);
            printf("%-10s", student[i][2]);
            printf(" %s", student[i][3]);
            printf("\n");
        }
        printf("\n");
    }
}
void insertStudent(float *number, char *student[MAX][MAX], uint8_t add)
{
    float age, mark;
    uint8_t i;
    for (i = *number; i < *number + add; ++i)
    {
        char *name = (char*) malloc(50 * sizeof(char));
        char *id = (char*) malloc(50 * sizeof(char));
        char *_age = (char*) malloc(50 * sizeof(char));
        char *_mark = (char*) malloc(50 * sizeof(char));
        printf("Enter name of student %d: ", i + 1);
        fflush(stdin);
        gets(name);
        do
        {
            printf("Enter age of student %d: ", i + 1 );
            scanf("%f", &age);
            /* Notify error */
            if (age <= 0)
            {
                printf("Age of students must be larger than 0!\n");
            }
            else if (age >= 255)
            {
                printf("Age of students must be lower than 255!\n");
            }
            else if (age - (int)age != 0)
            {
                printf("Age of students must be an integer!\n");
            }
        } while (age - (int)age != 0 || age <= 0 || age >= 255);
        fflush(stdin);
        printf("Enter ID of student %d: ", i + 1 );
        gets(id);
        do
        {
            printf("Enter mark of student %d: ", i + 1 );
            scanf("%f", &mark);
            if(mark < 0 || mark > 10)
            {
                printf("Mark of students must be between 0 and 10\n");
            }
        } while (mark < 0 || mark > 10);
        /* Convert float to char array */
        convert(mark, _mark);
        convert(age, _age);
        /* Assign to char array */
        student[i][0]= name;
        student[i][1]= _age;
        student[i][2]= id;
        student[i][3]= _mark;
        system("cls");
    }
    (*number) += add;
}
void inputNumber(float *add)
{
    do
    {
        printf("Enter number of students you want to add: ");
        scanf("%f", &(*add));
        /* Notify error to user */
        if (*add <= 0)
        {
            printf("Number of students must be larger than 0!\n");
        }
        else if (*add - (int)*add != 0)
        {
            printf("Number of students must be an integer!\n");
        }
    } while (*add - (int)*add != 0 || *add <= 0);
}
