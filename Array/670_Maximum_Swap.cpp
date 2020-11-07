//Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
//
//Example 1:
//Input: 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: 9973
//Output: 9973
//Explanation: No swap.
//Note:
//The given number is in the range [0, 108]

//Time complexity O(n)
class Solution {
public:
    int maximumSwap(int num) {
        int leftidx = -1, rightidx = -1;
        int maxdigit = -1, maxidx = -1;
        string str = to_string(num);
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] - '0' > maxdigit) {
                maxdigit = str[i] - '0';
                maxidx = i;
                continue;
            }

            if (str[i] - '0' < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }
        if (leftidx == -1) return num;
        swap(str[leftidx], str[rightidx]);
        return stoi(str);
    }
};