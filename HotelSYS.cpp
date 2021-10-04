#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

unsigned int num = 0, num1, num2, num3;

struct visitors {
    string name;
    unsigned static int day;
    unsigned static int month;
    unsigned static int year;
    unsigned static int duration;
};

class room {
public:
    bool clear;
    bool vacant;
    unsigned int number;


};

visitors enter() {
    visitors vis;
    cout << "Введите данные посетителя\n";
    cout << "Введите ФИО\n";
    cin >> vis.name;
    cout << "Введите день въезда\n";
    cin >> vis.day;
    cout << "Введите месяц въезда\n";
    cin >> vis.month;
    cout << "Введите год въезда\n";
    cin >> vis.year;
    cout << "Введите срок аренды\n";
    cin >> vis.duration;
    return vis;
}
class room1 : public room {
public:
    static int nu;
    unsigned static int price;
    vector <visitors> a;
    void show1() {
        cout << "Одноместный номер\n";
        if (vacant) cout << "Сободен\n";
        else cout << "Занят\n";
        if (clear) cout << "Не нуждается уборке\n";
        else cout << "Требуется уборка\n";
        if (vacant == false) for (int i = 0; i < a.size(); i++) cout << "Посетилель " << i + 1 << ' ' << a[i].name << endl;
    }
    void push1() {
        cout << "Добавить еще посетителя?\n1-Да\n2-Нет\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            if (a.size() <= 1) {
                a.push_back(enter()); push1();
            }
            else {
                cout << "Большего количества человек нельзя добавить";
                system("pause");
            }
            break; }
        case 2: {
            break;
        }
        }
    }

};

class room2 : public room {
public:
    static int nu;
    unsigned static int price;
    vector <visitors> b;
    void show2() {
        cout << "Одноместный номер\n";
        if (vacant) cout << "Сободен\n";
        else cout << "Занят\n";
        if (clear) cout << "Не нуждается уборке\n";
        else cout << "Требуется уборка\n";
        if (vacant == false) for (int i = 0; i < b.size(); i++) cout << "Посетилель " << i + 1 << ' ' << b[i].name << endl;
    }
    void push2() {
        cout << "Добавить еще посетителя?\n1-Да\n2-Нет\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            if (b.size() <= 3) {
                b.push_back(enter()); push2();
            }
            else {
                cout << "Большего количества человек нельзя добавить";
                system("pause");
            }
            break; }
        case 2: {
            break;
        }
        }
    }
};

class room3 : public room {
public:
    static int nu;
    unsigned static int price;
    vector <visitors> c;
    void show3() {
        cout << "Одноместный номер\n";
        if (vacant) cout << "Сободен\n";
        else cout << "Занят\n";
        if (clear) cout << "Не нуждается уборке\n";
        else cout << "Требуется уборка\n";
        if (vacant == false) for (int i = 0; i < c.size(); i++) cout << "Посетилель " << i + 1 << ' ' << c[i].name << endl;
    }
    void push3() {
        cout << "Добавить еще посетителя?\n1-Да\n2-Нет\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            if (c.size() <= 5) {
                c.push_back(enter()); push3();
            }
            else {
                cout << "Большего количества человек нельзя добавить";
                system("pause");
            }
            break; }
        case 2: {
            break;
        }
        }
    }
};



int pric(visitors v) {
    time_t t;
    time(&t);
    int now = localtime(&t)->tm_mday + (localtime(&t)->tm_mon + 1) * 30 + (localtime(&t)->tm_year + 1900) * 365;
    int zaezd = v.day + v.month * 30 + v.year * 365;
    if (now - zaezd <= v.duration) { cout << "Посетитель должен заплатить "; return v.duration; }
    else {
        cout << "Посетитель должен заплатить "; return v.duration + (now - zaezd - v.duration) * 2;
    }
}
class hotel {
public:
    vector <room1> a1;
    vector <room2> a2;
    vector <room3> a3;
    void fill1() {
        unsigned int i;
        for (i = 0; i < num1; i++) {
            room1 a;
            a.clear = true;
            a.vacant = true;
            a.number = 101 + i;
            a1.push_back(a);


        }
    }
    void fill2() {
        unsigned int i;
        for (i = 0; i < num2; i++) {
            room2 b;
            b.clear = true;
            b.vacant = true;
            b.number = 201 + i;
            a2.push_back(b);


        }
    }
    void fill3() {
        unsigned int i;
        for (i = 0; i < num3; i++) {
            room3 c;
            c.clear = true;
            c.vacant = true;
            c.number = 301 + i;
            a3.push_back(c);


        }
    }
    void sdat() {
        unsigned int i;
        int a;
        cout << "Введите, на сколько комнат вы хотите сдать номер\n";
        cin >> a;
        switch (a) {
        case 1: {
            for (i = 0; i < num1; i++) if (a1[i].vacant == true) { a1[i].vacant = false; a1[i].a.push_back(enter()); a1[i].push1(); break; }
            break; }

        case 2: {
            for (i = 0; i < num2; i++) if (a2[i].vacant == true) { a2[i].vacant = false; a2[i].b.push_back(enter()); a2[i].push2(); break; }
            break;
        }
        case 3: {
            for (i = 0; i < num3; i++) if (a3[i].vacant == true) { a3[i].vacant = false; a3[i].c.push_back(enter()); a3[i].push3(); break; }
            break;
        }
        }
    }
    void dirty() {
        unsigned int i;
        cout << "Вот список комнат, нуждающихся в уборке\n";
        for (i = 0; i < num1; i++) if (a1[i].clear == false) { cout << endl << "Комната №" << a1[i].number << endl; }
        for (i = 0; i < num2; i++) if (a2[i].clear == false) { cout << endl << "Комната №" << a2[i].number << endl; }
        for (i = 0; i < num3; i++) if (a3[i].clear == false) { cout << endl << "Комната №" << a3[i].number << endl; }
        system("pause");
    }
    void livers() {
        unsigned int i;
        cout << "Вот список заселённых комнат\n";
        for (i = 0; i < num1; i++) if (a1[i].vacant == false) { cout << endl << "Комната №" << a1[i].number << endl; }
        for (i = 0; i < num2; i++) if (a2[i].vacant == false) { cout << endl << "Комната №" << a2[i].number << endl; }
        for (i = 0; i < num3; i++) if (a3[i].vacant == false) { cout << endl << "Комната №" << a3[i].number << endl; }
        system("pause");
    }
    void cle() {
        switch (num / 100)
        {
        case 1:
        {
            if (a1[num - 101].clear) cout << "Комната не нуждается в уборке\n";
            else { cout << "Комната убрана\n"; a1[num - 101].clear = true; };
            break;
        }
        case 2:
        {
            if (a2[num - 201].clear) cout << "Комната не нуждается в уборке\n";
            else { cout << "Комната убрана\n"; a2[num - 201].clear = true; };
            break;
        }
        case 3:
        {
            if (a3[num - 301].clear) cout << "Комната не нуждается в уборке\n";
            else { cout << "Комната убрана\n"; a3[num - 301].clear = true; };
            break;
        }
        }
        system("pause");
    }
    void getroom() {
        switch (num / 100)
        {
        case 1:
        {
            if (a1[num - 101].vacant) cout << "Комната не была заселена\n";
            else {
                cout << "Комната принята\n";
                cout << pric(a1[num - 101].a[0]) * a1[num - 101].price << " Условных единиц\n";
                a1[num - 101].vacant = true;  for (int j = 0; j < a1[num - 101].a.size(); j++) { a1[num - 101].a.pop_back(); a1[num - 101].clear = false; };

            }
            break;
        }
        case 2:
        {
            if (a2[num - 201].vacant) cout << "Комната не была заселена\n";
            else {
                cout << "Комната принята\n";
                cout << pric(a2[num - 201].b[0]) * a2[num - 201].price << " Условных единиц\n";
                a2[num - 201].vacant = true;  for (int j = 0; j < a2[num - 201].b.size(); j++) { a2[num - 201].b.pop_back(); a2[num - 201].clear = false; };

            }

            break;
        }
        case 3:
        {
            if (a3[num - 301].vacant) cout << "Комната не была заселена\n";
            else {
                cout << "Комната принята\n";
                cout << pric(a3[num - 301].c[0]) * a3[num - 301].price << " Условных единиц\n";
                a3[num - 301].vacant = true;  for (int j = 0; j < a3[num - 301].c.size(); j++) { a3[num - 301].c.pop_back(); a3[num - 301].clear = false; };

            }
            break;

        }

        }
        system("pause");
    }
};


hotel inn;




void menu2() {
    cout << "\033[2J\033[1;1H";
    if (num == 0) {
        cout << "Введите номер комнаты" << endl;
        cin >> num;
    }
    int  cho;
    cout << "1-Отправить уборщицу в номер\n2-Просмотр подробной информации о комнате\n3-Принять номер у гостя\n4-Выбрать другую комнату\n5-Вернуться к главному меню\n";
    cin >> cho;
    switch (cho)
    {
    case 1:
    {
        inn.cle();
        menu2();
        break;

    }
    case 2:
    {
        switch (num / 100)
        {
        case 1:
        {
            inn.a1[num - 101].show1();
            system("pause");
            break;
        }
        case 2:
        {
            inn.a2[num - 201].show2();
            system("pause");
            break;
        }
        case 3:
        {
            inn.a3[num - 301].show3();
            system("pause");
            break;
        }
        }
        menu2();
        break;
    }
    case 3:
    {
        inn.getroom();
        menu2();
        break;
    }
    case 4:
    {
        num = 0;
        menu2();
        break;
    }
    case 5:
    {
        num = 0;
        break;
    }
    }

}
void fill() {
    inn.fill1();
    inn.fill2();
    inn.fill3();
}
void menu() {
    cout << "\033[2J\033[1;1H";
    cout << "1-Сдать номер посетителю\n2-Посмотреть список комнат, требующих уборку\n3-Посмотреть занятые комнаты\n4-Работа с комнатой\n5-Выход\n";
    int c;
    cin >> c;
    switch (c) {
    case 1:
    {
        inn.sdat();
        break;
    }
    case 2:
    {
        inn.dirty();
        break;
    }
    case 3:
    {
        inn.livers();
        break;
    }
    case 4:
    {
        menu2();
        break;
    }
    case 5:
    {
        exit(0);
    }
    }
}


unsigned int visitors::day = 0;
unsigned int visitors::month = 0;
unsigned int visitors::year = 0;
unsigned int visitors::duration = 0;
int room1::nu = 1;
unsigned int room1::price = 10000;
int room2::nu = 2;
unsigned int room2::price = 20000;
int room3::nu = 3;
unsigned int room3::price = 30000;


int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Vvod 1 rooms\n";
    cin >> num1;
    cout << "Vvod 2 rooms\n";
    cin >> num2;
    cout << "Vvod 3 rooms\n";
    cin >> num3;
    fill();
    while (true) menu();

    return 0;
}