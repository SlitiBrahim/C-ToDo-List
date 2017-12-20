#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Task Task;
struct Task {
    char name[50];
    char desc[100];
    bool isDone;
    char date[10];
};

// Function Declarations
void debugTask(struct Task task);
void initTask(struct Task *task);