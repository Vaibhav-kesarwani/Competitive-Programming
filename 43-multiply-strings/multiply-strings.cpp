class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0"; // Handle zero case
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0); // Initialize result storage

        // Multiply each digit of num1 with num2
        for(int i = n1 - 1; i >= 0; i--) {
            int carry = 0;
            for(int j = n2 - 1; j >= 0; j--) {
                int tmp = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = tmp % 10; // Store the single-digit result
                carry = tmp / 10;         // Update carry
            }
            res[i] += carry; // Add any remaining carry to the higher place
        }

        // Convert result vector to string
        int idx = 0;
        while(idx < res.size() - 1 && res[idx] == 0) idx++; // Skip leading zeros
        string ans;
        ans.reserve(res.size() - idx);
        for(; idx < res.size(); idx++) {
            ans.push_back(res[idx] + '0'); // Convert each digit to character
        }
        return ans;
    }
};