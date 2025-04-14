#include <iostream>
#ifndef HEADER_H
#define HEADER_H

void CreateMatrix(int32_t**&, int32_t, int32_t);
void DeleteMatrix(int32_t**&, int32_t, int32_t);
void InputSize(int32_t&);
void FillMatrix(int32_t**&, int32_t, int32_t);
void OutputMatrix(int32_t**, int32_t, int32_t);
void MultiplicationMatrix(int32_t**&, int32_t**, int32_t**, int32_t, int32_t, int32_t);
void TranspositionMatrix(int32_t**&, int32_t**, int32_t, int32_t);


#endif 
