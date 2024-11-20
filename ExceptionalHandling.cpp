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
 * @LastEditTime: 2024-11-20 10:52:39
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\ExceptionalHandling.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

// 异常处理示例程序(GBK编码)
#include <iostream>
#include <stdexcept>  
#include <limits>    

using namespace std;

// 函数用于清理输入流
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    bool continueCalculation = true;

    while (continueCalculation) {
        try {
            int a, b;
            cout << "请输入两个整数 a 和 b (a/b): ";
            cin >> a >> b;

            if (cin.fail()) { 
                throw runtime_error("错误: 输入无效，请确保输入是两个整数。");
            }

            if (b == 0) { 
                throw runtime_error("错误: 除数不能为零，请重新输入.");
            }

            double result = static_cast<double>(a) / b; // 进行除法运算
            cout << "结果: " << result << endl;

            cout << "是否继续计算？(y/n): ";
            char response;
            cin >> response;
            continueCalculation = (response == 'y' || response == 'Y');
        } catch (const runtime_error& e) {
            cout << e.what() << " 请确保输入格式正确，例如 '5 2'。\n";
            clearInput();
        } catch (...) {
            cout << "未知错误，请重试。\n";
            clearInput();
        }
    }

    return 0;
}