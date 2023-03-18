class BrowserHistory {
public:
    vector<string> urls;
    int index;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        BrowserHistory* obj = this;
        int currentIndex = obj->index;
        if(currentIndex == obj->urls.size()-1){
            obj->urls.push_back(url);
        }
        else{
            obj->urls.insert(obj->urls.begin() + currentIndex+1, url);
            obj->urls.erase(obj->urls.begin()+currentIndex+2, obj->urls.end());            
        }
        obj->index = currentIndex+1;        
    }
    
    string back(int steps) {
        BrowserHistory* obj = this;
        int currentIndex = max(0, obj->index - steps);
        obj->index = currentIndex;
        return obj->urls[currentIndex];        
    }
    
    string forward(int steps) {
        BrowserHistory* obj = this;
        int len = obj->urls.size()-1;
        int currentIndex = min(len, obj->index + steps);
        obj->index = currentIndex;
        return obj->urls[currentIndex];        
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */