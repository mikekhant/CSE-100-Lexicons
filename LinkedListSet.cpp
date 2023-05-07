#include "Set.h"
/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    return linked.size();
}

void LinkedListSet::insert(string s) {
    if(!find(s)) {
        linked.push_back(s);
    }
    //linked.insert(linked.end(), s);
}

void LinkedListSet::remove(const string & s) {
    linked.remove(s);
}

bool LinkedListSet::find(const string & s) {
    list<string>::iterator it = linked.begin();
    while(it != linked.end()) {
        if(s == *it) {
            return true;
        }
        it++;
    }
    return false;
}
