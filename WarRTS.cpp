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
 * @Date: 2024-11-05 16:01:43
 * @LastEditTime: 2024-11-05 16:44:38
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\WarRTS.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

#include <iostream>
#include <stdexcept> 
using namespace std;

class Player {
private:
    int gameID;
    string nickname;
    string password;
    bool VIP;
    int gameCoins;
    int woods;
    int stone;
    int iron;

    // 检查资源是否有效
    void validateResources() const {
        if (gameCoins < 0 || woods < 0 || stone < 0 || iron < 0) {
            throw invalid_argument("资源数量不能为负数");
        }
    }

public:
    Player(int id, string name, string psw, bool vip, int coins, int wood, int stone, int iron) 
        : gameID{id}, nickname{std::move(name)}, password{std::move(psw)}, VIP{vip}, 
          gameCoins{coins}, woods{wood}, stone{stone}, iron{iron} {
        validateResources();
    }

    void showInfo() const { 
        cout << "___玩家信息：___" << endl;
        cout << "游戏ID：" << gameID << endl;
        cout << "昵称：" << nickname << endl;
        cout << "VIP：" << (VIP ? "是" : "否") << endl; 
        cout << "游戏币：" << gameCoins << endl;
        cout << "木材：" << woods << endl;
        cout << "石料：" << stone << endl;
        cout << "铁矿：" << iron << endl;
    }
};

int main() {
    try {
        Player players[] = {
            {1001, "Archangel", "123456", true, 10000, 1000, 500, 300},
            {1002, "刘备", "123456", false, 5000, 2000, 1000, 800},
            {1003, "曹操", "123456", true, 100000, 5000, 2000, 1000},
            {1004, "孙权", "123456", false, 50000, 20000, 10000, 5000}
        };

        for (const auto& player : players) {
            player.showInfo();
        }
    } catch (const invalid_argument& e) {
        cerr << "错误： " << e.what() << endl; 
    }

    return 0;
}
