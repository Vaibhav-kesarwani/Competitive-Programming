class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        std::string result;
        int symbolCount[26] = {0};
        int indices[26] = {0};
        
        for (char c : s) { // Count total number of symbols in s
            symbolCount[c - 'a']++;
        }


        for (int i = 1; i < 26; i++) { // Setup indices
            if (symbolCount[i] > 0)
                indices[i] = i;
            else
                indices[i] = indices[i - 1];
        }

        int i = 25;
        while (true) { // Loop for every letter 'z'->'a'
            if (symbolCount[i] <= 0) { // Ran out of symbols
                i = indices[i - 1]; // Pick the next present llc
            }

            if (i == 0) { // i points to 'a', so we can no longer take llc from the left
                result.append(std::min(repeatLimit, symbolCount[0]), 'a'); // Add whatever is left
                return result;
            }

            while (symbolCount[i] > repeatLimit) { // Handle the case when we have more symbols than repeatLimit
                result.append(repeatLimit, 'a' + i);  // Add the character
                symbolCount[i] -= repeatLimit;

                if (symbolCount[indices[i - 1]] <= 0) { // If next llc is empty
                    if (indices[i - 1] <= 0) // If indices[i-1] points to 'a' => can't take the next llc
                        return result;
                    indices[i - 1] = indices[indices[i - 1] - 1]; // Move to the next lexicographically largest
                }

                result.push_back('a' + indices[i - 1]); // Add "filler" character
                symbolCount[indices[i - 1]]--;
            }

            result.append(symbolCount[i], 'a' + i); // Add remaining characters
            symbolCount[i] = 0;
        }
    }
};