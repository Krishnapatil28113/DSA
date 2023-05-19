#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hashtable
{
    public:

    int addr;

}HT[10];

class Employee : public Hashtable
{
    int emp_id;
    char salary[10];
    char name[10];
    char exp[10];

public:
    
    void add_Rec();
    void display_Rec();
    void search_Rec();
    void delete_rec();

};


void Employee :: add_Rec()
{

        int index, count, tablesize = 10;
        int location;
    

        cout<<"\n\t How many records..? : ";
        cin>>count;

        ofstream fout;
        fout.open("FileDAF.txt", ios::out);

        for (int i = 0; i < count; i++)
        {
            cout << "Enter Employee id: ";
            cin >> emp_id;

            cout << "Enter Employee name: ";        
            cin >> name;            

            cout << "Enter Employee salary: ";
            cin >> salary;            
            
            cout << "Enter Experience: ";            
            cin >> exp;

            location = fout.tellp();

            index = emp_id % tablesize;

            HT[index].addr = location;

            fout<<emp_id<<" "<<name<<" "<<""<<exp<<" "<<salary<<endl;
        }  
        fout.close();     
        
}

void Employee :: display_Rec()
{
    char buffer[40];
    int cnt = 1;
    ifstream fin;
    fin.open("FileDAF.txt", ios::in);

    while(! fin.eof())
    {        
        fin.getline(buffer,40);
        cout<<"Record "<<cnt<<" : "<<buffer;
        cnt++;
    }
}

void Employee :: search_Rec()
{
    int id;
    int tablesize = 10;

    cout<<"\n\t Enter Emp_id to search record: ";
    cin>>id;

    int index = id % tablesize;

    int location = HT[index].addr;

    ifstream fin;
    fin.open("FileDAF.txt", ios::in);

    fin.seekg(location, ios::beg);

    char buffer[40];
    fin.read(buffer, 15);
    cout<<"\n\t Found: "<<buffer;
}

int main()
{
    Employee E;
    
    E.add_Rec();

    E.display_Rec();
    
    E.search_Rec();

    return 0;
}