/*** 
 * @ ������������������������������������������������������������������������������������������������������������������������������
 * @ �����������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ������Щ���������
 * @ ����Esc��!1 ��@2 ��#3 ��$4 ��%5 ��^6 ��&7 ��*8 ��(9 ��)0 ��_- ��+= ��|\ ��`~ ����
 * @ �����������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة������ȩ�
 * @ ���� Tab �� Q �� W �� E �� R �� T �� Y �� U �� I �� O �� P ��{[ ��}] �� BS  ����
 * @ ���������������ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ةЩ����ة����������ȩ�
 * @ ���� Ctrl �� A �� S �� D �� F �� G �� H �� J �� K �� L ��: ;��" '�� Enter  ����
 * @ �����������������ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��Щ��ة��������Щ������ȩ�
 * @ ���� Shift  �� Z �� X �� C �� V �� B �� N �� M ��< ,��> .��? /��Shift ��Fn ����
 * @ ���������������Щ����ةЩ����ة����Щة������ة������ة������ة������ة������ة����Щة������ةЩ����ةЩ����������ة���������
 * @ ��      ��Fn �� Alt ��         Space         �� Alt ��Win��   HHKB   ��
 * @ ��      ���������ة����������ة����������������������������������������������ة����������ة�������          ��
 * @ ������������������������������������������������������������������������������������������������������������������������������
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
    // ʹ��map�洢ƴ���뺺�ֵ�ӳ��
    map<string, string> pymap;
    ifstream in("pinyinutf8.txt");

    // ����ļ��Ƿ�ɹ���
    if (!in.is_open()) {
        cerr << "�޷����ļ�: pinyinutf8.txt" << endl;
        return EXIT_FAILURE; // ʹ�ñ�׼�˳���
    }

    // ��ȡ�ļ������map
    string data;
    while (getline(in, data)) {
        size_t pos = data.find('=');
        if (pos != string::npos) {
            string key = data.substr(0, pos);
            string value = data.substr(pos + 1);
            pymap[key] = value;
        }
    }

    in.close(); // �ر��ļ�

    // ����ʽ����ƴ��
    while (true) {
        cout << "������ƴ����";
        string inputkey;
        cin >> inputkey;

        // ʹ��at()���������쳣����
        try {
            string inputValue = pymap.at(inputkey);
            for (size_t i = 0; i < inputValue.size() / 2; i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << endl; // ÿ5�����ֻ���
                }
                cout << i + 1 << ". " << inputValue.substr(i * 2, 2) << "\t";
            }
            cout << endl;

            // ���������������Ӧ����
            int num = 0;
            cout << "������Ҫѡ��ı�ţ�";
            cin >> num;
            if (num > 0 && num <= inputValue.size() / 2) {
                cout << inputValue.substr((num - 1) * 2, 2) << endl;
            } else {
                cout << "�����Ч�����������롣" << endl;
            }
        } catch (const out_of_range&) {
            cout << "ƴ�������ڣ����������롣" << endl;
        } catch (const invalid_argument&) {
            cout << "������Ч����������ȷ��ƴ����" << endl;
        }
    }

    return EXIT_SUCCESS;
}
