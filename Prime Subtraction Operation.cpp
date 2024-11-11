class Solution
{
public:
    bool isPrimeArray[1001];
    void sieveOfErosthesis()
    {
        // filled array all value is prime at the start
        fill(isPrimeArray, isPrimeArray + 1000, true);

        // Set 0 and 1 as not prime numbers
        isPrimeArray[0] = isPrimeArray[1] = false;

        for (int p = 2; p * p <= 1000; ++p)
        {
            if (isPrimeArray[p])
            {
                // Mark all multiples of p as false
                for (int i = p * p; i <= 1000; i += p)
                {
                    isPrimeArray[i] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int> &nums)
    {

        sieveOfErosthesis();

        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        { // o(n)
            // nums[i] < nums[i+1]; continue;
            // nums[5] < nums[5+1] n=7;

            if (nums[i] < nums[i + 1])
            {
                continue;
            }

            // nums[i] >= nums[i+1]
            // jub tak decrease karunga uske chote prime se

            bool reduced = false;
            for (int p = 2; p < nums[i] && !reduced; p++)
            { // o(max(nums[i]))
                if (isPrimeArray[p])
                {
                    int temp = nums[i] - p;
                    if (temp < nums[i + 1])
                    {
                        nums[i] = temp;
                        reduced = true;
                    }
                }
            }

            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};