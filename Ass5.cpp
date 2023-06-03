/*
Implement all the functions of a dictionary (ADT) using open hashing technique: separate chaining using
linked list Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, and Keys
must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)

Name : Krishna Patil
Roll no : 21359
*/

#include <iostream>
#include <string.h>
using namespace std;

class node
{
    node *next;
    string word;
    string meaning;

public:
    node(){};
    node(string key, string value)
    {
        this->word = key;
        this->meaning = value;
    }

    friend class Dictionary;
};

class Dictionary
{
    int dictionarysize;
    node **headnode;

public:
    Dictionary(){};
    Dictionary(int size)
    {
        this->dictionarysize = size;
        this->headnode = new node *[dictionarysize];
        for(int i=0;i<dictionarysize;i++) {
            headnode[i] = nullptr;
        }
    }

    int hash(string key)
    {
        int ascii = 0;
        for (int i = 0; i < key.length(); i++)
        {
            ascii = ascii + key[i];
        }
        return ascii % dictionarysize;
    }

    void insert(string, string);
    void display();
    void search(string);
    void deleteword(string);
};

void Dictionary::insert(string key, string value)
{
    int index = hash(key);
    if(headnode[index] == nullptr) {
        headnode[index] = new node(key,value);
    }
    else {
        node* newnode = new node(key,value);

        node* current = headnode[index];
        while(current!=nullptr) {
            current = current->next;
        }
        current = newnode;

    }
}

void Dictionary::display(){
    for(int i = 1 ; i <= dictionarysize ; i++) {
        cout.width(5);
        cout<<i<<" ";
        
        node* current = headnode[i];
        while(current!=nullptr) {
            cout<<current->word<<" "<<current->meaning<<endl;
            current = current->next;
        }

    }
}

void Dictionary::search(string key) {
    int index = hash(key);

    node* current = headnode[index];
    int comparisons = 1 ;
    while(current!=nullptr) {
        if(current->word == key) {
            cout<<"Record found!"<<endl;
            cout<<current->word<<" : "<<current->meaning<<endl;
            cout<<"Number of comparisons: "<<comparisons<<endl;
            break;
        }
        else {
            current = current -> next;
            comparisons++;
        }
    }
    if(current == nullptr) {
        cout<<"Record not found!"<<endl;
        cout<<"Number of comparisons: "<<comparisons<<endl; 
    }
    
}

// void Dictionary::deleteword(string key) {
//     int index = hash(key);
    
//     if(headnode[index] == nullptr) {
//         cout<<"Record to be deleted not found!"<<endl;
//     }
//     else {
//         node* current = headnode[index];
//         while(current!=nullptr) {
//         if(current->word == key) {
//             // cout<<"Number of comparisons: "<<comparisons<<endl;
//             break;
//         }
//         else {
//             current = current -> next;
//             // comparisons++;
//         }
//     }
//     }
// }

int main()
{
    cout<<"Hello world"<<endl;
    return 0;
}