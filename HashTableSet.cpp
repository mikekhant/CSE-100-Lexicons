#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    return ht.size();
}

void HashTableSet::insert(string s) {
    ht.insert(s);
}

void HashTableSet::remove(const string & s) {
    if(ht.find(s) != ht.end()) {
        ht.erase(ht.find(s));
    }
}

bool HashTableSet::find(const string & s) {
    if(ht.find(s) != ht.end()) {
        return true;
    }
    else return false;
}
