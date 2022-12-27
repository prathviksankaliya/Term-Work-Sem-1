#include <stdio.h>
int hcf(int no1, int no2)
{
    if (no2 != 0)
    {
        return hcf(no2, no1 % no2);
    }
    else
    {
        return no1;
    }
}
int main()
{
    int no1, no2;
    printf("Enter two numbers: ");
    scanf("%d %d", &no1, &no2);
    printf("hcf is :%d", hcf(no1, no2));
    return 0;
}