struct comp {
 bool operator()(const pair<int, string> &a, const pair<int, string> &b) const 
    { 
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

class FoodRatings {
public:
    map<string, int> r; 
    map<string, set<pair<int, string>, comp>> m;
    map<string, string> c;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0; i<n; i++)
        {
            r[foods[i]]=ratings[i];
            m[cuisines[i]].insert({ratings[i], foods[i]});
            c[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        m[c[food]].erase({r[food], food});
        m[c[food]].insert({newRating, food});
        r[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*--m[cuisine].end()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */