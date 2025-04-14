#include <iostream>
#include <iomanip>
#include "header.h"

void CreateMatrix(int32_t**& mtr, int32_t rows, int32_t cols) {
	mtr = new int32_t * [rows];
	for (size_t i = 0; i < rows; ++i) {
		mtr[i] = new int32_t[cols];
	}
}

void DeleteMatrix(int32_t**& mtr, int32_t rows, int32_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
}

void InputSize(int32_t& size) {
	std::cin >> size;
	if (size < 1) {
		throw "incorrect size!";
	}
}

void FillMatrix(int32_t**& mtr, int32_t rows, int32_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << i + 1 << j + 1 << ' ';
			std::cin >> mtr[i][j];
		}
		std::cout << '\n';
	}
}

void OutputMatrix(int32_t** mtr, int32_t rows, int32_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << std::setw(3) << mtr[i][j];
		}
		std::cout << '\n';
	}
}

void MultiplicationMatrix(int32_t**& multMtr, int32_t** mtr1, int32_t** mtr2, int32_t rows1, int32_t cols1, int32_t cols2) {


	for (size_t i = 0; i < rows1; ++i) {
		for (size_t j = 0; j < cols2; ++j) {
			multMtr[i][j] = 0;
			for (size_t k = 0; k < cols1; ++k) {
				multMtr[i][j] += mtr1[i][k] * mtr2[k][j];
			}
		}
	}
}

void TranspositionMatrix(int32_t**& transMtr,int32_t** mtr, int32_t rows, int32_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			transMtr[j][i] = mtr[i][j];
		}
	}
}