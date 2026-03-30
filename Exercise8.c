#include <stdio.h>
#include <string.h>

void MinusString(char string[], char minus[], char capitals[]){
    int string_length = strlen(string);
    int lookup_len = strlen(minus);
    for (int i = 0; i < string_length; i++){
        for (int j = 0; j < lookup_len; j++){
            if (string[i] == capitals[j]){
                string[i] = minus[j];
                break; // Stop looking once replaced
            }
        }
    }
}

void CapitlizeString(char string[], char minus[], char capitals[]){
    int string_length = strlen(string);
    int lookup_len = strlen(minus);
    for (int i = 0; i < string_length; i++){
        for (int j = 0; j < lookup_len; j++){
            if (string[i] == minus[j]){
                string[i] = capitals[j];
                break; // Stop looking once replaced
            }
        }
    }
}

void FixString(char string[], char minus[], char capitals[]) {
    // 1. Lowercase everything first
    MinusString(string, minus, capitals);
    
    int string_length = strlen(string);
    int lookup_len = strlen(minus);
    
    for (int i = 0; i < string_length; i++) {
        // 2. Only check for a swap if it's the start of a word
        if (i == 0 || string[i - 1] == ' ') {
            for (int j = 0; j < lookup_len; j++) {
                if (string[i] == minus[j]) {
                    string[i] = capitals[j];
                    break; 
                }
            }
        }
    }
}

int main(){
    char Cletters[] = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    char Mletters[] = "abcdefghijklmnñopqrstuvwxyz";
    char name[50];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    
    // Remove the newline character added by fgets
    name[strcspn(name, "\n")] = 0;

    printf("Original/Minus: ");
    MinusString(name, Mletters, Cletters);
    printf("%s\n", name);

    printf("All Caps:       ");
    CapitlizeString(name, Mletters, Cletters);
    printf("%s\n", name);

    printf("Fixed Format:   ");
    FixString(name, Mletters, Cletters);
    printf("%s\n", name);

    return 0;
}