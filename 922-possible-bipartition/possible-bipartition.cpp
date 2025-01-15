class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        enum COLOR_CONSTANT {
            GREEN = -1,   // -1
            NOT_COLORDED, // 0
            BLUE          // 1
        };

        if (n == 1 || dislikes.size() == 0) {

            // Quick response for simple cases
            return true;
        }

        // each person maintains a list of dislike
        unordered_map<int, vector<int>> dislikeTable;

        // key: personID
        // value: color of person
        unordered_map<int, int> colorTable;

        // -----------------------

        std::function<bool(int, int)> helper;
        helper = [&](int personID, int color) -> bool {
            // Draw personID as color
            colorTable[personID] = color;

            // Draw theOther, with opposite color, in dislike table of current
            // personID
            for (const int& theOther : dislikeTable[personID]) {

                if (colorTable[theOther] == color) {
                    // the_other has the same color of current person_id
                    // Reject due to breaking the relationship of dislike
                    return false;
                }

                if (colorTable[theOther] == NOT_COLORDED &&
                    (!helper(theOther, -color))) {
                    // Other people can not be colored with two different
                    // colors. Therefore, it is impossible to keep dis-like
                    // relationship with bipartition.
                    return false;
                }
            }

            return true;
        };

        // -----------------------

        // update dislike table
        for (const auto& relation : dislikes) {

            int p1 = relation[0], p2 = relation[1];

            dislikeTable[p1].emplace_back(p2);
            dislikeTable[p2].emplace_back(p1);
        }

        // Try to draw dislike pair with different color in DFS
        for (int personID = 1; personID <= n; personID++) {

            if (colorTable[personID] == NOT_COLORDED &&
                (!helper(personID, BLUE))) {
                // Other people can not be colored with two different colors.
                // Therefore, it is impossible to keep dis-like relationship
                // with bipartition.
                return false;
            }
        }

        return true;
    }
};