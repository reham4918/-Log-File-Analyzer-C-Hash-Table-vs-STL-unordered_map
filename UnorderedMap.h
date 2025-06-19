#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>

using namespace std;
class UnorderedMap {
private:
    unordered_map<string, int> hashtable;
    mutex mtx;

public:
    UnorderedMap() = default;
    ~UnorderedMap();

    size_t size();
    void insert(const string& key, int value);
    int get(const string& key);
    void processLogFile(const string& filename);
    vector<pair<string, int>> getTop10();
};