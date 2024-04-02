#include <iostream>
#include "maths.h"


int main()
{
    for(double i = 1.0; i < 10.0; i++ ){
        double x = f1(i);
        double y = f2(i);
        std::cout << i << " 的平方：" << x << std::endl;
        std::cout << i << " 的立方：" << y << std::endl;
    }

    return 0;
}
