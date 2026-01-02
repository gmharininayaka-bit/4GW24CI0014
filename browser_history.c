#include <stdio.h>
#include <string.h>

#define MAX 10

char history[MAX][50];
int top = -1;

/* Visit a new page (PUSH) */
void visitPage() {
    if (top == MAX - 1) {
        printf("Browser history is full!\n");
        return;
    }
    top++;
    printf("Enter website URL: ");
    scanf("%s", history[top]);
    printf("Visited: %s\n", history[top]);
}

/* Go back (POP) */
void goBack() {
    if (top == -1) {
        printf("No previous pages!\n");
        return;
    }
    printf("Going back from: %s\n", history[top]);
    top--;
}

/* Display browser history */
void displayHistory() {
    if (top == -1) {
        printf("No browsing history!\n");
        return;
    }
    printf("\nBrowser History:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", history[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Browser History Simulation ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Display History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitPage();
                break;
            case 2:
                goBack();
                break;
            case 3:
                displayHistory();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}