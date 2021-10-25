#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height=0;
};
struct Node* rootPtr = NULL;

int Height(Node* x)
{
    if (x == NULL)
        return -1;
    return x->height;
}

int balance_factor(Node* x)
{
    int lh, rh;
    lh = Height(x->left);
    rh = Height(x->right);
    return lh - rh;
}

void Update_height(Node* x)
{
    while(x!= NULL)
    {
        x->height = 1 + max(Height(x->left), Height(x->right) );
        x = x->parent;
    }
}

void InorderTraversal(struct Node* x)
{
    if(x==NULL)
        return;

    InorderTraversal(x->left);
    cout << x->data << "(" << balance_factor(x) << ") ";
    InorderTraversal(x->right);
}

void Insertion(int key)
{
    Node* newNode = new Node();
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    Node* temp = rootPtr;

    if( temp == NULL){
        rootPtr = newNode;
        return;
    }

    Node* target;
    while( temp!= NULL)
    {
        target = temp;
        if( newNode->data < temp->data ){
            temp = temp->left;

        }
        else{
            temp = temp->right;
        }
    }

    newNode->parent = target;

    if(newNode->data < target->data){
        target->left = newNode;
    }
    else{
        target->right = newNode;
    }
    Update_height(newNode);
}

int main()
{
    int key;
    while(1)
    {
        cin >> key;
        if( key == -1)
            break;
        else{
            Insertion(key);
            InorderTraversal(rootPtr);
            cout << endl;
        }
    }
}

