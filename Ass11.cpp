/*
Department maintains a student information. The file contains roll
number, name, division and address. Allow user to add, delete
information of student. Display information of particular student. If
record of student does not exist an appropriate message is displayed. If
it is, then the system displays the student details. Use Sequential File
to maintain the data.

Name : Krishna Patil
Roll No : 21359
*/

//sequential file
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class record{
    int rollno,div;
    string name,add;
    public:
    record() {};

    //initializing values
    record(int rollno , int div , string name , string add) {
        this->rollno = rollno;
        this->div = div;
        this->name = name;
        this->add = add;
    }
    friend class seqFile;
};

class seqFile{
    string filename;
    fstream input;
    fstream output;
    public:

    //initializing the name of the file
    seqFile(string filename) {
        this->filename = filename;
    }
    void writeRecord(record* , int);
    void displayRecord();
    void deleteRecord(int);
    void searchRecord(int);
};

void seqFile::writeRecord( record* rec , int num) {

    //num denotes the number of records we want to add into the file
    output.open(filename,ios::out);
    for(int i = 0 ; i < num ; i++) {
        //write all the details in the output file onto a new line
        output<<rec[i].name<<" "<<rec[i].rollno<<" "<<rec[i].div<<" "<<rec[i].add<<endl;
    }
    output.close();
}

void seqFile::displayRecord() {
    input.open(filename , ios::in);
    while(!input.eof()) {
        string line;
        getline(input , line);
        cout<<line<<endl;
    }
    input.close();
}

void seqFile::searchRecord(int r) {

    //we are just searching an element in the file therefore there is no need to open the file in output or any other mode
    input.open(filename , ios::in);
    bool flag = false;
    while(!input.eof()) {
        string record_;
        input>>record_;
        if(int(record_[0] - 48) == r) {
            cout<<"Record found"<<endl;
            cout<<record_<<endl;
            flag = true;
            break;
        }
        input.close();
    }
    if(!flag) {
        cout<<"Record not found"<<endl;
    }
}

void seqFile::deleteRecord(int r) {

    vector <string> lines;
    input.open(filename , ios::in);
    while(!input.eof()) {
        string rec;
        input>>rec;
        if(int(rec[0] - 48) != r) {
            lines.push_back(rec);
        }
    }
    input.close();

    output.open(filename , ios::out);
    for(int i = 0 ; i < lines.size() ; i++) {
        //this will insert all the lines present in the vector lines which contains string as it's object
        output<<lines[i]<<endl;
    }
    output.close();

    //deleted the element passed as parameter
}

int main() {
    seqFile file("sample.txt");


    record rec[3] = {
        record( 59 , 3 , "Krishna" , "Shivane"),
        record( 56 , 3 , "Shubham" , "Thane"),
        record( 55 , 3 , "Kaustubh" , "Jalgaon"),
    };
    file.writeRecord(rec , 3);
    file.displayRecord();
    file.searchRecord(3);
    file.deleteRecord(3);
    file.displayRecord();
    return 0;
}