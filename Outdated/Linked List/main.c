#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *netxNode;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPrt);

int main(void) {
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';

    printf("Enter your choice: \n"
    "1. Insert an element it alphabetical order\n"
    "2. Insert to the end\n"
    "3. Insert to the beginning\n"
    "4. Delete\n"
    "5. Delete from the beggining\n"
    "6. End\n");

    printf(":: ");
    scanf("%d", &choice);
    while(choice != 6) {
        switch (choice)
        {
        case 1:
            printf("Enter a char: ");
            scanf(" ");
            scanf("%c", &item);
            insert(&head, item);
            printList(head);
            break;
        case 2:
            printf("Enter a char: ");
            scanf(" ");
            scanf("%c", &item);
            insertAtEnd(&head, item);
            printList(head);
            break;
        case 3:
            printf("Enter a char: ");
            scanf(" ");
            scanf("%c", &item);
            insertAtBeginning(&head, item);
            printList(head);
            break;
        case 4:
            if (!isEmpty(head)) {
                printf("Enter a char to be deleted: ");
                scanf(" ");
                scanf("%c", &item);
                if (delete(&head, item)) 
                    printList(head);
                else
                    printf("%c isn't found\n", item);
            }
            else 
                printf("List is empty\n");
            break;
        case 5:
            if (!isEmpty(head)) {
                deleteAtBeginning(&head);
                printf("%c is deleted\n", item);
                printList(head);
            } else {
                printf("List is empty.\n");
            }
            break;
        case 6:
            printf("See you!");
            exit(0);
        default:
            printf("Invalid choice....");
            break;
        }
        printf("Enter a choice: ");
        scanf("%d", &choice);
    }
    return 0;
}

void insertAtBeginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->netxNode = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value){ 
    ListNodePtr current = *head;
    if (current != NULL) {
        while (current->netxNode != NULL)
            current = current->netxNode;
        
        current->netxNode = malloc(sizeof(node_t));
        current->netxNode->data = value;
        current->netxNode->netxNode = NULL;
    }
    else {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->netxNode = NULL;
        *head = current;
    }
}

void insert(ListNodePtr *head, char value) {
    ListNodePtr newNode = NULL;
    ListNodePtr previousNode = NULL;
    ListNodePtr currentNode = NULL;

    newNode = malloc(sizeof(node_t));

    if (newNode != NULL) {
        newNode->data = value;
        newNode->netxNode = NULL;
        previousNode = NULL;
        currentNode = *head;

        while(currentNode != NULL && value > currentNode->data) {
            previousNode = currentNode;
            currentNode = currentNode->netxNode;
        }
        if (previousNode == NULL) {
            newNode->netxNode = *head;
            *head = newNode;
        }
    }
}

void deleteAtBeginning(ListNodePtr *head) {
    ListNodePtr tempNode = NULL;
    if (head == NULL) 
        return;
    else {
        tempNode = *head;
        *head = (*head)->netxNode;
        free(tempNode);
    }
}

char delete(ListNodePtr *head, char value) {
    ListNodePtr previousNode;
    ListNodePtr currentNode;
    ListNodePtr tempNode;

    if (value == (*head)->data) {
        tempNode = *head;
        *head = (*head)->netxNode;
        free(tempNode);
        return value;
    } else {
        previousNode = *head;
        currentNode = (*head)->netxNode;

        while (currentNode != NULL && currentNode->data != value) {
            previousNode = currentNode;
            currentNode = currentNode->netxNode;
        }

        if (currentNode != NULL) {
            tempNode = currentNode;
            previousNode->netxNode = currentNode->netxNode;
            free(tempNode);
            return value;
        }
    }
    return '\0';
}

void printList(ListNodePtr currentPrt) {
    if (currentPrt == NULL)
        printf("list is empty\n");
    else {
        printf("The list is: ");
        while(currentPrt != NULL) {
            printf("%c --> ", currentPrt->data);
            currentPrt = currentPrt->netxNode;
        }
    
    }
}

int isEmpty(ListNodePtr head) {
    return head==NULL;
}