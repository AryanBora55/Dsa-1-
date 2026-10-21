#include <stdio.h>

#define SIZE 5

struct que {
    int jobid;
    char title[20];
};

int front = 0, rear = 0, count = 0;

struct que q[SIZE];

int isFull()
{
    return count == SIZE;
}

void Addition(struct que elem)
{
    if (!isFull()) {
        q[rear] = elem;
        rear = (rear + 1) % SIZE;
        count++;
        printf("Element added.\n");
    }
    else {
        printf("Queue is full.\n");
    }
}

int isEmpty()
{
    return count == 0;
}

void Deletion()
{
    struct que save;

    if (!isEmpty()) {
        save = q[front];

        printf("Deleted element:\n");
        printf("Job ID: %d\n", save.jobid);
        printf("Title: %s\n", save.title);

        front = (front + 1) % SIZE;
        count--;
    }
    else {
        printf("Queue is empty.\n");
    }
}

void Display()
{
    int i, j;

    if (!isEmpty()) {
        printf("\nQueue elements:\n");

        i = front;

        for (j = 0; j < count; j++) {
            printf("Job ID: %d\n", q[i].jobid);
            printf("Title: %s\n", q[i].title);

            i = (i + 1) % SIZE;
        }
    }
    else {
        printf("Queue is empty.\n");
    }
}

int main()
{
    struct que elem;
    int choice;

    do {
        printf("\n1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter jobid and title: ");
                scanf("%d %19s", &elem.jobid, elem.title);
                Addition(elem);
                break;

            case 2:
                Deletion();
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
