#include <bits/stdc++.h>
using namespace std;

map<int, int> keys;
int msize;
list<int> order;
map<int, typename list<int>::iterator> pointers;

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int val);
};

LRUCache::LRUCache(int capacity) {
    keys = map<int, int>();
    order = list<int>();
    pointers = map<int, typename list<int>::iterator>();
    msize = capacity;
}

int LRUCache::get(int key) {
    auto it = keys.find(key);
    if(it == keys.end()) {
        return -1;
    }
    else {
        auto old = pointers[key];
        pointers.erase(key);
        order.erase(old);
        order.push_front(key);
        pointers[key] = order.begin();
        return it->second;
    }
}

void LRUCache::set(int key, int value) {
    auto it = keys.find(key);
    if(it != keys.end()) {
        keys[key] = value;
        auto old = pointers[key];
        pointers.erase(key);
        order.erase(old);
        order.push_front(key);
        pointers[key] = order.begin();
    }
    else {
        if(keys.size() < msize) {
            keys[key] = value;
            order.push_front(key);
            pointers[key] = order.begin();
        }
        else {
            int to_rem = order.back();
            order.erase(--order.end());
            pointers.erase(to_rem);
            keys.erase(to_rem);
            keys[key] = value;
            order.push_front(key);
            pointers[key] = order.begin();
        }
    }
}

int main(void) {
    return 0;
}
