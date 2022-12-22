**Question 1**
In this Question we have to make a total 3 C files

file 1 :
    Since we cant do strict ordering here we use semaphores on the philosophers

    This means that when a semaphores decreases in value then both the right and the left 
    fork are picked up at once

    A philosopher checks both the left and the right philosophers, if their values are 1
    then the philosophers starts eating since that means both the forks are free

file 2 :
    Here we strictly order the requests of fork by creating the forks as semaphores.

    in fork i and fork j for a philosopher, if i > j, then fork i is called first.

    However this can cause a deadlocks, so for any one of the philosophers the order
    is reversed

file 3 :
    Along the lines of file 2 we add another semaphore "bowl" initialised with value 2

    This semaphore can be called twice, thus letting the philosophers eat from the bowl in
    an unordered fashion.

    They can call the bowl and if either of the two initialised in the semaphore are empty
    then they are allowed to eat

    Ofcourse the forks also have to be available

file 4 :
	In this program we add another bowl semaphore along with the philosophers
	
	We can clearly see that the resources are not requested in a particular order

**Question 2**
We create 6 C files for this Question

FIFO :
    We need to make 2 FIFO pipes since they are uni-directional

    We write into one of the pipes from the client side and then wait for
    a second using the sleep() function for the server to read the data

    The server reads the fifth string and prints it out

    Then the server sends the same string back to the client and the 
    client acknowledges by printing out the string it receives in the
    buffer

SOCKET :
    Here we need to make one socket only

    We can use read and write function to 
    read and write strings in the socket.

    A certain set of functions need to be followed for
    both the client and the server side

    Client : 


    Server :


SHARED MEMORY :
    Here we makes a shared memory segment with the same key in both the files

    The memory segment is pointed at with a pointer, in which
    we cope the strings we want to send between the processes

    We MUST use the sleep function to coordinate the accessing of the shared memory block

**Question 3**
    Here we create a kernel module with the required syscall which finds the process id
    we input.

    we need to define the init function which is executed at the starting 

    we also need to define the exit function which is executed just before exiting

    in the init function we get the task struct and print the necessary data

    to actually run the file we write the following command

    in the directory first we use the "make" command

    then we use the "insmod ./file.ko id=x" command

    x is the int we enter

    the demsg to see the kernel log where at the end we will find the desired output