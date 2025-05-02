#include <algorithm>   
#include <array>
#include <chrono>    
#include <cstddef>   
#include <iostream>
#include <numeric>   

const int g_arrayElements{ 100000 };

class Timer
{
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:

    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1);         

    Timer t;

    std::ranges::sort(array);   
    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}