#include <iostream>
#include <stdexcept> // 用于标准异常类

/**
 * Introduction:
 *
 * 异常处理的本质就是非本地跳转。try语句类似setjmp()，代表异常的发生点；catch子句类似longjmp()，代表异常的返回点。
 */

// 一个简单的函数，执行除法并抛出异常
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        // throw语句类似longjmp()，代表异常的发生点
        throw std::invalid_argument("Denominator cannot be zero"); // 抛出标准异常
    }
    return numerator / denominator;
}

int main() {
    double num, den, result;

    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> den;

    try {
        result = divide(num, den);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) { // 捕获标准异常
        // catch子句类似setjmp()，代表异常的返回点
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) { // 捕获所有其他类型的异常
        std::cerr << "Unknown error occurred" << std::endl;
    }

    return 0;
}
