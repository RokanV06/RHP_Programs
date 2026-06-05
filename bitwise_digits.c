#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[1000001];
    scanf("%s", str);

    int flag = 0;

    for(int i = 0; str[i]; i++)
    {
        flag = flag | (1 << (str[i] - '0'));
    }

    if(flag == (1<<10) - 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}