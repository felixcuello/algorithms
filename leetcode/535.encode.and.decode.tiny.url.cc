class Solution {
public:
  map<string, string> dec;
  map<string, long long> enc;
  long long curr;
  
  Solution() {
    curr = 0;
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if(enc.find(longUrl) == enc.end()) {
      curr++;
      enc[longUrl] = curr;
      dec[to_string(curr)] = longUrl;
    }
    return to_string(enc[longUrl]);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    if(dec.find(shortUrl) == dec.end())
      return "";
    return dec[shortUrl];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
