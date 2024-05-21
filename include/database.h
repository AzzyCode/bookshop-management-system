#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
private:
    sqlite3* db; // Pointer to the SQLite database connection
    char* errMsg; // Pointer to a string for storing error messages from SQLite.
    int rc; // Integer to store return codes from SQLite functions.

public:
    Database(const std::string& dbName);
    ~Database(); // Destructor to close the database connection
    void initialize();
};

#endif
