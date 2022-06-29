class Solution {
public:
    // struct cmp{
    //   bool operator()(const string &a, const string &b){
    //       {return a.length()<b.length();}
    //   }  
    // };
    string arrangeWords(string text) {
        vector<string>v;
        text[0] = tolower(text[0]);
        stringstream s(text);
        string word;
        while(s>>word){
            v.push_back(word);
        }
        stable_sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return (a.size() < b.size());
        });
        v[0][0] = toupper(v[0][0]);
        string ans="";
        for(auto it:v){
            ans.append(it);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};