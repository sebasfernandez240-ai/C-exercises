#include <stdio.h>
#include <string.h>

int changeDomain(char email[]){
    char domain[] = "@ceu.es";
    char newMail[50];
    int i = 0;

    while (email[i] != '@' && i < (int)strlen(email)){
        newMail[i] = email[i];
        i++;
    }


    if (i >= (int)strlen(email)){
        printf("It is not a valid email\n");
        return 0;
    }


    newMail[i] = '\0'; 

    printf("%s%s\n", newMail, domain);
    return 1;
}

int main(){
    char email[50];
    printf("Enter your email: ");
    scanf("%49s", email); 
    changeDomain(email);
    return 0;
}