#include <vector>
#include <iostream>
using namespace std;

class RecentCounter {

private:
    int last_count;
    vector<int> all_pings;
public:
    RecentCounter()
    {
        last_count = 0;
    }

    int ping(int t)
    {
        int interval_down = t - 3000;
        int interval_up = t;
        int cur_count = 1;
        all_pings.push_back(t);

        int n = all_pings.size();
        int p = 0;
        while (p < n && all_pings[p] < interval_down)
        {
            ++p;
            --last_count;
        }
        if (p > 0)
            all_pings.erase(all_pings.begin(), all_pings.begin() + p);
        last_count += cur_count; 
        return last_count;
    }
};

int main() {
    RecentCounter * obj = new RecentCounter();
    std::cout<<obj->ping(1)<<std::endl;
    std::cout << obj->ping(100) << std::endl;
    std::cout << obj->ping(3001) << std::endl;
    std::cout << obj->ping(3002) << std::endl;
    std::cout << obj->ping(3100) << std::endl;
    return 0;
}