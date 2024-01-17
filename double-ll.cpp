#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next;
    node* prev ;
    int data;

    
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL ;
    }
    
};
void printfx(node * head ){
    while(head != NULL){
        cout << head -> data << " " ;
        head = head->next ;
    }cout << endl ;
}
void insertin(int data , node  *&head){
    node *newnode = new node(data);

    head->next = newnode;
    newnode->prev = head ;
    head = newnode;

}

int main () {
    
    node *newnode = new node(15);
    node*head = newnode;
    insertin(16 ,newnode);
    insertin(17 ,newnode);
    insertin(18 ,newnode);
    insertin(19 ,newnode);



    printfx(head);

}