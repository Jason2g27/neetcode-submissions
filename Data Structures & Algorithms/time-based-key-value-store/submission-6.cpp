class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> structure;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        structure[key].emplace_back(timestamp, value);
    }
    
string get(string key, int timestamp) {
    auto& cur = structure[key];
    if (cur.empty()) return "";
    int l = 0, r = cur.size() - 1;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;   // round UP since keep-branch writes to l
        if (cur[mid].first <= timestamp) {
            l = mid;        // mid could be the answer; keep it
        } else {
            r = mid - 1;    // mid is definitely too late, ruled out
        }
    }
    return (cur[l].first <= timestamp) ? cur[l].second : "";
}
};
