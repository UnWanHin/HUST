#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void inputStudents(Student students[], int n);
void sortStudents(Student students[], int n);
void outputStudents(Student students[], int n);
void binarySearch(Student students[], int n, int target);
int main() {
    Student students[MAX_STUDENTS];
    int choice, n;
    do {
        scanf("%d", &choice);
        ;
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
        case 4:
        	{
        	int target;
            scanf("%d", &target);
            binarySearch(students, n, target);
            break;
			}
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
        printf("%s %d\n", students[i].name, &students[i].score);
    }
}
void binarySearch(Student students[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int found = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].score == target) {
            int i = mid;
            while (i >= 0 && students[i].score == target) {
                i--;
            }
            i++;
            for (; i < n && students[i].score == target; i++) {
                printf("%s %d\n", students[i].name, students[i].score);
            }
            found = 1;
            break;
        } else if (students[mid].score > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (!found) {
        printf("not found\n");
    }
}
