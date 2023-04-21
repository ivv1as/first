#include <iostream>

using namespace std;

// ����� ��� ���� ������
class Node {
public:
    int data;        // ������, ������� �������� � ���� ������
    Node* next;      // ��������� �� ��������� ���� ������

    // ����������� ��� ������������� ������ � ��������� �� ��������� ����
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// ����� ��� �������������� ������
class LinkedList {
private:
    Node* head;     // ��������� �� ������ ������� ������

public:
    // ����������� �� ���������, �������������� ������ ������
    LinkedList() {
        this->head = nullptr;
    }

    // ����� ��� ���������� �������� � ����� ������
    void append(int data) {
        Node* newNode = new Node(data);    // ������� ����� ���� ������
        if (this->head == nullptr) {       // ���� ������ ������, ����� ���� ���������� ������
            this->head = newNode;
        }
        else {
            Node* current = this->head;
            while (current->next != nullptr) {  // ���� ��������� ���� ������
                current = current->next;
            }
            current->next = newNode;        // ��������� ����� ���� � ����� ������
        }
    }

    // ����� ��� ���������� �������� � ������ ������
    void prepend(int data) {
        Node* newNode = new Node(data);    // ������� ����� ���� ������
        newNode->next = this->head;        // ����� ���� ��������� �� ������ ������� ������
        this->head = newNode;              // ����� ���� ���������� ������ ��������� ������
    }

    // ����� ��� ���������� �������� � �������� �������
    void insertAt(int position, int data) {
        Node* new_node = new Node(data);
        if (position == 0) {                // ���� ������� - ������ ������
            new_node->next = this->head;
            this->head = new_node;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {  // ���� �������, �������������� �������� �������
            if (current == nullptr) {       // ���� ������� ������, ��� ���������� ��������� � ������, ������� �� ������
                cout << "Position is out of range!" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {           // ���� ������� �� ����������, ������� �� ������
            cout << "Position is out of range!" << endl;
            return;
        }
        new_node->next = current->next;     // ��������� ����� �������
        current->next = new_node;
    }
    // ����� ��� �������� �������� �� ��������
    void remove(int data) {
        if (this->head == nullptr) {       // ���� ������ ������, ������� �� ������
            return;
        }
        if (this->head->data == data) {    // ���� ������ ������� ������ - ��������� �������, ������� ��� � ������� �� ������
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }
        Node* current = this->head;
        while (current->next != nullptr) {  // ���� ��������� �������
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;                // ������� ��������� ������� � ������� �� ������
                return;
            }
            current = current->next;
        }
    }

    // ����� ��� �������� �������� �� ������ �������
    void removeAt(int position) {
        if (this->head == nullptr) {       // ���� ������ ������, ������� �� ������
            return;
        }
        if (position == 0) {               // ���� ��������� ������� - ������, ������� ��� � ������� �� ������
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {  // ���� ���� ����� ��������� ���������
            if (current == nullptr) {             // �������� �� ������: ������� �� ����� ���� ������ ������� ������
                cout << "Error: position is out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {  // �������� �� ������: ��������� ������� ������ ������������
            cout << "Error: element doesn't exist" << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;                    // ������� ��������� ������� � ������� �� ������
    }

    // ����� ��� ������ �������� �� ��������
    int search(int data) {
        Node* current = this->head;
        int position = 0;
        while (current != nullptr) {    // ���������� ��� �������� ������
            if (current->data == data) {
                return position;        // ���� ����� ������� �������, ���������� ��� �������
            }
            current = current->next;
            position++;
        }
        return -1;                      // ���� ������� �� ������, ���������� -1
    }

    // ����� ��� ������ �������� � �������� �������
    int searchAt(int position) {
        Node* current = this->head;
        for (int i = 0; i < position; i++) {  // ���� �������� �������

            // ����� ��� ������ �������� � �������� �������
            int searchAt(int position); {
                if (this->head == nullptr) {        // ���� ������ ������, ������� �� ������
                    return -1;
                }
                Node* current = this->head;
                for (int i = 0; i < position; i++) {  // ���� �������� �������
                    if (current == nullptr) {       // ���� ������� ������, ��� ���������� ��������� � ������, ���������� -1
                        return -1;
                    }
                    current = current->next;
                }
                if (current == nullptr) {           // ���� ������� �� ����������, ���������� -1
                    return -1;
                }
                return current->data;               // ���� ������� ������, ���������� ��� ��������
            }

            // ����� ��� ������ ���� ��������� ������
            void printList(); {
                Node* current = this->head;
                while (current != nullptr) {        // ���������� ��� �������� ������
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
        };
    }
};