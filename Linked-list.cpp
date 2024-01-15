#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void insertAtEnd(int data, Node *&Root)
    {
        
        Node *Temp = new Node(data);
        Root->next = Temp;
        Root = Temp;
    }
    void printlist(Node *Root)
    {
        Node *temp = Root;
        while (temp->next != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void insertany(Node* &root , int data , int place){
        Node *temp = new Node(data);
        Node* prev = root;
        Node* curr = NULL;
        int count =0;
        if(place ==0 ){
            temp->next = root;
            root = temp;
            return;
        }
        else{
            while(count != place-1){
                prev = prev-> next;
                count++;
                
            }
            curr= prev->next;
            prev->next = temp;
            temp->next = curr;
        }
    }
};

int main()
{

    Node *newnode = new Node(5);
    Node *front = newnode;

    newnode->insertAtEnd(10, front);
    newnode->insertAtEnd(15, front);
    newnode->insertAtEnd(20, front);
    newnode->insertAtEnd(30, front);
    newnode->insertAtEnd(40, front);
    

    newnode->insertany(newnode,1,0);
    newnode->insertany(newnode,7,2);

    newnode->printlist(newnode);
    
}