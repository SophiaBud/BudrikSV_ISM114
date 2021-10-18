#include "ModelWindow.h"

ModelWindow::ModelWindow()
{
	header = "����";
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
	cout << "������� ��������� ����: ";
	getline(cin, header);

	cout << "������� ���������� x ������ �������� ���� (> 0): ";
	cin >> x1;

	cout << "������� ���������� y ������ �������� ���� (> 0): ";
	cin >> y1;

	do
	{
		cout << "������� ������ �� ����������� (�� 1 �� " << 1920 - x1 << "): ";
		cin >> width;
	} while (width < 1 || width > 1920 - x1);
	do
	{
		cout << "������� ������ �� ��������� (�� 1 �� " << 1080 - y1 << "): ";
		cin >> height;
	} while (height < 1 || height > 1080 - y1);

	int col;
	cout << "���� ���� (0 - �������, 1 - �������, 2 - �����): ";
	cin >> col;
	color = static_cast<Color>(col);

	cout << "��������� ���� - 0, ������� - 1: ";
	cin >> visible;

	cout << "���� ��� ����� - 0, � ������ - 1: ";
	cin >> frame;

	cin.ignore();
}

void ModelWindow::PrintColor()
{
	if (color == Color::RED)
		cout << "�������" << endl;
	else if (color == Color::GREEN)
		cout << "�������" << endl;
	else
		cout << "�����" << endl;
}

void ModelWindow::Display()
{
	cout << "��������� ����: " << header << endl;
	cout << "���������� ������ �������� ����: ("
		<< x1 << ", " << y1 << ")" << endl;
	cout << "������: " << width << "; ������: " << height << endl;
	cout << "����: ";
	PrintColor();
	cout << "���� " << (GetVisible() ? "�������" : "���������");
	cout << (GetFrame() ? ", � ������" : ", ��� �����") << endl;
}

void ModelWindow::MoveX(int dx)
{
	if (x1 - dx < 0 || x1 + width + dx > 1920)
		cout << "������! ����� �� ������� ���� �� �����������." << endl;
	else
		x1 += dx;
}

void ModelWindow::MoveY(int dy)
{
	if (y1 - dy < 0 || y1 + height + dy > 1080)
		cout << "������! ����� �� ������� ���� �� ���������." << endl;
	else
		y1 += dy;
}

void ModelWindow::SetHeight(size_t h)
{
	if (y1 + h > 1080)
		cout << "������! ����� �� ������� ���� �� ���������." << endl;
	else
		height = h;
}

void ModelWindow::SetWidth(size_t w)
{
	if (x1 + w > 1920)
		cout << "������! ����� �� ������� ���� �� �����������." << endl;
	else
		width = w;
}

void ModelWindow::SetColor(Color c)
{
	color = c;
	cout << "����� ����: ";
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