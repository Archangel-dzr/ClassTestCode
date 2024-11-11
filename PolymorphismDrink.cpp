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
 * @Date: 2024-11-11 14:44:42
 * @LastEditTime: 2024-11-11 14:48:28
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\PolymorphismDrink.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

//制作饮品的大致流程为：煮水-冲泡-倒入杯中-加入辅料
//利用多态技术，提供抽象（纯虚函数）制作饮品基类，提供子类制作咖啡和茶叶

#include <iostream>
using namespace std;

class Drink
{
public:
    virtual void boilWater() = 0; // 纯虚函数，必须实现
    virtual void brew() = 0; // 纯虚函数，必须实现
    virtual void addCondiments() = 0; // 纯虚函数，必须实现
    virtual void pourInCup() = 0; // 纯虚函数，必须实现
};

class Coffee : public Drink
{
public:
    void boilWater()
    {
        cout << "烧水..." << endl;
    }
    void brew()
    {
        cout << "通过滤器滴咖啡..." << endl;
    }
    void addCondiments()
    {
        cout << "加入糖和牛奶..." << endl;
    }
    void pourInCup()
    {
        cout << "将咖啡倒入杯中..." << endl;
    }
};

class Tea : public Drink
{
public:
    void boilWater()
    {
        cout << "烧水..." << endl;
    }
    void brew()
    {
        cout << "浸泡茶包..." << endl;
    }
    void addCondiments()
    {
        cout << "加入柠檬..." << endl;
    }
    void pourInCup()
    {
        cout << "将茶倒入杯中..." << endl;
    }
};

int main()
{
    Coffee c;
    Tea t;

    c.boilWater();
    c.brew();
    c.addCondiments();
    c.pourInCup();

    t.boilWater();
    t.brew();
    t.addCondiments();
    t.pourInCup();

    return 0;
}
