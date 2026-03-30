#include <stdio.h>

int main(){
    char name[50]; 
    int n;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("%s", name);
    }

    return 0;
}