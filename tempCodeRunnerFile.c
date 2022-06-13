#include <stdio.h>
#include <stdlib.h>
#define max 8

int t[max] = {-1};
int sol = 1;
void printsol()
{
    int i, j;
    char crossboard[max][max];
    // Place all the positions as _
    // Place the Queens in its correct positions on each row

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (t[i] == j)
                crossboard[i][t[i]] = 'Q';
            else
                crossboard[i][j] = '-';
        }
    }

    // Print the Board

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            printf("%c ", crossboard[i][j]);
        }
        printf("\n");
    }
}
int empty(int i)
{
    int j = 0;
    while ((t[i] != t[j]) && (abs(t[i] - t[j]) != (i - j)) && j < max)
        j++;
    return i == j ? 1 : 0;
}
void queens(int i)
{
    for (t[i] = 0; t[i] < max; t[i]++)
    {
        if (empty(i))
        {
            if (i == max - 1)
            {
                printsol();
                printf("\n solution %d\n", sol++);
            }
            else
                queens(i + 1);
        }
    }
}

int main()
{
    queens(0);
    return 0;
}
