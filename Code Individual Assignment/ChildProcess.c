#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    //mendeklarasikan variabel
    int Jumlah_ChildProcess;
    pid_t ChildProcessID;

    //input jumlah child process dari pengguna
    printf("Jumlah Child Process: ");
    scanf("%d", &Jumlah_ChildProcess);

    //membuat child process sebanyak input pengguna
    for (int i = 0; i < Jumlah_ChildProcess; i++){
        ChildProcessID = fork();

        if (ChildProcessID == 0){
            //membuat child process
            printf("Child Process (Process ID: %d) sedang berjalan\n", getpid());
            exit(0);
        } else if (ChildProcessID > 0){
            //membuat parent process
            printf("parent process (Process ID: %d) telah membuat child process (Process ID: %d\n)", getpid(), ChildProcessID);
        } else {
            printf("Child Process gagal dimuat\n");
        }
    }

    wait(NULL);

    return 0;
}