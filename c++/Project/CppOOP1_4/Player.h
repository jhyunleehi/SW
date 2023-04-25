#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
    int _num;

public:
    Player(int num) : _num(num)
    {
        cout << "Constroctor : " << _num << endl;
    }

    ~Player() // �ı���(�Ҹ���), �׻� �Ķ���Ͱ� ����, ������� �ʾƵ� �����Ϸ��� �������
    {
        cout << "Destructor : " << _num << endl;
    }
};

Player player0(0);
Player* player1 = new Player(1); // player1�� ���� ������ *player1�� ������ ���� ����


void func()
{
    static Player player2(2);
}


void player()
{
    // ������ ������ Ȯ���غ���
    Player player3(3);
    Player* player4 = new Player(4);
    {
        Player player5(5);
        Player* player6 = new Player(6); // delete�� �������� �� ����� ������ ���� ���� �ʴ´�. *player6�� �������� ����
    }
    delete player4;
    func();
    func(); // static�� �� ���� ���� �Ǳ� ������ �� ��° ȣ�� �ÿ��� �������� �ʴ´�
}
