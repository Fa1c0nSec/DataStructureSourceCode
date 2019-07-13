//
//  main.cpp
//  PTA-编程题-01-复杂度1-最大子列和问题
//
//  Created by 姜昭宇 on 2019/7/12.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  题目：给定K个整数组成的序列{ N​1​​ , N​2​​ , ..., N​K​​ }，
//  “连续子列”被定义为{ Ni, N​i+1, ...,Nj}，
//  其中1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。
//  例如给定序列{ -2, 11, -4, 13, -5, -2 }，
//  其连续子列{ 11, -4, 13}有最大的和20。
//  现要求你编写程序，计算给定整数序列的最大子列和。
//  本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

//  数据1：与样例等价，测试基本正确性；
//  数据2：10^2个随机整数；
//  数据3：10^3个随机整数；
//  数据4：10^4个随机整数；
//  数据5：10^5个随机整数；
//  输入格式:
//  输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
//  输出格式:
//  在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
//  输入样例:
//  6
//  -2 11 -4 13 -5 -2
//
//  输出样例:
//  20
//  解答：仍然使用MaximumSubsequenceSum中的算法


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#define FATAL_INTERRUPTION -127
#define ElemType int
#define MAXK 100000

int MaxSubSequenceSum(ElemType A[], int N) {
    int CurrentSum, MaxSum, i;
    CurrentSum = MaxSum = 0;
    for (i = 0; i < N; i++) {
        CurrentSum += A[i];
        if (CurrentSum > MaxSum) {
            MaxSum = CurrentSum;
        }
        else if(CurrentSum < 0) {
            CurrentSum = 0;
        }
    }
    return MaxSum;
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
    int ans = MaxSubSequenceSum(A, K);
    std::cout << ans << std::endl;
}
