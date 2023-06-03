/*
Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client’s telephone number.
Make use of two collision handling techniques and compare them using
number of comparisons required to find a set of telephone numbers
(Note: Use linear probing with replacement and without replacement)

Name : Krishna Patil
Roll No : 21359
*/

#include <iostream>
#include <string>
using namespace std;

class record
{
    string clientname;
    int num;

public:
    record()
    {
        clientname = "";
        num = 0;
    }
    record(string name, int num)
    {
        this->clientname = name;
        this->num = num;
    }

    friend class Hashtable;
};

class Hashtable
{
    int tablesize;
    record *rec;

public:
    Hashtable()
    {
        tablesize = 0;
        rec = nullptr;
    }
    Hashtable(int size)
    {
        this->tablesize = size;

        // initializing the record array to which the rec pointer is gonna point
        this->rec = new record[tablesize];

        // Assigning every telephone value to 0
        for (int i = 0; i < tablesize; i++)
        {
            rec[i].num = 0;
        }
    }

    int hash(string);
    void display();
    void search();
    void insert_without_replacement();
    void insert_with_replacement();
};

// returns the hashaddress of the given clientname
int Hashtable::hash(string name)
{
    int ascii = 0;
    for (int i = 0; i < name.length(); i++)
    {
        ascii = ascii + name[i];
    }
    return ascii % tablesize;
}

// display record
void Hashtable::display()
{
    for (int i = 0; i < tablesize; i++)
    {
        cout <<"Name: "<< rec[i].clientname << " Telephone: " << rec[i].num << endl;
    }
}

// insert without replacement
void Hashtable::insert_without_replacement()
{
    cout << "Enter the client's name: ";
    string name;
    cin >> name;

    cout << "Enter the telephone number: ";
    int telenum;
    cin >> telenum;

    int index = hash(name);
    if (rec[index].num == 0)
    {
        rec[index].clientname = name;
        rec[index].num = telenum;
    }
    else
    {
        int tempIndex = index;
        while (rec[tempIndex].num != 0)
        {
            tempIndex = (tempIndex + 1) % tablesize;
        }
        rec[tempIndex].clientname = name;
        rec[tempIndex].num = telenum;

    }
    cout << "Record inserted without replacement!" << endl;
}

// insert with replacement
void Hashtable::insert_with_replacement()
{
    cout << "Enter the client's name: ";
    string name;
    cin >> name;

    cout << "Enter the telephone number: ";
    int telenum;
    cin >> telenum;

    int index = hash(name);

    if (rec[index].num == 0)
    {
        rec[index].clientname = name;
        rec[index].num = telenum;
    }
    else
    {
        int existing_index = hash(rec[index].clientname);
        if (existing_index == index)
        {

            int tempIndex = existing_index;
            while (rec[tempIndex].num != 0)
            {
                tempIndex = (tempIndex + 1) % tablesize;
            }
            rec[tempIndex].clientname = rec[existing_index].clientname;
            rec[tempIndex].num = rec[existing_index].num;

            rec[index].clientname = name;
            rec[index].num = telenum;
        }
        else
        {
            int tempIndex = index;
            while (rec[tempIndex].num != 0)
            {
                tempIndex = (tempIndex + 1) % tablesize;
            }
            rec[index].clientname = name;
            rec[tempIndex].num = telenum;
        }
    }

    cout<<"Record inserted with replacement!"<<endl;
}

void Hashtable::search()
{
    cout << "Enter the clientname whose telephone number is to be searched: ";
    string name;
    cin >> name;

    int comparisons = 0;
    int index = hash(name);

    if (rec[index].clientname == name)
    {
        cout << "Record found!" << endl;
        cout << "Client's telephone number: " << rec[index].num<<endl;
        comparisons++;
    }
    else
    {
        int tempIndex = index;
        int passes = 0;
        while (rec[tempIndex].clientname != name && passes!=tablesize)
        {
            tempIndex = (tempIndex + 1) % tablesize;
            passes++;
            comparisons++;
        }
        if (rec[tempIndex].clientname == name)
        {
            cout << "Record found!" << endl;
            cout << "Client's telephone number: " << rec[tempIndex].num<<endl;
        }
        else {
            cout<<"Record with name "<<name<<" not found!"<<endl;
        }
    }

    cout<<"Number of comparisons: "<<comparisons<<endl;
}

int main() {

    Hashtable ht(10);
    ht.insert_without_replacement();
    ht.insert_without_replacement();
    ht.insert_with_replacement();
    ht.display();

    ht.search();

    return 0;
}