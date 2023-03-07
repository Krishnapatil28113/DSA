/*Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value*/

#include <iostream>
#include <stack>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
    node()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    friend class BST;
};

class BST
{
    node *root;

public:
    BST(int val)
    {
        this->root = new node;
        this->root->data = val;
    }

    void insert_node(int val)
    {
        node *temp = new node;
        temp->data = val;

        node *current = this->root;
        while (current->left != NULL && current->right != NULL)
        {
            if (temp->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if (temp->data < current->data)
        {
            current->left = temp;
        }
        else
        {
            current->right = temp;
        }
    }

    node *getroot()
    {
        return this->root;
    }


    void displayPreorder(node *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        else
        {
            cout << temp->data << " ";
            displayPreorder(temp->left);
            displayPreorder(temp->right);
        }
    }


    void displayPreorder_NonRecursive(node* root)
    {
        
        // Base condition of root == NULL
        if (root == NULL)
        {
            return;
        }
        else
        {
            stack< node* > s;
            s.push(root);

            while (!s.empty())
            {
                node* currValue = s.top();
                cout<<currValue->data<<" ";
                s.pop();

                if (currValue->right)
                {
                    s.push(currValue->right);
                }
                if (currValue->left)
                {
                    s.push(currValue->left);
                }
            }
        }
    }

    void display_Inorder(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            display_Inorder(root->left);
            cout<<root->data<<" ";
            display_Inorder(root->right);
        }
    }

    void display_Inorder_NonRecursive(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            // 20 30 35 40 45 50 
            stack <node*> s;
            s.push(root);

            while(!s.empty())
            {

            }
        }
    }


    void searchNode(int key)
    {
        int level = 0;
        node *temp = this->root;
        while (temp->data != key)
        {
            if (key < temp->data)
            {
                temp = temp->left;
                level++;
            }
            else
            {
                temp = temp->right;
                level++;
            }
        }
        cout << "Data with value key found at level: " << level << endl;
    }


    int count_of_nodes(node* root)
    {
        if (root == NULL)
        {
            return -1;
        }
        int left = count_of_nodes(root->left);
        int right = count_of_nodes(root->right);
        int count;
        if (left>=right)
        {
            count = left + 1;
        }
        else
        {
            count = right + 1;
        }
        return count;
    }


    //Basic idea is to swap all the nodes other then root.
    //So in order to do that we will initialize a current pointer equal to root.
    //While current pointer is not equal to null we have to call the swap function recursively.
    void swap_nodes(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            node* current = this->root;
            if (current->left || current->right)
            {
                //Swap the left and right pointers.
                node* temp;
                temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
            swap_nodes(current->left);
            swap_nodes(current->right);
        }
    }
};

int main()
{

    cout << "Enter the value of root: " << endl;
    int val;
    cin >> val;

    BST b(val);
    // node* root = b.create_BST(val);//creation of root node
    node *root = b.getroot();

    node *temp = new node;

    b.insert_node(30);
    b.insert_node(50);
    b.insert_node(20);
    b.insert_node(35);
    b.insert_node(45);

    // BST has been created at this point
    // cout << "Your tree is as follows: " << endl;
    // b.displayPreorder(root);
    // cout << endl;

    // b.searchNode(45);

    // b.displayPreorder_NonRecursive(root);

    // b.display_Inorder(root);

    // int res = b.count_of_nodes(root);
    // cout<<res<<endl;

    b.swap_nodes(root);
    b.displayPreorder(root);

    return 0;
}
