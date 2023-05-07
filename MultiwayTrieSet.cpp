#include "Set.h"
#include <iostream>

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    numElements = 0;
    root = new Node();
}

void deletetree(MultiwayTrieSet::Node* n) {
    if(n != nullptr) {
        if(!n->children.empty()) {
            for (const auto & [ key, value ] : n->children) {
               deletetree(value); 
            }
        }
    }
    delete(n);
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    numElements = 0;
    deletetree(root);
    root = nullptr;
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    return numElements;
}

void insertnew(string s, int i, MultiwayTrieSet::Node* curr) {
    char currLetter = s.at(i);
    while(i < s.length()-1) {
        MultiwayTrieSet::Node* node = new MultiwayTrieSet::Node();
        pair<char,MultiwayTrieSet::Node*> element (s.at(i), node);
        curr->children.insert(element);
        curr = curr->children.at(currLetter);
        i++;
        currLetter = s.at(i);
    }

    MultiwayTrieSet::Node* node = new MultiwayTrieSet::Node();
   // curr->children.emplace(s.at(i), node);
    pair<char,MultiwayTrieSet::Node*> element (s.at(i), node);
    curr->children.insert(element);
    curr = curr->children.at(currLetter);
    curr->isWord = true;
}

void MultiwayTrieSet::insert(string s) {
    char currLetter;
    int i=0;
    Node* curr = root;
    currLetter = s.at(i);

    while(i < s.length()-1) {
        if(curr->children.find(currLetter) != curr->children.end()) {
            curr = curr->children.at(currLetter);
            i++;
            currLetter = s.at(i);
        }
        else {
            numElements = numElements + s.length() - i;
            insertnew(s, i, curr);
        }
    }

    if(curr->children.find(currLetter) != curr->children.end()) {
        curr->isWord = true;
    }
    else {
        numElements++;
        insertnew(s, i, curr);
    }
    
}

bool MultiwayTrieSet::find(const string & s) {
    char currLetter;
    int i=0;
    Node* curr = root;
    currLetter = s.at(i);

    while(i < s.length()-1) {
        if(curr->children.find(currLetter) != curr->children.end()) {
            curr = curr->children.at(currLetter);
            i++;
            currLetter = s.at(i);
        }
        else {
            return false;
        }
    }
    if(curr->isWord) {
        return true;
    }
    else {
        return false;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    if(!find(s)) {
        return;
    }
    char currLetter;
    int i=0;
    Node* curr = root;
    currLetter = s.at(i);

    while(i < s.length()-1) {
        if(curr->children.find(currLetter) != curr->children.end()) {
            curr = curr->children.at(currLetter);
            i++;
            currLetter = s.at(i);
        }
        else {
            return;
        }
    }
    if(curr->children.find(currLetter) != curr->children.end()) {
        curr->isWord = false;
    }
    else {
        return;
    }

}


