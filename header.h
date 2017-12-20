#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #define TASK_MEMBER_SIZE 100;

typedef struct Task Task;
struct Task {
    unsigned id;
    char name[50];
    char desc[100];
    bool isDone;
    char date[10];
};

// Function Declarations
void displayWelcome();
void userInput(int *ptInProgress, struct Task *tasks, int *ptIdIncrementor);
void debugTask(struct Task task);
void initTask(struct Task *ptTask, int *ptIdIncrementor);
void clearBuffer(char *command);
void interpret(char *command, int *ptInProgress, struct Task *tasks, int *ptIdIncrementor);
void createCommand(struct Task *tasks, int *ptIdIncrementor);
void taskInput(char displayMsg[], int propLength, char taskMember[]);
void display(struct Task *tasks, int *ptIdIncrementor);
void displayTask(struct Task task);
void displayHeaderList();
void doneCommand(struct Task *ptTask, bool isDone);
int selectTaskId(char doneOrUndone[], int *ptIdIncrementor);