#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_password(char* ppassword)
{
    printf("Enter the password\n");
    scanf("%s", ppassword);
//    printf("%s\n", ppassword);
    return;
}

void check_password(int* presult,char *password)
{
//    printf("%s", password);
//    return;
    char* temp[50];
    FILE* fp = fopen("database", "r");
    if(0 == fp)
    {
        printf("Failed to open the file\n");
//        return 0;
    }
    printf("1\n");
    while(!feof(fp)) 
    {
        fscanf(fp, "%12s", temp);
        printf("%s\n", temp);
        printf("2\n");
        *presult = strcmp(*temp, password);
    }
    printf("%d------\n", *presult);
}

int main(int argc, char **argv)
{
    char *password;
    int result = 1;
    password = (char*) malloc(16 * sizeof(char));
    while(1)
    {
        get_password(password);
        check_password(& result, password);
    }

    printf("----------------%d\n", result);
    return 0;
}
