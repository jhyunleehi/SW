#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player4
{
private:
    int _health;
    int _power;
    const string _name;

public:
    Player4() : Player4(100, 50, "noname") 
    {
    }
    Player4(int health, int power, string name)
        : _health(health), _power(power), _name(name) // ��� �ʱ�ȭ ����Ʈ, �ʱ�ȭ ������ Ŭ������ ����� ����
    {
        // �Ʒ��� ���� �����, ��, ��� �������� �ʱ�ȭ (�⺻ �����ڰ� �̹� ȣ�� �� ����) 
        //_health = health;
        //_power = power;
        //_name = name; ����� �̹� �ʱ�ȭ�� �Ǿ� �־ �� ��

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _name << endl;
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player4()
{
    Player4 player;
    player.print();
}

