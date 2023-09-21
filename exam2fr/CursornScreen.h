#pragma once
#include <iostream>
#include <windows.h>
#include "InitialComposition.h"

namespace ProjectGame
{
	namespace Settings
	{
		// ����� ��� ��������
		class CursornScreen
		{
		public:
			// ������ ������ ����� � �������
			static void hideConsoleCursor();
			// �������� ������ ����� � �������
			static void showConsoleCursor();
			// �������� ����� �������
			void clearScreen();
			// ������������� ���������� ��������� �� �������� ���������� �����������
			void sleepMilliseconds(int milliseconds);
			// �������� ���� ������ � ������� �� ������ ���������� �����
			void printWithColor(char letter);
		};
	}
}
