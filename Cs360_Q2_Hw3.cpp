#include <iostream>
#include <vector>

class IntegerSet {
private:
    std::vector<bool> elements; // Vector of bools to represent the set

public:
    // Default constructor that initializes the set to be empty
    IntegerSet() : elements(101, false) {} // 101 elements for 0 through 100

    // Constructor that initializes the set with an array of integers
    IntegerSet(const int arr[], int size) : elements(101, false) {
        for (int i = 0; i < size; i++) {
            if (arr[i] >= 0 && arr[i] <= 100) {
                elements[arr[i]] = true;
            }
        }
    }

    // Insert an element into the set
    void insertElement(int element) {
        if (element >= 0 && element <= 100) {
            elements[element] = true;
        }
    }

    // Delete an element from the set
    void deleteElement(int element) {
        if (element >= 0 && element <= 100) {
            elements[element] = false;
        }
    }

    // Union of two sets
    IntegerSet unionOfSets(const IntegerSet& otherSet) const {
        IntegerSet unionSet;
        for (int i = 0; i < 101; i++) {
            unionSet.elements[i] = this->elements[i] || otherSet.elements[i];
        }
        return unionSet;
    }

    // Intersection of two sets
    IntegerSet intersectionOfSets(const IntegerSet& otherSet) const {
        IntegerSet intersectionSet;
        for (int i = 0; i < 101; i++) {
            intersectionSet.elements[i] = this->elements[i] && otherSet.elements[i];
        }
        return intersectionSet;
    }

    // Print the set
    void printSet() const {
        bool isEmpty = true;
        for (int i = 0; i < 101; i++) {
            if (elements[i]) {
                std::cout << i << " ";
                isEmpty = false;
            }
        }
        if (isEmpty) {
            std::cout << "---"; // Print --- for an empty set
        }
        std::cout << std::endl;
    }

    // Check if two sets are equal
    bool isEqualTo(const IntegerSet& otherSet) const {
        for (int i = 0; i < 101; i++) {
            if (this->elements[i] != otherSet.elements[i]) {
                return false;
            }
        }
        return true;
    }
};

// Main function to test the IntegerSet class
int main() {
    // Instantiate IntegerSet objects and test the functionality
    IntegerSet set1;
    IntegerSet set2;
    int arr[] = {1, 3, 5, 7, 99};
    IntegerSet set3(arr, 5);

    set1.insertElement(0);
    set1.insertElement(50);
    set2.insertElement(100);
    set3.deleteElement(7);

    std::cout << "Set 1: ";
    set1.printSet();

    std::cout << "Set 2: ";
    set2.printSet();

    std::cout << "Set 3: ";
    set3.printSet();

    IntegerSet unionSet = set1.unionOfSets(set3);
    std::cout << "Union of Set 1 and Set 3: ";
    unionSet.printSet();

    IntegerSet intersectionSet = set1.intersectionOfSets(set3);
    std::cout << "Intersection of Set 1 and Set 3: ";
    intersectionSet.printSet();

    std::cout << "Set 1 is equal to Set 2: " << (set1.isEqualTo(set2) ? "Yes" : "No") << std::endl;
    std::cout << "Set 1 is equal to Set 3: " << (set1.isEqualTo(set3) ? "Yes" : "No") << std::endl;

    return 0;
}
