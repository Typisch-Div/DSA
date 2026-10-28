class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();

        int l = 0;
        int r = nums1.size();
        while (l <= r) {
            int ct1 = l + (r - l) / 2;
            int ct2 = ((n1 + n2 + 1) / 2) - ct1;

            int l1 = ct1 == 0 ? INT_MIN : nums1[ct1 - 1];
            int l2 = ct2 == 0 ? INT_MIN : nums2[ct2 - 1];
            int r1 = ct1 == n1 ? INT_MAX : nums1[ct1];
            int r2 = ct2 == n2 ? INT_MAX : nums2[ct2];
            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            } else if (l1 > r2)
                r = ct1 - 1;
            else
                l = ct1 + 1;
        }
        return 0.0;
    }
};