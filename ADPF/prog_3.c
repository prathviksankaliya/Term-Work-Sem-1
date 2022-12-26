#include <stdio.h>
#include <string.h>

void sort(char str[], int n)
{
    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int fun(char str1[], char str2[], int str1len, int str2len)
{
    int count = 0;
    int flag = 0;
    for (int i = 0; i < str1len; i++)
    {
        for (int j = 0; j < str2len; j++)
        {
            if (str1[i] == str2[j])
            {
                flag = 1;
                if (i == j)
                {
                    count++;
                }
            }
            else if (j == str2len - 1 && flag == 0)
            {
                return -1;
            }
        }
    }
    return count;
}
int main()
{
   
    char str1[100];
    char str2[100];
    printf("Enter the First String : ");
    scanf("%s",str1);

    printf("Enter the Second String : ");
    scanf(" %s",str2);
    if (strlen(str1) != strlen(str2))
    {
        printf("%d", -1);
    }
    else
    {
        char str1Temp[strlen(str1)];
        char str2Temp[strlen(str2)];
        strcpy(str1Temp, str1);
        strcpy(str2Temp, str2);
        sort(str1Temp, strlen(str1));
        sort(str2Temp, strlen(str2));
        if (strcmp(str1Temp, str2Temp) == 0)
        {
            printf("%d", fun(str1, str2, strlen(str1), strlen(str2)));
        }else{
            printf("%d", -1);
        }
    }
}

// #include <stdio.h>
// #include <string.h>

// int Check_anagram(char str1[], char str2[]) {
//     int s_freq[26] = {0};
//     int t_freq[26] = {0};
//     for (int i = 0; i < strlen(str1); i++) {
//         s_freq[str1[i] - 'a']++;
//     }
//     for (int i = 0; i < strlen(str2); i++) {
//         t_freq[str2[i] - 'a']++;
//     }
//     for (int i = 0; i < 26; i++) {
//         if (s_freq[i] != t_freq[i]) {
//             return -1;
//         }
    
//     int count = 0;
//     for (int i = 0; i < strlen(str1); i++) {
//         if (str1[i] == str2[i]) {
//             count++;
//         }
//     }
//     return count;
// }
// }
// int main(){
//     char str1[50];
//     char str2[50];

//     printf("Enter the First String : ");
//     scanf("%s",str1);

//     printf("Enter the Second String : ");
//     scanf(" %s",str2);

//     printf("%d ",Check_anagram(str1,str2));
//     return 0;
// }