export module swap;

export void swap(int&x, int&y)  // �����ų �Ϳ��� export�� ����
{
	int temp = x;
	x = y;
	y = temp;
}