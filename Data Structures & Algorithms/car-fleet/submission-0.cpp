class Solution {
public:
    float calTime(float target, float pos, float speed) {
        return (target-pos)/speed;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> st;
        int res = 0;

        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](pair<int,int> &a, pair<int,int> &b){
            return a.first < b.first;
        });

        for (int i = 0; i < cars.size(); i++) {
            while(!st.empty() && 
                (calTime(target, cars[i].first, cars[i].second) >= 
                calTime(target, cars[st.top()].first, cars[st.top()].second))
            ) {
                st.pop();
            }

            st.push(i);
        }

        return st.size();    
    }
};
