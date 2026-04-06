class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maximumNumOfFruits = 1;

        unordered_map<int, int> hashMap;
        int uniqueFruitTaken = 0;
        int i = 0;
        int lastPtr = 0;

        while(i < n) {
            if(!hashMap.count(fruits[i])) {
                if(uniqueFruitTaken >= 2) {
                    while(uniqueFruitTaken >= 2 && lastPtr <= i) {
                        hashMap[fruits[lastPtr]]--;
                        if(hashMap[fruits[lastPtr]] == 0) {
                            hashMap.erase(fruits[lastPtr]);
                            uniqueFruitTaken--;
                        }
                        lastPtr++;
                    }
                }
                uniqueFruitTaken++;
            }

            maximumNumOfFruits = max(maximumNumOfFruits, i - lastPtr + 1);
            hashMap[fruits[i]]++;
            i++;
        }

        return maximumNumOfFruits;
    }
};