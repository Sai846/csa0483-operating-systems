# csa0483-operating-systems 
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
