//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
//
//Example 1:
//
//Input: dividend = 10, divisor = 3
//Output: 3
//Explanation: 10/3 = truncate(3.33333..) = 3.
//Example 2:
//
//Input: dividend = 7, divisor = -3
//Output: -2
//Explanation: 7/-3 = truncate(-2.33333..) = -2.
//Note:
//
//Both dividend and divisor will be 32-bit signed integers.
//The divisor will never be 0.
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


//ex. 19/3  --> 3*2^2 + 3*2^1 = 3*(2^2+2^1) = 18, ans=2^2+2^1=6
//找出被除數 = 除數*2的幾次方相加組成, 其乘數為答案

class Solution {
public:
    int divide(int dividend, int divisor) {
        long ldividend = labs(dividend), ldivisor = labs(divisor), res = 0;
        if (ldividend < ldivisor) return 0;
        long t = ldivisor, multiplier = 1;
        // <<x 為位元左旋運算子, 把二進位數往右移x個單位, 在不溢出位數的情況下相當於*2的x次方 
        while (ldividend > (t << 1)) {
            t <<= 1;
            multiplier <<= 1;
        }
        res += multiplier + divide(ldividend - t, ldivisor);
        if ((dividend < 0) ^ (divisor < 0)) res = -res;  // ^ XOR
        return res > INT_MAX ? INT_MAX : res;
    }
};