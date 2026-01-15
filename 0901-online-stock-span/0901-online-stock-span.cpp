class StockSpanner {
private:
    vector<int> arr;
public:
    StockSpanner() {
    
    }
    
    int next(int price) {
        this->arr.push_back(price);
        int span = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > price) span = 0;
            else span++;
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */