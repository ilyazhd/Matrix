#include <iostream>
#include "header.h"

int main() {

	int32_t rows1{};
	int32_t cols1{};
	int32_t rows2{};
	int32_t cols2{};
	int32_t** mtr1 = nullptr;
	int32_t** mtr2 = nullptr;
	int32_t** multMtr = nullptr;
	int32_t** transMtr = nullptr;

	try
	{	
		//ввод характеристик первой матрицы
		std::cout << "input rows of first matrix:\n";
		InputSize(rows1);
		std::cout << "input cols of first matrix:\n";
		InputSize(cols1);
		//создание матрицы 1
		CreateMatrix(mtr1, rows1, cols1);

		//ввод характеристик второй мастрицы
		std::cout << "input rows of second matrix:\n";
		InputSize(rows2);
		std::cout << "input cols  of second matrix:\n";
		InputSize(cols2);
		//создание матрицы 2
		CreateMatrix(mtr2, rows2, cols2);

		//заполняем первую и вторую матрицы
		std::cout << "input First matrix: \n";
		FillMatrix(mtr1, rows1, cols1);
		std::cout << "input second matrix: \n";
		FillMatrix(mtr2, rows2, cols2);

		//выводим первую и вторую матрицу
		std::cout << "first matrix:\n";
		OutputMatrix(mtr1, rows1, cols1);
		std::cout << "second matrix:\n";
		OutputMatrix(mtr2, rows2, cols2);

		if (cols1 != rows2) {
			throw "incorrect size of matrix for multiplication!";
		}
		//создаем матрицу в которой будет наш резутат перемножения матриц
		CreateMatrix(multMtr, rows1, cols2);
		//произведение матриц
		MultiplicationMatrix(multMtr, mtr1, mtr2, rows1, cols1, cols2);
		std::cout << "RESULT:\n";
		OutputMatrix(multMtr, rows1, cols2);

		//транспонироваение матрицы 1
		std::cout << "transposition matrix: \n";
		CreateMatrix(transMtr, cols1, rows1);
		TranspositionMatrix(transMtr, mtr1, rows1, cols1);
		OutputMatrix(transMtr, cols1, rows1);
		DeleteMatrix(transMtr, cols1, rows1);


	}
	catch (const char * e)
	{
		std::cout << e;
	}
	


	DeleteMatrix(multMtr, rows1, cols2);
	DeleteMatrix(mtr2, rows2, cols2);
	DeleteMatrix(mtr1, rows1, cols1);
	return 0;
}