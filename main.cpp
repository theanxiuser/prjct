using namespace std;
#include<iostream>
#include"user.h"
// #include"DBLite.h"
#include<vector>
#include<stdlib.h>

// void access(User usr){
    
// }

void inputData(){
    // Getting information using CLI
    string name, address, email, gender, phone;
    cout<<"Enter full name: ";
    getline(cin, name);
    cout<<"Enter email: ";
    cin>>email;
    cout<<"Enter address: ";
    getline(cin, address);
    cout<<"Enter phone no: ";
    cin>>phone;
    cout<<"Enter gender: ";
    cin>>gender;

    // Passing data into User class object
    User usr;
    // Check either user already present or not
    if(usr.searchUser(name)){
        cout<<"Sorry, "<<name<<" is already exists.\nTry for others."<<endl;
    }
    else{
        usr.addUser(name, email, address, phone, gender);
        cout<<"User created succesfully."<<endl;
    }
}

void displayAllUser(){
    // Requesting member function of User class to display all the users
    User usr;
    for(int i=0; i< usr.numOfRow(); i++){
        usr.displayAllUser();
        usr.displayUser();
    }
}

void searchUser(){
    string name;
    cout<<"Which user do you want to search ?"<<endl;
    getline(cin, name);

    // SEnding request to User object
    User usr;
    if(usr.searchUser(name)){
        usr.returnUser(name);
        cout<<"User Information:"<<endl;
        usr.displayUser();
    }
    else
        cout<<"User: "<<name<<" Doesn't exists !!!"<<endl;
}

void updateUser(){
    // Displaying all the users
    displayAllUser();

    // Conformation for updating
    cout<<"Which user you want to update?"<<endl;
    string name, email, address, phone;
    getline(cin, name);

    // Before updating check either user is in db or not
    User usr;
    if(usr.searchUser(name)){
        // New Informations for upated user
        cout<<"Enter new information for "<<name<<endl;
        cout<<"Email: ";
        cin>>email;
        cout<<"Address: ";
        getline(cin, address);
        cout<<"Phone: ";
        cin>>phone;

        // Sending update request to User object along with new infos
        usr.updateUser(name, email, address, phone);
        cout<<name<<" Updated successfully."<<endl;
    }
    else
        cout<<name<<" is not in datatbase to update.\n\
            First Add"<<name<<" into database!!"<<endl;
}

void removeUser(){
    // Displaying all the users
    displayAllUser();

    // Conformation for deleting
    cout<<"Which user you want to delete?"<<endl;
    string name;
    getline(cin, name);

    // Sending delete request to User object;
    User usr;
    usr.removeUser(name);
    cout<<name<<" removed from user successfully"<<endl;
}

int main(){
    // This is CLI for user to operate and control over program 
    int choice;
    while(1){
        cout<<"\n1. Add user\n\
            2. Search user\n\
            3. Display all users\n\
            4. Update user\n\
            5. Remove user\n\
            6. Exit\n";
        cout<<"What do You want? "<<endl;
        cin>>choice;
        switch(choice){
            case 1: inputData();
                    break;

            case 2: searchUser();
                    break;

            case 3: displayAllUser();
                    break;

            case 4: updateUser();
                    break;

            case 5: removeUser();
                    break;

            case 6: cout<<"Exiting program..."<<endl;
                    exit(1);
            
            default: cout<<"Enter correct option!!!"<<endl;
        }
    }

    // vector<string> v;
    // User u;
    // u.addUser("20", "b", "p", "m");
    // cout<<"User created in class"<<endl;
    
    // User usr = u.returnUsere();
    // cout<<"Display from class"<<endl;
    // usr.displayUser();

    // v = u.returnUser();
    // for (int i=0; i<8 ;i++)
    //     cout<<i<<" = "<<v[i]<< typeid(v[i]).name()<<endl;
    // string id, fn, ln, gn, ad, em, ph, dp;
    // id = v[0];
    // fn = v[1];
    // ln = v[2];
    // gn = v[3];
    // ad = v[4];
    // em = v[5];
    // ph = v[6];
    // dp = v[7];

    // DBLite sqldb;
    // sqldb.createTable();
    // // Inserting into db
    // sqldb.insertData("255", "John", "Pradhan", "Male", " "," "," "," ");
    // cout<<"Inserted into db"<<endl<<endl;

    // sqldb.insertData(usr.user_id.c_str(), usr.first_name.c_str(), usr.last_name.c_str(), usr.gender.c_str(), usr.address.c_str(), usr.email.c_str(), usr.phone.c_str(), usr.department.c_str());
    // sqldb.insertData(v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back());
    // sqldb.insertData(id.c_str(), fn.c_str(), ln.c_str(), gn.c_str(), ad.c_str(), em.c_str(), ph.c_str(), dp.c_str());
    // cout<<"Data from db"<<endl<<endl;;
    // sqldb.showTable();
    // sqldb.closeDB();


    // u.displayUser();
    // u1.displayUser();
    return 0;
}
