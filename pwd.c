#include <unistd.h>
#include <stdio.h>


char buffer[255];

int main()
{
    printf("%s\n", getcwd(buffer, 255));
}
