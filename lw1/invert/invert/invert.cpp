#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
using namespace std;

// объявить тип данных матрицы
// про ссылки посмотреть &, && 
// открывать файлы в функции
float FindMatrixOpredelitel(array<array<float, 3>, 3>& matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][1] * matrix[1][0] * matrix[2][2] -
		matrix[0][0] * matrix[1][2] * matrix[2][1];
}

array<array<float, 3>, 3> FindInvertMatrix(array<array<float, 3>, 3>& matrix, float matrixOpredelitel)
{// искать определитель здесь
	// посмотреть про optional и завернуть в него вывод если определитель = 0
	array<array<float, 3>, 3> invertMatrix;
	invertMatrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) / matrixOpredelitel;
	invertMatrix[1][0] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) / matrixOpredelitel;
	invertMatrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) / matrixOpredelitel;
	invertMatrix[0][1] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]) / matrixOpredelitel;
	invertMatrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) / matrixOpredelitel;
	invertMatrix[2][1] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]) / matrixOpredelitel;
	invertMatrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) / matrixOpredelitel;
	invertMatrix[1][2] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]) / matrixOpredelitel;
	invertMatrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) / matrixOpredelitel;
	return invertMatrix;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "There are no name of input file." << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		cout << "Can`t open input file" << endl;
		return 1;
	}

	array<array<float, 3>, 3> matrix;
	for (int i = 0; i < 3; ++i)
		inputFile >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
	inputFile.close();



	float matrixOpredelitel = FindMatrixOpredelitel(matrix);
	if (matrixOpredelitel == 0)
	{
		cout << "There is no inverse matrix" << endl;
		return 1;
	}
	array<array<float, 3>, 3> invertMatrix = FindInvertMatrix(matrix, matrixOpredelitel);


	for (int i = 0; i < 3; ++i)
	{
		printf("%.3f %.3f %.3f", invertMatrix[i][0], invertMatrix[i][1], invertMatrix[i][2]);
		cout << endl;
	}
	return 0;
}