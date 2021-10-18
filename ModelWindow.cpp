#include "ModelWindow.h"

ModelWindow::ModelWindow()
{
	header = "Окно";
	x1 = 100;
	y1 = 100;
	width = 100;
	height = 100;
	color = Color::RED;
	visible = true;
	frame = false;
}

void ModelWindow::Read()
{
	cout << "Введите заголовок окна: ";
	getline(cin, header);

	cout << "Введите координату x левого верхнего угла (> 0): ";
	cin >> x1;

	cout << "Введите координату y левого верхнего угла (> 0): ";
	cin >> y1;

	do
	{
		cout << "Введите размер по горизонтали (от 1 до " << 1920 - x1 << "): ";
		cin >> width;
	} while (width < 1 || width > 1920 - x1);
	do
	{
		cout << "Введите размер по вертикали (от 1 до " << 1080 - y1 << "): ";
		cin >> height;
	} while (height < 1 || height > 1080 - y1);

	int col;
	cout << "Цвет окна (0 - красный, 1 - зеленый, 2 - синий): ";
	cin >> col;
	color = static_cast<Color>(col);

	cout << "Невидимое окно - 0, видимое - 1: ";
	cin >> visible;

	cout << "Окно без рамки - 0, с рамкой - 1: ";
	cin >> frame;

	cin.ignore();
}

void ModelWindow::PrintColor()
{
	if (color == Color::RED)
		cout << "красный" << endl;
	else if (color == Color::GREEN)
		cout << "зеленый" << endl;
	else
		cout << "синий" << endl;
}

void ModelWindow::Display()
{
	cout << "Заголовок окна: " << header << endl;
	cout << "Координаты левого верхнего угла: ("
		<< x1 << ", " << y1 << ")" << endl;
	cout << "Ширина: " << width << "; высота: " << height << endl;
	cout << "Цвет: ";
	PrintColor();
	cout << "Окно " << (GetVisible() ? "видимое" : "невидимое");
	cout << (GetFrame() ? ", с рамкой" : ", без рамки") << endl;
}

void ModelWindow::MoveX(int dx)
{
	if (x1 - dx < 0 || x1 + width + dx > 1920)
		cout << "Ошибка! Выход за границы окна по горизонтали." << endl;
	else
		x1 += dx;
}

void ModelWindow::MoveY(int dy)
{
	if (y1 - dy < 0 || y1 + height + dy > 1080)
		cout << "Ошибка! Выход за границы окна по вертикали." << endl;
	else
		y1 += dy;
}

void ModelWindow::SetHeight(size_t h)
{
	if (y1 + h > 1080)
		cout << "Ошибка! Выход за границы окна по вертикали." << endl;
	else
		height = h;
}

void ModelWindow::SetWidth(size_t w)
{
	if (x1 + w > 1920)
		cout << "Ошибка! Выход за границы окна по горизонтали." << endl;
	else
		width = w;
}

void ModelWindow::SetColor(Color c)
{
	color = c;
	cout << "Новый цвет: ";
	PrintColor();
}

void ModelWindow::SetVisible(bool v)
{
	visible = v;
}

void ModelWindow::SetFrame(bool f)
{
	frame = f;
}

bool ModelWindow::GetVisible()
{
	return visible;
}

bool ModelWindow::GetFrame()
{
	return frame;
}