#include "CMakeProject2.h"

void print(int num)
{
    bool neg = false;
    if (num < 0)
    {
        num *= -1;
        neg = true;
    }
    int rev = 0, len = 0;
    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
        len++;
    }
    if (len == 0)
    {
        putchar('0');
    }
    if (neg)
    {
        putchar('-');
    }
    while (rev != 0)
    {
        putchar(rev % 10 + '0');
        rev /= 10;
        len--;
    }
    for (int i = 0; i < len; i++)
    {
        putchar('0');
    }
    putchar('\n');
}

int scan(int& str)
{
    int num = 0;
    bool stop = false, neg = false, error = false, first = true;
    while(!stop)
    {
        char c = getchar();
        if (c == '-' && first)
        {
            neg = true;
        }
        else if (c == '+' && first)
        {

        }
        else if (c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
        }
        else if(c == ' ' || c == '\n')
        {
            stop = true;
        }
        else
        {
            error = true;
            stop = true;
        }
        first = false;
    }
    if (neg)
    {
        num *= -1;
    }
    str = num;
    if (error)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int main()
{
    int a;
    printf("Enter an integer:\n");
    if (scan(a) == EXIT_SUCCESS)
    {
        print(a);
        printf("\n");
    }
    else
    {
        printf("Not an integer number was entered.\n\n");
    }
    print(10000);
    print(-10);
    print(1406450);
    print(0);
    print(-254);
    print(-0);
    print(91823765);
    return 0;
}
