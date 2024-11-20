/*** 
 * @Author: Archangel 781446156@qq.com
 * @Date: 2024-11-20 11:32:15
 * @LastEditTime: 2024-11-20 11:48:19
 * @LastEditors: Archangel 781446156@qq.com
 * @Description:  
 * @FilePath: \ClassTestCode\ForEachLoop.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */


#include <iostream>
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    for (int number : numbers) {
        std::cout << number << " ";
    }
    return 0;
}