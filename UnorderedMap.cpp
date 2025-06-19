#include "UnorderedMap.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

UnorderedMap::~UnorderedMap() {
    hashtable.clear();
}

size_t UnorderedMap::size() {
    lock_guard<mutex> lock(mtx);
    return hashtable.size();
}

void UnorderedMap::insert(const string& key, int value) {
    lock_guard<mutex> lock(mtx);
    hashtable[key] += value;
}

int UnorderedMap::get(const string& key) {
    lock_guard<mutex> lock(mtx);
    auto it = hashtable.find(key);
    if (it != hashtable.end()) {
        return it->second;
    }
    return -1;
}

void UnorderedMap::processLogFile(const string& filename) {
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


vector<pair<string, int>> UnorderedMap::getTop10() {
    vector<pair<string, int>> result;
    for (const auto& pair : hashtable) {
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