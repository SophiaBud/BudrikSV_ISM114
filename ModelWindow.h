#pragma once
#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// ����
/// </summary>
enum class Color
{
	RED = 0,
	GREEN = 1,
	BLUE = 2
};

/// <summary>
/// ����� ��� ������ � �������� �������� ����
/// </summary>
class ModelWindow
{
private:
	/// <summary>
	/// ��������� ����
	/// </summary>
	string header;
	
	/// <summary>
	/// ���������� ������ �������� ����
	/// </summary>
	size_t x1, y1;
	
	/// <summary>
	/// ������ �� �����������
	/// </summary>
	size_t width;
	
	/// <summary>
	/// ������ �� ���������
	/// </summary>
	size_t height;
	
	/// <summary>
	/// ���� ����
	/// </summary>
	Color color;

	/// <summary>
	/// ��������� "������� / ���������"
	/// </summary>
	bool visible;

	/// <summary>
	/// ��������� "� ������ / ��� �����"
	/// </summary>
	bool frame;

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	ModelWindow()
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

	/// <summary>
	/// ����� ������ ������
	/// </summary>
	void Read()
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

	/// <summary>
	/// ��������������� ������� ��� ������ �����
	/// </summary>
	void PrintColor()
	{
		if (color == Color::RED)
			cout << "�������" << endl;
		else if (color == Color::GREEN)
			cout << "�������" << endl;
		else
			cout << "�����" << endl;
	}

	/// <summary>
	/// ������� ������ �� �����
	/// </summary>
	void Display()
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

	/// <summary>
	/// ������������ ���� �� �����������
	/// </summary>
	/// <param name="dx">��� ������������ �� ��� X</param>
	void MoveX(int dx)
	{
		if (x1 - dx < 0 || x1 + width + dx > 1920)
			cout << "������! ����� �� ������� ���� �� �����������." << endl;
		else
			x1 += dx;
	}

	/// <summary>
	/// ������������ ���� �� ���������
	/// </summary>
	/// <param name="dy">��� ������������ �� ��� Y</param>
	void MoveY(int dy)
	{
		if (y1 - dy < 0 || y1 + height + dy > 1080)
			cout << "������! ����� �� ������� ���� �� ���������." << endl;
		else
			y1 += dy;
	}

	/// <summary>
	/// ��������� ������ ����
	/// </summary>
	/// <param name="h">����� ������</param>
	void SetHeight(size_t h)
	{
		if (y1 + h > 1080)
			cout << "������! ����� �� ������� ���� �� ���������." << endl;
		else
			height = h;
	}

	/// <summary>
	/// ��������� ������ ����
	/// </summary>
	/// <param name="w">����� ������</param>
	void SetWidth(size_t w)
	{
		if (x1 + w > 1920)
			cout << "������! ����� �� ������� ���� �� �����������." << endl;
		else
			width = w;
	}

	/// <summary>
	/// ��������� �����
	/// </summary>
	/// <param name="c">����� ���� ����</param>
	void SetColor(Color c)
	{
		color = c;
		cout << "����� ����: ";
		PrintColor();
	}

	/// <summary>
	/// ��������� ��������� ���������
	/// </summary>
	/// <param name="v">����� �������� ��������� ����</param>
	void SetVisible(bool v)
	{
		visible = v;
	}
	
	/// <summary>
	/// ��������� ��������� �����
	/// </summary>
	/// <param name="f">����� �������� ������� ����� ����</param>
	void SetFrame(bool f)
	{
		frame = f;
	}

	/// <summary>
	/// ����� ��������� ���������
	/// </summary>
	/// <returns></returns>
	bool GetVisible()
	{
		return visible;
	}

	/// <summary>
	/// ����� ��������� �����
	/// </summary>
	/// <returns></returns>
	bool GetFrame()
	{
		return frame;
	}
};