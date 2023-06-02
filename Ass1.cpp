/*
Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value
Name : Krishna patil
Roll No : 21359
*/

#include <iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
    node(){
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    friend class Bst;
};

class Bst
{
    node *root;
    int count_of_nodes;

public:


    Bst(int n) {
        root = nullptr;
        count_of_nodes = 1;
    }

    void createBST();
    void insertNode();
    int longestPath(node*);
    void minvalue();
    void maxvalue();
    void swapNodes(node*);
    void searchValue(int);

    node* getroot()
    {
        return this->root;
    }
    
    void displayInorder(node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        displayInorder(node->left);
        cout << node->data << " ";
        displayInorder(node->right);
    }
};

//Creating a BST
void Bst::createBST()
{
    cout << "Enter the value of root: ";
    int root_data;
    cin >> root_data;
    root = new node(root_data);
}


//Inserting a node in BST
void Bst::insertNode() {
    cout<<"Enter the value of the node you want to insert in the BST: ";
    int value;
    cin>>value;

    node* newnode = new node(value);
    node* current = this->root;
    node* previous = current;

    while(current!=nullptr) {
        if(value > current->data) {
            previous = current;
            current = current->right;
        }
        else {
            previous = current;
            current = current->left;
        }
    }
    if(value < previous->data) {
        previous->left = newnode;
    }
    else {
        previous->right = newnode;
    }
    //node inserted
}


//finding number of nodes in the longest path of tree
int Bst::longestPath(node* root) {
    if(root == nullptr) {
        return -1;
    }
    int left = longestPath(root->left);
    int right = longestPath(root->right);

    int count;
    if(left>=right) {
        count = count + left;
    }
    else {
        count = count + right;
    }
    return count;
}

void Bst::swapNodes(node* root) {
    node* current = root;
    node* temp;

    if(current!=nullptr) {
        if(current->left || current->right) {
            temp = current->left;
            current->left = current->right;
            current->right = temp;
        }
        swapNodes(current->left);
        swapNodes(current->right);
    }
    else {
        return;
    }
}

void Bst::searchValue(int key) {

    node* current = this->root;
    int level = 0 ;

    while(current!=nullptr) {
        if(key < current->data) {
            current = current->left;
            level++;
        }
        else if(key > current->data) {
            current = current->right;
            level++;
        }
        else {
            cout<<"Element found at level: "<<level<<endl;
            break;
        }
    }

    //Note: We will have to check whether current is nullptr or not because 
    //the loop can break because of two things: 
    //1.If the while condition becomes false
    //2.If the element is found and the break statement gets executed(In this case the current might not be a nullptr)

    //Because of the second case , we can't assume that the loop might have been broken because the condition got false
    if(current == nullptr) {
        cout<<"Element not found!"<<endl;
    }
}


void Bst::minvalue() {
    node* current = this->root;
    while(current->left != nullptr) {
        current = current->left;
    }
    cout<<"The value of the minimum element is: "<<current->data<<endl;
}

void Bst::maxvalue() {
    node* current = this->root;
    while(current->right) {
        current = current->right;
    }
    cout<<"THe value of the maximum element is: "<<current->data<<endl;
}

int main() {
    cout<<"Hello"<<endl;

    Bst b(2);

    b.createBST();

    for(int i=0;i<6;i++) {
        b.insertNode();
    }

    node* root = b.getroot();

    // b.displayInorder(root);
    // cout<<endl;

    // b.swapNodes(root);
    // b.displayInorder(root);

    cout<<"Enter the value you want to search: ";
    int value;
    cin>>value;

    b.searchValue(value);

    return 0;
}


