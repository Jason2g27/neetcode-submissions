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
        int l = 0, r = cur.size() - 1;
        string result = "";
        while(l <= r){
            int mid = (l+r)/2;
            if(cur[mid].first <= timestamp){
                result = cur[mid].second;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return result;
    }
};
