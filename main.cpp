#include "ModelWindow.h"

int main()
{
	system("chcp 1251");
	system("cls");

	ModelWindow mw;
	mw.Read();

	cout << endl << "����� ���� �� 1050 �� ���������." << endl;
	mw.MoveY(1050);
	
	cout << endl << "����� ���� �� 15 �� ���������." << endl;
	mw.MoveY(15);

	cout << endl << "����� ���� �� -1900 �� �����������." << endl;
	mw.MoveX(-1900);

	cout << endl << "����� ���� �� -9 �� �����������." << endl;
	mw.MoveX(-9);

	cout << endl << "����� ������ = 1800." << endl;
	mw.SetHeight(1800);

	cout << endl << "����� ������ = 150." << endl;
	mw.SetHeight(150);

	cout << endl << "����� ������ = 3000." << endl;
	mw.SetWidth(3000);

	cout << endl << "����� ������ = 300." << endl;
	mw.SetWidth(300);

	cout << endl << "����� ������: " << endl;
	mw.Display();

	system("pause");

	return 0;
}