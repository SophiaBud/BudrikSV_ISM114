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
	ModelWindow();

	/// <summary>
	/// ����� ������ ������
	/// </summary>
	void Read();

	/// <summary>
	/// ��������������� ������� ��� ������ �����
	/// </summary>
	void PrintColor();

	/// <summary>
	/// ������� ������ �� �����
	/// </summary>
	void Display();

	/// <summary>
	/// ������������ ���� �� �����������
	/// </summary>
	/// <param name="dx">��� ������������ �� ��� X</param>
	void MoveX(int dx);

	/// <summary>
	/// ������������ ���� �� ���������
	/// </summary>
	/// <param name="dy">��� ������������ �� ��� Y</param>
	void MoveY(int dy);

	/// <summary>
	/// ��������� ������ ����
	/// </summary>
	/// <param name="h">����� ������</param>
	void SetHeight(size_t h);

	/// <summary>
	/// ��������� ������ ����
	/// </summary>
	/// <param name="w">����� ������</param>
	void SetWidth(size_t w);

	/// <summary>
	/// ��������� �����
	/// </summary>
	/// <param name="c">����� ���� ����</param>
	void SetColor(Color c);

	/// <summary>
	/// ��������� ��������� ���������
	/// </summary>
	/// <param name="v">����� �������� ��������� ����</param>
	void SetVisible(bool v);
	
	/// <summary>
	/// ��������� ��������� �����
	/// </summary>
	/// <param name="f">����� �������� ������� ����� ����</param>
	void SetFrame(bool f);

	/// <summary>
	/// ����� ��������� ���������
	/// </summary>
	/// <returns></returns>
	bool GetVisible();

	/// <summary>
	/// ����� ��������� �����
	/// </summary>
	/// <returns></returns>
	bool GetFrame();
};