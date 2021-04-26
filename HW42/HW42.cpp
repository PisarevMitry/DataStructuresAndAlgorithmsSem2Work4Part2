#include <iostream>
#include <chrono>
#include <iomanip>
#include <Windows.h>

using namespace std;

long long M, C;

//функция сортировки методом простого обмена
//Предусловие: на вход поступает указатель на ненулевой массив, количество элементов массива
//Постусловие: функция перемещает элементы массива
void exchangeSort(long*& array, long N) {
	bool swapped;
	C++;
	for (long i = 0; i < N - 1; i++) {
		C++;
		swapped = false;
		C++;
		for (long j = 0; j < N - i - 1; j++) {
			C++;
			C++;
			if (array[j] > array[j + 1]) {
				M++;
				swap(array[j], array[j + 1]);
				swapped = true;
			}
		}
		C++;
		if (swapped == false) {
			break;
		}
	}
}

//Функция заполнения массива случайными числами
void filling_array(long*& array, long N) {
	srand(time(NULL));
	for (long i = 0; i < N; i++) {
		array[i] = rand() % 1000;
	}
}

//Функция заполнения массива по возрастанию
void filling_array_ASK(long*& array, long N) {
	for (long i = 0; i < N; i++) {
		array[i] = i;
	}
}

//Функция заполнения массива по убыванию
void filling_array_DESK(long*& array, long N) {
	for (long i = 0; i < N; i++) {
		array[i] = N - i;
	}
}

//Функция вывода массива
void print_array(long array[], long N) {
	for (long i = 0; i < N; i++) {
		cout << setw(7) << array[i];
	}
	cout << "\n";
}

//Функция вывода результатов теста для общего случая
void test(long N, long*& array) {
	array = new  long[N];
	cout << "Тестирование для массива из " << N << " чисел: " << endl;
	filling_array(array, N);
	//cout << "Не отсортированный массив: " << endl;
	//print_array(array, N);
	M = 0;
	C = 0;
	auto begin = std::chrono::steady_clock::now();
	exchangeSort(array, N);
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Затраченнное время: " << elapsed_ms.count() << " ms" << endl;
	cout << "C + M = " << M + C << endl;
	//cout << "Отсортированный массив: " << endl;
	//print_array(array, N);
}

//Функция вывода результатов теста для возрастающих элементов
void test_ASK(long N, long*& array) {
	array = new  long[N];
	cout << "Тестирование для массива из " << N << " строго возрастающих чисел: " << endl;
	filling_array_ASK(array, N);
	//cout << "Не отсортированный массив: " << endl;
	//print_array(array, N);
	M = 0;
	C = 0;
	auto begin = std::chrono::steady_clock::now();
	exchangeSort(array, N);
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Затраченнное время: " << elapsed_ms.count() << " ms" << endl;
	cout << "C + M = " << M + C << endl;
	//cout << "Отсортированный массив: " << endl;
	//print_array(array, N);
}

//Функция вывода результатов теста для возрастающих элементов
void test_DESK(long N, long*& array) {
	array = new  long[N];
	cout << "Тестирование для массива из " << N << " строго убывающих чисел: " << endl;
	filling_array_DESK(array, N);
	//cout << "Не отсортированный массив: " << endl;
	//print_array(array, N);
	M = 0;
	C = 0;
	auto begin = std::chrono::steady_clock::now();
	exchangeSort(array, N);
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Затраченнное время: " << elapsed_ms.count() << " ms" << endl;
	cout << "C + M = " << M + C << endl;
	//cout << "Отсортированный массив: " << endl;
	//print_array(array, N);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите [1] - для заполнения массива случайными числами, [2] - для заполнения массива вручную (ввод с клавиатуры): ";

	long* array = nullptr;
	long N;

	int num;
	cin >> num;
	switch (num)
	{
	case 1:
	{
		N = 100;
		test(N, array);
		test_ASK(N, array);
		test_DESK(N, array);

		N = 1000;
		test(N, array);
		test_ASK(N, array);
		test_DESK(N, array);

		N = 10000;
		test(N, array);
		test_ASK(N, array);
		test_DESK(N, array);

		N = 100000;
		test(N, array);
		test_ASK(N, array);
		test_DESK(N, array);

		N = 1000000;
		test(N, array);
		test_ASK(N, array);
		test_DESK(N, array);
	}
	break;

	case 2:
	{
		cout << "Введите размер массива: ";
		cin >> N;
		array = new  long[N];
		cout << "Введите " << N << " чисел: ";
		for (long i = 0; i < N; i++) {
			cin >> array[i];
		}
		M = 0;
		C = 0;
		auto begin = std::chrono::steady_clock::now();
		exchangeSort(array, N);
		auto end = chrono::steady_clock::now();
		auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		cout << "Затраченнное время: " << elapsed_ms.count() << " ms" << endl;
		cout << "C + M = " << M + C << endl;
		cout << "Отсортированный массив: " << endl;
		print_array(array, N);
	}
	break;

	default:
		cout << "Ошибка, введите корректное число";
	}
}
