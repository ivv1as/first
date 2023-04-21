#include <iostream>

using namespace std;

// класс для узла списка
class Node {
public:
    int data;        // данные, которые хранятся в узле списка
    Node* next;      // указатель на следующий узел списка

    // конструктор для инициализации данных и указателя на следующий узел
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// класс для односвязанного списка
class LinkedList {
private:
    Node* head;     // указатель на первый элемент списка

public:
    // конструктор по умолчанию, инициализирует пустой список
    LinkedList() {
        this->head = nullptr;
    }

    // метод для добавления элемента в конец списка
    void append(int data) {
        Node* newNode = new Node(data);    // создаем новый узел списка
        if (this->head == nullptr) {       // если список пустой, новый узел становится первым
            this->head = newNode;
        }
        else {
            Node* current = this->head;
            while (current->next != nullptr) {  // ищем последний узел списка
                current = current->next;
            }
            current->next = newNode;        // добавляем новый узел в конец списка
        }
    }

    // метод для добавления элемента в начало списка
    void prepend(int data) {
        Node* newNode = new Node(data);    // создаем новый узел списка
        newNode->next = this->head;        // новый узел указывает на первый элемент списка
        this->head = newNode;              // новый узел становится первым элементом списка
    }

    // метод для добавления элемента в заданную позицию
    void insertAt(int position, int data) {
        Node* new_node = new Node(data);
        if (position == 0) {                // если позиция - начало списка
            new_node->next = this->head;
            this->head = new_node;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {  // ищем элемент, предшествующий заданной позиции
            if (current == nullptr) {       // если позиция больше, чем количество элементов в списке, выходим из метода
                cout << "Position is out of range!" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {           // если элемент не существует, выходим из метода
            cout << "Position is out of range!" << endl;
            return;
        }
        new_node->next = current->next;     // добавляем новый элемент
        current->next = new_node;
    }
    // метод для удаления элемента по значению
    void remove(int data) {
        if (this->head == nullptr) {       // если список пустой, выходим из метода
            return;
        }
        if (this->head->data == data) {    // если первый элемент списка - удаляемый элемент, удаляем его и выходим из метода
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }
        Node* current = this->head;
        while (current->next != nullptr) {  // ищем удаляемый элемент
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;                // удаляем найденный элемент и выходим из метода
                return;
            }
            current = current->next;
        }
    }

    // метод для удаления элемента по номеру позиции
    void removeAt(int position) {
        if (this->head == nullptr) {       // если список пустой, выходим из метода
            return;
        }
        if (position == 0) {               // если удаляемый элемент - первый, удаляем его и выходим из метода
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }
        Node* current = this->head;
        for (int i = 0; i < position - 1; i++) {  // ищем узел перед удаляемым элементом
            if (current == nullptr) {             // проверка на дурака: позиция не может быть больше размера списка
                cout << "Error: position is out of range" << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {  // проверка на дурака: удаляемый элемент должен существовать
            cout << "Error: element doesn't exist" << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;                    // удаляем найденный элемент и выходим из метода
    }

    // метод для поиска элемента по значению
    int search(int data) {
        Node* current = this->head;
        int position = 0;
        while (current != nullptr) {    // перебираем все элементы списка
            if (current->data == data) {
                return position;        // если нашли искомый элемент, возвращаем его позицию
            }
            current = current->next;
            position++;
        }
        return -1;                      // если элемент не найден, возвращаем -1
    }

    // метод для поиска элемента в заданной позиции
    int searchAt(int position) {
        Node* current = this->head;
        for (int i = 0; i < position; i++) {  // ищем заданный элемент

            // метод для поиска элемента в заданной позиции
            int searchAt(int position); {
                if (this->head == nullptr) {        // если список пустой, выходим из метода
                    return -1;
                }
                Node* current = this->head;
                for (int i = 0; i < position; i++) {  // ищем заданный элемент
                    if (current == nullptr) {       // если позиция больше, чем количество элементов в списке, возвращаем -1
                        return -1;
                    }
                    current = current->next;
                }
                if (current == nullptr) {           // если элемент не существует, возвращаем -1
                    return -1;
                }
                return current->data;               // если элемент найден, возвращаем его значение
            }

            // метод для вывода всех элементов списка
            void printList(); {
                Node* current = this->head;
                while (current != nullptr) {        // перебираем все элементы списка
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
        };
    }
};