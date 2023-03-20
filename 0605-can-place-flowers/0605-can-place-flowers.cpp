class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < size(flowerbed); ++i) {
            if (flowerbed[i] == 1) continue;
            if ((i == 0 || flowerbed[i - 1] == 0) && (i == size(flowerbed) - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1; --n;
            }
        }
        return n <= 0;
    }
};