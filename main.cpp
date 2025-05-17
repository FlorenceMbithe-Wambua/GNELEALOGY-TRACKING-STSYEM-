#include "tree.h"

int main() {
    // Root person
    Person* john = new Person("John");

    // Children of John
    Person* alice = addChild(john, "Alice");
    Person* bob = addChild(john, "Bob");

    // Children of Alice
    Person* charlie = addChild(alice, "Charlie");
    Person* diana = addChild(alice, "Diana");

    // Children of Bob
    Person* edward = addChild(bob, "Edward");
    Person* fiona = addChild(bob, "Fiona");

    std::cout << "Family Tree:\n";
    printFamily(john);

    std::cout << "\nRelationships:\n";
    describeRelationship(alice, bob);      // Siblings
    describeRelationship(alice, charlie);  // Parent-child
    describeRelationship(charlie, edward); // Cousins
    describeRelationship(bob, john);       // Parent-child (reverse)

    return 0;
}
