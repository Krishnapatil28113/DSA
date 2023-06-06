/*
You have a business with several offices; you want to lease phone lines to connect them up with each
other; and the phone company charges different amounts of money to connect different pairs of cities.
You want a set of lines that connects all your offices with a minimum total cost. Solve the problem 
by suggesting appropriate data structures.

Name : Krishna Patil
Roll No : 21359
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class node{
    char name;
    int cost;
    node* next;
    node* down;
    public:
    node(int cost , char name) {
        this->cost = cost;
        this->name = name;
        this->next = nullptr;
        this->down = nullptr;
    }

    friend class graph;

};

class Edge{
    char v1,v2;
    int weight;

    public:
    Edge() {};
    Edge(char var1 , char var2 , int weight) {
        this->v1 = var1;
        this->v2 = var2;
        this->weight = weight;
    }
    friend class graph;
};

class graph{
    node* node1,*node2,*node3,*node4,*node5;
    public:

    graph() {
        this->node1 = new node(0,'A');
        this->node1 = new node(0,'B');
        this->node1 = new node(0,'C');
        this->node1 = new node(0,'D');
        this->node1 = new node(0,'E');

        this->node1->down = this->node2;
        this->node2->down = this->node3;
        this->node3->down = this->node4;
        this->node4->down = this->node5;
    }

    void insert(char parentName , char adjacentName , int val) {
        node* parent = node1;
        while(parent!=nullptr) {
            if(parent->name = parentName) {
            break;
        }
        parent = parent->down;
        }
    }
};

int main() {

    return 0;
}