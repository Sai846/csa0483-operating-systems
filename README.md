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
step5:-End of program
