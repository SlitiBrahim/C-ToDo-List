#include "header.h"

int main() {
    Task sport;

    // debugTask(sport);
    initTask(&sport);
    debugTask(sport);
}

void debugTask(struct Task task) {
    printf("Name: %s\n", task.name);
    printf("Description: %s\n", task.desc);
    printf("Is Done ?: ");
    printf(task.isDone ? "true" : "false");
    printf("\nDate: %s\n", task.date);
}

void initTask(struct Task *ptTask) {
    strcpy(ptTask->name, "Undefined");
    strcpy(ptTask->desc, "Undefined");
    strcpy(ptTask->name, "Undefined");
    ptTask->isDone = false;
    strcpy(ptTask->date, "Undefined");
}