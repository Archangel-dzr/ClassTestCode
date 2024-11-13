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
 * @Date: 2024-11-13 09:58:24
 * @LastEditTime: 2024-11-13 10:09:22
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 用友元函数实现计算两个点之间的距离
 * @FilePath: \ClassTestCode\FriendFunction.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

#include <iostream>
#include <cmath>

using namespace std;

class Point 
{
    private:
        double x, y;
    public:
        Point(double x, double y) : x(x), y(y) {}

        // 获取点的x坐标
        double getX() const {
            return x;
        }

        // 获取点的y坐标
        double getY() const {
            return y;
        }

        friend double distance(const Point& p1, const Point& p2); // 声明友元函数 
};

double distance(const Point& p1, const Point& p2)  // 定义友元函数 
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); // 计算两点距离并返回
};

int main() 
{
    double x1, y1, x2, y2;
    
    // 输入错误处理
    cout << "请输入P1的x坐标和y坐标（以空格分隔）：";
    if (!(cin >> x1 >> y1)) {
        cerr << "输入错误，请输入数字！" << endl;
        return 1; // 返回错误代码
    }
    
    cout << "请输入P2的x坐标和y坐标（以空格分隔）：";
    if (!(cin >> x2 >> y2)) {
        cerr << "输入错误，请输入数字！" << endl;
        return 1; // 返回错误代码
    }

    Point p1(x1, y1);  // 根据输入的坐标创建点p1
    Point p2(x2, y2);  // 根据输入的坐标创建点p2
    
    cout << "Point 1 的位置为: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "Point 2 的位置为: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "两点之间的距离为：" << distance(p1, p2) << endl;

    return 0;
}
