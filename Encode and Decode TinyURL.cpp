class Solution {
public:

    map<string,string>m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string sb="";
        sb+=((char)(int)rand()*100);
        while(m.find(sb)!=m.end()){
           sb+=((char)(int)rand()*100); 
        }
        m[sb]=longUrl;
        return sb;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
