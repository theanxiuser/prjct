#include <iostream>
#include <string.h>
#include <sqlite3.h>
// #include "user.h"
using namespace std;

class DBLite {
	private:
		// Pointer to SQLite connection
    	sqlite3 *db;

    	// Save any error messages
    	char *errMsg;

    	// Save the result of opening the file
    	int rc;

    	// Saved SQL
    	char const *sql;

    	// Compiled SQLite Statement
    	sqlite3_stmt *stmt;

    	// Create a callback function  
		static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
		    // int argc: holds the number of results
		    // (array) azColName: holds each column returned
		    // (array) argv: holds each value

		    for(int i = 0; i < argc; i++) {    
		        // Show column name, value, and newline
		        cout << azColName[i] << ": " << argv[i] << endl;
		    
		    }
		    // Insert a newline
		    cout << endl;

		    // Return successful
		    return 0;
		}

		void checkDBErrors() {

			if( rc ){
		        // Show an error message
		        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
		        closeDB();
		        
    		}
		}

	public:
		DBLite() {
			// Save the result of opening the file
    		rc = sqlite3_open("user.db", &db);
    		checkDBErrors();	
		}

		void createTable() {
		    // Save SQL to create a table
		    sql = "CREATE TABLE IF NOT EXISTS user ("
				"user_id INT PRIMARY KEY NOT NULL,"
				"name TEXT NOT NULL UNIQUE,"
				"email TEXT NOT NULL UNIQUE,"
				"address TEXT NOT NULL,"
				"phone TEXT NOT NULL UNIQUE,"
				"gender TEXT NOT NULL );";
		    
		    // Run the SQL
		    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
		}

		void insertData(char const * name, const char *email, const char *address, const char *phone, const char *gender) {

			char *query = NULL;
			cout<<"INTO DB"<<endl;
			cout<<name<<endl;
			cout<<email<<endl;

			// Build a string using asprintf()
			asprintf(&query, "INSERT INTO user ('name', 'email', 'address', 'phone', 'gender') VALUES  ('%s', '%s', '%s', '%s', '%s');", name, email, address, phone, gender);   

			// Prepare the query
		    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);

		    // Test it
			rc = sqlite3_step(stmt);

			// Finialize the usage
			sqlite3_finalize(stmt);

			// Free up the query space
			free(query);     

		}

		void showTable() {

			// Save SQL insert data
    		sql = "SELECT * FROM 'user';";
    
   			// Run the SQL
    		rc = sqlite3_exec(db, sql, callback, 0, &errMsg);

		}

		bool searchTable(const char *name){
			// Searching user in table by name
			sql = "SELECT * FROM user WHERE name = 'name';";
			rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
			// Not working need to be modify
			return true;
		}

		void returnRow(const char* name){
			// Return info of specific user
			sql = "SELECT * FROM 'user' WHERE name = 'name';";
			rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
		}

		int numOfRow(){
			sql = "SELECT COUNT(*) as rownum FROM 'user';";
			// Not working 
			return 1;
		}

		void updateData(const char *name, const char* email, const char* address, const char* phone){
			sql = ("UPDATE 'user' SET email='%s', address='%s', phone='%s' WHERE name='%s';", email, address, phone, name);
			rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
		}

		void deleteRow(char const* name) {

			char *query = NULL;

			// Build a string using asprintf()
			asprintf(&query, "DELETE FROM 'user' WHERE name = '%s';", name);   

			// Prepare the query
		    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);

		    // Test it
			rc = sqlite3_step(stmt);

			// Finialize the usage
			sqlite3_finalize(stmt);

			// Free up the query space
			free(query);     

		}

		void closeDB() {
			// Close the SQL connection
    		sqlite3_close(db);
		}
};

// OPERATIONS:
// DBLite sqldb;
// sqldb.createTable();
// sqldb.insertData("10", "RK");
// sqldb.showTable();
// sqldb.deleteRow("3");
// sqldb.closeDB();