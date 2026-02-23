#include <stdio.h>

int char2int(char x[])
{
    int val=0,i=0;

    for (i = 0; x[i]>='0' && x[i]<='9'; i++)
        val = val * 10 + (x[i] - '0');

    return val;
}

int main() {

    char x[101];
    int var = 0, s=0;

    FILE* file;

    fopen_s(&file, "ini.txt", "r");
   
    if (file == NULL)
    {
        printf("Eroare\n");
        return 0;
    }

    while (fgets(x, 101, file))
        s+=char2int(x);

    printf("%d",s);

    fclose(file);

    getchar();

    return 0;
}
