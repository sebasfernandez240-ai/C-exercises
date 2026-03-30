#include <stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int total = (n * (n + 1)) / 2;
    printf("%d\n", total);
    return 0;
}