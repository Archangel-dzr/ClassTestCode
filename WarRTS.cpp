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
 * @LastEditTime: 2024-11-05 16:15:59
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

public:
    Player(int id, string name, string psw, bool vip, int coins, int wood, int stone, int iron) {
        if (coins < 0 || wood < 0 || stone < 0 || iron < 0) {
            throw invalid_argument("资源数量不能为负数");
        }
        gameID = id;
        nickname = name;
        password = psw;
        VIP = vip;
        gameCoins = coins;
        woods = wood;
        this->stone = stone; 
        this->iron = iron;
    }

    void showInfo() const { 
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
        Player player(1001, "Archangel", "123456", true, 10000, 1000, 500, 300);
        cout << "玩家信息：" << endl;
        player.showInfo();
    } catch (const invalid_argument& e) {
        cerr << "错误： " << e.what() << endl; 
    }

    return 0;
}
