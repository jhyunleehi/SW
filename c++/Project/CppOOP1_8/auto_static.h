#pragma once
#include <iostream>


void autoStatic()
{
    using namespace std;

    for (int i = 0; i < 10; ++i)
    {
        int autoVar = 0; // �Ź� �Ҵ�
        autoVar++;
        cout << "auto : " << autoVar << endl;

        static int staticVar = 0; // �� �� �Ҵ�
        staticVar++;
        cout << "static : " << staticVar << endl;
    }
}
