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
 * @Date: 2024-11-18 19:09:50
 * @LastEditTime: 2024-11-18 20:23:48
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\Shurufa.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 使用map存储拼音与汉字的映射
    map<string, string> pymap;
    ifstream in("pinyinutf8.txt");

    // 检查文件是否成功打开
    if (!in.is_open()) {
        cerr << "无法打开文件: pinyinutf8.txt" << endl;
        return EXIT_FAILURE; // 使用标准退出码
    }

    // 读取文件并填充map
    string data;
    while (getline(in, data)) {
        size_t pos = data.find('=');
        if (pos != string::npos) {
            string key = data.substr(0, pos);
            string value = data.substr(pos + 1);
            pymap[key] = value;
        }
    }

    in.close(); // 关闭文件

    // 交互式输入拼音
    while (true) {
        cout << "请输入拼音：";
        string inputkey;
        cin >> inputkey;

        // 使用at()方法进行异常处理
        try {
            string inputValue = pymap.at(inputkey);
            for (size_t i = 0; i < inputValue.size() / 2; i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << endl; // 每5个汉字换行
                }
                cout << i + 1 << ". " << inputValue.substr(i * 2, 2) << "\t";
            }
            cout << endl;

            // 输入索引并输出对应汉字
            int num = 0;
            cout << "请输入要选择的编号：";
            cin >> num;
            if (num > 0 && num <= inputValue.size() / 2) {
                cout << inputValue.substr((num - 1) * 2, 2) << endl;
            } else {
                cout << "编号无效，请重新输入。" << endl;
            }
        } catch (const out_of_range&) {
            cout << "拼音不存在，请重新输入。" << endl;
        } catch (const invalid_argument&) {
            cout << "输入无效，请输入正确的拼音。" << endl;
        }
    }

    return EXIT_SUCCESS;
}
