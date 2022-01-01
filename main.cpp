using namespace std;
#include<iostream>
#include"user.h"
// #include"DBLite.h"
#include<vector>

// void access(User usr){
    
// }
int main(){
    // vector<string> v;
    User u;
    u.addUser("20", "b", "p", "m");
    cout<<"User created in class"<<endl;
    
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
