#include <iostream>
#include <iomanip>
 
int main()
{
    int x{ 7 };
    int y{ 4 };

    float res = (float) (x / y);
 
    std::cout << "int / int = " << x / y << std::endl;
    std::cout << "int / int = " << (float) (x / y) << std::endl;    
    std::cout << std::fixed << std::setprecision(3) << "(float) int / int = " << res << std::endl;    
    std::cout << "float / float = " << static_cast<float>(x) / static_cast<float>(y) << std::endl;
}
