#pragma once
#include <iostream>

using namespace std;


class Player2
{
private:
    int _health;
    int _power;

public:
    Player2()
    {
        // �ߺ� ���Ÿ� ���� Player2(int, int)�� ȣ���� �� �������� �����δ� Player2�� �� �� �� ����
        Player2(100, 50); 
    }
    Player2(int health, int power)
    {
        _health = health;
        _power = power;

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player2()
{
    Player2 player;
    player.print();
}
