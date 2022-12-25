#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char hexaValue[10];
    int digit = 0;
    int decimalNumber = 0;
    int count = 0;
    int flag = 1;

    printf("Enter Value of HexaDecimal : \n");
    scanf("%s", &hexaValue);

    int sizeOfHexaValue = strlen(hexaValue);

    for (int i = sizeOfHexaValue - 1; i >= 0; i--)
    {
        if (hexaValue[i] == 'A' || hexaValue[i] == 'a')
        {
            digit = 10;
        }
        else if (hexaValue[i] == 'B' || hexaValue[i] == 'b')
        {
            digit = 11;
        }
        else if (hexaValue[i] == 'C' || hexaValue[i] == 'c')
        {
            digit = 12;
        }
        else if (hexaValue[i] == 'D' || hexaValue[i] == 'd')
        {
            digit = 13;
        }
        else if (hexaValue[i] == 'E' || hexaValue[i] == 'e')
        {
            digit = 14;
        }
        else if (hexaValue[i] == 'F' || hexaValue[i] == 'f')
        {
            digit = 15;
        }
        else if (hexaValue[i] > 'F' && hexaValue[i] <= 'Z' || hexaValue[i] > 'f' && hexaValue[i] <= 'z')
        {
            printf("Plz Enter Valid HexaDecimal \n Number between 0 to 9 or A to F!!\n");
            flag = 0;
            break;
        }
        else if (hexaValue[i] <= 9 || hexaValue[i] >= 0)
        {
            digit = hexaValue[i] - 48; // ex. B65 - ascii value of 5 = 53 - 48 (ascii of 0) = 5 input value
        }

        decimalNumber += digit * pow(16, count);
        count++;
    }
    if (flag != 0)
    {
        printf("Decimal Value is : %d\n", decimalNumber);
    }

    return 0;
}

// #include<stdio.h>
// #include<string.h>
// #include<math.h>

// int main()
// {
//     char hexaValue[10];
//     int digit = 0;
//     int decimalNumber = 0;
//     int count = 0;
//     int flag = 1;

//     // retry :

//     printf("Enter Value of HexaDecimal : \n");
//     scanf("%s", &hexaValue);

//     int sizeOfHexaValue = strlen(hexaValue);

//     for(int i = sizeOfHexaValue - 1; i >= 0; i--)
//     {
//         if(hexaValue[i] >= 'A' || hexaValue[i] <= 'F')
//         {
//             digit = hexaValue[i] - 65 + 10;
//         }else if(hexaValue[i] >= 'a' || hexaValue[i] <= 'f')
//         {
//             printf("%c", hexaValue[i]);
//             digit = hexaValue[i] - 97 + 10;
//         }
//         else if (hexaValue[i] > 'F' && hexaValue[i] <= 'Z' || hexaValue[i] > 'f' && hexaValue[i] <= 'z')
//         {
//             printf("Plz Enter Valid HexaDecimal \n Number between 0 to 9 or A to F!!\n");
//             flag = 0;
//             break;
//         }else if(hexaValue[i] <= 9 || hexaValue[i] >= 0){
//             digit = hexaValue[i] - 48; //ex. B65 - ascii value of 5 = 53 - 48 (ascii of 0) = 5 input value
//         }
//         printf("%d \n", digit);
//         decimalNumber += digit * pow(16, count);
//         count++;
//     }
//     if (flag != 0)
//     {
//         printf("Decimal Value is : %d\n", decimalNumber);
//     }
//     // goto retry;

//     return 0;
// }
