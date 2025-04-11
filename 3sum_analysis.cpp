#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <random>  


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;  
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end()); 
                        uniqueTriplets.insert(triplet);
                    }
                }
            }
        }

        vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
        return result;
    }
};

void runTimingTest() {
    vector<int> sizes = {100, 200, 400, 800, 1600, 3200, 4000}; // You can expand up to 8000 or 4000 if runtime allows but it didn't
    srand(time(0)); // Seed for randomness

    Solution sol;

    for (int n : sizes) {
        vector<int> nums;

        int a = rand() % 100 + 1;
        int b = rand() % 100 + 1;
        nums.push_back(-a);
        nums.push_back(-b);
        nums.push_back(a + b);

        while ((int)nums.size() < n) {
            int rand_num = rand() % 2001 - 1000;
            nums.push_back(rand_num);
        }

        shuffle(nums.begin(), nums.end(), default_random_engine(rand()));


        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = sol.threeSum(nums);
        auto end = chrono::high_resolution_clock::now();

        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        // Output results
        cout << "n = " << n << ", time = " << time_ms << " ms" << endl;
    }
}

int main() {
    runTimingTest();
    return 0;
}


