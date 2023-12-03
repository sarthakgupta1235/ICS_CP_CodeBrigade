#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define reset "\x1B[0m"
#define bold "\x1B[1m"
typedef struct{
    char id[9];
    int vote;
}datar;

//screen clearing      
void cameo(){
            //printf("**** please press enter to continue: ");
            
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif
        }


    /////functions for voters


    //to open problem statement and return total number of candidates
        int questionare(){
            FILE *quiz=fopen("problemstatement.txt","r");
                int nom; 
                if(quiz==NULL){
                    printf("sorry voting statement doesnt exist\n");
                    fclose(quiz);
                    return -1000;
                }else{
                    printf("\n");
                    fscanf(quiz,"%d\n",&nom);
                        //read the first number to find number of candidates for proper entry from voter
                    char *q=malloc(sizeof(char));
                    while((*q=fgetc(quiz))!=EOF){
                        printf("%c",*q);
                    }
                    free(q);
                    fclose(quiz);
                }
            return nom;
        }

    //checks if you are voting again
        int cram(char trans[]){
            FILE *ptr=fopen("datauserin.txt","r");
            if(ptr==NULL){
                printf("cant open data file itself now\n");
                return 5;
            }else{
                char *tempstr=strdup(trans);
                datar *data=malloc(sizeof(datar));

                while(fscanf(ptr,"%9s %d", data->id,&data->vote)!=EOF){
                    if(strcmp(tempstr,data->id)==0){
                        fclose(ptr);
                        free(data);
                        free(tempstr);
                        return 1;
                    }
                }
                fclose(ptr);
                free(data);
                free(tempstr);
            }
            return 0;
        }

    //voting if eligible
        void voting(char id[]){
            FILE *ptr=fopen("datauserin.txt","a");
            if(ptr==NULL){
                printf("sorry data file itself doesnt exist so cant vote\n");
                return;
            }else{
                datar *pf=(datar *)malloc(sizeof(datar));
                strcpy(pf->id, id);
                
                    
                    int *terminal;
                    terminal =(int *)malloc(sizeof(int));
                    *terminal=0;
                    int *nom=malloc(sizeof(int));

                    

                        do{
                            if(*terminal>0){
                                *terminal = 0;
                                cameo();
                                printf("\n\n**please vote correctly from given options only**\n\n");
                            }
                            *nom=questionare();
                            if(*nom==-1000){break;}
                            printf("\n\nplease vote the number corresponding to the candidate of your choice: ");
                            scanf("%d",&(pf->vote)); //depend on the candidates have to change code
                            *terminal++;
                        }while((pf->vote)>*nom || (pf->vote)<1 );



                        if(*nom!=-1000){
                            fprintf(ptr, "%s %d\n",pf->id,pf->vote);
                        }else{
                            fclose(ptr);
                            return;
                        }


                        printf("\nyour vote is for candidate (%d)\n",pf->vote);

                        
                    free(terminal);
                    free(nom);
                    free(pf);
                    fclose(ptr);
            }
            return;
        }

    //extra
    void ping(char inp[]){
        cameo();
        printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
        printf("write correct id (capitals not allowed)\n");
    }
    //to check id validity
        int checkid(char inp[]){
            if(inp[0]=='@' && inp[1]=='!'){
                return 100;
            }
            if(inp[0]=='b'||inp[0]!='m'){
                if(inp[3]=='b'){
                    if(inp[4]=='b');else{ping(inp); return 0;}
                }else if(inp[3]=='e'){
                    if(inp[4]=='e' ||inp[4]=='s');else{ping(inp); return 0;}
                }else if(inp[3]=='m'){
                    if(inp[4]=='e'||inp[4]=='t'||inp[4]=='a');else{ping(inp); return 0;}
                }else if(inp[3]=='c'){
                    if(inp[4]=='m'||inp[4]=='i'||inp[4]=='h'||inp[4]=='y'||inp[4]=='s');else{ping(inp); return 0;}
                }else if(inp[3]=='a'){
                    if(inp[4]=='i');else{ping(inp); return 0;}
                }else if(inp[3]=='p'){
                    if(inp[4]=='h');else{ping(inp); return 0;}
                }
            }
            for(int i=0;i<9;i++){
                if(i==0 || i==3 || i==4){
                    if(inp[i]<97||inp[i]>122){
                        cameo();
                        printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
                        printf("write correct id (capitals not allowed)\n");
                        return 0;
                    }
                }else{
                    //
                    if(inp[i]<48 || inp[i]>57){
                        cameo();
                        printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
                        printf("write correct id (capitals not allowed)\n");
                        return 0;
                    }
                }
                //special year case for 2023 only
                if(inp[1]>'2'){
                    cameo();
                    printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
                    printf("write correct id (max year registered is 2023) not 20%c%c\n", inp[1],inp[2]);
                    return 0;
                }else if(inp[1]='2'){
                    if(inp[2]>'3'){
                        cameo();
                        printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
                        printf("write correct id (max year registered is 2023) not 20%c%c\n", inp[1],inp[2]);
                        return 0;
                    }
                }
                if(inp[5]>'1'){
                    cameo();
                    printf("%sid that you gave (%s) is not registered%s\n",bold,inp,reset);
                    printf("write correct id please\n");
                    return 0;
                }
            }
            cameo();
            return 1;
        }



//////////functions for admin

    //counts number of votes given the candidate's number
        int func(int n){
            int result=0;
            FILE *ptr=fopen("datauserin.txt","r");
            if(ptr==NULL){
                printf("cant open data file itself now\n");
                fclose(ptr);
                return 0;
            }else{
                int tempno;
                char tempid[9];
                while (fscanf(ptr, "%s %d", tempid, &tempno) == 2) {
                    if (tempno == n) {
                        result++;
                    }
                }
            fclose(ptr);
            return result;
            }
        }

    //for quest0 specific candidate
        void quest0(){
            int candidate; //select candidate
            int nom; //nominees number
            FILE *quiz=fopen("problemstatement.txt","r");
                if(quiz==NULL){
                    printf("sorry voting statement doesnt exist\n");
                    fclose(quiz);
                    return;
                }else{
                    printf("\n");
                    fscanf(quiz,"%d\n",&nom);
                        //read the first number to find number of candidates for proper entry from voter
                    char *q=malloc(sizeof(char));
                    while((*q=fgetc(quiz))!=EOF){
                        printf("%c",*q);
                    }
                    printf("\n");
                    free(q);
                    fclose(quiz);
                }
            do{
                printf("%schoose which candidate's votes you want to check:%s ",bold,reset);
                scanf("%d", &candidate);
            }while(candidate<0 || candidate>nom);
            printf("good\n");
            printf("%sVOTES FOR THE CANDIDATE (%d) is =%s %d\n",bold,candidate,reset,func(candidate));
        }

    //for quest1 all candidates
        void quest1(){
            int nom; //nominees number
            FILE *quiz=fopen("problemstatement.txt","r");
                if(quiz==NULL){
                    printf("sorry voting statement doesnt exist\n");
                    fclose(quiz);
                    return;
                }else{
                    printf("\n");
                    fscanf(quiz,"%d\n",&nom);
                        //read the first number to find number of candidates for proper entry from voter
                    char *q=malloc(sizeof(char));
                    while((*q=fgetc(quiz))!=EOF){
                        printf("%c",*q);
                    }
                    printf("\n");
                    free(q);
                    fclose(quiz);
                }
            printf("\n");
            for(int i=0;i<nom;i++){
                printf("%sVOTES FOR THE CANDIDATE (%d) is =%s %d\n",bold,i+1,reset,func(i+1));
            }
        }

    //for quest2 total votes
        void quest2(){
            int total=0;
            int nom; //nominees number
            FILE *quiz=fopen("problemstatement.txt","r");
                if(quiz==NULL){
                    printf("sorry voting statement doesnt exist\n");
                    fclose(quiz);
                    return;
                }else{
                    printf("\n");
                    fscanf(quiz,"%d\n",&nom);
                        //read the first number to find number of candidates for proper entry from voter
                    char *q=malloc(sizeof(char));
                    while((*q=fgetc(quiz))!=EOF){
                        printf("%c",*q);
                    }
                    printf("\n");
                    free(q);
                    fclose(quiz);
                }
            printf("\n");
            for(int i=0;i<nom;i++){
                total+=func(i+1);
            }
            printf("%sTOTAL VOTES FOR (%d) CANDIDATES is =%s %d\n",bold,nom,reset,total);
        }
