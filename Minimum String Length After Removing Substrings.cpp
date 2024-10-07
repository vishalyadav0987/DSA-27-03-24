class Solution {
public:
    int minLength(string s) {
        for(int i=0;i<s.length();i++){
            if(s.substr(i,2)=="AB"||s.substr(i,2)=="CD"){
                s.erase(i,2);
                i=-1;
            }
        }
        if(s=="AB"||s=="CD") return 0;
        return s.length();
    }

};