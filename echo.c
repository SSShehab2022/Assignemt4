#include <stdio.h>


char buffer[255];

int main()
{

    scanf("%[^\n]%c", buffer);

    printf("%s\n", buffer);




}
