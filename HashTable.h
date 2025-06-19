#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <mutex>
using namespace std;
class HashTable {
private:

    unsigned int hash(string key);

public:
    HashTable(int size);
    ~HashTable();

    void insert(string key, int value);
    void processLogFile(const string& filename);
    int size;
    vector<pair<string, int>> data;
    vector<pair<string, int>> getTop10();
    int get(string key);
};

#endif // HASHTABLE_H