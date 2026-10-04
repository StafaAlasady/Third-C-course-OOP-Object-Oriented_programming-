#include <iostream>
#include <string>
using namespace std;

// Character class for the adventure game
class Character {
public:
    string name;
    int level;
    int experience;
    int health;

    // Constructor
    Character(string n, int l = 1, int exp = 0, int hp = 100) 
        : name(n), level(l), experience(exp), health(hp) {}

    // Display character information
    void displayInfo() const {
        cout << "Character: " << name << " | Level: " << level 
             << " | Experience: " << experience << " | Health: " << health << endl;
    }
};

// Node structure for linked list (inventory management)
struct Node {
    string itemName;  // The data
    Node* next;       // The pointer to the next node
    
    // Constructor for easier node creation
    Node(string item, Node* nextNode = nullptr) : itemName(item), next(nextNode) {}
};

// ========================================
// STEP 1: Function Parameter Passing with References
// ========================================

// TODO: Implement levelUp function
// This function should take a Character reference and:
// - Add 100 to experience
// - Increment level by 1
// - Display a level up message
    void levelUp(Character& charRef) {
    charRef.experience += 100;
    charRef.level++;
    std::cout << charRef.name << "You just leveled up! Level is now: " << charRef.level << std::endl;
}

// TODO: Implement healCharacter function
// This function should take a Character reference and healing amount:
// - Add healing amount to health
// - Ensure health doesn't exceed a maximum (e.g., 100)
// - Display healing message
void healCharacter(Character& charRef, int healAmount) {
    // TODO: Implement function body
    charRef.health += healAmount;
    if(charRef.health > 2000){
        charRef.health = 2000; //Capping it at 2000 max health
    }
    std::cout << charRef.name << " was healed by: " << healAmount <<"! Current health: " << charRef.health << std::endl;
}

// ========================================
// STEP 2: Data Structure Navigation with Pointers
// ========================================

// TODO: Implement addItem function
// This function should add an item to the front of the linked list
// Parameters: Node*& head (reference to pointer), const string& item
void addItem(Node*& head, const std::string& item) {
    Node* newNode = new Node (item, head);
    // TODO: Create new node with the item
    // TODO: Set the new node's next pointer to current head
    // TODO: Update head to point to new node
    head = newNode;
    // Hint: Node* newNode = new Node(item, head);
    std::cout <<"Added item to inventory: " << item << std::endl;
}

// TODO: Implement displayInventory function
// This function should traverse and display all items in the linked list
void displayInventory(const Node* head) {
    // TODO: Check if inventory is empty
    if (head == nullptr){
        std::cout << " inventory is empty!" << std::endl;
        return;
    }
    // TODO: Traverse the linked list using a pointer
    const Node* current = head;
    // TODO: Display each item name
    std::cout << " === Current inventoy ===" << std::endl;
    // Hint: Use a while loop with current->next
    while(current!= nullptr){
        std::cout <<"- " << current->itemName << std::endl;
        current = current->next;
    }
}

// TODO: Implement removeItem function
// This function should remove the first occurrence of an item from the list
// Return true if item was found and removed, false otherwise
bool removeItem(Node*& head, const std::string& targetItem) {
    // TODO: Handle empty list case
    if (head == nullptr)
    {
        return false;
    }
    
    // TODO: Handle case where first item matches
    if (head->itemName == targetItem)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // TODO: Traverse list to find item
    Node* current = head;
    while (current->next != nullptr && current->next->itemName != targetItem)
    {
        current = current->next;
    }
    
    // TODO: Update pointers to remove node
    // TODO: Delete the removed node
    // TODO: Return appropriate boolean value
    if (current->next !=nullptr)
    {
        Node* temp = current->next;
        current->next = temp->next; // A reaches around b to grab c
        delete temp; // and this deletes b safely!
        return true;
    }
    
    return false;
}

// ========================================
// STEP 3: Efficient Memory Usage - Dynamic Allocation
// ========================================

// TODO: Implement createScoreArray function
// This function should dynamically allocate an array of integers
// Parameters: int initialSize
// Return: pointer to the allocated array
int* createScoreArray(int initialSize) {
       if(initialSize <= 0){
        return nullptr;
    }
    // TODO: Allocate array using new
    int* scores = new int[initialSize];
    // TODO: Initialize all elements to 0
    for (int i = 0; i < initialSize; ++i){
        scores[i] = 0;
    }
    // TODO: Return pointer to array
    return scores;
    // Hint: int* scores = new int[initialSize];
}

// TODO: Implement displayScores function
// This function should display all scores in the array
// Parameters: int* scores, int size
void displayScores(const int* scores, int size) {
    // TODO: Check if scores pointer is valid
    if (scores == nullptr)
    {
        std::cout << "Scores array is null!" << std::endl;
        return;
    }
    
    // TODO: Loop through array and display each score
    for(int i = 0; i < size; ++i){
        std::cout << " Score ["<< i <<"]: " << scores [i] << endl;
    }
}

// TODO: Implement updateScore function
// This function should safely update a score at given index
// Parameters: int* scores, int size, int index, int newScore
// Return: true if update successful, false if invalid index
bool updateScore(int* scores, int size, int index, int newScore) {
    // TODO: Validate parameters (scores not null, valid index)
    if (scores == nullptr || index < 0 || index >= size){
        return false; // out of bounds or invalid
    }
    // TODO: Update score at index
    // TODO: Return success/failure status
    scores[index] = newScore;
    return true;
}

// ========================================
// STEP 4: Safety and Error Prevention
// ========================================

// TODO: Implement safeDeleteArray function
// This function should safely delete a dynamically allocated array
void safeDeleteArray(int*& scores) {
    // TODO: Check if pointer is not null
    if(scores!= nullptr){
        // TODO: Delete the array using delete[]
        delete[] scores;
        // TODO: Set pointer to nullptr (passed by reference)
        scores = nullptr;
    }


}

// TODO: Implement clearInventory function
// This function should safely delete all nodes in the linked list
void clearInventory(Node*& head) {
    // TODO: Create temporary pointer
    // TODO: Loop through list
    while (head != nullptr){
        Node* temp = head;
        head = head ->next;
        delete temp;
    }
    // TODO: Store current node in temp
    // TODO: Move to next node
    // TODO: Delete temp node
    // TODO: Set head to nullptr when done
}

// ========================================
// MAIN FUNCTION - Testing Ground
// ========================================

int main() {
    cout << "=== Adventure Game Memory Management System ===" << endl;
    
    // Test Step 1: Function Parameter Passing with References
    cout << "\n--- Step 1: Character Management with References ---" << endl;
    Character Mustafa = {"Slayer", 10, 350, 1550};
    Mustafa.displayInfo();
    
    // TODO: Test levelUp function
    cout << "Leveling up character..." << endl;
    levelUp(Mustafa);
    Mustafa.displayInfo();
    
    // TODO: Test healCharacter function
    cout << "Healing character..." << endl;
     healCharacter(Mustafa, 150);
    Mustafa.displayInfo();
    
    // Test Step 2: Inventory Management with Linked List
    cout << "\n--- Step 2: Inventory Management with Pointers ---" << endl;
    Node* inventory = nullptr;  // Empty inventory initially
    
    // TODO: Test addItem function
    cout << "Adding items to inventory..." << endl;
    addItem(inventory, "Health Potion");
    addItem(inventory, "Magic Sword");
    addItem(inventory, "Shield");
    
    // TODO: Test displayInventory function
    cout << "Current inventory:" << endl;
    displayInventory(inventory);
    
    // TODO: Test removeItem function
    cout << "Removing 'Health Potion' from inventory..." << endl;
    if (removeItem(inventory, "Health Potion")) {
     cout << "Item removed successfully!" << endl;
    } else {
     cout << "Item not found!" << endl;
    }
    displayInventory(inventory);
    
    // Test Step 3: Dynamic Memory for Game Stats
    cout << "\n--- Step 3: Dynamic Score Management ---" << endl;
    const int numScores = 5;
    
    // TODO: Test createScoreArray function
    int* gameScores = createScoreArray(numScores);
    
    // TODO: Test updateScore function
    updateScore(gameScores, numScores, 0, 1500);
    updateScore(gameScores, numScores, 2, 2300);
    updateScore(gameScores, numScores, 4, 1800);
    
    // TODO: Test displayScores function
    cout << "Game scores:" << endl;
    displayScores(gameScores, numScores);
    
    // Test Step 4: Cleanup and Safety
    cout << "\n--- Step 4: Safe Memory Cleanup ---" << endl;
    
    // TODO: Test safeDeleteArray function
    safeDeleteArray(gameScores);
    
    // TODO: Test clearInventory function
    clearInventory(inventory);
    
    cout << "All memory cleaned up safely!" << endl;
    cout << "\n=== Adventure Game Demo Complete ===" << endl;
    
    return 0;
}

/*
IMPLEMENTATION CHECKLIST:
□ Step 1: levelUp function implemented
□ Step 1: healCharacter function implemented
□ Step 2: addItem function implemented
□ Step 2: displayInventory function implemented  
□ Step 2: removeItem function implemented
□ Step 3: createScoreArray function implemented
□ Step 3: displayScores function implemented
□ Step 3: updateScore function implemented
□ Step 4: safeDeleteArray function implemented
□ Step 4: clearInventory function implemented
□ All test calls in main() uncommented
□ Program compiles and runs without errors
□ No memory leaks (all new matched with delete)

SAFETY REMINDERS:
- Always check pointers for nullptr before dereferencing
- Match every 'new' with 'delete', every 'new[]' with 'delete[]'
- Set pointers to nullptr after deletion
- Use references for function parameters to avoid unnecessary copying
- Validate array indices before access
*/

