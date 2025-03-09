class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto partition = [&](vector<int>& A, int left, int right) {
            int pivot = rand() % (right - left + 1) + left;
            swap(A[pivot], A[right]);
            int i = left;
            for (int j = left; j < right; j++) {
                if (A[j] < A[right]) {
                    swap(A[i], A[j]);
                    i++;
                }
            }
            swap(A[i], A[right]);
            return i;
        };

        auto quicksort = [&](auto &&self, vector<int>& A, int left, int right) {
            if (left >= right) return;
            int p = partition(A, left, right);
            self(self, A, left, p - 1);
            self(self, A, p + 1, right);
        };

        quicksort(quicksort, nums, 0, (int)nums.size() - 1);
        return nums;
    }
};