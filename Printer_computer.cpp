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
 * @Date: 2024-11-08 16:08:23
 * @LastEditTime: 2024-11-08 16:21:25
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\Printer_computer.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

#include <iostream>
#include <cstring>
using namespace std;

class Printer {
public:
    Printer() {
        cout << "构造函数 Printer()" << endl;
        // 打印机初始化
    }
    Printer(const char *deviceName) {
        cout << "打印机名称: " << deviceName << endl;
    }
    ~Printer() {
        cout << "析构函数 ~Printer()" << endl;
    }
    void print(const char *info) {
        cout << "正在打印: " << info << endl;
    }
};

class Computer {
public:
    Printer d; // 打印机对象
    char cpu[30];
    char graphicsCard[30];
    char ramBrand[30];

    // 构造函数
    Computer(const char *name, const char *cpuName, const char *graphicsCardName, const char *ramBrandName) 
        : d("3D-打印机"), // 初始化打印机
          cpu(), graphicsCard(), ramBrand() {
        strcpy(cpu, cpuName);
        strcpy(graphicsCard, graphicsCardName);
        strcpy(ramBrand, ramBrandName);
        cout << "电脑名称: " << name << endl;

    }
    
    ~Computer() {
        cout << "析构函数 ~Computer()" << endl;
    }

    void show() {
        cout << "CPU: " << cpu << endl;
        cout << "显卡: " << graphicsCard << endl;
        cout << "内存条品牌: " << ramBrand << endl;
    }
};

int main() {
    Computer a("Huawei MateBook D15", "Intel i7", "NVIDIA GTX 3060", "Western Digital");
    a.d.print("电脑信息");
    a.show(); // 显示电脑信息
    return 0;
}
