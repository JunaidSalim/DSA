// Boyer Moore;s Algo for all elements in array of length n
// with greater than n/3 frequency

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count1 = 0, count2 = 0;
    int element1 = 0, element2 = 0;

    for (const auto &num : nums)
    {
        if (num == element1)
        {
            count1++;
        }
        else if (num == element2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            element1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            element2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for (const auto &num : nums)
    {
        if (num == element1)
            count1++;
        else if (num == element2)
            count2++;
    }

    vector<int> result;
    if (count1 > n / 3)
        result.push_back(element1);
    if (count2 > n / 3)
        result.push_back(element2);

    return result;
}
