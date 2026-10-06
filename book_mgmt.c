
// DSA- Assignment 2 
// Q. Write a menu driven Book management system that utilizes a singly linked list to handle operations such as adding , removing and displaying books , as well as searching for a specific books and count number of books available.
// Book.mgmt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    struct Book *next;
};

struct Book *head = NULL;

void addBook() {
    struct Book *newBook;
    newBook = (struct Book *)malloc(sizeof(struct Book));
    printf("Enter Book ID: ");
    scanf("%d", &newBook->id);
    printf("Enter Book Name: ");
    scanf(" %s", newBook->name);
    newBook->next = head;
    head = newBook;
    printf("Book added successfully!\n");
}

void removeBook() {
    int id;
    struct Book *temp = head;
    struct Book *prev = NULL;
    printf("Enter Book ID to remove: ");
    scanf("%d", &id);
    if (head != NULL && head->id == id) {
        head = head->next;
        free(temp);
        printf("Book removed successfully!\n");
        return;
    }
    
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Book not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Book removed successfully!\n");
}

void displayBooks() {
    struct Book *temp = head;
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("\n--- Book List ---\n");
    while (temp != NULL) {
        printf("Book ID: %d\n", temp->id);
        printf("Book Name: %s\n", temp->name);
        printf("----------------\n");

        temp = temp->next;
    }
}

void searchBook() {
    int id;
    struct Book *temp = head;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Book found!\n");
            printf("Book ID: %d\n", temp->id);
            printf("Book Name: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
}

void countBooks() {
    int count = 0;
    struct Book *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of books: %d\n", count);
}

int main() {
    int choice;
    do {
        printf("\n===== BOOK MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Search Book\n");
        printf("5. Count Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                removeBook();
                break;

            case 3:
                displayBooks();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                countBooks();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
