Programming exercise 3.21
The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
n =
{ n∕2, if n is even
3 × n + 1, if n is odd
The conjecture states that when this algorithm is continually applied,
all positive integers will eventually reach 1. For example, if n = 35, the
sequence is
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1
Write a C program using the fork() system call that generates this
sequence in the child process. The starting number will be provided
from the command line. For example, if 8 is passed as a parameter on
the command line, the child process will output 8, 4, 2, 1. Because the
parent and child processes have their own copies of the data, it will be
necessary for the child to output the sequence. Have the parent invoke
the wait() call to wait for the child process to complete before exiting
the program. Perform necessary error checking to ensure that a positive
integer is passed on the command line.

Solution approach:
The progrram needs to generate the pattern using a child process so fork() system call is used.
Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.
The wait() function suspends processing until a child process has ended.So the parent process is completed after the child process executes using wait() system call.

How to compile and run
Using the command line 
Compile: gcc \<filename>.c
Run: ./a.out \<parameter>
