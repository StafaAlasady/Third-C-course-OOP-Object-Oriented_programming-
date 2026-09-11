#include <iostream>
#include <string>
#include <chrono>
#include <format>
#include <vector>
#include <algorithm>

class DigitalAsset {
private:
    std::string fileName;
    std::string fileType;
    double fileSizeMB;
    std::string creationDate;
    bool isActive;
    static int totalAssets;  // Track total number of assets created

    // Helper function for extension validation
    bool validateExtension(const std::string& name, const std::string& type) const {
        if (name.empty()) return false;
        size_t dotIndex = name.rfind('.');
        if (dotIndex == std::string::npos) return false;
        
        std::string ext = name.substr(dotIndex + 1);
        // Simple matching logic for demonstration
        if (type == "image" && (ext == "png" || ext == "jpg" || ext == "jpeg")) return true;
        if (type == "video" && (ext == "mp4" || ext == "avi" || ext == "mkv")) return true;
        if (type == "document" && (ext == "txt" || ext == "pdf" || ext == "docx")) return true;
        
        // Allow unknown or generic matches with a warning flag if needed
        return true; 
    }

public:
    // Default constructor
    DigitalAsset() : fileName("untitled.txt"), fileType("document"), fileSizeMB(0.0), isActive(true) {
        auto now = std::chrono::system_clock::now();
        creationDate = std::format("{:%Y-%m-%d %H:%M:%S}", now);       
        totalAssets++;
        std::cout << "✓ Default asset created: " << fileName << " | Total assets: " << totalAssets << std::endl;
    }    

    // Parameterized constructor with validation
    DigitalAsset(const std::string& name, const std::string& type, double size) 
        : fileType(type), isActive(true) {        
        
        // 1. Validate negative file sizes
        if (size < 0.0) {
            std::cout << "⚠️ Warning: Negative size (" << size << ") for '" << name << "'. Defaulting to 0.0 MB." << std::endl;
            fileSizeMB = 0.0;
        } else {
            fileSizeMB = size;
        }

        // 2. Validate file extension matches type
        if (!validateExtension(name, type)) {
            std::cout << "⚠️ Warning: Extension for '" << name << "' doesn't typically match type '" << type << "'." << std::endl;
        }

        fileName = name;

        auto now = std::chrono::system_clock::now();
        creationDate = std::format("{:%Y-%m-%d %H:%M:%S}", now);        
        totalAssets++;
        std::cout << "✓ Asset created: " << fileName << " (" << fileType << ") | Total assets: " << totalAssets << std::endl;
    }    

    // Copy constructor
    DigitalAsset(const DigitalAsset& other) 
        : fileName(other.fileName + "_copy"), fileType(other.fileType), 
          fileSizeMB(other.fileSizeMB), creationDate(other.creationDate), isActive(other.isActive) {        
        totalAssets++;
        std::cout << "✓ Asset copied: " << fileName << " from " << other.fileName 
                  << " | Total assets: " << totalAssets << std::endl;
    }    

    // Destructor
    ~DigitalAsset() {
        totalAssets--;
        std::cout << "✗ Asset destroyed: " << fileName << " | Remaining assets: " << totalAssets << std::endl;
    }    

    // Member functions
    void displayInfo() const {
        std::cout << "Asset: " << fileName << " [" << fileType << "] - " 
                  << fileSizeMB << "MB - Created: " << creationDate 
                  << " - Status: " << (isActive ? "Active" : "Archived") << std::endl;
    }    

    void archive() {
        isActive = false;
        std::cout << "Asset " << fileName << " has been archived." << std::endl;
    }    

    static int getTotalAssets() {
        return totalAssets;
    }
};

// Initialize static member
int DigitalAsset::totalAssets = 0;

int main() {
    std::cout << "=== Digital Asset Management System ===" << std::endl;
    std::cout << "Initial total assets: " << DigitalAsset::getTotalAssets() << std::endl << std::endl;    

    // 1. Test default constructor
    std::cout << "1. Creating default asset:" << std::endl;
    DigitalAsset defaultAsset;
    defaultAsset.displayInfo();
    std::cout << std::endl;    

    // 2. Test parameterized constructor (including validation tests)
    std::cout << "2. Creating specific assets (testing validation):" << std::endl;
    DigitalAsset logo("company_logo.png", "image", 2.5);
    DigitalAsset badSizeAsset("corrupt_file.tmp", "document", -45.2); // Triggers negative size check
    std::cout << std::endl;    

    // 3. Test copy constructor and demonstrate lifecycle block scope
    std::cout << "3. Testing copy constructor:" << std::endl;
    {
        DigitalAsset logoCopy = logo;  // Copy constructor called
        logoCopy.displayInfo();
        logoCopy.archive();        
        std::cout << "--- logoCopy going out of scope ---" << std::endl;
    } // logoCopy destructor called here automatically (LIFO order)   

    // 4. Test vector/array of objects to see multiple constructor/destructor calls
    std::cout << "\n4. Testing vector/array of assets in a local scope:" << std::endl;
    {
        std::vector<DigitalAsset> assetBatch;
        assetBatch.emplace_back("report.pdf", "document", 4.1);
        assetBatch.emplace_back("trailer.mp4", "video", 300.0);
        
        std::cout << "--- Batch size: " << assetBatch.size() << " ---" << std::endl;
    } // Entire vector goes out of scope here, destroying batch items in reverse order!

    std::cout << "\n5. Final status check:" << std::endl;
    std::cout << "Total assets remaining: " << DigitalAsset::getTotalAssets() << std::endl;    

    std::cout << "\n=== Program ending - remaining objects will be destroyed ===" << std::endl;
    return 0;
}