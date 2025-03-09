class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto qselect = [&](auto &&self, vector<int> &A, int left, int right, int k) -> int {
            int pivot = rand() % (right - left + 1) + left;
            swap(A[pivot], A[right]);
            int i = left, j = right;
            while (i < j) {
                while (i < j && A[i] >= A[right]) i++;
                while (i < j && A[j] <= A[right]) j--;
                if (i < j) swap(A[i], A[j]);
            }
            swap(A[i], A[right]);
            if (i == k - 1) return A[i];
            if (i < k - 1) return self(self, A, i + 1, right, k);
            return self(self, A, left, i - 1, k);
        };

        int n = nums.size();
        return qselect(qselect, nums, 0, n - 1, k);
    }
};