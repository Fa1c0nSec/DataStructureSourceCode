//
//  main.cpp
//  PrintN
//
//  Created by 姜昭宇 on 2019/7/3.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  备注：浙江大学MOOC数据结构-实现PrintN，循环显示从1到N。

#include <iostream>
#include <cstdlib>
#include <ctime>

clock_t start_time, end_time;

void PrintN(int N, int CycleTime) {
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            int i = 0;
            for (i=1; i<=N; i++) {
                std::cout << i << std::endl;
                //std::fflush(stdout);
            }
        }
    } else {
        PrintN(N, 1);
    }
}

void PrintN_Recursion(int N, int CycleTime) {
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            if (N) {
                std:: cout << N << std::endl;
                //std::fflush(stdout);
                PrintN_Recursion(N-1, 1);
            }
        }
    } else {
        PrintN_Recursion(N, 1);
    }
    
}

double Function_Timing(int N, int CycleTime, void (*PrintN)(int, int)) {
    start_time = clock();
    PrintN(N, CycleTime);
    end_time = clock();
    double duration = (double)(end_time-start_time)/CLOCKS_PER_SEC;
    return duration;
}

int main(int argc, const char * argv[]) {
    int N, CycleTime;
    std::cout << "Please Input N: ";
    std::cin >> N;
    std::cout << "Please Input CycleTime: ";
    std::cin >> CycleTime;
    double func_without_recursion = Function_Timing(N, CycleTime, PrintN);
    double func_with_recursion = Function_Timing(N, CycleTime, PrintN_Recursion);
    std::cout << "PrintN Running Time: " << func_without_recursion << std::endl;
    std::cout << "PrintN With Recursion Running Time: " << func_with_recursion << std::endl;
    return EXIT_SUCCESS;
}

