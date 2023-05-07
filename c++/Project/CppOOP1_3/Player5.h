#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player5
{
private:
    // �ζ��� �ʱ�ȭ
    int _health = 100;
    int _power = 50;
    const string _name = "noname";

public:
    Player5() = default; // �����Ϸ��� ���� �����ڸ� ����ϰڴٴ� ���� ���
    //Player5() = delete; // �����Ϸ��� �����ڸ� �Ͻ������� ������ �� ���� ���
    Player5(int health, int power, string name)
        : _health(health), _power(power), _name(name)
    {

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _name << endl;
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player5()
{
    Player5 player;
    player.print();
}

