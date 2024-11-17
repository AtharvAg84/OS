#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process: sleep for a while to simulate work
        printf("Child process: My PID is %d, Parent's PID is %d\n", getpid(), getppid());
        sleep(5);  // Sleep for 5 seconds
        printf("Child process: I am exiting now. My PID is %d\n", getpid());
        exit(0);  // Child exits, but becomes a zombie because parent hasn't called wait()
    } else {
        // Parent process: Does not call wait, so child becomes a zombie
        printf("Parent process: My PID is %d, and I am not calling wait().\n", getpid());
        // Sleep for a while to let the child become a zombie
        sleep(10);  // Parent sleeps longer than child so the child becomes a zombie
        printf("Parent process: After child exits, I am still alive.\n");
        // The parent is still alive and has not cleaned up the child
        // The child process will be a zombie process until the parent terminates.
    }

    return 0;
}
