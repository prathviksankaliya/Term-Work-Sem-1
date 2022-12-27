#include<stdio.h>

int reverse()
{
    char str;
    scanf("%c", &str);
    if(str != '\n')
    {
        reverse();
        printf("%c", str);
    }
    // //Base
    // if(size == 0)
    // {
    //     return str[0];
    // }else{
    //     printf("%c", str[size]);
    //     return reverse(str, size - 1);
    // } 
}
int main()
{
    reverse();
    return 0;
}