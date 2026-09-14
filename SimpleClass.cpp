#include <iostream>


class saveFile{
    private:
    std::string fileName;
    int saveFileID;
    public:
    saveFile() : fileName(""), saveFileID(0) {
        std::cout << " Default saveFile created with no file bound. " << std::endl;

    };

    //parameterized constructor
    saveFile(const std::string& name, int id) : fileName(name), saveFileID(id){
        std::cout << "saveFile initilized with a file: "<< fileName << std::endl;
    }

    //3, the destructor that outputs the message
    ~saveFile(){
        std::cout << "saveFile destroyed, file unbound from: " << fileName << std::endl;
    }

}




int main(){

    return 0;
}