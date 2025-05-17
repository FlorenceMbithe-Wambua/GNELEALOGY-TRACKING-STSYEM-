#include "tree.h"

Person* addChild(Person* parent, const std::string& childName) {
    Person* child = new Person(childName);
    child->parent = parent;
    parent->children.push_back(child);
    return child;
}

void printFamily(Person* person, int level) {
    for (int i = 0; i < level; ++i) std::cout << "  ";
    std::cout << person->name << std::endl;

    for (Person* child : person->children) {
        printFamily(child, level + 1);
    }
}

bool areSiblings(Person* a, Person* b) {
    if (!a || !b || a == b) return false;
    return a->parent == b->parent;
}

bool areCousins(Person* a, Person* b) {
    if (!a || !b || !a->parent || !b->parent) return false;
    return a->parent->parent == b->parent->parent && a->parent != b->parent;
}

void describeRelationship(Person* a, Person* b) {
    if (!a || !b) {
        std::cout << "One or both people do not exist." << std::endl;
        return;
    }

    if (a == b) {
        std::cout << a->name << " and " << b->name << " are the same person." << std::endl;
    }
    else if (a->parent == b) {
        std::cout << b->name << " is the parent of " << a->name << std::endl;
    }
    else if (b->parent == a) {
        std::cout << a->name << " is the parent of " << b->name << std::endl;
    }
    else if (areSiblings(a, b)) {
        std::cout << a->name << " and " << b->name << " are siblings." << std::endl;
    }
    else if (areCousins(a, b)) {
        std::cout << a->name << " and " << b->name << " are cousins." << std::endl;
    }
    else {
        std::cout << a->name << " and " << b->name << " have no direct relationship in this tree." << std::endl;
    }
}