#include <stdio.h>
#include <unistd.h>  // For fork() and sleep()
#include <stdlib.h>  // For exit()

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
        printf("Child process: My PID is %d, Parent's PID was %d\n", getpid(), getppid());

        // Sleep for a few seconds to give the parent time to exit
        sleep(5);

        // After the parent exits, check the new parent PID (should be 1, i.e., init)
        printf("Child process: After sleep, my new parent is %d\n", getppid());
    } else {
        // This block is executed by the parent process
        printf("Parent process: My PID is %d, and I am exiting now.\n", getpid());

        // Terminate the parent process immediately
        exit(0);
    }

    return 0;
}
