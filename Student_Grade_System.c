#include <stdio.h>
#include <stdlib.h>

float *get_grades(int n){
    float *grades;
    grades = (float*)malloc(sizeof(float) * n);

    for (int i = 0; i < n; i++){
        printf("Student %d grade: ", i + 1);
        scanf("%f", (grades + i));
    }

    return grades;
}

void sort(float array[], int n){
    float temp; 
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

float average(float array[], int n){
    float total = 0;
    for (int i = 0; i < n; i++){
        total += *(array + i);
    }
    float average = total / n;
    return average;
}

char assign_score(float score){
    if (score >= 90 && score <= 100){
        return 'A';
    }
    if(score >= 80){
        return 'B';
    }
    if (score >= 70){
        return 'C';
    }
    if (score >= 60){
        return 'D';
    }
    if (score <= 59 && score >= 0){
        return 'F';
    }
    return 'x';
}

void printArrFloat(float array[], int n){
    for (int i = 0; i < n; i++){
        printf("%g\t", *(array + i));
    }
    printf("\n");
}

void printArrChar(char array[], int n){
    for (int i = 0; i < n; i++){
        printf("%c\t", *(array + i));
    }
    printf("\n");
}

int main(){
    int n_students;
    float *grades;
    float avg, highest, lowest;
    do {
        printf("Number of students: ");
        scanf("%d", &n_students);
    }while(n_students <= 0 || n_students > 100);
    grades = get_grades(n_students);
    char *scores = (char*)malloc(sizeof(char) * n_students);
    sort(grades, n_students);
    avg = average(grades, n_students);
    highest = *(grades + (n_students - 1));
    lowest = *grades;
    for (int i = 0; i < n_students; i++){
        *(scores + i) = assign_score(*(grades + i));
    }
    printf("Scores: \n");
    printArrFloat(grades, n_students);
    printArrChar(scores, n_students);
    printf("Average: %g\nHighest: %g\nLowest: %g\n", avg, highest, lowest);
    return 0;
}