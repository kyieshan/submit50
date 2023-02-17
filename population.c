#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int get_int_check(string prompt);

int main(void)
{
    // prompt for start size
    int start = get_int_check("Start size: ");

    // prompt for end size
    int end = get_int_check("End size: ");
    while (end < start)
    {
        printf("End size must be greater than or equal to start size.\n");
        end = get_int_check("End size: ");
    }

    // keep track of number of years
    int years = 0;

    // update population until we reach threshold
    while (start < end)
    {
        start += start / 3 - start / 4;
        years++;
    }

    // print number of years
    printf("Years: %d\n", years);
}

// function to prompt user for integer input with error checking
int get_int_check(string prompt)
{
    int value;
    char input[10];
    bool valid_input = false;
    do
    {
        value = 0;
        printf("%s", prompt);
        scanf("%s", input);
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (isdigit(input[i]))
            {
                value = value * 10 + (input[i] - '0');
                valid_input = true;
            }
            else
            {
                valid_input = false;
                break;
            }
        }
    }
    while (!valid_input);
    return value;
}
