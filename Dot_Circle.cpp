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
 * @Date: 2024-11-08 17:55:49
 * @LastEditTime: 2024-11-08 18:04:07
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\Dot_Circle.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

//设计一个圆形类和一个点类，计算点和圆的关系（判断该点是在圆内，圆外还是圆上）

#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
};

class Circle {
public:
    double x, y, r;
    Circle(double x = 0, double y = 0, double r = 0) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    bool isInside(Point p) {
        double dis = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
        return dis <= r;
    }
    bool isOutside(Point p) {
        double dis = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
        return dis > r;
    }
    bool isOn(Point p) {
        double dis = sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
        return dis == r;
    }
};

int main() {
    double px, py;
    cout << "请输入点的坐标 (x, y): ";
    cout << "圆心坐标 (0, 0), 半径为 3" << endl;
    cin >> px >> py; // 获取用户输入的点坐标
    Point p(px, py);

    Circle c(0, 0, 3); // 圆心在 (0, 0)，半径为 3
    if (c.isInside(p))
        cout << "点在圆内" << endl;
    else if (c.isOutside(p))
        cout << "点在圆外" << endl;
    else
        cout << "点在圆上" << endl;

    return 0;
}
