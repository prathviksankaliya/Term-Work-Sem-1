#include<stdio.h>
int strlength(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char str[] = "ppqqqyrtgfdreeennnnnnssggrrjfhg";
    int size = strlength(str);
    int start = 0;
    int end = 1;
    int res = 0;
    int ans = 0;

    while(end <= size)
    {
        if(str[start] == str[end] )
        {
            end++;
        }else{
            res = end - start;
            if(ans < res)
            {
                ans = res;
            }
            start = end;
            end++;
        }
        
    }
    printf("%d", ans);
}