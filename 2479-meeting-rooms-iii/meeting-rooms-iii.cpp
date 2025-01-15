class Solution {
public:
#define END first
#define ROOM_IDX second

typedef long long time_t;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(),
            [&](const vector<int> &m1, const vector<int> &m2) {
                return m1[0] < m2[0];
            });
        
        std::vector<int> room_cnt(n, 0);
        std::priority_queue<pair<time_t, int>, std::vector<pair<time_t, int> > > pq;
        std::priority_queue<int, std::vector<int> > free_rooms;
        for (int i = 0; i < n; i++) free_rooms.push(-i);

        for (auto &m : meetings) {
            time_t start = m[0], duration = m[1] - m[0];

            while (!pq.empty() && -pq.top().END <= start) {
                free_rooms.push(pq.top().ROOM_IDX);
                pq.pop();
            }

            int free_room;

            if (free_rooms.empty()) {
                // free up one room
                start = -pq.top().END;
                free_room = -pq.top().ROOM_IDX;
                pq.pop();
            } else {
                free_room = -free_rooms.top();
                free_rooms.pop();
            }

            pq.push({-(start + duration), -free_room});
            ++room_cnt[free_room];
        }

        return std::max_element(room_cnt.begin(), room_cnt.end()) - room_cnt.begin();
    }
};