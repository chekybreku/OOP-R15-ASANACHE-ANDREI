#include <stdio.h>

int my_strlen(char s[][101], int i)
{
    int j=0,nr = 0;

    for (; s[i][j] != '\0'; j++)
        nr++;

    return nr;
}

int my_strcmp(char s[][101], int i,int j)
{
    int l;
    for (l = 0; s[i][l] != '\0'; l++)
    {
        if (s[i][l] - s[j][l] < 0)
            return -1;
        else if (s[i][l] - s[j][l] > 0)
            return 1;
    }

    return 0;
}
void strswap(char s[][101], int i, int j)
{
    int l=0;
    while (s[i][l] != '\0' && s[j][l]!='\0')
    {
        char aux=s[i][l];
        s[i][l] = s[j][l];
        s[j][l] = aux;
        l++;
    }

    if (s[i][l] != '\0')
    {
        int lc = l;
        while (s[i][l] != '\0')
        {
            s[j][l] = s[i][l];
            l++;
        }
        s[j][l] = '\0';
        s[i][lc] = '\0';
    }
    while (s[j][l] != '\0')
    {
        int lc = l;
        while (s[j][l] != '\0')
        {
            s[i][l] = s[j][l];
            l++;
        }
        s[i][l] = '\0';
        s[j][lc] = '\0';
    }
}


int main()
{
    int i = 0, j = 0, n, m, jm = -1,a,b,nrlit[51];
    char x[101],s[51][101],rez[51][101];

    while (scanf_s("%100s", x, 101)) {
        
        for (j = 0; x[j] != '\0';j++)//parcurg cuvantul si pun litera cu litera in matrice
            s[i][j] = x[j];
        s[i][j] = '\0';
        i++;
        if (jm < j)
            jm = j;

        if (getchar() == '\n')
            break;
    }

    jm++;
    n = i;

    for (i = 0; i < n ; i++)//creez vector de lungime de cuvinte
        nrlit[i] = my_strlen(s,i);

    for (i = 0; i < n-1; i++)// ordonez cuvintele dupa marimea lor din vecotrul de lungime si daca au lungimi egale le ordonez descrescator dupa codul ASCII
    {
        for (j = i + 1; j < n; j++)
        {
            if (nrlit[i] < nrlit[j])
            {
                int aux = nrlit[i];
                nrlit[i] = nrlit[j];
                nrlit[j] = aux;

                strswap(s, i, j);
            }
            else if (nrlit[i] == nrlit[j])
                if (my_strcmp(s, i, j) < 0)
                    strswap(s, i, j);
        }
    }

    for (i = 0; i < n; i++)
        printf("%s\n", s[i]);

    getchar();
  
    return 0;
}