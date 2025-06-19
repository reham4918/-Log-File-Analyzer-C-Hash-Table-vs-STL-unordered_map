#include "UnorderedMap.h"
#include <chrono>
#include <iostream>
#include "HashTable.h"

using namespace std;
int main() {

    HashTable ht(20000);
    auto start = chrono::high_resolution_clock::now();
    ht.processLogFile("../access_log.txt");
    auto end = chrono::high_resolution_clock::now();

    cout << "Top 10 most visited web pages: " << endl;
    for (const auto& pair : ht.getTop10()) {
        cout << pair.first << " # of total visits: " << pair.second << endl;
    }
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Total Elapsed Time : " << duration.count()/1000.0 << " seconds" << endl;


    UnorderedMap hashtable;

    auto start2 = chrono::high_resolution_clock::now();
    hashtable.processLogFile("../access_log.txt");
    auto end2 = chrono::high_resolution_clock::now();

    cout << "Top 10 most visited web pages: " << endl;
    for (const auto& pair : hashtable.getTop10()) {
        cout << pair.first << " # of total visits: " << pair.second << endl;}
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    cout << "Total Elapsed Time : " << duration2.count()/1000.0<< " seconds" << endl;
    return 0;

}







