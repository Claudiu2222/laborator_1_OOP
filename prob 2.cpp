//PROBLEMA 2
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include<cstring>
#include<cmath>
using namespace std;
int functieStringToNumber(char number[200])
{
    int sizeString = strlen(number);
    int numberUpdated = 0;
    for (int i = 0; i < sizeString; i++)
    {
        numberUpdated += pow(10, sizeString - i - 1) * (number[i] - '0');
    }
    return numberUpdated;

}
bool verificareString(char number[200])
{
    for (int i = 0; i < strlen(number); i++)
    {
        if (isdigit(number[i]) == 0)
            return false;
    }
    return true;
}
int main()
{
    FILE* fileProblemaUnu;
    fileProblemaUnu = fopen("in.txt", "r");
    if (fileProblemaUnu != NULL)
    {
        int okk = 0;
        unsigned sum = 0;
        char myString[200];
        while (fgets(myString, 200, fileProblemaUnu))
        {

            myString[strlen(myString) - 1] = '\0';
            if (verificareString(myString) == true)
                sum += functieStringToNumber(myString);
            else
            {
                printf("VALOAREA INSERATA NU ESTE UN NUMAR!");
                okk = 1;
                break;
            }
        }
        if (okk == 0)
            printf("SUMA ESTE : %d", sum);
        fclose(fileProblemaUnu);

    }
    else
    {
        printf("EROARE DESCHIDERE FISIER");
    }



    return 0;
}