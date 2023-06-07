/*
 Author - Krishna Patil

 Data Structure Explanation: https://www.javatpoint.com/avl-tree

 A dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
 updating values of an entry. Provide facility to display whole data in sorted Ascending / Descending order.
 Also find out how many comparisons are required for finding any entry. Use height balance tree and find
 complexity for finding a keyword.
 */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class node
{
    int key;
    string value;
    int height = 1;
    node *left = nullptr;
    node *right = nullptr;

public:
    node(int key, string value)
    {
        key = key;
        value = value;
    }

    friend class AVLTree;
};

class AVLTree
{
    node *root = nullptr;

    int nodeBalanceFactor(node *node)
    {
        return nodeHeight(node->left) - nodeHeight(node->right);
    }
    int nodeHeight(node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }
    void updateHeight(node *node)
    {
        node->height = 1 + max(nodeHeight(node->left), nodeHeight(node->right));
    }

    node *LLRotation(node *root)
    {
        node *newroot = root->left;
        newroot->right = root;
        root->left = nullptr;

        updateHeight(root);
        updateHeight(newroot);

        return newroot;
    }

    node *LRRotation(node *root)
    {
        root->left = RRRotation(root->left);
        return LLRotation(root);

        // node* newroot = root->left->right;
        // newroot->right = root;
        // root->left = nullptr;
        // root->left->right = nullptr;

        // updateHeight(root);
        // updateHeight(root->left);
        // updateHeight(newroot);

        // return newroot;
    }

    node *RLRotation(node *root)
    {
        root->right = LLRotation(root->right);
        return RRRotation(root);
    }

    node *RRRotation(node *root)
    {
        node *newroot = root->right;
        newroot->left = root;
        root->right = nullptr;

        updateHeight(root);
        updateHeight(newroot);

        return newroot;
    }

    node *balance(node *root)
    {
        if (nodeBalanceFactor(root) == 2)
        {
            if (nodeBalanceFactor(root->left) > 0)
            {
                root = LLRotation(root);
            }
            else
            {
                root = LRRotation(root);
            }
        }
        else if (nodeBalanceFactor(root) == -2)
        {
            if (nodeBalanceFactor(root->right) > 0)
            {
                root = RLRotation(root);
            }
            else
            {
                root = RRRotation(root);
            }
        }
        updateHeight(root);
        return root;
    }

    node *insertSubTree(node *current, int key, string value)
    {
        if (current == nullptr)
        {
            node *newnode = new node(key, value);
            return newnode;
        }
        else {
            if (key < current->key) {
                current->left = insertSubTree(current->left, key, value);
            }
            else if (key > current->key) {
                current->right = insertSubTree(current->right, key, value);
            }
            else {
                // because current->key is already equal to the passed key
                current->value = value;
                return current;
            }
        }
        return balance(current);
    }

    public:

    AVLTree(int key , string val) {
        this->root->key = key;
        this->root->value = val;
    }
    node* getroot() {
        return this->root;
    }

    void inorder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left);
        cout << root->value << endl;
        inorder(root->right);
    }

    void insert(int key , string value) {
        root = insertSubTree(root,key,value);
    }

    node *search(int key)
    {
        node *current = this->root;
        while (current != nullptr)
        {
            if (current->key < root->key)
            {
                current = current->left;
            }
            else if (current->key > root->key)
            {
                current = current->right;
            }
            else
            {
                return current;
            }
        }
        // if current becomes nullptr
        return nullptr;
    }

    void BFS() {
        queue<node*> q;
        q.push(this->root);

        while(!q.empty()) {
            node* poppedvalue = q.front();
            q.pop();
            cout<<poppedvalue->key<<" ";

            if(poppedvalue->left) {
                q.push(poppedvalue->left);
            }
            if(poppedvalue->right) {
                q.push(poppedvalue->right);
            }
        }
        cout<<endl;
    }
};

int main()
{
    AVLTree tree(70 , "0");

    node* root = tree.getroot();

    tree.insert(100, "1");
    tree.insert(50, "2");
    tree.insert(150, "3");
    tree.insert(25, "4");
    tree.insert(75, "5");
    tree.insert(125, "6");
    

    tree.BFS();
    tree.inorder(root);
    
    tree.insert(175, "7");
    tree.insert(65, "8");
    tree.insert(85, "9");
    
    tree.BFS();
    tree.inorder(root);
    return 0;
}
