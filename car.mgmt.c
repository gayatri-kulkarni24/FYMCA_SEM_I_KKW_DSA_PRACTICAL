// Q. Implement  a car management system using doubly linked list which will maintain a list of a car models ,their price, name of the manufacturer ,engine capacity etc.  as a doubly linked list. The menu should make provisions for inserting information pertaining to new car model , delete obsolete models, update data such as price besides answering queries ,such as listing all car models within a price range specifid by the client and listing all details of a car model.
// car_mgmt.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
    char model[50];
    char manufacturer[50];
    float price;          
    int engine;           
    struct Car *prev;
    struct Car *next;
};

struct Car *head = NULL;

void insertCar(){
    struct Car *newCar, *temp;
    newCar = (struct Car *)malloc(sizeof(struct Car));
    printf("\nEnter car model: ");
    scanf(" %s", newCar->model);
    printf("Enter manufacturer: ");
    scanf(" %s", newCar->manufacturer);
    printf("Enter price: ");
    scanf("%f", &newCar->price);      
    printf("Enter engine capacity: ");
    scanf("%d", &newCar->engine);     
    
    newCar->prev = NULL;
    newCar->next = NULL;
    
    if (head == NULL){
        head = newCar;
    }else{
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
            
        temp->next = newCar;
        newCar->prev = temp;
    }
    printf("\nCar inserted successfully!\n");
}

void deleteCar(){
    char model[50];
    struct Car *temp;
    printf("\nEnter model to delete: ");
    scanf(" %s", model);
    temp = head;
    while (temp != NULL){
        if (strcmp(temp->model, model) == 0){
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;
                
            free(temp);
            printf("\nCar deleted successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model not found!\n");
}
void updatePrice(){
    char model[50];
    float newPrice;
    struct Car *temp = head;
    printf("\nEnter model to update: ");
    scanf("%s", model);
    while (temp != NULL){
        if (strcmp(temp->model, model) == 0){
            printf("Enter new price: ");
            scanf("%f", &newPrice);    
            temp->price = newPrice;     
            printf("\nPrice updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model not found!\n");
}
void priceRange(){
    float min, max;
    struct Car *temp = head;
    int found = 0;
    printf("\nEnter minimum price: ");
    scanf("%f", &min);                
    printf("Enter maximum price: ");
    scanf("%f", &max);                 
    printf("\nCars within price range:\n");
    while (temp != NULL){
        if (temp->price >= min && temp->price <= max){
            printf("\nModel: %s", temp->model);
            printf("\nManufacturer: %s", temp->manufacturer);
            printf("\nPrice: %.2f", temp->price);    
            printf("\nEngine: %d CC\n", temp->engine);
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 0)
        printf("\nNo cars found in this price range.\n");

void searchCar(){
    char model[50];
    struct Car *temp = head;
    printf("\nEnter car model: ");
    scanf(" %s", model);
    while (temp != NULL){
        if (strcmp(temp->model, model) == 0){
            printf("\n--- Car Details ---\n");
            printf("Model        : %s\n", temp->model);
            printf("Manufacturer : %s\n", temp->manufacturer);
            printf("Price        : %.2f\n", temp->price);  
            printf("Engine       : %d (CC)\n", temp->engine); 
            return;
        }
        temp = temp->next;
    }
    printf("\nCar model not found!\n");
}
void displayCars(){
    struct Car *temp = head;
    if (head == NULL){
        printf("\nNo cars available.\n");
        return;
    }
    printf("\n========== ALL CARS ==========\n");
    while (temp != NULL){
        printf("\nModel        : %s", temp->model);
        printf("\nManufacturer : %s", temp->manufacturer);
        printf("\nPrice        : %.2f", temp->price);     
        printf("\nEngine       : %d CC\n", temp->engine);   
        temp = temp->next;
    }
}
int main(){
    int choice;
    while (1){
        printf("\n\n===== CAR MANAGEMENT SYSTEM =====");
        printf("\n1. Insert new car");
        printf("\n2. Delete car");
        printf("\n3. Update car price");
        printf("\n4. List cars within price range");
        printf("\n5. Search car details");
        printf("\n6. Display all cars");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:insertCar();
                break;
            case 2:deleteCar();
                break;
            case 3:updatePrice();
                break;
            case 4:priceRange();
                break;
            case 5:searchCar();
                break;
            case 6:displayCars();
                break;
            case 7:printf("\nExiting program...\n");
                return 0;
            default:printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
