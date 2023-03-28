// Implement all the functions of dicitionary ADT using hashing and handle collision by seperate chaining with the help of linked list
// Data is set of key value pairs where key is word and value is its meaning
// keys must be comparable and unique
// Operations to be performed:
// 1.Insert key and value
// 2.Find key and value
// 3.Delete key and value

#include <iostream>
#include <string>
using namespace std;

class node
{
    string word;
    string meaning;
    node *next;

public:
    node()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    node(string key, string value)
    {
        this->word = key;
        this->meaning = value;
        this->next = NULL;
    }
    friend class dictionary;
};

class dictionary
{
    int dictionarysize; // The size of the hash table
    node **headnode;    // The array of pointers

    //Accessing index corresponding to the key
    int hash(string name)
    {
        int ascii = 0;
        for (int i = 0; name[i] != '\0'; i++)
        {
            ascii = ascii + int(name[i]);
        }
        return ascii % 10;
    }

    //Printing the seperate key value pairs of each pointer in the headnode
    void print(node* head)
    {
        node* current = head;
        while(current)
        {
            cout.width(5);
            cout<<current->word<<" - "<<current->meaning;
            current = current->next;
        }
    }

    void insertNode(node *head, node *newentry){
        node *current = head;
        while(current!= nullptr){
            current = current -> next;
        }
        current = newentry;
    }

public:
    //Initialization
    dictionary(int size)
    {
        this->dictionarysize = size;
        headnode = new node*[size];
        for (int i=0;i<size;i++)
        {
            headnode[i] = NULL;
            //initially all the pointers inside the headnode array will be set to NULL
        }
    }

    //Insert Operation
    void insert(string key,string value)
    {
        int index = hash(key);

        if (headnode[index] = NULL)
        {
            headnode[index] = new node(key,value);
        }
        else
        {
            node* newnode = new node(key,value);
            insertNode(headnode[index],newnode);
        }
    }

    void display()
    {
        for (int i=0;i<dictionarysize;i++)
        {
            cout.width(5);
            cout<<i;
            print(headnode[i]);
            cout<<endl;
        }
    }
};

int main()
{
    dictionary d(10);
    d.insert("Advait","unique");
    d.insert("Kaustubh","VishnuAvatar");
    d.insert("Krishna","AllAttractive");

    d.display();
    return 0;
}