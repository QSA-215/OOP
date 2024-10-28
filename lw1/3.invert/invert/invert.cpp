#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

typedef array<array<float, 3>, 3> matrixType;

// посмотреть про optional и завернуть в него вывод если определитель = 0
float FindMatrixOpredelitel(matrixType matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][1] * matrix[1][0] * matrix[2][2] -
		matrix[0][0] * matrix[1][2] * matrix[2][1];
}

matrixType FindInvertMatrix(matrixType matrix)
{
	float matrixOpredelitel = FindMatrixOpredelitel(matrix);

	if (matrixOpredelitel == 0)
	{
		cout << "There is no inverse matrix" << endl;
		exit(1);
	}

	matrixType invertMatrix;
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

void OpenFilesWithAction(string inputFileName)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Can`t open input file" << endl;
		exit(1);
	}

	matrixType matrix;
	for (int i = 0; i < 3; ++i)
		inputFile >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
	inputFile.close();

	matrixType invertMatrix = FindInvertMatrix(matrix);

	for (int i = 0; i < 3; ++i)
	{
		printf("%.3f %.3f %.3f", invertMatrix[i][0], invertMatrix[i][1], invertMatrix[i][2]);
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "There are no name of input file." << endl;
		return 1;
	}

	OpenFilesWithAction(argv[1]);

	return 0;
}