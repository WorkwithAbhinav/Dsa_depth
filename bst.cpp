#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree(Node*& root, int data) {
    if (root == NULL) {
        root= new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = buildtree(root->left, data);
    }
    else {
        root->right = buildtree(root->right, data);
    }
    return root;
}

void lot(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

void insertnum(Node*& root) {
    int data;
    cout << "Enter numbers to insert (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = buildtree(root, data);
        cin >> data;
    }
}
void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root-> left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    insertnum(root);
    cout << "Level order traversal:" << endl;
    lot(root);
    cout << "inorder" << endl;
    inorder(root);

    return 0;
}
