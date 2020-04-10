#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

int t1 = fork();

int t2 = fork();

if (t1 > 0 && t2 == 0){
    char*agrs[] = {"ps", "-ef" ,NULL};
    execvp("ps", agrs);
}
else if (t2 > 0 && t1 == 0){
    char*agrs[] = {"free", "-h", NULL};
    execvp("free", agrs);
}
return 0;
}
