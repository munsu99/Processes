// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    if (fork() < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fork() == 0)
    {
        x = 50;
        printf("Hello from Child! x is %d\n", x);
    }
    else
    {
        x = 500;
        printf("Hello from Parent! x is %d\n", x);
    }

    printf("%d\n",x);
    return 0;
}