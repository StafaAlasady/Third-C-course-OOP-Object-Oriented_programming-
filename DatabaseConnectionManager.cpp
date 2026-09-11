#include <iostream>
#include <string>
#include <memory>

class DatabaseConnection {
private:
    std::string connectionString;
    std::string databaseName;
    bool isConnected;
    int connectionId;
    static int nextId;
    // Simulate connection establishment
    bool establishConnection() {
        std::cout << "Establishing connection to " << databaseName << "..." << std::endl;
        // Simulate connection logic
        isConnected = true;
        return true;
    }    
    // Simulate connection cleanup
    void closeConnection() {
        if (isConnected) {
            std::cout << "Closing database connection [ID: " << connectionId << "]" << std::endl;
            isConnected = false;
        }
    }
public:
    // Default constructor
    DatabaseConnection() : connectionString("localhost:5432"), databaseName("default_db"), 
                          isConnected(false), connectionId(++nextId) {
        std::cout << "Creating default database connection [ID: " << connectionId << "]" << std::endl;
        establishConnection();
    }    
    // Parameterized constructor
    DatabaseConnection(const std::string& connStr, const std::string& dbName) 
        : connectionString(connStr), databaseName(dbName), isConnected(false), connectionId(++nextId) {
        std::cout << "Creating database connection [ID: " << connectionId << "] to " << databaseName << std::endl;
        establishConnection();
    }    
    // Copy constructor (creates new connection)
    DatabaseConnection(const DatabaseConnection& other) 
        : connectionString(other.connectionString), databaseName(other.databaseName + "_copy"), 
          isConnected(false), connectionId(++nextId) {
        std::cout << "Creating copied database connection [ID: " << connectionId 
                  << "] based on connection " << other.connectionId << std::endl;
        establishConnection();
    }    
    // Destructor
    ~DatabaseConnection() {
        std::cout << "Destroying database connection [ID: " << connectionId << "]" << std::endl;
        closeConnection();
    }    
    // Member functions
    void executeQuery(const std::string& query) {
        if (isConnected) {
            std::cout << "Executing on " << databaseName << ": " << query << std::endl;
        } else {
            std::cout << "Cannot execute - connection not established" << std::endl;
        }
    }    
    bool getConnectionStatus() const {
        return isConnected;
    }    
    int getId() const {
        return connectionId;
    }
};
// Initialize static member
int DatabaseConnection::nextId = 0;
// Complete the main function
int main() {
    std::cout << "=== Database Connection Manager ===" << std::endl;    
    // Your code here: Create different types of database connections
    // Test all three constructor types and demonstrate their usage

    //constructor
    DatabaseConnection defaultDb;
    DatabaseConnection salesDb("localhost:3306", "sales_db" );

    salesDb.executeQuery("SELECT * FROM users;");

    {
    DatabaseConnection salesDbCopy = salesDb;
    salesDbCopy.executeQuery("SELECT * FROM users;");
    }



    return 0;
}