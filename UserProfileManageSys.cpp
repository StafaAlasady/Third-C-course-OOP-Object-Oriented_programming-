#include <iostream>
#include <string>
#include <vector>
#include <regex>
class UserProfile {
private:
    std::string username;
    std::string email;
    std::string passwordHash;
    std::string fullName;
    int age;
    std::vector<std::string> friends;
    bool isPrivateProfile;
    bool isVerified;
    std::string phoneNumber;
    // Private validation helpers
    bool isValidEmail(const std::string& email) const {
        std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        return std::regex_match(email, emailPattern);
    }    
    bool isValidUsername(const std::string& username) const {
        return username.length() >= 3 && username.length() <= 20;
    }
public:
    // Constructor with comprehensive validation
    UserProfile(const std::string& user, const std::string& mail, const std::string& name) 
        : isPrivateProfile(true), isVerified(false), age(0) {        
        if (!setUsername(user)) {
            throw std::invalid_argument("Invalid username");
        }
        if (!setEmail(mail)) {
            throw std::invalid_argument("Invalid email address");
        }
        if (!setFullName(name)) {
            throw std::invalid_argument("Invalid full name");
        }
    }    
    // Getters for public information
    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }
    std::string getDisplayName() const { 
        return isPrivateProfile ? username : fullName; 
    }
    bool isProfilePrivate() const { return isPrivateProfile; }
    bool isUserVerified() const { return isVerified; }
    int getFriendCount() const { return friends.size(); }    
    // Secured setters with validation
    bool setUsername(const std::string& newUsername) {
        if (isValidUsername(newUsername)) {
            username = newUsername;
            return true;
        }
        std::cout << "Error: Username must be 3-20 characters long" << std::endl;
        return false;
    }    
    bool setEmail(const std::string& newEmail) {
        if (isValidEmail(newEmail)) {
            email = newEmail;
            return true;
        }
        std::cout << "Error: Invalid email format" << std::endl;
        return false;
    }
    bool setFullName(const std::string& name) {
        if (!name.empty() && name.length() <= 100) {
            fullName = name;
            return true;
        }
        std::cout << "Error: Full name cannot be empty or exceed 100 characters" << std::endl;
        return false;
    }    
    bool setAge(int newAge) {
        if (newAge >= 13 && newAge <= 120) {
            age = newAge;
            return true;
        }
        std::cout << "Error: Age must be between 13 and 120" << std::endl;
        return false;
    }
    bool SetPrivacyStatus(bool status) {
        isPrivateProfile = status;
        return true;
    }
    bool TogglePrivacy(){
        isPrivateProfile = !isPrivateProfile;
        return isPrivateProfile;
    }
    // Your implementation here: Add methods for privacy settings, friend management, etc.    
    // Friend declarations for platform administration
    friend class PlatformModerator;
    friend void technicalSupport(UserProfile& user, const std::string& issue){
    std::cout << "[Tech Support Ticket] Issue reported: " << issue << std::endl;
    
    // Example of using friend access: checking if the user's profile is private
    // (Normally outside code can't see 'isPrivateProfile', but tech support can!)
    if (user.isPrivateProfile) {
        std::cout << "Note: User profile is currently private.\n";
    } else {
        std::cout << "Note: User profile is public.\n";
    }
    }
};
// Complete this implementation
int main() {
    // Your code here: Create UserProfile objects and demonstrate encapsulation
    
    UserProfile myUser("stafa_user", "stafa@email.com", "Stafa");

    if(myUser.setAge(25)){
        std::cout << "Age was accepted! \n";
    } 
    // Test an invalid age
    if (myUser.setAge(10)) {
        std::cout << "Age 10 was accepted! \n";
    } else {
        std::cout << "Age 10 was rejected as expected! \n";
    }
    //now its time to call the setprivacystatus Method
    myUser.SetPrivacyStatus(true);
    //now its time to call the toggleprivacy Method
    myUser.TogglePrivacy();
    technicalSupport(myUser, "cannot upload profile picture");
    return 0;
}