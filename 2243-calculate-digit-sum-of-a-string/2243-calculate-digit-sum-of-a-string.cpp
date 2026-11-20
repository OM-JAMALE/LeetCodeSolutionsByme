class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string temp = "";
            int i = 0;
            while (i < s.size()) {
                int j = i;
                int sum = 0;
                while (j < s.size() && j < i + k) {
                    sum += (s[j] - '0');
                    j++;
                }
                temp += to_string(sum);
                i = j;
            }
            s = temp;
        }
        return s;
    }
};
