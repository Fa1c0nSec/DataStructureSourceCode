//
//  main.cpp
//  MaximumSubsequenceSum
//
//  Created by 姜昭宇 on 2019/7/4.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  备注：最大子列和算法

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

#define FATAL_INTERRUPTION -127
#define ElemType int
#define MAXN 8

int MaxSubSequenceSum1(ElemType A[] , int N, int CycleTime) {
    int CurrentSum, MaxSum = 0;
    int i,j,k;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            for (i = 0; i < N; i++) {
                for (j = i; j < N; j++) {
                    CurrentSum = 0;
                    for (k = i;k<=j; k++) {
                        CurrentSum += A[k];
                    }
                    if (CurrentSum > MaxSum) {
                        MaxSum = CurrentSum;
                    }
                }
            }
        }
    } else {
        MaxSubSequenceSum1(A, N, 1);
    }
    return MaxSum;
}

int MaxSubSequenceSum2(ElemType A[], int N, int CycleTime) {
    int CurrentSum, MaxSum = 0;
    int i,j;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            for (i = 0; i < N; i++) {
                CurrentSum = 0;
                for (j = i; j < N; j++) {
                    CurrentSum += A[j];
                    if (CurrentSum > MaxSum) {
                        MaxSum = CurrentSum;
                    }
                }
            }
        }
    } else {
        MaxSubSequenceSum2(A, N, 1);
    }
    return MaxSum;
}

int getMaxValueWithThreeParams(int A, int B, int C) {
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int MaxSubSequenceSum3Adapter(int List[], int left, int right) {
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int center, i;
    
    if (left == right) {
        if (List[left] > 0) {
            return List[left];
        } else {
            return 0;
        }
    }
    
    center = (left + right) / 2;
    MaxLeftSum = MaxSubSequenceSum3Adapter(List, left, center);
    MaxRightSum = MaxSubSequenceSum3Adapter(List, center+1, right);
    
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--) {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }
    
    return getMaxValueWithThreeParams(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubSequenceSum3(ElemType A[], int N, int CycleTime) {
    int ans = 0;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            ans = MaxSubSequenceSum3Adapter(A, 0, N-1);
        }
    } else {
        MaxSubSequenceSum3(A, N, 1);
    }
    return ans;
    
}

int MaxSubSequenceSum4(ElemType A[], int N, int CycleTime) {
    int CurrentSum, MaxSum, i;
    CurrentSum = MaxSum = 0;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
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
        }
    } else {
        MaxSubSequenceSum4(A, N, 1);
    }
    return MaxSum;
}

double Function_Timing(ElemType A[], int N, int CycleTime, int (*MaxSubSequenceSum)(ElemType[], int, int)) {
    double start_time, end_time;
    timeval function_timing;
    gettimeofday(&function_timing, NULL);
    start_time = function_timing.tv_usec;
    //Function Start Here
    double result = MaxSubSequenceSum(A, N, CycleTime);
    std::cout.setf(std::ios::fixed);
    std::cout << "Maximum Subsequence Sum Result: " << std::setprecision(6) << result << std::endl;
    gettimeofday(&function_timing, NULL);
    end_time = function_timing.tv_usec;
    return end_time-start_time;
}

int FunctionSelector() {
    int function_select = 0;
    std::cout << "Function List: " << std::endl;
    std::cout << "\t1.Triple Cycle Function. O(N^3)" << std::endl;
    std::cout << "\t2.Double Cycle Function. O(N^2)" << std::endl;
    std::cout << "\t3.Divide Conquer Function. O(N*logN)" << std::endl;
    std::cout << "\t4.Online Processing Function. O(N)" << std::endl;
    std::cout << "\t5.All Function Running." << std::endl;
    std::cin >> function_select;
    return function_select;
}

int main(int argc, const char * argv[]) {
    int CycleTime = 0;
    ElemType Sequence[MAXN];
    double timing_result = 0.0;
    double timing_func1 = 0.0, timing_func2 = 0.0, timing_func3 = 0.0, timing_func4 = 0.0;
    std::cout << "Please Input Function CycleTime: ";
    std::cin >> CycleTime;
    std::cout << "Please Input Serial Sequence (" << MAXN << "): ";
    for (int i = 0; i < MAXN; i++) {
        std::cin >> Sequence[i];
    }
    int function = FunctionSelector();
    switch (function) {
        case 1:
            timing_result = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum1);
            break;
        case 2:
            timing_result = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum2);
            break;
        case 3:
            timing_result = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum3);
            break;
        case 4:
            timing_result = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum4);
            break;
        case 5:
            timing_func1 = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum1);
            timing_func2 = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum2);
            timing_func3 = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum3);
            timing_func4 = Function_Timing(Sequence, MAXN, CycleTime, MaxSubSequenceSum4);
            break;
        default:
            std::cout << "Function Serial Fatal Error." << std::endl;
            return FATAL_INTERRUPTION;
    }
    if (function <= 4) {
        std::cout << "Function " << function << " Running for :" << timing_result << std::endl;
    } else if (function == 5) {
        std::cout << "Triple Cycle Function Running for :" << timing_func1 << std::endl;
        std::cout << "Double Cycle Function Running for :" << timing_func2 << std::endl;
        std::cout << "Divide Conquer Function Running for :" << timing_func3 << std::endl;
        std::cout << "Online Processing Function Running for :" << timing_func4 << std::endl;
    } else {
        std::cout << "Function Serial Fatal Error." << std::endl;
        return FATAL_INTERRUPTION;
    }
    return EXIT_SUCCESS;
}
