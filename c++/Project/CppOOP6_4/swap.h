#pragma once


template<typename T>
void swap(T& x, T& y);



// ����� ��üȭ
// ����, ���Ǹ� header, cpp �и��ϴ� ��� �� Ÿ�Ը��� ����� ��üȭ�� �ؾ��Ѵ�
// �� ����Ϸ��� Ÿ�Ը��� ������Ͽ� ����ϱ� ������ ���ø��� ����/������ �и��� ���� �ʰ� ���Ǹ� ���� ����� �д�
template
void swap<int>(int&, int&);
