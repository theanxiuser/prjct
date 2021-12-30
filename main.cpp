using namespace std;
#include<iostream>
#include"user.h"
#include"DBLite.h"
#include<vector>

// void access(User usr){
    
// }
int main(){
    // vector<string> v;
    User u;
    u.addUser("20", "b", "p", "m");
    cout<<"User created in class"<<endl;
    
    User usr = u.returnUsere();
    cout<<"Display from class"<<endl;
    usr.displayUser();

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

    DBLite sqldb;
    sqldb.createTable();
    // Inserting into db
    sqldb.insertData("255", "John", "Pradhan", "Male", " "," "," "," ");
    cout<<"Inserted into db"<<endl<<endl;

    cout<<"Data from db"<<endl<<endl;;
    sqldb.showTable();
    sqldb.closeDB();

    // sqldb.insertData(usr.user_id, usr.first_name, usr.last_name, usr.gender, usr.address, usr.email, usr.phone, usr.department);
    // sqldb.insertData(v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back(), v.pop_back());
    // sqldb.insertData(id, fn, ln, gn, ad, em, ph, dp);

    // u.displayUser();
    // u1.displayUser();
    return 0;
}
