//PROBLEMA 3
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    FILE* fileProblemaDoi;
    fileProblemaDoi = fopen("in.txt","r");
    if(fileProblemaDoi != NULL)
    {   int k =0;
       char matrice[30][50];
        char myString[200];
        while (fgets(myString, 200, fileProblemaDoi))
        {
            myString[strlen(myString) - 1] = '\0';
            char *p;
            p=strtok(myString," ");
            while(p)
            {
                strcpy(matrice[++k],p);
                p = strtok(NULL, " ");
            }

        }

    for(int i=1;i<k;i++)
     for(int j=i+1;j<=k;j++)
     {
         if(strlen(matrice[i]) < strlen(matrice[j]))
            swap(matrice[i],matrice[j]);
        else if(strlen(matrice[i]) == strlen(matrice[j]))
        {
            if(strcmp(matrice[i] , matrice[j]) > 0)
                swap(matrice[i],matrice[j]);
        }

     }
     for(int i =1;i<=k;i++)
     {
         printf("%s\n",matrice[i]);
     }



fclose(fileProblemaDoi);
    }
    else
    {
        printf("EROARE DESCHIDERE FISIER");
    }



    return 0;
}
