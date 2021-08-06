#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
const int MSG_LENGTH=80;
int main(int argc, char** argv) 
{
    pid_t child_pid, my_pid,parent_pid;
    //pid_t wait;

    child_pid = fork();
    parent_pid = getppid();
    my_pid = getpid();

    int status=0;
    int* ptr;
    ptr = &status;

if(child_pid!=0 && child_pid>0){
    printf("Parent waits for child till it end itself.\n");
    waitpid(-1,ptr,WNOHANG);
    int a=0;
    while(a<4){
        sleep(1);
        printf("I wait for my child to end.\n");
        printf("Status:%d\n",status);
        a++;
    }
    //exit(0);
}
else if(child_pid==0){
            printf("Child starts work.\n");
            sleep(3); //zombie process for 3 seconds.
            printf("Child ends work.\n");
            exit(0);
        }

//system("ps");
}