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
