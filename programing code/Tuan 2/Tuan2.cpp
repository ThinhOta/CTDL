#include<iostream>

using namespace std;

class IntSLinkedList {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    void add(int element) {
        if(this->empty()){
            this->count++;
            Node* newNode = new Node(element);
            this->head = this->tail = newNode;
        }
        else{
            this->count++;
            Node* newNode = new Node(element);
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void add(int index, int element) {
        if(index > this->size()|| index < 0){
             throw std::out_of_range("Out of range");
         }
        else if(this->empty()){
            return this->add(element);
        }
        else if(index == 0){
            Node* newNode = new Node(element);  
            newNode->next = this->head;
            this->head = newNode;
            this->count++;
        }
        else if(index == (this->size() )){
            return this->add(element);
        }
        else{
            Node* newNode = new Node(element);
            Node* preNode = this->head;
            for(int i = 0; i < index - 1; i++){
                preNode = preNode->next;
            }
            newNode->next = preNode->next;
            preNode->next = newNode;
            this->count++;
        }
    }

    int removeAt(int index) {

        return 0;
    }

    bool removeItem(int item) {

        return false;
    }

    bool empty() {
        if (head == nullptr)
            return true;
        return false;
    }

    int size() {
        return count;
    }
    
    int get(int index) {
        if(index > this->size()|| index < 0){
             throw std::out_of_range("Out of range");
         }
        Node* currNode = head;
        for(int i = 0; i < index ; i++){
                currNode = currNode->next;
            }
        return currNode->data;
    }

    void set(int index, int element) {
        if(index > this->size()|| index < 0){
             throw std::out_of_range("Out of range");
             return;
         }
        Node* currNode = head;
        for(int i = 0; i < index ; i++){
                currNode = currNode->next;
            }
        currNode->data = element;
    }

    int indexOf(int item) {
        for(int i = 0;i < this->size(); i++){
            if(this->get(i) == item)
                return i;
        }
        return -1;
    }

    bool contains(int item) {
        if(this->indexOf(item)==-1)
            return false;
        return true;
    }
    
    void clear() {

    }
    
    string toString();

public:
    class Node {
    public:
        int data;
        Node* next;

    public:
        Node() : next(NULL) {};
        Node(int data) : 
            data(data), next(NULL) {};
    };
};

int main()
{
    	
    IntSLinkedList list;
    int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
    int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
    for (int idx = 0; idx < 8; idx++){
    list.add(index[idx], values[idx]);
    }

    cout << list.get(2) << endl;

    try {
        cout << list.get(11);
    }
    catch (std::out_of_range e) {
        cout << "Out of range";
    }
    return 1;
}