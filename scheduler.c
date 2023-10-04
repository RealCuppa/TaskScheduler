#include <stdio.h>
#include <time.h>
#include <unistd.h>

// Define a structure to represent a task
typedef struct {
    char name[50];
    int hour;
    int minute;
    void (*function)(void);  // Function pointer for the task function
} Task;

// Define functions for tasks
void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

// Function to execute tasks based on the schedule
void executeTasks(Task tasks[], int numTasks) {
    time_t currentTime;
    struct tm *localTime;

    while (1) {
        time(&currentTime);
        localTime = localtime(&currentTime);

        for (int i = 0; i < numTasks; ++i) {
            if (tasks[i].hour == localTime->tm_hour && tasks[i].minute == localTime->tm_min) {
                printf("Executing %s at %02d:%02d\n", tasks[i].name, tasks[i].hour, tasks[i].minute);
                tasks[i].function();  // Execute the task function
            }
        }

        sleep(60);  // Wait for one minute before checking again
    }
}

int main() {
    // Define tasks and their schedules
    Task tasks[] = {
        {"Task 1", 12, 0, task1},  // Task 1 scheduled at 12:00
        {"Task 2", 15, 30, task2}  // Task 2 scheduled at 15:30
    };

    int numTasks = sizeof(tasks) / sizeof(tasks[0]);

    // Start the task scheduler
    executeTasks(tasks, numTasks);

    return 0;
}
