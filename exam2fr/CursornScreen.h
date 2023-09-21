#pragma once
#include <iostream>
#include <windows.h>
#include "InitialComposition.h"

namespace ProjectGame
{
	namespace Settings
	{
		// Класс для настроек
		class CursornScreen
		{
		public:
			// Скрыть курсор ввода в консоли
			static void hideConsoleCursor();
			// Показать курсор ввода в консоли
			static void showConsoleCursor();
			// Очистить экран консоли
			void clearScreen();
			// Приостановить выполнение программы на заданное количество миллисекунд
			void sleepMilliseconds(int milliseconds);
			// Изменить цвет текста в консоли на основе переданной буквы
			void printWithColor(char letter);
		};
	}
}
