#include <iostream>
#include <cfloat>

using std::cout;
using std::endl;

union ID
{
    char chars[10];
    int integer;
};


int main()
{
    ID id;
    id.integer = 10;

    // �ش� ��Ʈ �迭�� int�� �ν��ϰڴٴ� �ǹ�
    // ��뿡 ����
    int* p = reinterpret_cast<int*>(&id);
    cout << *p << endl;


    // Ư���� ��� �޸��� Ư�� �ּҿ� �ִ� ���� Device�� �ٷ�� ��찡 ���� �� ����
    //Device* p0 = reinterpret_cast<Device*>(0xabcd);

    
    // 0000,0000,0000,0000,0000,0000,0000,0001
    // int, 1�� ��Ʈ �迭�� flaot ���·� �ؼ��ϸ� float�� �ּ� ���� ����
    int i = 1;
    float* a = reinterpret_cast<float*>(&i);
    cout << *a << endl;
    cout << FLT_TRUE_MIN << endl;

    // �Ϲ� ����ȯ�� �ܼ��� 1�� ���´�
    float b = i;
    cout << b << endl;

}