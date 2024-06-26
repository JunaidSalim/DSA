// Unstable Algorithm With Time Complexity O(N)
// Works only for Array with Positive Elements and Elements should be in range(1,n) where n is size of array

void CycleSort(vector<int> nums)
{
    int n = nums.size();
    int i = 0;

    while (i < n)
    {
        int value = nums[i];
        if (value > 0 && value <= n && nums[value - 1] != value)
        {
            swap(nums[i], nums[value - 1]);
        }
        else
        {
            i++;
        }
    }
}