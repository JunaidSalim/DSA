// Kadane's Algorithm is used for finding maximum subarray

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}