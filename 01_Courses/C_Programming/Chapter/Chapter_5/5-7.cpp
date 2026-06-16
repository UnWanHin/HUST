#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// ?¥Í?ÌÛÊ^©w?
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

// ¨ç??©ú
void inputStudents(Student students[], int n);
void sortStudents(Student students[], int n);
void outputStudents(Student students[], int n);

int main() {
    Student students[MAX_STUDENTS];
    int choice, n;

    do {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            scanf("%d", &n);
            inputStudents(students, n);
            break;
        case 2:
            sortStudents(students, n);
            break;
        case 3:
            outputStudents(students, n);
            break;
        case 0:
            break;
        }
    } while (choice!= 0);

    return 0;
}


void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {

        scanf("%s %d", students[i].name, &students[i].score);
    }
}


void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].score < students[j].score) {
                int tempScore = students[i].score;
                students[i].score = students[j].score;
                students[j].score = tempScore;

    
                char tempName[MAX_NAME_LENGTH];
                strcpy(tempName, students[i].name);
                strcpy(students[i].name, students[j].name);
                strcpy(students[j].name, tempName);
            } else if (students[i].score == students[j].score) {
          
                if (strcmp(students[i].name, students[j].name) > 0) {
  
                    char tempName[MAX_NAME_LENGTH];
                    strcpy(tempName, students[i].name);
                    strcpy(students[i].name, students[j].name);
                    strcpy(students[j].name, tempName);

                
                    int tempScore = students[i].score;
                    students[i].score = students[j].score;
                    students[j].score = tempScore;
                }
            }
        }
    }
}


void outputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }
}
