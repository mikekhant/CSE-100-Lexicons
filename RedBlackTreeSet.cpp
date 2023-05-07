#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    if(rbt.find(s) != rbt.end()) {
        rbt.erase(rbt.find(s));
    }
}

bool RedBlackTreeSet::find(const string & s) {
    if(rbt.find(s) != rbt.end()) {
        return true;
    }
    else return false;
}
