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
 * @Date: 2024-11-08 18:06:06
 * @LastEditTime: 2024-11-08 19:06:41
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 设计一个人的类（基类），再分别设计一个学生类（子类）和教师类（子类）单继承人类
 * @FilePath: \ClassTestCode\.vscode\Person.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class Person {
private:
    string name;
    int age;
    char gender;

public:
    Person(const string &name, int age, char gender) 
        : name(name), age(age), gender(gender) {
        if (age < 0) throw invalid_argument("年龄不能为负值");
        if (gender != 'M' && gender != 'F') throw invalid_argument("性别必须为'M'或'F'");
    }

    // 输出个人信息
    virtual void printInfo() const {
        cout << "姓名: " << name << ", 年龄: " << age << ", 性别: " << (gender == 'M' ? "男" : "女") << endl;
    }

    void eat() const {
        cout << name << " is eating." << endl;
    }

    void sleep() const {
        cout << name << " is sleeping." << endl;
    }
};

class Student : public Person {
private:
    int score;
    string id;

public:
    Student(const string &name, int age, char gender, int score, const string &id)
        : Person(name, age, gender), score(score), id(id) {
        if (score < 0 || score > 100) throw invalid_argument("分数必须在0到100之间");
    }

    // 输出学生信息
    void printInfo() const override {
        Person::printInfo();
        cout << "学号: " << id << ", 分数: " << score << endl;
    }

    void play() const {
        cout << "Student " << id << " is playing." << endl;
    }

    void study() const {
        cout << "Student " << id << " is studying." << endl;
    }
};

class Teacher : public Person {
private:
    int years;
    string job;

public:
    Teacher(const string &name, int age, char gender, int years, const string &job)
        : Person(name, age, gender), years(years), job(job) {
        if (years < 0) throw invalid_argument("教龄不能为负值");
    }

    // 输出教师信息
    void printInfo() const override {
        Person::printInfo();
        cout << "教龄: " << years << "年, 职业: " << job << endl;
    }

    void teach() const {
        cout << "Teacher " << job << " is teaching." << endl;
    }

    void prepare() const {
        cout << "Teacher " << job << " is preparing." << endl;
    }
};

int main() {
    try {
        Person p("Archangel", 24, 'M');
        p.printInfo(); // 输出个人信息
        p.eat();
        p.sleep();

        Student s("Tom", 22, 'M', 90, "2019001");
        s.printInfo(); // 输出学生信息
        s.eat();
        s.sleep();
        s.play();
        s.study();

        Teacher t("Jane", 30, 'F', 5, "Math Teacher");
        t.printInfo(); // 输出教师信息
        t.eat();
        t.sleep();
        t.teach();
        t.prepare();
    } catch (const exception &e) {
        cerr << "错误: " << e.what() << endl;
    }

    return 0;
}

