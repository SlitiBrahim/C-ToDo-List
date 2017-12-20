#include "header.h"

int main() {

    int idIncrementor = 0;
    Task tasks[50];

    Task sport;
    initTask(&sport, &idIncrementor);
    strcpy(sport.name, "Do Sport");
    strcpy(sport.desc, "Eliminer les kebabs");
    // debugTask(sport);

    Task eat;
    initTask(&eat, &idIncrementor);
    strcpy(eat.name, "Mieux Manger");
    strcpy(eat.desc, "Haha");
    // debugTask(eat);

    tasks[0] = sport;
    tasks[1] = eat;

    int inProgress = 1;
    // userInput(&inProgress, tasks, &idIncrementor);
    
    displayWelcome();
    while (inProgress) {
        userInput(&inProgress, tasks, &idIncrementor);
        
    }

    return 0;
}

void displayWelcome() {
    printf("ToDo List in C\n\n");
}

void userInput(int* ptInProgress, struct Task *tasks, int* ptIdIncrementor) {

    // for(int i = 0; i < 2; i++) {
    //     printf("%s\n", tasks[i].name);
    // }

    printf("\nEnter Command: (help for commands) ");
    char command[100];
    fgets(command, sizeof(command), stdin);
    clearBuffer(command);

    interpret(command, ptInProgress, tasks, ptIdIncrementor);
}

void debugTask(struct Task task) {
    printf("Id: %d\n", task.id);
    printf("Name: %s\n", task.name);
    printf("Description: %s\n", task.desc);
    printf("Is Done ?: ");
    printf(task.isDone ? "true" : "false");
    printf("\nDate: %s\n", task.date);
}

void initTask(struct Task *ptTask, int* ptIdIncrementor) {
    ptTask->id = ++(*ptIdIncrementor);
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
    }
    // else { while((getchar() != '\n') && (getchar() != EOF)); }
}

void helpDisplay() {
    printf("\ncreate:  create new task\n");
    printf("help:  display available commands\n");
    printf("done:  mark a specified task as done\n");
    printf("undone:  mark a specified task as undone\n");
    printf("exit:  Exit the program\n");
}

void interpret(char *command, int *ptInProgress, struct Task *tasks, int *ptIdIncrementor)
{
    if(strcmp("create", command) == 0) {
        createCommand(tasks, ptIdIncrementor);
    }
    else if(strcmp("tasks", command) == 0) {
        for (unsigned i = 0; i < (*ptIdIncrementor); i++) {
            debugTask(tasks[i]);
        }
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

void createCommand(struct Task *tasks, int *ptIdIncrementor)
{   
    Task tmpTask;
    initTask(&tmpTask, ptIdIncrementor);
    // char tmpName[50] = {0};

    printf("Task's name: ");
    fgets(tmpTask.name, 50, stdin);
    clearBuffer(tmpTask.name);

    printf("Task's description: ");
    fgets(tmpTask.desc, 100, stdin);
    clearBuffer(tmpTask.desc);

    printf("Task's date: ");
    fgets(tmpTask.date, 50, stdin);
    clearBuffer(tmpTask.date);

    tmpTask.isDone = false;

    tasks[(*ptIdIncrementor - 1)] = tmpTask;    //inserting new task
}
