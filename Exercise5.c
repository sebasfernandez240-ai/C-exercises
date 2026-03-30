#include <stdio.h>

int main(){
    float pph, total_payment;
    int wh;
    printf("Pay per hour: ");
    scanf("%f", &pph);
    printf("Worked hours: ");
    scanf("%d", &wh);
    total_payment = wh * pph;
    printf("Total payment: %f\n", total_payment);
    return 0;
}