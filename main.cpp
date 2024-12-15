#include "Lab5.h"
#include <clocale>
#include <vector>

int main() {

  std::cout << "задание 1\n";

  WorkFile::RandomFillFile("gg.bin", 10, 1, 9);
  WorkFile::CopyFile("gg.bin", "Lox.bin", 2);
  std::cout << "Все элементы созданного файла: ";
  WorkFile::ViewFile("gg.bin");
  std::cout << "Элементы файла кратные k: ";
  WorkFile::ViewFile("Lox.bin");
  std::cout << '\n';

  std::cout << "задание 2\n";

  int k = 4;
  WorkFile::RandomFillFile("matrix.bin", k * k, 1, 12);
  std::vector<std::vector<int>> arr = WorkFile::ReadMatrix("matrix.bin", k);
  std::cout << "Изначальная матрица: \n";
  WorkFile::ViewMatrix(arr);
  WorkFile::ReplaceColumns(arr);
  std::cout << "Матрица после замены столбцов: \n";
  WorkFile::ViewMatrix(arr);

  /*
  std::cout << "задание 3\n";

  std::vector<Toy> toys = {{"конструктор", "набор инженера", 150, 1, 20},
                           {"конструктор", "набор сварщика", 160, 5, 19},
                           {"машинка", "Хот вилс гелик", 150500230, 51, 99}};
  int count = 3;
  WorkFile::CreateToyFile("toy.bin", toys);
  std::cout << "aboba\n";
  std::cout << WorkFile::FindExpensiveKit("toy.bin");
  */

  std::cout << "задание 4\n";
  WorkFile::RandomFillFileTXT("out.txt", 20, 1, 20);
  std::cout << "Сумма элементов файла равных индексу равна: "
            << WorkFile::SumNumFileTXT("out.txt") << '\n';

  std::cout << "задание 5\n";
  k = 3;
  WorkFile::RandomFillFileTXTLines("out_line.txt", 20, 1, 10, k);
  std::cout << "Произведение элементов кратных " << k << " ^ "
            << WorkFile::ProductNumbersTXT("out_line.txt", 3) << '\n';

  setlocale(LC_ALL, "Russian");
  WorkFile::NoRussianText("tt.txt", "no_rus.txt");
  return 0;
}
