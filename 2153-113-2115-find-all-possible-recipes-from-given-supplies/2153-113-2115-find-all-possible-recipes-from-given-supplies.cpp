
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree; 
        unordered_map<string, vector<string>> graph; 
        
        
        for (const string& recipe : recipes) {
            inDegree[recipe] = 0;
        }
        
       
        for (int i = 0; i < recipes.size(); i++) {
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]); // Edge from ingredient -> recipe
                inDegree[recipes[i]]++; // Increase in-degree of the recipe
            }
        }
        
      
        queue<string> q;
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;
        
       
        while (!q.empty()) {
            string current = q.front();
            q.pop();

            
            if (find(recipes.begin(), recipes.end(), current) != recipes.end()) {
                result.push_back(current);
            }
            
          
            for (const string& dependentRecipe : graph[current]) {
                inDegree[dependentRecipe]--; 
                if (inDegree[dependentRecipe] == 0) { 
                    q.push(dependentRecipe);
                    available.insert(dependentRecipe);
                }
            }
        }
        
        return result;
    }
};
