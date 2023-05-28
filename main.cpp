#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Функція для створення нового елемента
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функція для додавання елемента в початок списку
void addNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Функція для виведення списку
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для вставки нового елемента після кожного елемента зі значенням V1
void insertAfterValue(Node*& head, int V1, int V2) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == V1) {
            Node* newNode = createNode(V2);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
    }
}

int main() {
    // Створення списку
    Node* list = nullptr;
    addNode(list, 5);
    addNode(list, 4);
    addNode(list, 3);
    addNode(list, 2);
    addNode(list, 1);

    // Виведення початкового списку
    cout << "Початковий список: ";
    printList(list);

    // Введення значень V1 та V2
    int V1, V2;
    cout << "Введіть значення V1: ";
    cin >> V1;
    cout << "Введіть значення V2: ";
    cin >> V2;

    // Вставка елементів після елементів зі значенням V1
    insertAfterValue(list, V1, V2);

    // Виведення зміненого списку
    cout << "Змінений список: ";
    printList(list);

    // Видалення списку
    while (list != nullptr) {
        Node* temp = list;
        list = list->next;
        delete temp;
    }

    return 0;
}

