#include<stdio.h>

int f(int num, int count)
{
    //Base
    if(num == 1)
    {
        return count;
    }else{
        // Recursive Fun
        if(num%2 == 0)
        {
            return f(num/2, ++count);
        }else{
            return f(3*num+1, ++count);
        }
    }
}
int main()
{
    int n;
    int count = 0;
    printf("Enter N : \n");
    scanf("%d", &n);
    printf("Ans is : %d", f(n, count));
    return 0;
}