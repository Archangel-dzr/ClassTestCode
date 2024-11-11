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
 * @Date: 2024-11-11 10:49:54
 * @LastEditTime: 2024-11-11 10:56:17
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 运用多态设计实现两个操作数进行运算的计算机类（加减乘）
 * @FilePath: \ClassTestCode\Polymorphism.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */


#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Computer
{
public:
    int num1, num2;

    void input()
    {
        cout << "输入两个整数: ";
        while (!(cin >> num1 >> num2)) // 添加错误处理机制
        {
            cin.clear(); // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的错误内容
            cout << "无效输入，请重新输入两个整数: ";
        }
    }
};

class Calculator
{
public:
    virtual void calculate() = 0; // 抽象方法合并，简化接口
};

class AddComputer : public Computer, public Calculator
{
public:
    void calculate() override
    {
        input();
        cout << "结果为: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    }
};

class SubComputer : public Computer, public Calculator
{
public:
    void calculate() override
    {
        input();
        cout << "结果为: " << num1 << " - " << num2 << " = " << num1 - num2 << endl; // 修正输出内容
    }
};

class MulComputer : public Computer, public Calculator
{
public:
    void calculate() override
    {
        input();
        cout << "结果为: " << num1 << " * " << num2 << " = " << num1 * num2 << endl; // 修正输出内容
    }
};

int main()
{
    int choice;
    cout << "选择运算方式:\n1. 加法\n2. 减法\n3. 乘法\n请输入你的选择 (1/2/3): ";
    
    while (!(cin >> choice) || (choice < 1 || choice > 3)) // 输入选择的验证
    {
        cin.clear(); // 清除错误标志
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的错误内容
        cout << "无效选择，请输入 1、2 或 3: ";
    }

    Calculator* calculator = nullptr;

    switch (choice)
    {
        case 1:
            calculator = new AddComputer();
            break;
        case 2:
            calculator = new SubComputer();
            break;
        case 3:
            calculator = new MulComputer();
            break;
    }

    if (calculator != nullptr)
    {
        calculator->calculate();
        delete calculator; // 释放动态分配的内存
    }

    return 0;
}
