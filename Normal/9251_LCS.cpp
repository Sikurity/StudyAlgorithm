#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int LCS[MAX_SIZE + 1][MAX_SIZE + 1];

char first_string[MAX_SIZE + 1];
char second_string[MAX_SIZE + 1];

int main(void)
{
    scanf("%s %s", first_string, second_string);
    
    size_t length_first_string = strlen(first_string);
    size_t length_second_string = strlen(second_string);
    
    for(int i = 1; i <= length_first_string; i++)
    {
        for(int j = 1; j <= length_second_string; j++)
        {
            if(first_string[i-1] == second_string[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = LCS[i-1][j] > LCS[i][j-1] ? LCS[i-1][j] : LCS[i][j-1];
        }
    }
    
    printf("%d", LCS[length_first_string][length_second_string]);
    
    return 0;
}
