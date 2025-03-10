class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;  
        int left = 0;  
        int maxLength = 0;  

        for (int right = 0; right < s.length(); ++right) {  
            // If the character is already in the set, move the left pointer  
            while (charSet.find(s[right]) != charSet.end()) {  
                charSet.erase(s[left]);  
                left++;  
            }  
            // Add the current character to the set  
            charSet.insert(s[right]);  
            // Update the maximum length  
            maxLength = std::max(maxLength, right - left + 1);  
        }  

        return maxLength; 
    }
};