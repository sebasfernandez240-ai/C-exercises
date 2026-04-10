#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    float grade;
} Student;

int main() {
    int n_students;
    Student* classroom_1;

    printf("Enter the amount of students: ");
    scanf("%d", &n_students);
    getchar(); 

    classroom_1 = (Student*)malloc(sizeof(Student) * n_students);
    if (classroom_1 == NULL) return 1;

    FILE *students_data = fopen("studentsdata.txt", "w");
    if (students_data == NULL) {
        free(classroom_1);
        return 1;
    }

    for (int i = 0; i < n_students; i++) {
        printf("\n--- STUDENT %d ---\n", i + 1);
        
        printf("Name: ");
        fgets(classroom_1[i].name, 50, stdin);
        
        for(int j=0; j<50; j++) if(classroom_1[i].name[j] == '\n') classroom_1[i].name[j] = '\0';

        printf("ID: ");
        scanf("%d", &classroom_1[i].id);

        do {
            printf("Grade: ");
            scanf("%f", &classroom_1[i].grade);
        } while (classroom_1[i].grade > 100 || classroom_1[i].grade < 0);
        
        getchar(); 

        fprintf(students_data, "ID: %d | Name: %s | Grade: %.2f\n", 
                classroom_1[i].id, classroom_1[i].name, classroom_1[i].grade);
    }

    fclose(students_data);
    free(classroom_1);
    printf("\nData saved to studentsdata.txt\n");
    return 0;
}