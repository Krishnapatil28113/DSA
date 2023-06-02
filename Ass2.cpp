/*
Beginning with an empty binary tree, Construct binary tree by inserting the
values in the order given. After constructing a binary tree perform following
operations on it-
 Perform inorder, preorder and post order traversal
 Change a tree so that the roles of the left and right pointers are swapped at
every node
 Find the height of tree
 Copy this tree to another [operator=]
 Count number of leaves, number of internal nodes.
 Erase all nodes in a binary tree.

Name : Advait Naik
Roll No : 21354
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
    int value;
    node *left;
    node *right;

public:
    node()
    {
        this->value = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    node(int val)
    {
        this->value = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    friend class Bt;
};

class Bt
{

    node *root;
    queue<node *> q;

public:
    node *getroot()
    {
        return this->root;
    }

    Bt()
    {
        this->root = nullptr;
    }
    Bt(int val)
    {
        this->root = new node(val);
        root->left = nullptr;
        root->right = nullptr;
        q.push(root);
    }

    ~Bt()
    {
        this->deletenodes();
    }
    
    void insert(int);
    void inorder();
    void preorder();
    void postorder();
    void swapnodes(node *);
    int height(node *);
    void countnodes();
    void deletenodes();

    void displayInorder(node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        displayInorder(node->left);
        cout << node->value << " ";
        displayInorder(node->right);
    }

    // overloading = operator
    Bt operator=(Bt &tree)
    {
        Bt b;
        queue<node *> q;
        q.push(this->root);

        node *current = nullptr;

        while (!q.empty())
        {
            current = q.front();
            q.pop();
            b.insert(current->value);

            if (current->left)
            {
                q.push(current->left);
            }
            else if (current->right)
            {
                q.push(current->right);
            }
        }
        return b;
    }
};

void Bt::insert(int val)
{

    // creation of a new node to be inserted in the Binary tree
    node *newnode = new node(val);

    node *current = q.front();

    while (true)
    {
        if (current->left && current->right)
        {
            q.push(current->left);
            q.push(current->right);
            q.pop();
            current = q.front();
        }
        else if (current->left == nullptr)
        {
            current->left = newnode;
            break;
        }
        else if (current->right == nullptr)
        {
            current->right = newnode;
            break;
        }
    }
}

void Bt::inorder()
{
    stack<node *> s;
    node *current = this->root;

    while (!s.empty() || current != nullptr)
    {

        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->value << " ";
        current = current->right;
    }
    cout << endl;
}

void Bt::preorder()
{
    stack<node *> s;
    s.push(this->root);

    while (!s.empty())
    {
        node *current = s.top();
        s.pop();
        cout << current->value << " ";
        if (current->right)
        {
            s.push(current->right);
        }
        if (current->left)
        {
            s.push(current->left);
        }
    }
    cout << endl;
}

void Bt::postorder()
{
    stack<node *> s1, s2;
    s1.push(this->root);
    node *current = nullptr;

    while (!s1.empty())
    {
        current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left)
        {
            s1.push(current->left);
        }
        if (current->right)
        {
            s1.push(current->right);
        }
    }

    while (!s2.empty())
    {
        current = s2.top();
        s2.pop();
        cout << current->value << " ";
    }
    cout << endl;
}

void Bt::swapnodes(node *root)
{

    if (root == nullptr)
    {
        return;
    }
    else
    {
        if (root->left || root->right)
        {
            node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        swapnodes(root->left);
        swapnodes(root->right);
    }
}

int Bt::height(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    int count;
    if (left >= right)
    {
        count = left + 1;
    }
    else if (right >= left)
    {
        count = right + 1;
    }
    return count;
}

void Bt::countnodes()
{
    stack<node *> s;
    s.push(this->root);
    node *current = nullptr;

    int leafnodes = 0;
    int internalnodes = 0;

    while (!s.empty())
    {
        current = s.top();
        s.pop();
        if (current->left == nullptr && current->right == nullptr)
        {
            leafnodes++;
        }
        else
        {
            internalnodes++;
        }

        if (current->right)
        {
            s.push(current->right);
        }
        else if (current->left)
        {
            s.push(current->left);
        }
    }
    cout << "No. of leaf nodes: " << leafnodes << endl;
    cout << "No. of internal nodes: " << internalnodes << endl;
}

void Bt::deletenodes()
{
    stack<node *> s1, s2;
    s1.push(this->root);
    node *current = nullptr;

    while (!s1.empty())
    {
        current = s1.top();
        s2.push(current);
        s1.pop();

        if (current->left)
        {
            s1.push(current->left);
        }
        else if (current->right)
        {
            s1.push(current->right);
        }
    }

    while (!s2.empty())
    {
        delete s2.top();
        s2.pop();
    }
}

int main()
{
    Bt b(20);
    b.insert(30);
    b.insert(15);
    b.insert(45);
    b.insert(50);

    node *root = b.getroot();
    cout << endl;

    b.inorder();
    // b.preorder();
    // b.postorder();

    // b.swapnodes(root);
    // b.inorder();

    // int res = b.height(root);
    // cout<<res<<endl;

    // b.countnodes();

    Bt tree = b;

    tree.displayInorder(root);
    return 0;
}