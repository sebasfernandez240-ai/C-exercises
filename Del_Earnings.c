#include <stdio.h>
#include <stdlib.h>

float calculate_total(float ppd, int n_del, float gas){
    float multiplier;
    int bonus;

    printf("Was there a high demand bonus?(1-.Yes/0-.No): ");
    scanf("%d", &bonus);
    if (bonus == 1){
        multiplier = 1.2;
    }
    else{
        multiplier = 1;
    }
    float total = (ppd * n_del * multiplier) - gas;
    return total;
}

int best_earning(float array[], int n){
    float max = array[0];
    int index = 0;
    for (int i = 1; i < n; i++){
        if (array[i] > max){
            max = array[i];
            index = i;
        }
    }
    return index;
}

int main(){
    float ppd,gas;
    int n_days,n_del, index;
    printf("Number of worked days: ");
    scanf("%d", &n_days);
    float *earnings = (float*)malloc(sizeof(float) * n_days);
    for (int i = 0; i < n_days; i++){
         printf("Enter the pay per delivery of day %d: ", i + 1);
         scanf("%f", &ppd);
         printf("Enter the number of deliveries made day %d: ", i + 1);
         scanf("%d", &n_del);
         printf("Gas spent day %d: ", i + 1);
         scanf("%f", &gas);
        *(earnings + i)= calculate_total(ppd, n_del, gas);
    }
    index = best_earning(earnings, n_days);

    for (int i = 0; i < n_days; i++){
        printf("Day %d: %g $\n", i + 1, *(earnings + i));
    }
    printf("The best earning day was the %d day with %g $\n", index + 1, *(earnings + index));
    free(earnings);
    return 0;
}