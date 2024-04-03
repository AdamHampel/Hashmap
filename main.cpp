#include "HashMap.hpp"
#include <iostream>

int main() {
    // Create a HashMap object
    HashMap myMap;

    // Add key-value pairs to the HashMap
    myMap.add("apple", "red");
    myMap.add("banana", "yellow");
    myMap.add("grape", "purple");

    // Print the value associated with a key
    std::cout << "Color of apple: " << myMap.value("apple") << std::endl;
    std::cout << "Color of banana: " << myMap.value("banana") << std::endl;
    std::cout << "Color of grape: " << myMap.value("grape") << std::endl;

    // Remove a key-value pair from the HashMap
    myMap.remove("banana");

    // Check if a key exists in the HashMap
    if (myMap.contains("banana")) {
        std::cout << "Banana is in the HashMap" << std::endl;
    } else {
        std::cout << "Banana is not in the HashMap" << std::endl;
    }

    // Print the size and load factor of the HashMap
    std::cout << "Size of HashMap: " << myMap.size() << std::endl;
    std::cout << "Load factor of HashMap: " << myMap.loadFactor() << std::endl;

    // Print the HashMap
    std::cout << "HashMap contents:" << std::endl;
    myMap.printSelf();

    return 0;
}

