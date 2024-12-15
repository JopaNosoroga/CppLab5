#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Toy {
  char type[32] = "type";
  char name[32] = "name";
  int price = 1;
  int min_age = 0;
  int max_age = 99;
};

class WorkFile {
public:
  static void RandomFillFile(const std::string &filename, int count,
                             int minimal_number, int maximum_number) {

    if (minimal_number > maximum_number) {
      minimal_number = 1;
      maximum_number = 9;
    }
    if (count <= 0)
      count = 10;

    std::ofstream file(filename, std::ios::binary);

    static bool flag = false;
    if (!flag) {
      std::srand(static_cast<unsigned int>(std::time(0)));
      flag = true;
    }

    for (int i = 0; i < count; i++) {
      int random =
          (minimal_number) + (rand() % (maximum_number - minimal_number + 1));
      // std::cout << random << ' ';
      file.write(reinterpret_cast<char *>(&random), sizeof(int));
    }
    std::cout << '\n';
    file.close();
  }

  static void CopyFile(const std::string &input_file,
                       const std::string &output_file, int k) {
    std::ifstream input(input_file, std::ios::binary);
    std::ofstream output(output_file, std::ios::binary);

    int num;
    while (input.read(reinterpret_cast<char *>(&num), sizeof(int))) {
      // std::cout << num << ' ';
      if (num % k == 0)
        output.write(reinterpret_cast<char *>(&num), sizeof(int));
    }
    // std::cout << "\n";
    input.close();
    output.close();
  }

  static void ViewFile(const std::string &input_file) {
    std::ifstream input(input_file, std::ios::binary);

    int num;
    while (input.read(reinterpret_cast<char *>(&num), sizeof(int)))
      std::cout << num << ' ';
    input.close();
    std::cout << '\n' << '\n';
  }

  static std::vector<std::vector<int>> ReadMatrix(const std::string &input_file,
                                                  int k) {
    std::ifstream input(input_file, std::ios::binary);
    std::vector<std::vector<int>> arr(k, std::vector<int>(k, 0));
    int num;
    int count = 0;
    while (input.read(reinterpret_cast<char *>(&num), sizeof(int)) &&
           count < k * k) {
      arr[count / k][count % k] = num;
      count++;
    }
    input.close();
    return arr;
  }

  static void ReplaceColumns(std::vector<std::vector<int>> &arr) {
    int k = arr.size();
    if (!k)
      return;
    int ind, min_sum;

    for (int i = 0; i < k; i++) {
      int sum = 0;

      for (int j = 0; j < k; j++) {
        sum += arr[j][i];
      }

      if (!i) {
        min_sum = sum;
        ind = 0;
      }
      if (sum < min_sum) {
        min_sum = sum;
        ind = i;
      }
    }

    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        arr[j][i] = arr[j][ind];
  }

  static void ViewMatrix(std::vector<std::vector<int>> &arr) {
    for (const auto &row : arr) {
      for (int num : row)
        std::cout << num << ' ';
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  static void CreateToyFile(const std::string &output_file,
                            const std::vector<Toy> &toys) {
    std::ofstream output(output_file, std::ios::binary);
    std::cout << "Maksdmwpoefvwe";
    for (const Toy &toy : toys) {
      std::cout << "acsdfc";
      output.write(reinterpret_cast<const char *>(-2), sizeof(int));
      output.write(toy.type, sizeof(toy.type));
      output.write(toy.name, sizeof(toy.name));
      output.write(reinterpret_cast<const char *>(&toy.price), sizeof(int));
      output.write(reinterpret_cast<const char *>(&toy.min_age), sizeof(int));
      output.write(reinterpret_cast<const char *>(&toy.max_age), sizeof(int));
    }
    output.write(reinterpret_cast<const char *>(-1), sizeof(int));
    output.close();
  }

  static int FindExpensiveKit(const std::string &input_file) {
    std::ifstream input(input_file, std::ios::binary);
    int max_price = 0;
    Toy toy;
    int num = 0;
    input.read(reinterpret_cast<char *>(&num), sizeof(int));
    while (num != -1) {
      input.read(toy.type, sizeof(char) * 32);
      input.read(toy.name, sizeof(char) * 32);
      input.read(reinterpret_cast<char *>(toy.price), sizeof(int));
      input.read(reinterpret_cast<char *>(toy.min_age), sizeof(int));
      input.read(reinterpret_cast<char *>(toy.max_age), sizeof(int));
      if (toy.price > max_price)
        max_price = toy.price;
      input.read(reinterpret_cast<char *>(num), sizeof(int));
    }

    return max_price;
  }

  static void RandomFillFileTXT(const std::string &output_file, int count,
                                int minimal_number, int maximum_number) {
    std::ofstream output(output_file);

    static bool flag = false;
    if (!flag) {
      std::srand(static_cast<unsigned int>(std::time(0)));
      flag = true;
    }

    for (int i = 0; i < count; i++) {
      output << minimal_number +
                    (rand() % (maximum_number - minimal_number + 1))
             << '\n';
    }
    output.close();
  }

  static long long SumNumFileTXT(const std::string &input_file) {
    std::ifstream input(input_file);
    long long sum = 0;
    int num, i;
    i = 0;
    while (input >> num) {
      if (num == i)
        sum += num;
      i++;
    }
    input.close();
    return sum;
  }

  static void RandomFillFileTXTLines(const std::string &output_file, int count,
                                     int minimal_number, int maximum_number,
                                     int columns_count) {
    std::ofstream output(output_file);

    static bool flag = false;
    if (!flag) {
      std::srand(static_cast<unsigned int>(std::time(0)));
      flag = true;
    }

    for (int i = 0; i < count; i++)
      for (int j = 0; j < columns_count; j++) {
        output << minimal_number +
                      (rand() % (maximum_number - minimal_number + 1));
        if (j != columns_count - 1)
          output << ' ';
      }
    output << '\n';
    output.close();
  }

  static long long ProductNumbersTXT(const std::string &input_file, int k) {
    std::ifstream input(input_file);

    long long product = 1;
    std::string line;
    while (std::getline(input, line)) {
      std::stringstream str_stream(line);
      int num;
      while (str_stream >> num) {
        if (num % k == 0) {
          product *= num;
        }
      }
    }
    input.close();
    return product;
  }
  static void NoRussianText(const std::string &input_file,
                            const std::string &output_file) {
    std::ifstream input(input_file);
    std::ofstream output(output_file);
    char RUS[] = "йцукенгшщзхъэждлорпавыфячсмитьбю";
    std::string line;
    while (std::getline(input, line)) {
      std::stringstream str_stream(line);
      std::string new_line = "";
      std::string temp;
      bool flag = true;
      while (str_stream >> temp) {
        for (int i = 0; i < temp.size(); i++) {
          if (std::strchr(RUS, char(temp[i]))) {
            flag = false;
            break;
          }
        }
        if (flag)
          new_line += " " + temp;
        else
          break;
      }
      if (flag)
        output << new_line << '\n';
    }
    input.close();
    output.close();
  }
};
