#include<string>
#include<iostream>
#include<vector>
#include"DBLite.h"
using namespace std;
class User{
    private:
    string user_id;
    string first_name;
    string last_name;
    string gender;
    string address;
    string email;
    string phone;
    string department;
    public:
    void addUser(string, string, string, string, string="non", string="non", string="non", string="non");
    vector<string> returnUser();
    User returnUsere();
    void displayUser();
    void updateUser();
    void removeUser();
    // friend void access(User usr);
};

// Adding new user
void User::addUser(string id, string fn, string ln, string gn, string ad, string em, string ph, string dp){
    this->user_id = id;
    this->first_name = fn;
    this->last_name = ln;
    this->gender = gn;
    this->address = ad;
    this->email = em;
    this->phone = ph;
    this->department = dp;

    // Adding user into database
    DBLite sqldb;
    sqldb.createTable();
    sqldb.insertData(user_id.c_str(), first_name.c_str(), last_name.c_str(), gender.c_str(), address.c_str(), email.c_str(), phone.c_str(), department.c_str());
    sqldb.closeDB();
}

// Returning the specific user object
vector<string> User::returnUser(){
    vector<string> v;
    v.push_back(user_id);
    v.push_back(first_name);
    v.push_back(last_name);
    v.push_back(gender);
    v.push_back(address);
    v.push_back(email);
    v.push_back(phone);
    v.push_back(department);
    return v;
    // User usr;
    // usr.user_id = user_id;
    // usr.first_name = first_name;
    // usr.last_name = last_name;
    // usr.gender = gender;
    // usr.address = address;
    // usr.email = email;
    // usr.phone = phone;
    // usr.department = department;
    // return usr;
}

User User::returnUsere(){
    User usr;
    usr.user_id = user_id;
    usr.first_name = first_name;
    usr.last_name = last_name;
    usr.gender = gender;
    usr.address = address;
    usr.email = email;
    usr.phone = phone;
    usr.department = department;
    return usr;
}

// Display the info of user, this may not be useful
// Just created for test
void User::displayUser(){
    cout<<"\nUser Informations:"<<endl
        <<"Id = "<<user_id<<endl
        <<"Name = "<<first_name<<" "<<last_name<<endl
        <<"Gender = "<<gender<<endl
        <<"Address = "<<address<<endl
        <<"Email = "<<email<<endl
        <<"Phone = "<<phone<<endl
        <<"Department = "<<department<<endl;
}

void User::updateUser(){

}

void User::removeUser(){

}