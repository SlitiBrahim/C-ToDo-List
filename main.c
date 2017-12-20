#include "header.h"

int main() {
    // Task sport;

    // initTask(&sport);
    // debugTask(sport);

    displayWelcome();
    int inProgress = 1;
    while (inProgress) {
        userInput(&inProgress);
    }

    return 0;
}

void displayWelcome() {
    printf("ToDo List in C\n\n");
}

void userInput(int* ptInProgress) {

    printf("\nEnter Command: (help for commands) ");
    char command[100];
    fgets(command, sizeof(command), stdin);
    clearBuffer(command);

    // printf("Result: %s", command);
    interpret(command, ptInProgress);
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

void clearBuffer(char* command) {
    
    char* p;

    p = strchr(command, '\n');
    if (p) {
        *p = '\0';
    } else { while((getchar() != '\n') && (getchar() != EOF)); }
}

void helpDisplay() {
    printf("\ncreate:  create new task\n");
    printf("help:  display available commands\n");
    printf("done:  mark a specified task as done\n");
    printf("undone:  mark a specified task as undone\n");
    printf("exit:  Exit the program\n");
}

void interpret(char* command, int* ptInProgress) {

    if(strcmp("create", command) == 0) {
        printf("create");
    }
    else if(strcmp("help", command) == 0) {
        helpDisplay();
    }
    else if (strcmp("done", command) == 0)
    {
        printf("done");
    }
    else if (strcmp("undone", command) == 0)
    {
        printf("undone");
    }
    else if (strcmp("exit", command) == 0)
    {
        printf("\nThank you for having use my ToDo List\n");
        *ptInProgress = 0;
    }
    else {
        printf("Invalid Command, please type 'help' for displaying available commands");
    }
}