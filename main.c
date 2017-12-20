#include "header.h"

int main() {

    int idIncrementor = 0;
    Task tasks[50];
    int inProgress = 1;
    
    displayWelcome();
    while (inProgress) {
        userInput(&inProgress, tasks, &idIncrementor);
        
    }

    return 0;
}

void displayWelcome() {
    printf("=== ToDo List in C ===\n");
    printf("=== Author: SLITI Brahim ===\n");
    printf("=== GitHub: https://github.com/SlitiBrahim/C-ToDo-List ===\n");

    printf("\n");
}

void userInput(int* ptInProgress, struct Task *tasks, int* ptIdIncrementor) {

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
}

void helpDisplay() {
    printf("\ncreate:  create new task\n");
    printf("help:  display available commands\n");
    printf("tasks:  display taks to achieve\n");
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
        display(tasks, ptIdIncrementor);
    }
    else if(strcmp("help", command) == 0) {
        helpDisplay();
    }
    else if (strcmp("done", command) == 0)
    {
        int selectedId = selectTaskId("done", ptIdIncrementor);

        if (selectedId) {
            doneCommand(&tasks[--selectedId], true);
        }
        else {
            printf("Invalid Task ID, please select a right one.");
        }

    }
    else if (strcmp("undone", command) == 0)
    {
        int selectedId = selectTaskId("done", ptIdIncrementor);

        if (selectedId)
        {
            doneCommand(&tasks[--selectedId], false);
        }
        else
        {
            printf("Invalid Task ID, please select a right one.");
        }
    }
    else if (strcmp("exit", command) == 0)
    {
        printf("\nThank you for having used my ToDo List\n");
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

    taskInput("Task's name: ", 50, tmpTask.name);
    taskInput("Task's description: ", 100, tmpTask.desc);
    taskInput("Task's date: ", 50, tmpTask.date);

    tmpTask.isDone = false;

    tasks[(*ptIdIncrementor - 1)] = tmpTask;    //inserting new task

    printf("\nTask created successfully.\n");
    displayHeaderList();
    displayTask(tasks[(*ptIdIncrementor - 1)]);
    printf("\n");
}

void taskInput(char displayMsg[], int propLength, char taskMember[]) {
    printf("%s", displayMsg);
    fgets(taskMember, propLength, stdin);
    clearBuffer(taskMember);
}

void display(struct Task *tasks, int *ptIdIncrementor) {

    displayHeaderList();

    for (unsigned i = 0; i < (*ptIdIncrementor); i++) {
        displayTask(tasks[i]);
    }

    printf("\n");
}

void displayTask(struct Task task) {

    printf("\n%d\t\t\t", task.id);
    printf("%s\t\t\t", task.name);
    printf("%s\t\t\t", task.desc);
    printf(task.isDone ? "Done" : "Not done");
    printf(strcmp(task.date, "") == 0 ? "\t\t\tNot Defined" : "\t\t\t%s", task.date);

}

void displayHeaderList() {

    printf("\nTask ID\t\t\t");
    printf("Task Name\t\t\t");
    printf("Task Description\t\t\t");
    printf("Status\t\t\t");
    printf("\t\t\tTask End Date");

    printf("\n");
}

int selectTaskId(char doneOrUndone[], int *ptIdIncrementor) {

    unsigned tmpId = 0;

    printf("\nSelect the id of the task you want to mark as %s: ", doneOrUndone);
    scanf("%d", &tmpId);
    while ((getchar() != '\n') && (getchar() != EOF));

    if (tmpId > 0 && tmpId <= (*ptIdIncrementor)) {
        return tmpId;
    }

    return -1;
}

void doneCommand(struct Task *ptTask, bool isDone) {
    ptTask->isDone = isDone;
}