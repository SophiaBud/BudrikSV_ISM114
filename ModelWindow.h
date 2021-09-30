#pragma once
#include <string>
#include <iostream>
using namespace std;

/// <summary>
/// Цвет
/// </summary>
enum class Color
{
	RED = 0,
	GREEN = 1,
	BLUE = 2
};

/// <summary>
/// Класс для работы с моделями экранных форм
/// </summary>
class ModelWindow
{
private:
	/// <summary>
	/// Заголовок окна
	/// </summary>
	string header;
	
	/// <summary>
	/// Координаты левого верхнего угла
	/// </summary>
	size_t x1, y1;
	
	/// <summary>
	/// Размер по горизонтали
	/// </summary>
	size_t width;
	
	/// <summary>
	/// Размер по вертикали
	/// </summary>
	size_t height;
	
	/// <summary>
	/// Цвет окна
	/// </summary>
	Color color;

	/// <summary>
	/// Состояние "видимое / невидимое"
	/// </summary>
	bool visible;

	/// <summary>
	/// Состояние "с рамкой / без рамки"
	/// </summary>
	bool frame;

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	ModelWindow()
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

	/// <summary>
	/// Метод чтения данных
	/// </summary>
	void Read()
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

	/// <summary>
	/// Вспомогательная функция для вывода цвета
	/// </summary>
	void PrintColor()
	{
		if (color == Color::RED)
			cout << "красный" << endl;
		else if (color == Color::GREEN)
			cout << "зеленый" << endl;
		else
			cout << "синий" << endl;
	}

	/// <summary>
	/// Функция вывода на экран
	/// </summary>
	void Display()
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

	/// <summary>
	/// Передвижение окна по горизонтали
	/// </summary>
	/// <param name="dx">шаг передвижения по оси X</param>
	void MoveX(int dx)
	{
		if (x1 - dx < 0 || x1 + width + dx > 1920)
			cout << "Ошибка! Выход за границы окна по горизонтали." << endl;
		else
			x1 += dx;
	}

	/// <summary>
	/// Передвижение окна по вертикали
	/// </summary>
	/// <param name="dy">шаг передвижения по оси Y</param>
	void MoveY(int dy)
	{
		if (y1 - dy < 0 || y1 + height + dy > 1080)
			cout << "Ошибка! Выход за границы окна по вертикали." << endl;
		else
			y1 += dy;
	}

	/// <summary>
	/// Изменение высоты окна
	/// </summary>
	/// <param name="h">новая высота</param>
	void SetHeight(size_t h)
	{
		if (y1 + h > 1080)
			cout << "Ошибка! Выход за границы окна по вертикали." << endl;
		else
			height = h;
	}

	/// <summary>
	/// Изменение ширины окна
	/// </summary>
	/// <param name="w">новая ширина</param>
	void SetWidth(size_t w)
	{
		if (x1 + w > 1920)
			cout << "Ошибка! Выход за границы окна по горизонтали." << endl;
		else
			width = w;
	}

	/// <summary>
	/// Изменение цвета
	/// </summary>
	/// <param name="c">новый цвет окна</param>
	void SetColor(Color c)
	{
		color = c;
		cout << "Новый цвет: ";
		PrintColor();
	}

	/// <summary>
	/// Изменение состояния видимости
	/// </summary>
	/// <param name="v">новое значение видимости окна</param>
	void SetVisible(bool v)
	{
		visible = v;
	}
	
	/// <summary>
	/// Изменение состояния рамки
	/// </summary>
	/// <param name="f">новое значение наличия рамки окна</param>
	void SetFrame(bool f)
	{
		frame = f;
	}

	/// <summary>
	/// Опрос состояния видимости
	/// </summary>
	/// <returns></returns>
	bool GetVisible()
	{
		return visible;
	}

	/// <summary>
	/// Опрос состояния рамки
	/// </summary>
	/// <returns></returns>
	bool GetFrame()
	{
		return frame;
	}
};