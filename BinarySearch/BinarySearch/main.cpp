//
//  main.cpp
//  BinarySearch
//
//  Created by 姜昭宇 on 2019/7/4.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  备注：二分查找具体实现 (顺序数组)

#include <iostream>
#include <cstdlib>

#define FATAL_INTERRUPTION -127
#define ElemType int
#define ARRAY_MAXLENGTH 10

template <class T>
int getArrayLength(T& array) {
    return (sizeof(array) / sizeof(ElemType));
}

int BinarySearch(ElemType arr[], ElemType arrlength, ElemType key) {
    int startPosition = 0;
    int endPosition = arrlength - 1;
    while (startPosition <= endPosition) {
        int mid = (startPosition + endPosition) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            endPosition = mid - 1;
        } else if (key > arr[mid]) {
            startPosition = mid + 1;
        }
    }
    return FATAL_INTERRUPTION;
}

int main(int argc, const char * argv[]) {
    ElemType arr[ARRAY_MAXLENGTH], key;
    std::cout << "Please Input Array Data (" << ARRAY_MAXLENGTH <<"): ";
    for (int i = 0; i < ARRAY_MAXLENGTH; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Please Input Search Key : ";
    std::cin >> key;
    int keyPosition = BinarySearch(arr, getArrayLength(arr), key);
    std::cout << "Key Position : " << keyPosition+1 << std::endl;
    return EXIT_SUCCESS;
}
