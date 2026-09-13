#include <iostream>


class ResourceHandler {
    private:
    std::string resourcePath;
    int resourceID;
    bool isLoaded;


    public:
    ResourceHandler() : resourcePath(""), resourceID(0), isLoaded(false){
        std::cout << " Default ResourceHandler created with no file bound. " << std::endl;
    };

    //parameterized constructor
    ResourceHandler(const std::string& path, int id) 
    : resourcePath(path),resourceID(id), isLoaded(false){

        if (path.empty()) {
            isLoaded = false;
            std::cout << " Error: invalid path, Resource  failed to load. please check path again. " << std::endl;
        } else {
            isLoaded = true;
            std::cout << " resource loaded successfully, Bound to: " << resourcePath << std::endl;
        }

    }

    //Copy constructor
    ResourceHandler(const ResourceHandler& other)
    : resourcePath(other.resourcePath), resourceID(other.resourceID), isLoaded(other.isLoaded){
        std::cout << "_copy constructor called, resource bound to: " << resourcePath << std::endl;
    }

    //Destructor
    ~ResourceHandler(){
        if (isLoaded){
            std::cout << " ResourceHandler destroyed, resource unbound from: " << resourcePath << std::endl;
        } else{
            std::cout << " ResourceHandler destroyed, resource was never bound." << std::endl;
        }
    }

        // Member functions
    void displayInfo() const {
        std::cout << std::endl;
    }    


};

int main(){
   std::cout << "=== Resource Handler ===" << std::endl;

        // 1. Test default constructor
    std::cout << "1. Creating default asset:" << std::endl;
    ResourceHandler DefaultHandler;

    std::cout << "Creating specific asset for testing: " << std::endl;
    ResourceHandler rh1("image.png", 1);

    // Test parameterized constructor (invalid path - empty string)
    ResourceHandler invalidHandler("", 2);
    std::cout << std::endl;

    // 2, Test parameterized constructor
    std::cout << "2. Creating specific assets (testing validation):" << std::endl;
    ResourceHandler("image.png", 1);
    std::cout << std::endl;

    std::cout << "3. Testing resource copying:" << std::endl;
    {
        ResourceHandler copiedHandler = rh1; // Copy constructor
        std::cout << "\n--- Leaving inner scope ---" << std::endl;
    } // Destructor called here



    std::cout << "\n=== Program ending - cleanup phase ===" << std::endl;

    return 0;
}