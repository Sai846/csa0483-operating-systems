# CSA0483-operating-systems 
1.system calls currently running process and parent display same.\
Algorithm:-\
step1:Include necessary header files like stdio.h,stdlib.h,unistd.h,sys/types.h\
step2:-use the fork()system call to create new process\
step3:-check if forking is successfull\
step4:-GetprocessID's(use getpid()systemcallto get process ID of child process and parentprocess)\
step5:-Display process IDs(print process ID and parent processID)\
step6:-End of Algorithm

2.systemcall to copy content from one file to another file\
Algorithm:-\
step1:-Include libraries(headerfiles like stdio.h,stdlib.h,fcntl.h,unistd.h)\
step2:-open source and destination files\
step3:-check if files are opened successfully\
step4:-Read content from source file\
step5:-write content to destination file\
step6:-close file(use 'close()'system callto close both source an destination file)\
step7:-End of Algorithm

3.Design CPU scheduling algorithm with c using FCFStechnique\
a.All process are activated time 0\
b.Assume no process in I/O devices\
Algorithm:-\
step1:-Include libraries(header file like stdio.h)\
step2:-Define process structure\
step3:-Input process data\
step4:-calculate waiting time and turnaroundtime\
step5:-calculate average waiting time and turnaroundtime\
step6:-Display process information\
step7:-End of Algorithm
4.ccode for scheduling select waiting process with executiontime to execute next\
Algorithm:-\
step1:-Input given by user wih n number of process\
step2:-sort process based on burst time\
step3:-Initialise variables(current time,completed process)\
step4:-process scheduling\
step5:-display output\
step6:-End of program

5.scheduling program with c select waitingprocess to execute next\
Algorithm:-\
step1:-Input(enter number of process)\
step2:-sort process based on priority(highest to lowest)\
step3:-Initialize variables(currenttime,completedprocess)\
step4:-process scheduling\
step5:-display the output\
step6:-End of program

6.c program to implement preemptive priority scheduling algorithm\
Algorithm:-\
step1:-Input(enter number of process)\
step2:-Initialise variables\
step3:-process scheduling\
step4:-display output\
st7.cprogram to implement nonpreemptive sjf algorithm\
Algorithm:-\
step1:-Input(Enter number of process)\
step2:-sort the process based on their burst time in ascending order\
step3:-Initialisation
step4:-for each process from 1 to n\
step5:-calculate average waiting time\
step6:-calculate average turnaroundtime\
step7:-End of program

8.cprogram to simulate roundrobin scheduling algorithm with c\
Algorithm:-\
step1:-Input(number of processes)\
step2:-Initialise an empty queue to store process\
step3:-while there are processed in queue or any process has remaining bursttime\
step4:-End of program

9.the concept of interprocess communication using shared memory with c program\
Algorithm:-
step1:-create shared memory segment to process\
step2:-Attach share memory segment to process\
step3:-Read\write data to\from sharedmemory\
step4:-Detach share memory segment\
step5:-Remove shared memory segment\
step6:-End of program

10.cprogram for interprocessing communication using messagequeue\
Algorithm:-\
step1:-create a message queue\
step2:-send a message\
step3:-Recieve a message\
step4:-Remove the message queue\
step5:-End of program

11.c program for multithreading
Algoritm:-\
step1:-Include necessary header file\
step2:-Define the threadfunction\
step3:-create threads\
step4:-join threads\
step5:-compile and run program\
step6:-End of program

12.cprogram for Dining Philosophers problem\
Algorithm:-\
step1:-Initialization\
step2:-philospher behaviour\
step3:-Handling forks\
step4:-synchronization\
step5:-Implementation using loop\
step6:-End of programep5:-End of program
