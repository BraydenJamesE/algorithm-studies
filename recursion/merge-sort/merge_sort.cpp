#include <iostream>
#include <vector>

template <typename T>
std::vector<T> merge(
    const std::vector<T>& v1, 
    const std::vector<T>& v2
) {
    std::size_t v1Size = v1.size();
    std::size_t v2Size = v2.size();
    std::size_t l = 0;
    std::size_t r = 0;

    std::vector<T> sortedVec;
    sortedVec.reserve(v1Size + v2Size);
    
    for (int i = 0; i < v1Size + v2Size; i++) {
        if (l >= v1Size) 
            sortedVec.push_back(v2[r++]); 
        else if (r >= v2Size) 
            sortedVec.push_back(v1[l++]); 
        else if (v1[l] <= v2[r]) 
            sortedVec.push_back(v1[l++]);
        else if (v2[r] < v1[l])
            sortedVec.push_back(v2[r++]);
    }
    return sortedVec;
}

template <typename T>
std::vector<T> mergeSort(const std::vector<T>& vec) {
    std::size_t vecSize = vec.size();
    if (vecSize > 1) {
        std::size_t midIdx = vec.size() / 2;
        std::vector<T> v1(vec.begin(), vec.begin() + midIdx); 
        std::vector<T> v2(vec.begin() + midIdx, vec.end());
        
        std::vector<T> sortedV1 = mergeSort(v1);
        std::vector<T> sortedV2 = mergeSort(v2);
        std::vector<T> sortedVec = merge(sortedV1, sortedV2);

        return sortedVec;
    }
    else
        return vec;
}

int main() {
    std::vector<int> unsortedVec = {10, 2, 30, 4, 5, 6, -1, 40, -2 , 1, 1000, -50, 7};
    std::vector<int> sortedVec = mergeSort(unsortedVec);

    std::cout << "Original Unsorted List: {";
    for (const auto& item: unsortedVec)
        std::cout << item << ",";
    std::cout << "}" << std::endl;

    std::cout << "Merge Sorted List: {";
    for (const auto& item: sortedVec)
        std::cout << item << ",";
    std::cout << "}" << std::endl;

    return 0;
}