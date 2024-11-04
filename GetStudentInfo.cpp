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
 * @Date: 2024-11-04 16:30:25
 * @LastEditTime: 2024-11-04 16:36:12
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\GetStudentInfo.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// 创建一个结构体以存储学生信息
struct Student {
    string name;
    char gender;
    int age;
};

int main()
{
    const int studentCount = 3; // 学生数量
    Student students[studentCount]; // 创建学生数组

    for (int i = 0; i < studentCount; ++i) {
        cout << "请输入第 " << (i + 1) << " 个学生的姓名、性别、年龄：" << endl;

        // 错误处理机制
        while (true) {
            if (cin >> students[i].name >> students[i].gender >> students[i].age) {
                if (students[i].gender == 'M' || students[i].gender == 'F') { // 仅允许性别为'M'或'F'
                    break;
                } else {
                    cout << "性别输入错误，请输入 'M' 或 'F'." << endl;
                }
            } else {
                cout << "输入无效，请重新输入姓名、性别和年龄。" << endl;
                cin.clear(); // 清除错误状态
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除缓冲区
            }
        }
    }

    // 输出结果
    for (int i = 0; i < studentCount; ++i) {
        cout << "第 " << (i + 1) << " 个学生的姓名：" << students[i].name << endl;
        cout << "第 " << (i + 1) << " 个学生的性别：" << students[i].gender << endl;
        cout << "第 " << (i + 1) << " 个学生的年龄：" << students[i].age << endl;
    }

    return 0;
}

