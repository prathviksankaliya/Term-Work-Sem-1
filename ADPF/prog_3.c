#include <stdio.h>

int strlength(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int fun(char str1[], char str2[], int str1len, int str2len)
{
        int count = 0;
        int flag = 0;
        for (int i = 0; i < str1len; i++)
        {
            for(int j = 0; j < str2len; j++)
            {
                if(str1[i] == str2[j])
                { 
                    flag = 1;
                    if(i == j)
                    {
                        count++;
                    }
                }else if(j == str2len-1 && flag == 0){
                    
                        return -1;
                }
            }
        }
        return count;
}
int main()
{
    char str1[] = "turingmachine";
    char str2[] = "turingmachime";
    int str1Len = strlength(str1);
    int str2Len = strlength(str2);

    if (str1Len != str2Len)
    {
        printf("%d", -1); 
    }
    else
    {
        printf("%d", fun(str1, str2, str1Len, str2Len));
    }
}