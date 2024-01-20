#include <bits/stdc++.h>
using namespace std ;

class node{
    public:
    int data ;
    node * left ;
    node * right ;

    node(int d){
        this->data = d;
        this -> left = NULL ;
        this ->right = NULL ;
    }
    
};
node* buildtree(node* &root){
    int data ;
    cout << "enter the data of the root node : "  << endl ;
    cin >> data ;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "enter the data to the left of" << data  << "node : "  << endl ;
    root -> left = buildtree(root->left);
    cout << "enter the data to the right of" << data  << "node : "  << endl ;
    root -> right = buildtree(root->right);
    return root;

}

void lot(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front() ;
        q.pop() ;
        

        if(temp == NULL){
            cout << endl ;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " "  ;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
void inorder(node * root){
    if(root == NULL){
        return;
    }
    inorder(root-> left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node * root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root-> left);
    preorder(root->right);
}
void postorder(node * root){
    if(root == NULL){
        return;
    }
    postorder(root-> left);
    postorder(root->right);
    cout << root->data << " ";

}

void buildform_LOT(node* &root){
    queue <node*> q;
    cout << "Enter the data in root : " << endl ;
    int data ;
    cin >> data ;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node * temp = q.front() ;
        q.pop() ;

        cout<< "enter data to be entered in left of "<< temp->data << endl ;
        int leftdata ;
        cin >> leftdata;

        if(leftdata != -1){
            temp->left  = new node(leftdata);
            q.push(temp->left);
        }
        cout<< "enter data to be entered in right of "<< temp->data << endl ;
        int rightdata ;
        cin >> rightdata;

        if(rightdata != -1){
            temp->right  = new node(rightdata);
            q.push(temp->right);
        }

    }

}


int main(){
    node * root = NULL ;


    buildform_LOT(root);
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    lot(root);

    
    // buildtree(root);

    // cout << "inorder : " ;
    // inorder(root);
    // cout << endl;

    // cout << "preorder : " ;
    // preorder(root);
    // cout << endl;


    // cout << "postorder : " ;
    // postorder(root);
    // cout << endl;


}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Inorder traversal: 7 3 11 1 17 5
// Preorder traversal: 1 3 7 11 5 17
// Postorder traversal: 7 11 3 17 5 1