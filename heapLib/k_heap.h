#include <iostream>
#include <string>
#include <sstream>


template<int M, int K, typename Key>
class k_heap {
private:
    int getParentPos(int const& pos);
    int getMinChildPos(int const& pos);
    void heapifyUp(int const& currIndex) noexcept;
    void heapifyDown(int const& currIndex) noexcept;
    int size;
    Key heap[M]{};
public:
    k_heap() noexcept;
    explicit k_heap(const Key heap[], int const& heapSize) noexcept;
    void insert(Key const& n) noexcept;
    Key peak() const noexcept;
    void pop() noexcept;
    int getSize() noexcept;
    std::string print2D() const noexcept;
    std::string toString() const noexcept;

};

template<int M, int K, typename Key>
k_heap<M, K, Key>::k_heap() noexcept {
    size = 0;
}

template<int M, int K, typename Key>
void k_heap<M, K, Key>::insert(Key const& n) noexcept {
    heap[size] = n;
    this->heapifyUp(size);
    ++size;
}

template<int M, int K, typename Key>
std::string k_heap<M, K, Key>::print2D() const noexcept {
    int level = 1, curr = 1;

    std::ostringstream heapStr;
    for(int i = 0; i < size; i++){
        heapStr << heap[i] << ", ";
        if(level == curr){
            heapStr << std::endl;
            curr *= K;
            level = 0; // bo potem odrazu zwiększam level
        }
        level++;
    }
    return heapStr.str();
}

template<int M, int K, typename Key>
void k_heap<M, K, Key>::heapifyUp(int const& currIndex) noexcept {
    if(currIndex == 0){
        return;
    }
    int index = currIndex;
    int parentPos = this->getParentPos(index);
    while(index > 0){
        if(heap[index] < heap[parentPos])
            std::swap(heap[index], heap[parentPos]);
        index = parentPos;
        parentPos = this->getParentPos(index);
    }
}

template<int M, int K, typename Key>
void k_heap<M, K, Key>::heapifyDown(const int &currIndex) noexcept {
    int index = currIndex;
    int minPos = this->getMinChildPos(currIndex);
    while(minPos != index) {
        std::swap(heap[minPos], heap[index]);
        index = minPos;
        minPos = this->getMinChildPos(minPos);
    }
}

template<int M, int K, typename Key>
std::string k_heap<M, K, Key>::toString() const noexcept {
    std::ostringstream heapStr;
    for(int i = 0; i < size-1; i++){
        heapStr << heap[i] << ", ";
    }
    heapStr << heap[size-1];
    return heapStr.str();
}

template<int M, int K, typename Key>
int k_heap<M, K, Key>::getSize() noexcept {
    return size;
}

template<int M, int K, typename Key>
int k_heap<M, K, Key>::getParentPos(const int &pos) {
    return (pos-1)/K;
}

template<int M, int K, typename Key>
int k_heap<M, K, Key>::getMinChildPos(const int &pos) {
    int min = pos;
    for(int i = 0; i < K; ++i){
        if (K * pos + i + 1 < size && heap[K * pos + i + 1] < heap[min])
            min = K * pos + i + 1;
    }
    return min;
}

template<int M, int K, typename Key>
Key k_heap<M, K, Key>::peak() const noexcept {
    return heap[0];
}

template<int M, int K, typename Key>
void k_heap<M, K, Key>::pop() noexcept {
    Key min = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
}

template<int M, int K, typename Key>
k_heap<M, K, Key>::k_heap(const Key heap[], int const& heapSize) noexcept {
    size = 0;
    for(int i = 0; i < heapSize; ++i){
        this->heap[i] = heap[i];
        this->heapifyUp(i);
        ++size;
    }
}
