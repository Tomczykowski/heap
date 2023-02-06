#include <gtest/gtest.h>
#include "k_heap.h"
#include <sstream>


TEST(heapUnitTest, twoAry) {
    k_heap<20, 2, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20");
}

TEST(heapUnitTest, threeAry) {
    k_heap<20, 3, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20");
}

TEST(heapUnitTest, fourAry) {
    k_heap<20, 4, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20");
}

TEST(heapUnitTest, twoAryBackWay) {
    k_heap<20, 2, int> heap;
    for(int i = 20; i > 0; --i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 3, 8, 5, 4, 11, 9, 12, 6, 13, 14, 20, 16, 17, 10, 21, 15, 18, 7, 19");
}

TEST(heapUnitTest, threeAryBackWay) {
    k_heap<20, 3, int> heap;
    for(int i = 20; i > 0; --i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 3, 13, 10, 8, 5, 4, 20, 15, 14, 19, 12, 11, 21, 16, 9, 18, 7, 6, 17");
}

TEST(heapUnitTest, makeHeapConstructor) {
    int k[20] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    auto heap = k_heap<20, 3, int>(k, 20);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 3, 13, 10, 8, 5, 4, 20, 15, 14, 19, 12, 11, 21, 16, 9, 18, 7, 6, 17");
}

TEST(heapUnitTest, fourAryBackWay) {
    k_heap<20, 4, int> heap;
    for(int i = 20; i > 0; --i){
        heap.insert(i+1);
    }
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 14, 10, 6, 3, 21, 17, 16, 15, 20, 13, 12, 11, 19, 9, 8, 7, 18, 5, 4");
}

TEST(heapUnitTest, twoAryRemoveMin) {
    k_heap<20, 2, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    int min = heap.extractMin();
    ASSERT_EQ(1, min);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 4, 3, 8, 5, 6, 7, 16, 9, 10, 11, 12, 13, 14, 15, 20, 17, 18, 19");
}

TEST(heapUnitTest, threeAryRemoveMin) {
    k_heap<20, 3, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    int min = heap.extractMin();
    ASSERT_EQ(1, min);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 5, 3, 4, 14, 6, 7, 8, 9, 10, 11, 12, 13, 20, 15, 16, 17, 18, 19");
}

TEST(heapUnitTest, fourAryRemoveMin) {
    k_heap<20, 4, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+1);
    }
    int min = heap.extractMin();
    ASSERT_EQ(1, min);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 6, 3, 4, 5, 20, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19");
}

TEST(heapUnitTest, twoAryHeapify) {
    k_heap<21, 2, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(2*i);
    }
    heap.insert(5);
    std::string s = heap.toString();
    ASSERT_EQ(s, "0, 2, 4, 6, 5, 10, 12, 14, 16, 8, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 18");
}

TEST(heapUnitTest, threeAryHeapify) {
    k_heap<21, 3 ,int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+2);
    }
    heap.insert(17);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 17");
}

TEST(heapUnitTest, fourAryHeapify) {
    k_heap<20, 4, int> heap;
    for(int i = 0; i < 20; ++i){
        heap.insert(i+2);
    }
    heap.insert(17);
    std::string s = heap.toString();
    ASSERT_EQ(s, "2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 17");
}
