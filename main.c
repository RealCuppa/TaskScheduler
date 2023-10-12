#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char name[50];
    char description[100];
    // Add other attributes like scheduled time, etc.
};

struct Task taskList[MAX_TASKS];
int numTasks = 0;  // Keep track of the number of tasks

void inputTask(struct Task *task) {
    printf("Enter task name: ");
    fgets(task->name, sizeof(task->name), stdin);
    task->name[strcspn(task->name, "\n")] = '\0';  // Remove newline character

    printf("Enter task description: ");
    fgets(task->description, sizeof(task->description), stdin);
    task->description[strcspn(task->description, "\n")] = '\0';  // Remove newline character
}

void scheduleTask(struct Task *task) {
    // Implement scheduling logic (e.g., set scheduled time)
    // For simplicity, let's assume the tasks are scheduled immediately.

    // Add the task to the task list
    taskList[numTasks] = *task;
    numTasks++;
}

void displayTasks() {
    if (numTasks == 0) {
        printf("No tasks scheduled.\n");
    } else {
        printf("Scheduled tasks:\n");
        for (int i = 0; i < numTasks; i++) {
            printf("Task %d:\n", i + 1);
            printf("Name: %s\n", taskList[i].name);
            printf("Description: %s\n", taskList[i].description);
            // Print other task details
            printf("\n");
        }
    }
}

int main() {
    int choice;
    struct Task newTask;

    do {
        printf("Task Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Schedule Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character in the buffer

        switch (choice) {
            case 1:
                inputTask(&newTask);
                break;
            case 2:
                scheduleTask(&newTask);
                printf("Task scheduled successfully!\n");
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                printf("Exiting Task Scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
