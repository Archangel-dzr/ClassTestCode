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
 * @LastEditTime: 2024-11-08 18:12:39
 * @LastEditors: Archangel 781446156@qq.com
 * @Description: 设计一个人的类（基类），再分别设计一个学生类（子类）和教师类（子类）单继承人类
 * @FilePath: \ClassTestCode\.vscode\Person.cpp
 * @Copyright (c) 2024 by Archangel email: 781446156@qq.com, All Rights Reserved. 
 */
//人类：属性：姓名，年龄，性别
//方法：吃饭，睡觉
//学生类：属性：姓名，年龄，性别，分数，学号
//方法：吃饭，睡觉，打游戏，学习
//教师类：属性：姓名，年龄，性别，教龄，工作类别
//方法：吃饭，睡觉，教学，备课
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

    void eat() const {
        cout << "Person " << name << " is eating." << endl;
    }

    void sleep() const {
        cout << "Person " << name << " is sleeping." << endl;
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
        p.eat();
        p.sleep();

        Student s("Tom", 22, 'M', 90, "2019001");
        s.eat();
        s.sleep();
        s.play();
        s.study();

        Teacher t("Jane", 30, 'F', 5, "Teacher");
        t.eat();
        t.sleep();
        t.teach();
        t.prepare();
    } catch (const exception &e) {
        cerr << "错误: " << e.what() << endl;
    }

    return 0;
}
