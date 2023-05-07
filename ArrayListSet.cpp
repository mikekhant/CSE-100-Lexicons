#include "Set.h"
int count = 0;

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    return arr.size();
}

void ArrayListSet::insert(string s) {
    arr.insert(arr.end(), s);
    count++;
}

void ArrayListSet::remove(const string & s) {
    int i=0;
    while(arr.begin() + i != arr.end()) {
        if(s == arr[i]) {
            arr.erase(arr.begin() + i);
            count--;
            return;
        }
        i++;
    }
}

bool ArrayListSet::find(const string & s) {
    int i=0;
    while(arr.begin() + i != arr.end()) {
        if(s == arr[i]) {
            return true;
        }
        i++;
    }
    return false;
}
