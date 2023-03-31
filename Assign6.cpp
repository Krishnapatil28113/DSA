#include <iostream>
#include <string>
#define size 10
using namespace std;

class node{
    string data;
    bool visited;
    node* down;
    node* next;

    public:
    node(){};
    node(string value){
        this->data = value;
        this->down = nullptr;
        this->next = nullptr;
    };
    friend class Graph;
};

class Graph{
    node* head;
    public:
    void create_graph();
    void display_graph();
    bool isConnected();
    int find_degree();
};

void Graph::create_graph()
{
    node* node1 = new node("Bharti");
    node1->next = new node("Katraj");
    node1->next->next = new node("Pict");
    this->head = node1;

    node* node2 = new node("Pict");
    node2->next = new node("Bharti");
    node2->next->next = new node("Katraj");
    node2->next->next->next = new node("Scoe");
    node1->down = node2;

    node* node3 = new node("Katraj");
    node3->next = new node("Pict");
    node3->next->next = new node("Temple");
    node3->next->next->next = new node("Bharti");
    node2->down = node3;

    node* node4 = new node("Scoe");
    node4->next = new node("Pict");
    node4->next->next = new node("Katraj");
    node4->next->next->next = new node("Temple");
    node3->down = node4;

    node* node5 = new node("Temple");
    node5->next = new node("Katraj");
    node5->next->next = new node("Scoe");
    node4->down = node5;

    node5->down = nullptr;
}

void Graph::display_graph()
{
    node* parent = this->head;
    node* current = parent;

    while(parent->down!=nullptr)
    {
        cout<<current->data<<" - ";
        while(current->next!=nullptr)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
        parent = parent->down;
    }
}

int main()
{
    Graph d;
    d.create_graph();
    d.display_graph();
    return 0;
}