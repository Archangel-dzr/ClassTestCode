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
 * @Date: 2024-11-14 10:02:42
 * @LastEditTime: 2024-11-14 10:09:36
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\OperatorOverloading.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */


#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

    // 私有方法：用于归一化时间
    void normalize()
    {
        if (second >= 60)
        {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60)
        {
            hour += minute / 60;
            minute %= 60;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
        normalize(); // 初始化时进行归一化
    }

    Time operator+(const Time &t)
    {
        return Time(hour + t.hour, minute + t.minute, second + t.second);
    }

    void print() const
    {
        cout << hour << ":" << (minute < 10 ? "0" : "") << minute << ":" << (second < 10 ? "0" : "") << second << endl;
    }
};

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;

    // 从用户输入时间
    cout << "请输入第一个时间 (小时 分钟 秒): ";
    if (!(cin >> h1 >> m1 >> s1) || h1 < 0 || m1 < 0 || m1 >= 60 || s1 < 0 || s1 >= 60)
    {
        cerr << "输入无效，请确保小时为非负数，分钟和秒钟在0到59之间。" << endl;
        return 1; // 返回错误码
    }

    Time t1(h1, m1, s1);

    cout << "请输入第二个时间 (小时 分钟 秒): ";
    if (!(cin >> h2 >> m2 >> s2) || h2 < 0 || m2 < 0 || m2 >= 60 || s2 < 0 || s2 >= 60)
    {
        cerr << "输入无效，请确保小时为非负数，分钟和秒钟在0到59之间。" << endl;
        return 1; // 返回错误码
    }

    Time t2(h2, m2, s2);

    Time t3 = t1 + t2;

    cout << "两个时间的和: ";
    t3.print();

    return 0;
}
