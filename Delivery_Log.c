/*
 * Project: Delivery Tracker 2.0
 * Author: Sebas
 * Description: Manages shift data using dynamic memory and pointer manipulation.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day_number;
    float profit;
    char type[15];
}Shift;

void initializeShift(Shift log[], int n_days){
    int n_orders;
    float pay_per_order;
    for (int i = 0; i < n_days; i++){
        log[i].day_number = i + 1;
        printf("Day %d\n", i + 1);
        printf("Number of orders today: ");
        scanf("%d", &n_orders);
        printf("Pay per order: ");
        scanf("%f", &pay_per_order);
        log[i].profit = pay_per_order * n_orders;
        printf("Type of order(Morning, Afternoon, Night): " );
        scanf("%s", log[i].type);
    }
}

void printShift(Shift log[], int n_days){
    printf("---PERFORMANCE REPORT---\n");
    printf("Day | Shift Type | Net Profit\n");
    printf("--------------------\n");
    for (int i = 0; i < n_days; i++){
        printf("%d  | %s |  $%g \n", log[i].day_number, log[i].type, log[i].profit);
        printf("-----------------------\n");
    }
}
void allocateLog(Shift **log, int n_days) {
    // We dereference 'log' to reach the pointer in main and assign the memory
    *log = (Shift*)malloc(sizeof(Shift) * n_days);
    
    if (*log == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}


// And freeLog becomes simple again because it's a single block:
void freeLog(Shift **log) {
    free(*log);
    *log = NULL; // Good practice: prevent dangling pointers
}

int main(){
    int n_days;
    printf("Enter the number of worked days: ");
    scanf("%d", &n_days);
    Shift *log = NULL;
    allocateLog(&log, n_days);
    initializeShift(log, n_days);
    printShift(log, n_days);
    freeLog(&log);
    return 0;
}