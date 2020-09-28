#include <random>
#include <ctime>
#include "src/Models/Classifiers/NeuralNetwork.h"
#include "src/Models/Classifiers/NeuralNetwork.cpp"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"

#define LINE std::cout << "===========================================" << std::endl;

int main()
{
    srand(time(NULL));

    CSVReader<double> reader;
    CSV<double> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_test.csv");

    Matrix<double>* xData = Matrix<double>::Create(csv.dataSize, csv.featureCount);
    xData->matrix = csv.dataMatrix;

    std::vector<int> topology = {784, 128, 64, 10};
    NeuralNetwork<double> network(topology, 10, 0.0001);

    auto res = network.FeedForward(xData->SliceRowAsCol(123));

    for (int i = 0; i < xData->rows; i++)
    {
        for(int j = 0; j < xData->cols; j++)
        {
            std::cout << xData->At(i, j) << " ";
        }
        std::cout << "\n\n\n\n\n\n";
    }


    return 0;
}
