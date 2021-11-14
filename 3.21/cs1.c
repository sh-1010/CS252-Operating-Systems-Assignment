/*include necessary libraries*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/*Collatz function*/
int Collatz(int num)
{
    int count = 0;
    while (count != 1000)
    {
        if (num < 0)
        {
            printf("Enter a positive integer\n");
            return 0;
        }
        if (num == 1)
        {
            printf("%i ", num);
            return 0;
        }
        else if (num % 2 == 0)
        {
            printf("%i ", num);
            num = num / 2;
        }
        else
        {
            printf("%i ", num);
            num = num * 3 + 1;
        }
        count++;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    int num, stat_loc = 0; /*Num is the input from user*/
    pid_t pid;
    num = atoi(argv[1]);
    pid = fork();  /*To create a child process*/
    if (pid == -1) /*Child process creation unsucessful*/
    {
        printf("Child process didn't get created\n");
    }
    else if (pid == 0) /*In the  child process*/
    {
        Collatz(num);
    }
    else if (pid > 0) /*In parent process*/
    {
        wait(&stat_loc); /*Wait for child process to get complete*/
        printf("\n");
    }
    return 0;
}

// The above code was taken from https://www.youtube.com/watch?v=CQYF_onRnlk with a little changes.