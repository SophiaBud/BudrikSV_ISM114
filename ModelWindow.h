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
	ModelWindow();

	/// <summary>
	/// Метод чтения данных
	/// </summary>
	void Read();

	/// <summary>
	/// Вспомогательная функция для вывода цвета
	/// </summary>
	void PrintColor();

	/// <summary>
	/// Функция вывода на экран
	/// </summary>
	void Display();

	/// <summary>
	/// Передвижение окна по горизонтали
	/// </summary>
	/// <param name="dx">шаг передвижения по оси X</param>
	void MoveX(int dx);

	/// <summary>
	/// Передвижение окна по вертикали
	/// </summary>
	/// <param name="dy">шаг передвижения по оси Y</param>
	void MoveY(int dy);

	/// <summary>
	/// Изменение высоты окна
	/// </summary>
	/// <param name="h">новая высота</param>
	void SetHeight(size_t h);

	/// <summary>
	/// Изменение ширины окна
	/// </summary>
	/// <param name="w">новая ширина</param>
	void SetWidth(size_t w);

	/// <summary>
	/// Изменение цвета
	/// </summary>
	/// <param name="c">новый цвет окна</param>
	void SetColor(Color c);

	/// <summary>
	/// Изменение состояния видимости
	/// </summary>
	/// <param name="v">новое значение видимости окна</param>
	void SetVisible(bool v);
	
	/// <summary>
	/// Изменение состояния рамки
	/// </summary>
	/// <param name="f">новое значение наличия рамки окна</param>
	void SetFrame(bool f);

	/// <summary>
	/// Опрос состояния видимости
	/// </summary>
	/// <returns></returns>
	bool GetVisible();

	/// <summary>
	/// Опрос состояния рамки
	/// </summary>
	/// <returns></returns>
	bool GetFrame();
};