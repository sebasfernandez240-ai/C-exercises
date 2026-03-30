#include <stdio.h>
#include <string.h>

int main(){
    char phone_number[17], number[10];
    printf("Enter your phone number (+34-9137324710-56): ");
    scanf("%s", phone_number);
    for (int i = 4; i < strlen(phone_number) - 3; i++){
        printf("%c", phone_number[i]);
    }
    printf("\n");

    return 0;
}