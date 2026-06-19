class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string str : strs){
            encoded_string += to_string(str.size()) + '#';
            encoded_string += str;
        }
        return encoded_string;
    }

vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0; // Use a while loop to manually handle the jumps
        
        while (i < s.size()) {
            int j = i;
            // Find the delimiter
            while (s[j] != '#') {
                j++;
            }
            
            // Read the length (from i up to j)
            int length = stoi(s.substr(i, j - i));
            
            // Move our reading pointer right past the '#'
            i = j + 1;
            
            // FIX: Extract the actual string starting at the corrected 'i'
            decoded_strs.push_back(s.substr(i, length));
            
            // FIX: Jump 'i' forward by the length of the string to find the next length block
            i += length;
        }
        return decoded_strs;
    }
};
