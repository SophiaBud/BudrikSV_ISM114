#include "ModelWindow.h"

int main()
{
	system("chcp 1251");
	system("cls");

	ModelWindow mw;
	mw.Read();

	cout << endl << "Сдвиг окна на 1050 по вертикали." << endl;
	mw.MoveY(1050);
	
	cout << endl << "Сдвиг окна на 15 по вертикали." << endl;
	mw.MoveY(15);

	cout << endl << "Сдвиг окна на -1900 по горизонтали." << endl;
	mw.MoveX(-1900);

	cout << endl << "Сдвиг окна на -9 по горизонтали." << endl;
	mw.MoveX(-9);

	cout << endl << "Новая высота = 1800." << endl;
	mw.SetHeight(1800);

	cout << endl << "Новая высота = 150." << endl;
	mw.SetHeight(150);

	cout << endl << "Новая ширина = 3000." << endl;
	mw.SetWidth(3000);

	cout << endl << "Новая ширина = 300." << endl;
	mw.SetWidth(300);

	cout << endl << "Новые данные: " << endl;
	mw.Display();

	system("pause");

	return 0;
}