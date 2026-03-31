#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

char* TranslateWord(char *word){
    int len = strlen(word);
    char *transWord = NULL;
    int isVowel = 0;
    char first = tolower(word[0]);


    if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
        isVowel = 1;
    }

    if (isVowel) {
        
        transWord = (char*)malloc(len + 4);
        sprintf(transWord, "%sway", word);
    } 
    else {
        transWord = (char*)malloc(len + 3);
        
       
        sprintf(transWord, "%s%cay", word + 1, first);
    }

    return transWord;
}

int main(){
    char word[50];
    printf("Enter word: ");
    scanf("%49s", word);

    char *neword = TranslateWord(word);
    
    if (neword != NULL) {
        printf("Pig Latin: %s\n", neword);
        free(neword); 
    }

    return 0;
}