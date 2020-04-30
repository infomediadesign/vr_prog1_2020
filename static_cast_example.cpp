#include <iostream>
#include <iomanip>
 
int main()
{
    int x{ 7 };
    int y{ 4 };

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "int / int =>" << x / y << std::endl;
    std::cout << "(float) int / int =>" << (float) (x / y) << std::endl;    
    std::cout << "(float) int / (float) int => " << (float) x / (float) y << std::endl;    
    std::cout << "static_cast<float> / static_cast<float> => " << static_cast<float>(x) / static_cast<float>(y) << std::endl;
}
