3 childs
/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 int main()
 printf("My name is Yash Parab\n");
 fork();
 fork();
 fork();
 printf("My roll no is: 46\n");
 return 0;*/






4(exit,wait)
/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t pid=fork();
printf("My name is Bhargav Patel\n");
if(pid==0)
{
printf("child process\n");
printf("Child process id %d and Parent process_id %d\n",getpid(), getppid());
char *args[]={"Hello", "SY", "AI-DS", NULL);
execv("./exforc2", args);
exit(EXIT_SUCCESS);
}
else if (pid>0)
{
printf("Parent process\n");
printf("Parent process_ id %d\n", getpid()); printf("Waiting for child to terminate\n");
wait(NULL);
printf(" Child got terminated\n");
}
else
printf("Unable to create process\n");
return 0;
}
*/
4.1(execv)
/*
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
printf("PID of exforcl.c = %d\n",getpid());
char *args[]={"Hello", "SY", "AI-DS", NULL};
execv("./exforc2", args);
printf("Back to exl.c");
}
return 0;*/

4.3(execv)
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
printf("We are in exforc2.c\n");
printf("PID of exforc2.c = %d", getpid());
}*/
