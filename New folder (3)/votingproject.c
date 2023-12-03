#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "votingprojectfunctions.c"
#define reset "\x1B[0m"
#define bold "\x1B[1m"

int main()
{
    int exitcode;
            int tester;
    cameo();
            char *nam=(char *)malloc((9)*(sizeof(char)));
    do{
        if(tester== 100){
            exitcode = 1;
            break;
        }
        printf("\n\nplease write 9 characters in your id\nfor example if your id is (b21me043) you should write it as (b23me0043)\n\n");
        printf("%sGIVE YOUR I.D for voting:%s ",bold,reset);
        scanf("%9s", nam);
        tester=checkid(nam);
    }while(tester==0 || tester ==100);

    if(exitcode==1){
        cameo();
        printf("forced exit\n");
        return 0;
    }
    printf("%syour id is%s (%s)\n",bold,reset,nam);
    int check=cram(nam);


//checking if we can vote or not and then voting
    {
        if(check==0){
            printf("you are eligible for voting\n");
            voting(nam);
        }else if(check==5){
            printf("sorry error\n");
        }else if(check==1){
            printf("vote already registered under your name\n");
            printf("you cant vote again\n");
        }
    }
    
    
    free(nam);
    printf("done\n");
    // Prompt user before clearing the console upon exiting
    {
        printf("\n%sPRESS (n) TO CLEAR THE CONSOLE:%s ", bold,reset);
        while(getchar()!='n');
        
        cameo();
        printf("exit\n");
    }
    return 0;
}