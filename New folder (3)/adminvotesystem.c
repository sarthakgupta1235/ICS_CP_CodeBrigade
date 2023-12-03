#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define reset "\x1B[0m"
#define bold "\x1B[1m"
#include "votingprojectfunctions.c"


int main()
{
    cameo();
    int checkp;
    printf("%scounting votingsystem%s\n",bold,reset);
    while(1){
        printf("to check for specific candidate press (0)\nelse to check all candidates press(1)\nelse to check total votes press (2)\n:=> ");
        scanf("%d",&checkp);
        if(checkp==0 || checkp==1 || checkp==2){
            break;
        }else{printf("give correct instructions (%d) not executable", checkp);}
    }
    cameo();
            printf("%syour instructions are%s\n",bold,reset);
        if(checkp==0){ 
            printf("you want to know specific candidate's votes\n");
            quest0();
        }else if(checkp==1){
            printf("you want to know every specific candidate's votes\n");
            quest1();
        }else if(checkp==2){
            printf("you want to know total votes\n");
            quest2();
        }


    printf("done\n");
        // Prompt for user before clearing the console upon exiting
        {
            printf("\n%sPRESS (n) TO CLEAR THE CONSOLE:%s ", bold,reset);
            while(getchar()!='n');
            
            cameo();
            printf("exit\n");
        }
    return 0;
}
