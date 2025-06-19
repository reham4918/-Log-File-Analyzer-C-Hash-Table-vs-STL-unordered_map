#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
using namespace std;
HashTable::HashTable(int size) {
    this->size = size;
    data.resize(size);
}

HashTable::~HashTable() {
    data.clear();
}

unsigned int HashTable::hash(string key) {
    unsigned int hash = 8581;
    int c;

    for (int i = 0; i < key.length(); i++) {
        c = key[i];
        hash = ((hash << 3) + hash) + c;
    }

    return hash % size;
}

void HashTable::processLogFile(const string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Find the position of "GET " in the line
            size_t pos = line.find("GET ");

            if (pos != string::npos) {
                // Extract the URL by skipping "GET " and finding the position of the next space
                size_t start = pos + 4; // Length of "GET "
                size_t end = line.find(' ', start);

                if (end != string::npos) {
                    string url = line.substr(start, end - start);
                    // Insert the URL into the hash table
                    insert(url, 1);
                }
            }
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

void HashTable::insert(string key, int value) {
    int index = hash(key);
    while (data[index].first != "" && data[index].first != key) {
        index = (index + 1) % size;
    }
    if(data[index].first == ""){
        data[index].first=key;
        data[index].second=1;}
    else {
        data[index].second += 1;}

}

int HashTable::get(string key) {
    int index = hash(key);
    while (data[index].first != "" && data[index].first != key) {
        index = (index + 1) % size;
    }
    if (data[index].first == "") {
        return -1;
    }
    return data[index].second;}

vector<pair<string, int>> HashTable::getTop10() {
    vector<pair<string, int>> result;
    for (const auto& pair : data) {
        result.push_back(pair);
    }

    sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    if (result.size() > 10) {
        result.resize(10);
    }

    return result;
}