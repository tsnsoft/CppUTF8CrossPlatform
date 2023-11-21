#include <stdlib.h>
#include <iostream>

#ifdef _WIN32 // Если это Windows
#include <io.h>
#include <fcntl.h>
#endif 


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru_RU.UTF-8"); // Установить русскую локаль для Linux

#ifdef _WIN32
	_setmode(_fileno(stdout), _O_U16TEXT); // Установить Юникод для вывода в консоли Windows
	_setmode(_fileno(stdin), _O_U16TEXT); // Установить Юникод для ввода в консоли Windows
	_setmode(_fileno(stderr), _O_U16TEXT); // Установить Юникод для вывода ошибок в консоли Windows
#endif 

	std::wcout << L"Замечательно! Das ist großartig! Wonderful! 精彩的！ رائع!\n";
	std::wcout << L"Введите имя: ";
	std::wstring fio; // Создать строковую переменную
	std::wcin >> fio; // Считать строку
	std::wcout << L"Привет, " << fio << "!" << std::endl; // Вывести строку
	std::wcout << L"Размер строки: " << fio.length() << std::endl;
	for (int i = 0; i < fio.length(); i++) {
		std::wcout << "[" << i << "]: " << fio[i] << " (code: " << int(fio[i]) << ")" << std::endl;
	}

}