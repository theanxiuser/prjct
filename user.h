#include<string>
#include<iostream>
#include<vector>
#include"DBLite.h"
using namespace std;
class User{
    private:
    string user_id;
    string name;
    // string last_name;
    string email;
    string address;
    string phone;
    string gender;
    // string department;
    public:
    void addUser(string, string, string, string, string);
    // vector<string> returnUser();
    // User returnUser(string);
    void returnUser(string);
    void displayUser();
    void updateUser(string, string, string, string);
    void removeUser(string);
    // User displayAllUser();
    void displayAllUser();
    bool searchUser(string);
    int numOfRow();
    // friend class DBLite;
    // friend void access(User usr);
};

// Find the number of rows present in database
int User::numOfRow(){
    DBLite sqldb;
    int num = sqldb.numOfRow();
    sqldb.closeDB();
    return num;
}

// Return all the users available in db into main
// User User::displayAllUser(){
//     User u;
//     DBLite sqldb;
//     sqldb.showTable();
//     // Returning all the content of table row by row 
//     sqldb.closeDB();
//     return u;
// }

void User::displayAllUser(){
    // User u;
    DBLite sqldb;
    sqldb.showTable();
    // Returning all the content of table row by row 
    sqldb.closeDB();
    // return u;
}

// User returnUser(string name){
//     User u;
//     DBLite sqldb;
//     // Requesting db to return row of name=name
//     sqldb.returnRow(name.c_str());
//     // Store info into object and return back to main
//     sqldb.closeDB();
//     return u;
// }

void User::returnUser(string name){
    this->name = name;
    DBLite sqldb;
    // Requesting db to return row of name=name
    sqldb.returnRow(name.c_str());
    // Store info into object and return back to main
    sqldb.closeDB();
}

bool User::searchUser(string name){
    this->name = name;
    DBLite sqldb;
    // Check either name is in db or not and respond to main
    if(sqldb.searchTable(name.c_str())){
        return true;
    }
    else
        return false;
    sqldb.closeDB();
}

void User::updateUser(string name, string email, string address, string phone){
    this->name = name;
    this->email = email;
    this->address = address;
    this->phone = phone;
    DBLite sqldb;
    // Update name with new infos in db
    sqldb.updateData(name.c_str(), email.c_str(), address.c_str(), phone.c_str());
    sqldb.closeDB();
}

void User::removeUser(string name){
    this->name = name;
    DBLite sqldb;
    sqldb.deleteRow(name.c_str());
    sqldb.closeDB();
}

// Adding new user
void User::addUser(string name, string email, string address, string phone, string gender){
    this->name = name;
    this->email = email;
    this->address = address;
    this->phone = phone;
    this->gender = gender;
    // this->department = dp;

    // Adding user into database
    DBLite sqldb;
    sqldb.createTable();
    // sqldb.insertData(user_id.c_str(), first_name.c_str(), last_name.c_str(), gender.c_str(), address.c_str(), email.c_str(), phone.c_str(), department.c_str());
    sqldb.insertData(name.c_str(), email.c_str(), address.c_str(), phone.c_str(), gender.c_str());
    sqldb.closeDB();
}

// Returning the specific user object
// vector<string> User::returnUser(){
//     vector<string> v;
//     v.push_back(user_id);
//     v.push_back(first_name);
//     v.push_back(last_name);
//     v.push_back(gender);
//     v.push_back(address);
//     v.push_back(email);
//     v.push_back(phone);
//     v.push_back(department);
//     return v;
//     // User usr;
//     // usr.user_id = user_id;
//     // usr.first_name = first_name;
//     // usr.last_name = last_name;
//     // usr.gender = gender;
//     // usr.address = address;
//     // usr.email = email;
//     // usr.phone = phone;
//     // usr.department = department;
//     // return usr;
// }

// User User::returnUsere(){
//     User usr;
//     usr.user_id = user_id;
//     usr.first_name = first_name;
//     usr.last_name = last_name;
//     usr.gender = gender;
//     usr.address = address;
//     usr.email = email;
//     usr.phone = phone;
//     usr.department = department;
//     return usr;
// }

// Display the info of user, this may not be useful
// Just created for test
void User::displayUser(){
    cout<<"Full Name = "<<name<<endl
        <<"User ID = "<<user_id<<endl
        <<"Email = "<<email<<endl
        <<"Address = "<<address<<endl
        <<"Phone no. = "<<phone<<endl
        <<"Gender = "<<gender<<endl;

    // cout<<"\nUser Informations:"<<endl
    //     <<"Id = "<<user_id<<endl
    //     <<"Name = "<<first_name<<" "<<last_name<<endl
    //     <<"Gender = "<<gender<<endl
    //     <<"Address = "<<address<<endl
    //     <<"Email = "<<email<<endl
    //     <<"Phone = "<<phone<<endl
    //     <<"Department = "<<department<<endl;
}