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

    auto res = network.FeedForward(xData->SliceRowAsCol(2));

    for(int i = 0; i < 128; i++)
    {
        std::cout << res["Z1"]->At(0, i) << std::endl;
    }

    return 0;
}
