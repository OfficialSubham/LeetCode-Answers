#include<bits/stdc++.h>

class StockSpanner {
private:
    stack<pair<int, int>> hashStack;
public:
    StockSpanner() {
    
    }
    
    int next(int price) {
        if(this->hashStack.empty() || this->hashStack.top().first > price) {
            this->hashStack.push({price, 1});
            return 1;
        }
        else {
            int span = 1;
            while(!this->hashStack.empty() && this->hashStack.top().first <= price) {
                span += this->hashStack.top().second;
                this->hashStack.pop();
            }
            this->hashStack.push({price, span});
            return span;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */