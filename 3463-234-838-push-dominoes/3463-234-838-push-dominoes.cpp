class Solution {
private:
    string f(int l, int r, char left, char right) {
        string ans = "";
        int len = r - l + 1;

        if (left == right) {
            for (int i = 0; i < len; ++i)
                ans += left;
        } else if (left == 'R' && right == 'L') {
            for (int i = 0; i < len; ++i) {
                if (i < len / 2) ans += 'R';
                else if (len % 2 == 1 && i == len / 2) ans += '.';
                else ans += 'L';
            }
        } else {
            for (int i = 0; i < len; ++i)
                ans += '.';
        }

        return ans;
    }

public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0;
        while (i < n && dominoes[i] == '.') {
            i++;
        }
        if (i >= n) return dominoes;

        string ans = "";
        if (dominoes[i] == 'L') {
            ans.append(i + 1, 'L');
        } else {
            ans.append(i, '.');
            ans += 'R';
        }

        for (int j = i + 1; j < n; j++) {
            if (dominoes[j] != '.') {
                ans += f(i + 1, j - 1, dominoes[i], dominoes[j]);
                ans += dominoes[j];
                i = j;
            }
        }

         if(dominoes[i]=='L'){
            for(int k=i+1;k<n;k++){
                ans+=".";
            }
        }
        else
        for(int k=i+1;k<n;k++){
                ans+="R";
            }
        

        return ans;
    }
};
