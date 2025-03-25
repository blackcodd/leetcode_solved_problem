class Solution {
private:
   
    bool f(int a, int b, int c, int d) {
        return (b <= c || a >= d);  
    }

public:
    bool checkValidCuts(int t, std::vector<std::vector<int>>& rectangles) {
        std::vector<std::vector<int>> x, y;

        for (auto it : rectangles) {
            x.push_back({it[0], it[2]});  
            y.push_back({it[1], it[3]});  
        }

        if (x.empty() || y.empty()) return false;  

        
        std::sort(x.begin(), x.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];  
        });
        std::sort(y.begin(), y.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];  
        });

        int cnt = 0;
        int m = x.size();
        int l = x[0][0], r = x[0][1];

        for (int i = 1; i < m; i++) {
            if (f(x[i][0], x[i][1], l, r)) {  
                cnt++;
            }
            l = std::min(x[i][0], l);
            r = std::max(x[i][1], r);
            if (cnt >= 2) return true;
        }

        cnt = 0;
        int n = y.size();
        l = y[0][0], r = y[0][1];

        for (int i = 1; i < n; i++) {
            if (f(y[i][0], y[i][1], l, r)) {  
                cnt++;
            }
            l = std::min(y[i][0], l);
            r = std::max(y[i][1], r);
            if (cnt >= 2) return true;
        }

        return false;
    }
};