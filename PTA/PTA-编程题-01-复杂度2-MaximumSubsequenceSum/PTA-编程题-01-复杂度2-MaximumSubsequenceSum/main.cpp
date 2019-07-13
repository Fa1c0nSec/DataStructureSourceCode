//
//  main.cpp
//  PTA-编程题-01-复杂度1-最大子列和问题
//
//  Created by 姜昭宇 on 2019/7/12.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  题目：Given a sequence of K integers { N​1​​ , N​2​​ , ..., N​K}. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj}
//  where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements.
//  For example, given sequence { -2, 11, -4, 13, -5, -2 },
//  its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.
//  Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.
//  Input Specification:
//  Each input file contains one test case.
//  Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.
//  Output Specification:
//  For each test case, output in one line the largest sum,
//  together with the first and the last numbers of the maximum subsequence.
//  The numbers must be separated by one space, but there must be no extra space at the end of a line.
//  In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case).
//  If all the K numbers are negative, then its maximum sum is defined to be 0,
//  and you are supposed to output the first and the last numbers of the whole sequence.
//  解答：仍然使用MaximumSubsequenceSum中的算法，增加输出子列的首尾。

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#define FATAL_INTERRUPTION -127
#define ElemType int
#define MAXK 100000

void MaxSubSequenceSum(ElemType A[], int N) {
    int CurrentSum = 0, MaxSum = -1, i, head = 0, tail = 0, index = 0;
    CurrentSum = MaxSum = 0;
    for (i = 0; i < N; i++) {
        CurrentSum += A[i];
        if (CurrentSum > MaxSum) {
            MaxSum = CurrentSum;
            head = index;
            tail = i;
        }
        if(CurrentSum < 0) {
            CurrentSum = 0;
            index=i+1;
        }
    }
    if (MaxSum < 0) {
        std::cout << "0 " << A[0] << " " << A[N-1] << std::endl;
    } else {
        std::cout << MaxSum << " " << A[head] << " " << A[tail] << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    int K = 0;
    if (K < MAXK) {
        std::cin >> K;
    }
    int A[K];
    for (int i=0; i < K; i++) {
        std::cin >> A[i];
    }
    MaxSubSequenceSum(A, K);
    return EXIT_SUCCESS;
}
