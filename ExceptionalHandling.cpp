/*** 
 * @ ┌─────────────────────────────────────────────────────────────┐
 * @ │┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐│
 * @ ││Esc│!1 │@2 │#3 │$4 │%5 │^6 │&7 │*8 │(9 │)0 │_- │+= │|\ │`~ ││
 * @ │├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤│
 * @ ││ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{[ │}] │ BS  ││
 * @ │├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤│
 * @ ││ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  ││
 * @ │├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤│
 * @ ││ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│Shift │Fn ││
 * @ │└─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┴───┘│
 * @ │      │Fn │ Alt │         Space         │ Alt │Win│   HHKB   │
 * @ │      └───┴─────┴───────────────────────┴─────┴───┘          │
 * @ └─────────────────────────────────────────────────────────────┘
 * @
 * @Author: Archangel 781446156@qq.com
 * @Date: 2024-11-20 10:44:51
 * @LastEditTime: 2024-11-20 10:48:03
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\ExceptionalHandling.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

// 异常处理示例程序
#include <iostream>
#include <stdexcept>  
#include <limits>    

using namespace std;

int main() {
    int a, b;

    while (true) {
        try {
            cout << "请输入两个整数 a 和 b (a/b): ";
            cin >> a >> b;

            if (cin.fail()) { // 检查输入是否有效
                throw runtime_error("错误: 输入无效，请确保输入是两个整数。");
            }

            if (b == 0) { // 检查除数是否为零
                throw runtime_error("错误: 除数不能为零，请重新输入.");
            }

            double result = static_cast<double>(a) / b; // 进行除法运算
            cout << "结果: " << result << endl;
            break; // 输入有效，退出循环
        } catch (const runtime_error& e) {
            cout << e.what() << endl; // 输出异常信息
            cin.clear(); // 清除错误标志位
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略剩余无效输入
        }
    }

    return 0;
}

