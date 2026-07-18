class Solution {
public:
    void mergeNums(vector<int>nums1,vector<int>nums2,vector<int>&mergedArray){
        int p1 = 0; int p2 = 0;
        int len1 = nums1.size(); int len2 = nums2.size();

        while(p1<len1 && p2<len2){
            int val1 = nums1[p1];
            int val2 = nums2[p2];
            if(val1<=val2){
                mergedArray.push_back(val1);
                p1++;
            }else{
                mergedArray.push_back(val2);
                p2++;
            }
        }

        if(p1==len1){
            while(p2<len2){
                mergedArray.push_back(nums2[p2]);
                p2++;
            }
        }
        if(p2==len2){
            while(p1<len1){
                mergedArray.push_back(nums1[p1]);
                p1++;
            }
        }
        return;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>mergedArray;
        mergeNums(nums1,nums2,mergedArray);

        int len = mergedArray.size();
        if(len%2==0){
            float n1 = float(mergedArray[len/2]);
            float n2 = float(mergedArray[len/2-1]);
            return float(n1+n2)/float(2);
        }
        return float(mergedArray[len/2]);
    }
};
