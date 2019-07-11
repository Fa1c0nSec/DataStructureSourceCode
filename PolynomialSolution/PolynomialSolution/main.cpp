//
//  main.cpp
//  PolynomialSolution
//
//  Created by 姜昭宇 on 2019/7/3.
//  Copyright © 2019 姜昭宇. All rights reserved.
//  备注：计算f(x)=1+sigma(i=1->100)x^i/i;

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <sys/time.h>

#define MAXN 100
#define MAXR 1e10


double polynomial_solution_func1(int n, double a[], double x, int CycleTime) {
    double sum = 0;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            double p = (double)1.0;
            for (int i=1; i<=n; i++) {
                p += (double)(pow(x, i) / i);
            }
            sum = p;
        }
    } else {
        polynomial_solution_func1(n, a, x, 1);
    }
    return sum;
}

double polynomial_solution_func2(int n, double a[], double x, int CycleTime) {
    double sum = 0;
    if (CycleTime) {
        for (int c = 1; c <= CycleTime; c++) {
            double p = (double)x/n;
            for (int i = n-1; i > 0; i--) {
                p = (double)(p+1.0/(double)i)*x;
            }
            sum = p;
        }
    } else {
        polynomial_solution_func2(n, a, x, 1);
    }
    return sum;
}

double Function_Timing(int n, double a[], double x, int CycleTime, double (*polynomial_solution)(int, double[], double, int)) {
    double start_time, end_time;
    timeval function_timing;
    gettimeofday(&function_timing, NULL);
    start_time = function_timing.tv_usec;
    // Function Start Here
    double result = polynomial_solution(n,a,x, CycleTime);
    std::cout.setf(std::ios::fixed);
    std::cout << "Solution Result : " << std::setprecision(6) <<  result << std::endl;
    gettimeofday(&function_timing, NULL);
    end_time = function_timing.tv_usec;
    return end_time-start_time;
}

int main(int argc, const char * argv[]) {
    int CycleTime = 0;
    double a[MAXN];
    std::cout << "Please Input CycleTime: ";
    std::cin >> CycleTime;
    for (int i = 0; i < MAXN; i++) {
        a[i] = (double)(1/(i+1));
    }
    double direct_solution_duration = Function_Timing(MAXN, a, (double)1.1, CycleTime, polynomial_solution_func1);
    double qin9shao_solution_duration = Function_Timing(MAXN, a, (double)1.1, CycleTime, polynomial_solution_func2);
    std::cout << "Direct Solution Running for : "  << direct_solution_duration << "." << std::endl;
    std::cout << "QinJiuShao Solution Running for : " << qin9shao_solution_duration << "." << std::endl;
    return EXIT_SUCCESS;
}
