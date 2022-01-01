#include <iostream>
#include <string.h>
#include <sqlite3.h>
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
				"first_name TEXT NOT NULL,"
				"last_name TEXT NOT NULL,"
				"gender TEXT NOT NULL,"
				"address TEXT NOT NULL,"
				"email TEXT NOT NULL,"
				"phone TEXT NOT NULL,"
				"department TEXT NOT NULL );";
		    
		    // Run the SQL
		    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
		}

		void insertData(char const * user_id, char const * first_name, char const *last_name, const char *gender, const char *address, const char *email, const char *phone, const char *department) {

			char *query = NULL;

			// Build a string using asprintf()
			asprintf(&query, "INSERT INTO user ('user_id', 'first_name', 'last_name', 'gender', 'address', 'email', 'phone', 'department' ) VALUES  ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');", user_id, first_name, last_name, gender, address, email, phone, department);   

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

		void searchTable(const char *id){
			// Searching user in table by id
			sql = "SELECT * FROM User WHERE user_id = 'id';";
			rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
		}

		void deleteRow(char const* user_id) {

			char *query = NULL;

			// Build a string using asprintf()
			asprintf(&query, "DELETE FROM 'user' WHERE ID = '%s';", user_id);   

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