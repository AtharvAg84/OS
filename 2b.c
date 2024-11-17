// What Are System Calls?
// System calls are functions provided by the operating system (OS) that allow user-level programs to request services from the kernel (the core part of the OS). These calls provide an interface for programs to interact with hardware, manage processes, perform file I/O, allocate memory, etc. System calls serve as the primary mechanism for programs to interact with the OS.

// Examples of common system calls include:

// fork(): Creates a new process.
// exec(): Replaces the current process with a new one.
// exit(): Terminates the current process.
// wait(): Waits for a child process to terminate.
// read() and write(): Used for reading from and writing to files.
// open() and close(): Used to open and close files.
// How Are System Calls Different from Normal Function Calls?
// Purpose:

// System Calls: These are used to request services from the operating system. They provide an interface to the kernel, which runs in a privileged mode and has direct access to hardware resources.
// Normal Function Calls: These are calls within the user-space application (i.e., between functions of the program itself), and they don’t involve the kernel or OS services.
// Execution Mode:

// System Calls: When a system call is made, the program transitions from user mode (where regular applications run) to kernel mode (where the OS code executes). This is called a context switch.
// Normal Function Calls: These are executed in user mode and do not cause a context switch.
// Overhead:

// System Calls: Calling a system call is more expensive than a normal function call because it involves switching from user mode to kernel mode and involves more complexity, such as error handling and context switching.
// Normal Function Calls: These are executed directly within the program and don’t involve mode switching or OS overhead.
// fork() System Call
// The fork() system call is used to create a new process by duplicating the calling process. The new process created by fork() is called a child process, and the original process is called the parent process. After the fork() call, both the parent and the child process continue executing the program from the point where fork() was called.

// Return Value of fork():
// In the parent process, fork() returns the PID (Process ID) of the child process.
// In the child process, fork() returns 0.



#include <stdio.h>
#include <unistd.h>  // For fork()
#include <sys/types.h>  // For pid_t

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred while forking
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // This block is executed by the child process
        printf("Child process: My PID is %d, Parent's PID is %d\n", getpid(), getppid());
    } else {
        // This block is executed by the parent process
        printf("Parent process: My PID is %d, Child's PID is %d\n", getpid(), pid);
    }

    return 0;
}
