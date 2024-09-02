class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size();
        // There are different cases like:
        // 1. if array have all positive element so, whole subarray is max product.
        // 2. if array have even negative number so, whole subarray is max product.
        // 3. if array have zero have difrrent position ,
        // so we will considered as partion of array if(sum ==0) then we find agin max product.
        // 4. if array have odd negative so i have find prefix and suffix
        // 5. ex., [2,5,-2,5,6];
        // iter 1 pre = 2 suff = 6  max = 6
        // iter 2 pre = 2*5=10 suff = 6*5=30  max = 30
        // iter 3 pre = 2*5*-2=-20 suff = 6*5*-2=-60  max = 30
        // go on...
        int prefixProduct = 1;
        int siffixProduct = 1;
        int maxPro = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prefixProduct == 0)
                prefixProduct = 1;
            if (siffixProduct == 0)
                siffixProduct = 1;

            prefixProduct = prefixProduct * arr[i];
            siffixProduct = siffixProduct * arr[n - i - 1]; // 5-0-1 == 4
            maxPro = max(maxPro, max(prefixProduct, siffixProduct));
        }
        return maxPro;
    }
};