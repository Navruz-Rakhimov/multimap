//
// Created by navruz on 12/27/2020.
//

#ifndef MULTIMAP_HASHNODE_H
#define MULTIMAP_HASHNODE_H
// Временно
#define TABLE_SIZE 100

#include <iostream>

template <typename K>
struct KeyHash {
    unsigned long operator()(const K &key) const {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};


template <typename K, typename V>
class HashNode {
private:
    K key;
    V value;
    HashNode *next;
    int pos;
public:
    int getPos() const {
        return pos;
    }

    void setPos(int pos) {
        HashNode::pos = pos;
    }

public:
    HashNode(const K &key, const V &value) : key(key), value(value), next(NULL) {}

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        HashNode::value = value;
    }

    void setNext(HashNode *next) {
        HashNode::next = next;
    }

    HashNode *getNext() const {
        return next;
    }
};

#endif //MULTIMAP_HASHNODE_H
