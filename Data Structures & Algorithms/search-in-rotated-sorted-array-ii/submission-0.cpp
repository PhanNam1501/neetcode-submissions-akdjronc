class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == target) return true;
            if (arr[m] == arr[l] && arr[m] == arr[r]) {
                l++;
                r--;
                continue;
            }

            if (arr[m] > arr[r]) {
                if (arr[m] < target && target > arr[r]) l = m + 1;
                else if (arr[m] > target && target <= arr[r]) l = m + 1;
                else if (arr[m] > target && target > arr[r]) r = m - 1;
            } else {
                if (arr[m] < target && target <= arr[r]) l = m + 1;
                else if (arr[m] > target && target <= arr[r]) r = m - 1;
                else if (arr[m] < target && target > arr[r]) r = m - 1;
            }
        }

        return false;
    }
};