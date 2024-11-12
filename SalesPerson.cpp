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
 * @Date: 2024-11-12 11:19:30
 * @LastEditTime: 2024-11-12 11:26:23
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: static的使用示例
 * @FilePath: \ClassTestCode\SalesPerson.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */


#include <iostream>
using namespace std;

class SalesPerson 
{
    private:
        static int total; // 静态成员变量，记录销售总量
        static int remain; // 静态成员变量，记录剩余库存
        static const int INITIAL_STOCK = 100000; // 初始库存量

    public:
        SalesPerson() // 构造函数
        {
            total += INITIAL_STOCK; // 销售总量增加初始库存量
            remain += INITIAL_STOCK; // 剩余库存增加初始库存量
        }

        ~SalesPerson() // 析构函数
        {
            total -= INITIAL_STOCK; // 销售总量减少初始库存量
            remain -= INITIAL_STOCK; // 剩余库存减少初始库存量
        }

        static void recruit() // 静态成员函数，招聘销售员
        {
            cout << "招聘销售员3人" << endl;
        }

        static void sale(int sales1, int sales2, int sales3) // 静态成员函数，销售产品
        {
            // 计算总销售量
            int totalSales = sales1 + sales2 + sales3;
            if (totalSales > remain) // 检查是否有足够库存销售
            {
                cerr << "错误：销售数量超过剩余库存！" << endl;
                return; // 终止销售
            }
            remain -= totalSales; // 更新剩余库存
            cout << "销售员1号销售" << sales1 << "台" << endl;
            cout << "销售员2号销售" << sales2 << "台" << endl;
            cout << "销售员3号销售" << sales3 << "台" << endl;
        }

        static void show() // 静态成员函数，显示剩余库存
        {
            cout << "剩余库存：" << remain << "台" << endl;
        }
};

int SalesPerson::total = 0; // 静态成员变量，记录销售总量
int SalesPerson::remain = 0; // 静态成员变量，记录剩余库存

int main() 
{
    SalesPerson::recruit(); // 招聘销售员
    SalesPerson salesperson; // 创建销售员实例以初始化库存
    SalesPerson::sale(18909, 39876, 40021); // 销售产品并传入每个销售员的销售数量
    SalesPerson::show(); // 显示剩余库存
    return 0;
}
