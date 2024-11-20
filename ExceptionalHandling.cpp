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
 * @Date: 2024-11-20 10:44:51
 * @LastEditTime: 2024-11-20 10:52:39
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 
 * @FilePath: \ClassTestCode\ExceptionalHandling.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

// �쳣����ʾ������(GBK����)
#include <iostream>
#include <stdexcept>  
#include <limits>    

using namespace std;

// ������������������
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    bool continueCalculation = true;

    while (continueCalculation) {
        try {
            int a, b;
            cout << "�������������� a �� b (a/b): ";
            cin >> a >> b;

            if (cin.fail()) { 
                throw runtime_error("����: ������Ч����ȷ������������������");
            }

            if (b == 0) { 
                throw runtime_error("����: ��������Ϊ�㣬����������.");
            }

            double result = static_cast<double>(a) / b; // ���г�������
            cout << "���: " << result << endl;

            cout << "�Ƿ�������㣿(y/n): ";
            char response;
            cin >> response;
            continueCalculation = (response == 'y' || response == 'Y');
        } catch (const runtime_error& e) {
            cout << e.what() << " ��ȷ�������ʽ��ȷ������ '5 2'��\n";
            clearInput();
        } catch (...) {
            cout << "δ֪���������ԡ�\n";
            clearInput();
        }
    }

    return 0;
}