#include "k_heap.h"
#include "benchmark.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <cstdlib>

class Key
{
private:
    unsigned long value = 0UL;
    static bool performDelay;
    void delay() const
    {
        if (performDelay)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
public:
    Key() = default;

    Key(Key const&) = default;

    Key(unsigned long v) : value(v)
    {
    }

    unsigned long getKey() const
    {
        return value;
    }

    static void delayOn()
    {
        performDelay = true;
    }

    static void delayOff()
    {
        performDelay = false;
    }


    bool operator==(Key const& v) const
    {
        delay();
        return value == v.value;
    }

    bool operator!=(Key const& v) const
    {
        delay();
        return value != v.value;
    }

    bool operator<(Key const& v) const
    {
        delay();
        return value < v.value;
    }
    bool operator<=(Key const& v) const
    {
        delay();
        return value <= v.value;
    }
    bool operator>(Key const& v) const
    {
        delay();
        return value > v.value;
    }
    bool operator>=(Key const& v) const
    {
        delay();
        return value >= v.value;
    }

};

bool Key::performDelay = false;

std::ostream& operator << (std::ostream& stream, Key const& key)
{
    stream << key.getKey();
    return stream;
}


int main(){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator((unsigned long)seed);

    unsigned long long sum = 0;
    unsigned long long sumUs = 0;
    const int size = 10000;
    Key::delayOff();
    k_heap<size, 4, int> heap4;
    k_heap<size, 2, int> heap2;
    k_heap<size, 3, int> heap3;
    Key::delayOn();
    for(int i = 0; i < 10; i++) {
        while (heap4.getSize() < size - 1) {
            unsigned long n = generator();
            Key key(n);
            Benchmark<std::chrono::nanoseconds> a;
            heap4.insert(n);
            sum += a.elapsed();
        }
        //usuwanie
        while (heap4.getSize() >= -1) {
            Benchmark<std::chrono::nanoseconds> b;
            heap4.extractMin();
            sumUs += b.elapsed();
        }
    }

//    Key::delayOff();
//    unsigned long long sumUs = 0;
//    Key::delayOn();
//    while(heap.getSize() >= -1) {
//        for (int i = 0; i < 10; ++i) {
//            unsigned long n = generator();
//            Key key(n);
//
//            Benchmark<std::chrono::nanoseconds> b;
//            heap.extractMin();
//            sumUs += b.elapsed();
//        }
//    }
    std::cout << sum/size/10 <<std::endl;
    std::cout << sumUs/size/10 <<std::endl;
    return 0;
}
