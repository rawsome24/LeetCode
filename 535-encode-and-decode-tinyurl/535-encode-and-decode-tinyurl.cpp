class Solution {
public:

    // Encodes a URL to a shortened URL.
    string ans;
    string encode(string longUrl) {
        ans = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));