#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>

struct Person {
    std::string name;
    Person* parent;
    std::vector<Person*> children;

    Person(const std::string& n) : name(n), parent(nullptr) {}
};

Person* addChild(Person* parent, const std::string& childName);
void printFamily(Person* person, int level = 0);
bool areSiblings(Person* a, Person* b);
bool areCousins(Person* a, Person* b);
void describeRelationship(Person* a, Person* b);

#endif