class Solution {
public:
    
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result;
        result.resize(temperatures.size());
        result[temperatures.size() - 1] = 0;
        int max = temperatures[temperatures.size()-1];
        for (int i = temperatures.size() - 2; i >= 0; --i)
        {
            if (temperatures[i] < temperatures[i + 1])
                result[i] = 1;
            else
            {
                if (temperatures[i] < max)
                {
                    int count = 1;
                    for (int j = i+1; j < temperatures.size(); j++,count++)
                    {
                        if (temperatures[j] > temperatures[i])
                        {
                            result[i] = count;
                            break;
                        }
                    }
                }
                else
                {
                    result[i] = 0;
                }
            }
            max = temperatures[i] > max ? temperatures[i] : max;
        }
        return result;
    }
};