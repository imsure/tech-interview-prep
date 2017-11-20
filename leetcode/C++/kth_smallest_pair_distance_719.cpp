#include "common.hpp"

// Brute force, Memory Limit Exceeded

class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    vector<int> dists;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        dists.push_back(abs(nums[i] - nums[j]));
      }
    }

    sort(dists.begin(), dists.end());
    return dists[k-1];
  }
};


// A better brute force, Time Limit Exceeded
// This is approach performs well for large input with a lot of repeated values,
// but worse with input with lots of distinct values and distance between max and min
// values are very large.

class Solution2 {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    auto num2count_ptr = new unordered_map<int, int> ();
    auto& num2count = *num2count_ptr;

    int min_num = numeric_limits<int>::max();
    int max_num = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
      num2count[nums[i]]++;
      min_num = min(nums[i], min_num);
      max_num = max(nums[i], max_num);
    }

    cout << "min num: " << min_num << ", max num: " << max_num << endl;

    int rank = 0;
    for (auto& kv : num2count) { // count pairs with distance of 0
      int same_count = kv.second;
      rank += same_count * (same_count-1) / 2;
      if (rank >= k) return 0;
    }

    for (int dist = 1; dist <= max_num - min_num; ++dist) {
      for (int num = min_num; num <= max_num; ++num) {
        if (num2count.find(num) == num2count.end()) continue;
        if (num2count.find(num + dist) == num2count.end()) continue;
        int c1 = num2count[num];
        int c2 = num2count[num + dist];
        rank += c1 * c2;
        if (rank >= k) return dist;
      }
    }

    return -1;
  }
};


class Solution3 {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int min_num = nums[0], max_num = nums[n-1];
    unordered_map<int, int> same_count;

    int i = 0;
    while (i < n) {
      int num = nums[i];
      int j = i;
      while (i + 1 < n && nums[i+1] == nums[i]) ++i;
      same_count[num] = i - j + 1;
      ++i;
    }

    int rank = 0;
    for (auto& kv : same_count) { // count pairs with distance of 0
      int count = kv.second;
      rank += count * (count-1) / 2;
      if (rank >= k) return 0;
    }

    for (int dist = 1; dist <= max_num - min_num; ++dist) {
      int i = 0;
      while (i < n) {
        if (nums[i] + dist > max_num) break;
        int c1 = same_count[nums[i]];
        auto up = std::upper_bound(nums.begin(), nums.end(), nums[i] + dist - 1);
        if (up != nums.end() && *up == nums[i] + dist) {
          int c2 = same_count[*up];
          rank += c1 * c2;
          if (rank >= k) return dist;
        }
        i += c1;
      }
    }

    return -1;
  }
};


class Solution4 {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int max_dist = nums[n-1] - nums[0];
    int lo_dist = 0, hi_dist = max_dist;

    while (lo_dist < hi_dist) {
      // cout << "lo: " << lo_dist << ", hi: " << hi_dist << endl;
      int mid_dist = (hi_dist + lo_dist) / 2;
      // find out how many pairs whose distance is <= mid_dist
      int i = 0, pair_count = 0;
      while (i < n - 1) {
        auto up = std::upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + mid_dist);
        pair_count += std::distance(nums.begin() + i + 1, up);
        ++i;
      }
      // cout << pair_count << endl;
      if (pair_count >= k) hi_dist = mid_dist - 1;
      else lo_dist = mid_dist + 1;
    }

    return lo_dist;
  }
};


int main()
{
   vector<int> nums {1,3,1};
  // vector<int> nums {221238,427286,829789,601893,358469,46342,598804,666075,725560,842824,261672,391778,964604,53621,533121,755551,807344,597092,774256,63098,948199,579547,3196,909877,95910,965027,411050,532303,362036,248585,389213,926908,139846,642116,527660,735487,787738,978186,545605,595011,705832,788214,407493,856161,947455,114342,459338,744156,179687,348085,724897,694016,170072,797188,194673,987604,748362,124575,101059,588749,515935,846183,783882,752572,984672,299643,474986,42219,914392,699717,862520,146910,156305,269341,268361,19009,292092,663200,349590,296229,194323,667426,751544,139621,339144,979848,895018,432652,524214,697568,946806,378351,536203,315145,567426,212742,871720,419529,340374,869276,865407,603396,609939,616585,590359,21031,813301,154998,592050,679203,535025,94441,193548,618901,170094,996902,981372,129574,272754,762181,746001,525671,398300,912121,682153,5904,473065,729188,727720,183096,851216,848578,908443,532556,369537,800932,713898,919800,350740,851358,734571,674194,624352,862486,254700,127824,705571,61267,335237,377466,124085,542898,263565,867445,570415,909045,947063,167541,113129,897668,402701,287017,87703,233079,67973,689618,433223,164387,627387,472038,97781,148808,263578,28836,226968,476149,778104,404041,300170,319580,355689,713032,92394,739268,614862,716425,260673,449432,607545,987946,243679,147202,111207,598535,676528,107358,372982,190321,217552,501122}; // 293377
  int k = 10000;
  Solution4 sol;
  cout << sol.smallestDistancePair(nums, 1) << endl;
  // cout << sol.smallestDistancePair(nums, k) << endl;
}
