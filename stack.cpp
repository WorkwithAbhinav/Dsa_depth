#include <iostream>
#include <stack>
#include <vector>

using namespace std ;

class Node{
  public:
  int data ;
  Node * next ;

    Node(int data){
        this -> data = data;
        next = NULL;
    }

};

void insertll (Node * head , int data ){
   Node* newnode = new Node(data);

    if (head == NULL) {
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printll(Node * temp){
    Node * head =temp ;
    while(head){
        cout << head -> data << " - > "  ; 
        head = head-> next;
    }
    cout << endl;
}


class s{
public:
    int *arr;
    int size ;
    int top;

        s(int data){
            this ->size = data;
            arr = new int[size];
            top = -1;
        }
    
    void push(int element){
        if(size - top >1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "stack full" << endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<< " stack is empty " << endl;
        }
        else{
            top--;
        }
    }
    void topelement(){
        if(top==-1){
            cout<< " stack is empty " << endl ;
        }
        cout <<  arr[top] << endl ;
    }
    void currsize(){
        cout << top+1 << endl ;
    }
    bool isempty (){
        if(top==-1){
            return true;
        }
        return false;
    }
    void printfx(){
        for (int i = 0; i < top+1; i++)
        {
            cout<< arr[i] << " ";
        }
        cout<< endl;
        
    }

};

class sLL {
public:
    Node* top;
    Node* front;
    int size;

    sLL(int data) {
        Node* newNode = new Node(data);
        top = newNode;
        front = newNode; // Initialize front with the first element
        size = 1;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top; // Set the new node's next to the current top
        top = newNode; // Update top to the new node
        size++;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next; // Update top to the next node
        delete temp; // Free the memory of the removed node
        size--;
    }

    void topelement() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << top->data << endl;
    }

    void printfx() {
        printll(front);
    }
};


int main(){
    // s st(5);
    // st.push(1);
    // st.push(3);
    // st.push(5);

    // st.topelement();

    // st.printfx();

    // st.currsize() ;

    // Node* head = new Node(12);
    // Node * node1 = head;
    // insertll(node1,13);
    // insertll(node1,14);
    // insertll(node1,15);
    // insertll(node1,16);

    // printll(head);

sLL stack(1); // Initialize stack with one element

    stack.push(2);
    stack.push(3);
    stack.push(4);

    stack.printfx(); // Output: 1 -> 2 -> 3 -> 4 -> NULL

    stack.pop(); // Pop the top element (4)
    stack.topelement(); // Output: 3

}