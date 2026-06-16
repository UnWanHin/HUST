#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NAME_LEN 50
typedef struct Student {
    char id[20];
    char name[NAME_LEN];
    float english;
    float math;
    float physics;
    float c_programming;
    float average;
    struct Student* next;
} Student;
Student* createNode(char* id, char* name, float english, float math, float physics, float c_programming) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) {
        exit(1);
    }
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    newNode->english = english;
    newNode->math = math;
    newNode->physics = physics;
    newNode->c_programming = c_programming;
    newNode->average = (english + math + physics + c_programming) / 4.0;
    newNode->next = NULL;
    return newNode;
}
void addStudent(Student** head, char* id, char* name, float english, float math, float physics, float c_programming) {
    Student* newNode = createNode(id, name, english, math, physics, c_programming);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printStudents(Student* head, int isAveragePrinted) {
    Student* temp = head;
    while (temp != NULL) {
        printf("%s %s ", temp->id, temp->name);
        if (isAveragePrinted) {
            printf("%.2f ", temp->english);
            printf("%.2f ", temp->math);
            printf("%.2f ", temp->physics);
            printf("%.2f\n", temp->c_programming);
        } else {
            if (floor(temp->english) == temp->english) {
                printf("%d ", (int)temp->english);
            } else {
                printf("%.2f ", temp->english);
            }
            if (floor(temp->math) == temp->math) {
                printf("%d ", (int)temp->math);
            } else {
                printf("%.2f ", temp->math);
            }
            if (floor(temp->physics) == temp->physics) {
                printf("%d ", (int)temp->physics);
            } else {
                printf("%.2f ", temp->physics);
            }
            if (floor(temp->c_programming) == temp->c_programming) {
                printf("%d\n", (int)temp->c_programming);
            } else {
                printf("%.2f\n", temp->c_programming);
            }
        }
        temp = temp->next;
    }
}
void modifyStudent(Student* head, char* id, int choice, float newValue) {
    Student* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            switch (choice) {
                case 1:
                    temp->english = newValue;
                    break;
                case 2:
                    temp->math = newValue;
                    break;
                case 3:
                    temp->physics = newValue;
                    break;
                case 4:
                    temp->c_programming = newValue;
                    break;
            }
            temp->average = (temp->english + temp->math + temp->physics + temp->c_programming) / 4.0;
            return;
        }
        temp = temp->next;
    }
}
void printAverages(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("%s %s ", temp->id, temp->name);
        printf("%.2f\n", temp->average);
        temp = temp->next;
    }
}
void printTotalAndAverage(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        float total = temp->english + temp->math + temp->physics + temp->c_programming;
        printf("%s %s %d %.2f\n", temp->id, temp->name, (int)total, temp->average);
        temp = temp->next;
    }
}
int main() {
    Student* head = NULL;
    int choice, n;
    char id[20], name[NAME_LEN];
    float english, math, physics, c_programming;
    char modifyId[20];
    int modifyChoice;
    float newValue;
    int isAveragePrinted = 0;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                while (head != NULL) {
                    Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            case 1:
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    scanf("%s %s %f %f %f %f", id, name, &english, &math, &physics, &c_programming);
                    addStudent(&head, id, name, english, math, physics, c_programming);
                }
                break;
            case 2:
                printStudents(head, isAveragePrinted);
                break;
            case 3:
                scanf("%s %d %f", modifyId, &modifyChoice, &newValue);
                modifyStudent(head, modifyId, modifyChoice, newValue);
                break;
            case 4:
                printAverages(head);
                isAveragePrinted = 1;
                break;
            case 5:
                printTotalAndAverage(head);
                break;
        }
    }
    return 0;
}
