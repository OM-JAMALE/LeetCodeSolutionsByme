class Solution {
public:
    bool checkString(string s) {
        int flag = 0;
        for(char ch : s){
            if((ch == 'a')&&(flag == 1)){
                return false;
            }else if(ch == 'b'){
                flag = 1;
            }
        }
        return true;
    }
};