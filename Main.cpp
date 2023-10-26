# include <iostream>
#include<string>

#define chui(sym) (unsigned int)(sym)

std::string tobinary(unsigned int num) {
	std::string result;
	result.reserve(32); // Резервирование памяти под 32 элемента массива char в строке
	while (num > 1) {
		result += std::to_string(num % 2);
		num /= 2;
	}	
	result += num == 0 ? '0' : '1';
	std::reverse(result.begin(),result.end()); // Ф., принимающая указатели на начало и конец стрки и отражающая \
	содержимое строки
	return result;
}

bool bit_at_index(unsigned int num, int index) {
	// Сложный вариант решения
	/*unsigned int tmp1 = 1 << index;
	unsigned int tmp2 = num & tmp1;
	tmp2 >>= index;	
	return tmp2;*/
	// Простой вариан решения
	return (1 << index) & num;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Битовые операции
	char sym1 = 14;
	std::cout << (sym1 << 1) << std::endl;
	char sym2 = 44;
	std::cout << (sym2 >> 2) << std::endl;

	unsigned char sym3 = ~100;
	unsigned int num = ~100;
	std::cout << unsigned int (~sym3) << std::endl;
	std::cout << ~num << std::endl;

	unsigned char sym4 = 154; // 10011010
	unsigned char sym5 = 171; // 10101011
	std::cout << chui(sym4 & sym5) << std::endl; // 10001010 Результат битового И
	std::cout << chui(sym4 | sym5) << std::endl; // 10111011 Результат битового ИЛИ
	// Результат исключающего ИЛИ ^:
	std::cout << chui(sym4 ^ sym5) << std::endl; // 00110001

	// Задача 1. DEC в BIN
	std::cout << "Задача 1.\nВведите число -> ";
	std::cin >> n;
	std::cout << n << " DEC = " << tobinary(n) << " BIN\n\n";

	// Задача 2. Бит в позиции
	std::cout << "Задача 2.\nВведите число -> ";
	std::cin >> n;
	int index;
	std::cout << "Введите индекс бита -> ";
	std::cin >> index;
	std::cout << "Бит в позиции: " << bit_at_index(n, index) << "\n";

	return 0;
}