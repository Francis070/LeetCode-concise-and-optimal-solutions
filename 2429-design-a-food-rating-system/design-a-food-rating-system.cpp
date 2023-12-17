class FoodRatings {
public:
    unordered_map<string, string> cusfood;
    unordered_map<string, int> foodrat;
    map<string, set<pair<int, string>>> mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i = 0; i < n; i++){
            cusfood[foods[i]] = cuisines[i];
            foodrat[foods[i]] = -1*ratings[i];

            mp[cuisines[i]].insert({-1*ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int rat = foodrat[food];
        mp[cusfood[food]].erase({rat, food});
        mp[cusfood[food]].insert({-1 * newRating, food});
        foodrat[food] = -1 * newRating;
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */