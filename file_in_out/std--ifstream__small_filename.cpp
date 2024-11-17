#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readFiles(const std::vector<std::string>& filenames) {
    for (const auto& filename : filenames) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                // Обработка содержимого файла
            }
            file.close();
        }
    }
}
// https://t.me/easy_c_plus/570
