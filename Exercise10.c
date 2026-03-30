#include <stdio.h>
#include <string.h>

int main(){
    char phrase[50], reversed[50];
    printf("Enter a phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    int j = 0;
    for (int i = strlen(phrase) - 1; i > -1; i--){
        reversed[j] = phrase[i];
        j++;
    }
    printf("%s", reversed);
    return 0;
}