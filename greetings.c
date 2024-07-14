#include <stdio.h>

void salam();
void namaste();
void hello();

int main()
{
    printf("Enter your religion:\n'm' for Muslim:\n'h' for Hindu:\n'o' for other:\n");
    char ch;
    scanf("%c", &ch);

    if (ch == 'i')
    {
        salam();
    }
    else if (ch == 'h')
    {
        namaste();
    }
    else if (ch == 'o')
    {
        hello();
    }

    return 0;
}

void salam()
{
    printf("Salam Habibi\n");
}

void namaste()
{
    printf("Namaste Dost\n");
}

void hello()
{
    printf("Hello friend\n");
}
