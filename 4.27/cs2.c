/*include necessary libraries*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
/*Data section shared by all the threads*/
int n;                 // size of fibonacci sequence.
int *fibseq;           // array holds the value of each fibonacci term.
int i;                 // counter for the threads.
void *runn(void *arg); /*Threads call this function*/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("format is:./a.out <intgervalue>\n");
        return -1;
    } // valdiate num of args.
    if (atoi(argv[1]) < 0)
    {
        printf("%d must be>=0\n", atoi(argv[1]));
        return -1;
    } // valdiate value of arg1.
    n = atoi(argv[1]);
    fibseq = (int *)malloc(n * sizeof(int));
    pthread_t *threads = (pthread_t *)malloc(n * sizeof(pthread_t));
    pthread_attr_t attr;      // set of thread attribute
    pthread_attr_init(&attr); // set default attributes of the threads
    for (i = 0; i < n; i++)
    {
        pthread_create(&threads[i], &attr, runn, NULL); // Create the thread
    }                                                   // End of creating threads.
    int j;
    for (j = 0; j < n; j++)
    {
        pthread_join(threads[j], NULL); // Wait for threads to exit.
    }

    // printing fibseq.

    printf("The Fibonacci sequence.:");

    int k;

    for (k = 0; k < n; k++)

    {

        printf("%d ", fibseq[k]);

    } // End of printing fibseq.
    printf("\n");
    return 0;

} // End of main.

void *runn(void *arg)

{

    if (i == 0)

    {

        fibseq[i] = 0;

        pthread_exit(0);

    } // first fib term

    if (i == 1)

    {

        fibseq[i] = 1;

        pthread_exit(0);

    } // seconed fib term

    else

    {

        fibseq[0] = 0;

        fibseq[1] = 1;

        fibseq[i] = fibseq[i - 1] + fibseq[i - 2];

        // printf("fibseq[%d]%d,\n",i,fibseq[i]);

        pthread_exit(0); // thread exit.
    }                    // End of else
} // End of run.

//The above code is taken from https://www.codegrepper.com/code-examples/c/Fibonacci+program+c+pthread with added comments.