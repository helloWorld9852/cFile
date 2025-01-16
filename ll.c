#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} *Node;

Node createNode() {
    Node newNode = (Node)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node createHeader() {
    Node header = (Node)malloc(sizeof(struct node));
    if (header == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    header->data = 0; // Counter for the number of nodes
    header->next = header->prev = header;
    return header;
}

void insertFront(Node header) {
    Node newNode = createNode();
    if (header->data == 0) {
        header->next = header->prev = newNode;
        newNode->next = newNode->prev = header;
    } else {
        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
    }
    header->data++;
}

void insertRear(Node header) {
    Node newNode = createNode();
    if (header->data == 0) {
        header->next = header->prev = newNode;
        newNode->next = newNode->prev = header;
    } else {
        newNode->prev = header->prev;
        newNode->next = header;
        header->prev->next = newNode;
        header->prev = newNode;
    }
    header->data++;
}

void insertAtPosition(Node header, int pos) {
    Node temp = header->next;
    int count = 1;
    while (temp != header && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == header && count < pos) {
        printf("Invalid position!");
        return;
    }
    Node newNode = createNode();
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    header->data++;
}

void deleteFront(Node header) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }
    Node temp = header->next;
    header->next = temp->next;
    temp->next->prev = header;
    free(temp);
    header->data--;
}

void deleteRear(Node header) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }
    Node temp = header->prev;
    header->prev = temp->prev;
    temp->prev->next = header;
    free(temp);
    header->data--;
}

void deleteAtPosition(Node header, int pos) {
    Node temp = header->next;
    int count = 1;
    while (temp != header && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == header) {
        printf("Invalid position!");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    header->data--;
}

void searchByKey(Node header, int key) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }
    Node temp = header->next;
    while (temp != header) {
        if (temp->data == key) {
            printf("The node with key %d is found", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Key not found!");
}

void deleteByKey(Node header, int key) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }

    Node temp = header->next;
    while (temp != header) {
        if (temp->data == key) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            header->data--;
            printf("Key %d deleted successfully!\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found!\n", key);
}

void insertByOrder(Node header) {
    Node newNode = createNode();
    
    if (header->data == 0) { // List is empty
        newNode->next = header;
        newNode->prev = header;
        header->next = newNode;
        header->prev = newNode;
    } else {
        Node current = header->next; // Start from the first actual node
        
        // Traverse to find the correct position
        while (current != header && current->data < newNode->data) {
            current = current->next;
        }
        
        // Insert newNode before 'current'
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    header->data++;
}

void reverseList(Node header) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }
    Node current = header;
    do {
        Node next = current->next;
        current->next = current->prev;
        current->prev = next;
        current = next;
    } while (current != header);
    printf("List reversed successfully!\n");
}

Node copyList(Node header) {
    Node newHeader = createHeader();
    Node temp, newNode, last;
    temp = header->next;
    last = newHeader;
        
    while (temp != header) {
        newNode = (Node)malloc(sizeof(struct node));
        newNode->data = temp->data;
        newNode->next = last->next;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        temp = temp->next;
        newHeader->data++;
    }
    last->next = newHeader;
    newHeader->prev = last;
    return newHeader;
}


void displayList(Node header) {
    if (header->data == 0) {
        printf("List is empty!");
        return;
    }

    Node temp = header->next;
    printf("\nList (Count=%d): ", header->data);
    while (temp != header) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("header");
}

int main() {
    Node header = createHeader();
    int choice, position, key;

    while (1) {
        printf("\n\nDoubly Circular Linked List Operations:");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Front");
        printf("\n5. Delete from Rear");
        printf("\n6. Delete from Position");
        printf("\n7. Delete by Key");
        printf("\n8. Search by Key");
        printf("\n9. Insert by order");
         printf("\n10. Reverse List");
        printf("\n11. Copy List");
        printf("\n12. Display List");
        printf("\n13. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront(header);
                break;
            case 2:
                insertRear(header);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(header, position);
                break;
            case 4:
                deleteFront(header);
                break;
            case 5:
                deleteRear(header);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(header, position);
                break;
            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(header, key);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(header, key);
                break;
            case 9:
                insertByOrder(header);
                break;
            case 10:
                reverseList(header);
                break;
            case 11: {
                Node newHeader = copyList(header);
                printf("Copied List: ");
                displayList(newHeader);
                free(newHeader);
                break;
            }
            case 12:
                displayList(header);
                break;
            case 13:
                free(header);
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}
