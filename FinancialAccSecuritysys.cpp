#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
// VULNERABLE CLASS - Current implementation with security flaws
class InsecureAccount {
public:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    std::string accountType;
    bool isActive;    
    void displayAccount() {
        std::cout << "Account: " << accountNumber << " | Owner: " << ownerName 
                  << " | Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    }
};

class BusinessAccount{
    private:
    std::string BusinessName;
    std::string AccountNumber;
    std::string BusinessAddress;
    std::string accountType;
    std::string taxID;
    double creditLimit;
    double balance;
    bool isActive;
    std::vector<std::string> transactionHistory;    
    // Private helper method for transaction logging
    void logTransaction(const std::string& transaction) {
        transactionHistory.push_back(transaction);
        if (transactionHistory.size() > 50) {
            transactionHistory.erase(transactionHistory.begin());
        }
    }

    public:
    BusinessAccount(const std::string& name, const std::string& accNum,
    const std::string& adress, double initialBalance = 0.0)
    : BusinessName(name), AccountNumber(accNum), BusinessAddress(adress),
    balance(initialBalance), isActive(true), accountType("Business"){

    }
    // getters
    std::string getBusinessName() const{ return BusinessName; }
    std::string getAccountNumber() const { return AccountNumber; }
    double getBalance() const { return balance; }
    bool getActiveStatus() const { return isActive; }

    //deposit method with the business rules
    bool deposit(double amount){
        if(!isActive){
            std::cout << "Error: cannot deposit to an inactive account." << std::endl;
            return false;
        }
        if (amount <= 0) {
            std::cout << "Error: Deposit amount must be positive." << std::endl;
            return false;
        }
        // Businesses might have higher deposit limits (e.g., $200,000)
        if (amount > 200000.0) {
            std::cout << "Error: Deposit exceeds business daily limit." << std::endl;
            return false;
        }

        balance += amount;
        logTransaction("Deposit: +$" + std::to_string(amount));
        std::cout << "Successfully deposited $" << std::fixed << std::setprecision(2) 
                  << amount << " into " << BusinessName << std::endl;
        return true;
    }

    // Withdrawal Method with Business Rules
    bool withdraw(double amount) {
        if (!isActive) {
            std::cout << "Error: Cannot withdraw from an inactive account." << std::endl;
            return false;
        }
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive." << std::endl;
            return false;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds for " << BusinessName << std::endl;
            return false;
        }

        balance -= amount;
        logTransaction("Withdrawal: -$" + std::to_string(amount));
        std::cout << "Successfully withdrew $" << std::fixed << std::setprecision(2) 
                  << amount << " from " << BusinessName << std::endl;
        return true;
    }

    //  Transfer Method
    bool transferTo(BusinessAccount& targetAccount, double amount) {
        std::cout << "\nInitiating business transfer of $" << amount << " from " 
                  << this->BusinessName << " to " << targetAccount.getBusinessName() << "..." << std::endl;

        if (this->withdraw(amount)) {
            targetAccount.deposit(amount);
            std::cout << "Transfer completed successfully!" << std::endl;
            return true;
        }
        std::cout << "Transfer failed." << std::endl;
        return false;
    }
    // --- 6. Display Method ---
    void displayAccount() const {
        std::cout << "\n=== Business Account Profile ===" << std::endl;
        std::cout << "Company: " << BusinessName << std::endl;
        std::cout << "Account #: " << AccountNumber << std::endl;
        std::cout << "Address: " << BusinessAddress << std::endl;
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        std::cout << "Status: " << (isActive ? "Active" : "Inactive") << std::endl;
        std::cout << "Recorded Transactions: " << transactionHistory.size() << std::endl;
    }
};
// SECURE REFACTORED CLASS - Your implementation
class SecureAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    std::string accountType;
    bool isActive;
    std::vector<std::string> transactionHistory;    
    // Private helper method for transaction logging
    void logTransaction(const std::string& transaction) {
        transactionHistory.push_back(transaction);
        if (transactionHistory.size() > 50) {
            transactionHistory.erase(transactionHistory.begin());
        }
    }
public:
    // Constructor with validation
    SecureAccount(const std::string& accNum, const std::string& owner, 
                  const std::string& type, double initialBalance = 0.0) 
        : accountNumber(accNum), ownerName(owner), accountType(type), 
          balance(initialBalance), isActive(true) {        
        if (accNum.empty() || owner.empty()) {
            throw std::invalid_argument("Account number and owner name cannot be empty");
        }
        if (initialBalance < 0) {
            balance = 0.0;
            std::cout << "Warning: Negative initial balance set to $0.00" << std::endl;
        }
        logTransaction("Account created with initial balance: $" + std::to_string(initialBalance));
    }    
    // Getters with appropriate access levels
    std::string getAccountNumber() const { return accountNumber; }
    std::string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }
    std::string getAccountType() const { return accountType; }
    bool getActiveStatus() const { return isActive; }    
    // Secured transaction methods with validation
    bool deposit(double amount) {
        if (!isActive) {
            std::cout << "Error: Cannot deposit to inactive account" << std::endl;
            return false;
        }
        if (amount <= 0) {
            std::cout << "Error: Deposit amount must be positive" << std::endl;
            return false;
        }
        if (amount > 50000) {
            std::cout << "Error: Deposit exceeds daily limit of $50,000" << std::endl;
            return false;
        }        
        balance += amount;
        logTransaction("Deposit: +$" + std::to_string(amount));
        std::cout << "Successfully deposited $" << std::fixed << std::setprecision(2) 
                  << amount << ". New balance: $" << balance << std::endl;
        return true;
    }    
    bool withdraw(double amount) {
        if (!isActive) {
            std::cout << "Error: Cannot withdraw from inactive account" << std::endl;
            return false;
        }
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive" << std::endl;
            return false;
        }
        if (amount > balance) {
            std::cout << "Error: Insufficient funds. Current balance: $" 
                      << std::fixed << std::setprecision(2) << balance << std::endl;
            return false;
        }
        if (amount > 10000) {
            std::cout << "Error: Withdrawal exceeds daily limit of $10,000" << std::endl;
            return false;
        }        
        balance -= amount;
        logTransaction("Withdrawal: -$" + std::to_string(amount));
        std::cout << "Successfully withdrew $" << std::fixed << std::setprecision(2) 
                  << amount << ". New balance: $" << balance << std::endl;
        return true;
    }    
    // Account management methods
    void setAccountStatus(bool status) {
        isActive = status;
        logTransaction(status ? "Account activated" : "Account deactivated");
        std::cout << "Account " << (status ? "activated" : "deactivated") << std::endl;
    }    
    void displayAccount() const {
        std::cout << "=== Account Information ===" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Owner: " << ownerName << std::endl;
        std::cout << "Type: " << accountType << std::endl;
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        std::cout << "Status: " << (isActive ? "Active" : "Inactive") << std::endl;
        std::cout << "Recent Transactions: " << transactionHistory.size() << std::endl;
    }    
    // Friend function for regulatory compliance and auditing
    friend class ComplianceAuditor;
    friend void emergencyFreeze(SecureAccount& account, const std::string& reason);
};
// Friend function for emergency account freezing (compliance requirement)
void emergencyFreeze(SecureAccount& account, const std::string& reason) {
    account.isActive = false;
    account.logTransaction("EMERGENCY FREEZE: " + reason);
    std::cout << "EMERGENCY: Account " << account.accountNumber 
              << " frozen due to: " << reason << std::endl;
}
// Friend class for compliance auditing
class ComplianceAuditor {
public:
    static void performAudit(const SecureAccount& account) {
        std::cout << "\n=== COMPLIANCE AUDIT ===" << std::endl;
        std::cout << "Account: " << account.accountNumber << std::endl;
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account.balance << std::endl;
        std::cout << "Transaction History Count: " << account.transactionHistory.size() << std::endl;
        std::cout << "Recent Transactions:" << std::endl;        
        int displayCount = std::min(5, static_cast<int>(account.transactionHistory.size()));
        for (int i = account.transactionHistory.size() - displayCount; 
             i < account.transactionHistory.size(); ++i) {
            std::cout << "  - " << account.transactionHistory[i] << std::endl;
        }
        std::cout << "Audit completed successfully." << std::endl;
    }
};
int main() {
    std::cout << "=== Financial Account Security System Demo ===" << std::endl;    
    // Demonstrate vulnerabilities of the insecure version
    std::cout << "=== Testing Custom BusinessAccount Class ===" << std::endl;

    // Create two business accounts
    BusinessAccount biz1("TechCorp LLC", "BUS-9001", "44 Silicon Way", 25000.0);
    BusinessAccount biz2("Logistics Inc", "BUS-9002", "12 Cargo Blvd", 10000.0);

    // Display initial states
    biz1.displayAccount();
    biz2.displayAccount();

    // Test transactions and limits
    std::cout << "\n--- Testing Business Transactions ---" << std::endl;
    biz1.deposit(5000.0);
    biz1.withdraw(2000.0);

    // Test transfer between business accounts
    biz1.transferTo(biz2, 5000.0);

    // Final display check
    std::cout << "\n--- Final Account States ---" << std::endl;
    biz1.displayAccount();
    biz2.displayAccount();
    std::cout << "\n1. INSECURE VERSION - Vulnerabilities:" << std::endl;
    InsecureAccount insecure;
    insecure.accountNumber = "ACC001";
    insecure.ownerName = "John Doe";
    insecure.balance = 1000.0;
    // Anyone can directly manipulate the balance!
    insecure.balance = 999999.99;  // Unauthorized modification
    insecure.balance = -5000.0;    // Invalid negative balance
    std::cout << "Insecure account manipulated - Balance now: $" 
              << std::fixed << std::setprecision(2) << insecure.balance << std::endl;
    // Demonstrate the secure version
    std::cout << "\n2. SECURE VERSION - Protected Operations:" << std::endl;
    try {
        SecureAccount secure("ACC002", "Jane Smith", "Checking", 1500.0);
        secure.displayAccount();
        // Test secure operations
        std::cout << "\nTesting deposit operations:" << std::endl;
        secure.deposit(500.0);
        secure.deposit(-100.0);  // Should be rejected
        secure.deposit(60000.0); // Should be rejected (over limit)
        std::cout << "\nTesting withdrawal operations:" << std::endl;
        secure.withdraw(200.0);
        secure.withdraw(5000.0); // Should succeed
        secure.withdraw(50000.0); // Should be rejected (insufficient funds)
        // Test friend function access
        std::cout << "\n3. Emergency compliance action:" << std::endl;
        emergencyFreeze(secure, "Suspicious activity detected");
        // Try operations on frozen account
        std::cout << "\nTrying operations on frozen account:" << std::endl;
        secure.deposit(100.0);  // Should be rejected
        // Compliance audit
        std::cout << "\n4. Compliance audit:" << std::endl;
        ComplianceAuditor::performAudit(secure);
    } catch (const std::exception& e) {
        std::cout << "Error creating account: " << e.what() << std::endl;
    }    
    return 0;
}