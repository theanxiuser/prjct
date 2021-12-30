#include<iostream>
#include"user.h"
using namespace std;

// Adding new user
void User::addUser(int id, string fn, string ln, string gn, string ad, string em, string ph, string dp){
    this->user_id = id;
    this->first_name = fn;
    this->last_name = ln;
    this->address = ad;
    this->email = em;
    this->phone[10] = ph;
    this->gender = gn;
    this->department = dp;
}

// Returning the specific user object
User User::returnUser(){
    User usr;
    usr.user_id = user_id;
    usr.first_name = first_name;
    usr.last_name = last_name;
    usr.gender = gender;
    usr.address = address;
    usr.email = email;
    usr.phone[10] = phone[10];
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
        <<"Phone = "<<phone[10]<<endl
        <<"Department = "<<department<<endl;
}

void User::updateUser(){

}

void User::removeUser(){

}