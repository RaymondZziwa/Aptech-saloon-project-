#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(){
struct client
{
    char name[50];
    char address[100];
    char contact[10];
};
char treat[]={"treatment"};
char wash[]={"washing"};
char hair[]={"weave"};
char choice[50];
FILE *dt;
char resp[5];
char new[5];
char hol[]={"yes"};
char pay[70];
int sum,hairp = 20000;
char extra[50];
char accpt[]={"yes"};
struct client rom;
/*welcoming the client to the saloon*/
printf("WELCOME TO SPARKLES UNISEX SALOON\n");
/*gathering personal info*/
printf("Are you willing to provide personal info?(yes or no)\n");
gets(resp);
if(strcmp(resp, accpt)==0)
    {
        /*collecting client personal info.*/
        printf("Enter client's name..\n");
        gets(rom.name);
        printf("Enter client's address..\n");
        gets(rom.address);
        printf("Enter client's contact..\n");
        gets(rom.contact);
        /*choice of hair by client*/
        printf("What hairstyle do want to do\n");
        gets(choice);
        /*client choice*/
            if(strcmp(choice, hair)==0){
                printf("Please have seat.We are going to work on you..\n");
                /*other services needed by client */
                printf("Do you want any extra services?(yes or no)\n");
                gets(new);
                    if(strcmp(new, hol)==0){
                            printf("Extra services available include; washing which costs UGX 15000 and treatment which costs UGX 20000\n");
                            printf("Any extra service that we can provide??\n");
                            gets(extra);
                                if(strcmp(extra, wash)==0){
                                    sum = hairp+15000;
                                    printf("Total cost is going to be :UGX %d..\n",sum);
                                }
                                else if (strcmp(extra, treat)==0){
                                    sum = hairp+20000;
                                    printf("Total cost is going to be :UGX %d..\n",sum);
                                }
                    }
                    else{
                        printf("You have not chosen any extra service so you will only be charged for the hair\n");
                        printf("You will be charged :UGX %d..\n",hairp);
                    }
                printf("\nHow are you going to checkout? By use of mobile money, credit card or cash\n");
                gets(pay);                /*no error till this point*/
                /*payment*/
                printf("You have chosen to pay with :%s\n",pay);
                /*exit of client from saloon and storage of personal info*/
                printf("It has been a pleasure to serve you..see you soon\n");
                dt=fopen("c:\\Users\\Zziwa Raymond Ian\\Desktop\\saloon_data.txt","w");
                if(dt!=NULL){
                    printf("saloon_data file creation was successful..\n");
                }
                else{
                    printf("file opening operation failed");
                }
                    fprintf(dt,"%s\t%s\t%s\t%s\t%d",rom.name,rom.address,rom.contact,choice,sum);
                }
            else{
                printf("The service requested is not currently available.Please try again later..");
            }
    }
    else{
        printf("Please we cant work on you as a result of your refusal to provide personal data!!");
        exit(0);
    }
}
