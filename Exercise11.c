#include <stdio.h>
#include <string.h>

int CapVowel(char string[], char vowel){
    char lower[5] = "aeiou";
    char capital[5] = "AEIOU";
    int index = 0;
    while(vowel != lower[index] && index < 5){
        index++;
    }
    if (index >= 5){
        printf("Itś not a vowel");
        return 0;
    }
    for (int i = 0; i < strlen(string); i++){
        if (string[i] == vowel){
            string[i] = capital[index];
        }
    }
    return 1;
}

int main(){
    char phrase[50];
    char vowel;
    printf("Enter your name: ");
    fgets(phrase, sizeof(phrase),stdin);
    printf("Enter a vowel: ");
    scanf(" %c", &vowel);
    CapVowel(phrase, vowel);
    printf("%s", phrase);
    return 0;
}