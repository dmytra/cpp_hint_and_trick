#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>
#include <mutex>
#include <string>
#include <map>

// compile $c++ -std=c++11 name_file.cpp
//
// https://www.linkedin.com/posts/naser-rezayi-89774723b_cplusplus-cpp-threading-activity-7253490236586946561-Wct9/?utm_source=share&utm_medium=member_desktop
//
/*
This program organizes files 📁
 in a specified directory into subfolders based on their file extensions. It uses multithreading to handle different file types in parallel, improving performance. It supports organizing pictures, videos, music, documents, and other files into specific folders.
It's a good example of threadpooling also!
 * /

const std::string PICTURES_FOLDER = "Pictures";
const std::string VIDEOS_FOLDER = "Videos";
const std::string MUSIC_FOLDER = "Music";
const std::string DOCUMENTS_FOLDER = "Documents";
const std::string OTHERS_FOLDER = "Others";

std::mutex mtx;

void printHelp() {
    std::cout << "Usage: organizer <directory_path>\n";
    std::cout << "Organizes files in the specified directory into subfotders based on file type.\n";
    std::cout << "\nExample:\n";
    std::cout << " organizer C:/Users/YourName/Downloads\n";
}

void organizeByExtension(const std::__fs::filesystem::path& sourceDir, const std::string&
    folderName, const std::vector<std::string>& extensions) {
        std::__fs::filesystem::path targetDir = sourceDir / folderName;
        std::__fs::filesystem::create_directory(targetDir);

    for (const auto& file : std::__fs::filesystem::directory_iterator(sourceDir)) {
        if (file.is_regular_file()) {
            std::string ext = file.path().extension().string();
            if (std::find(extensions.begin(), extensions.end(), ext) != extensions.end())
            {
                std::lock_guard<std::mutex> lock(mtx);
                std::__fs::filesystem::rename(file.path(), targetDir / file.path().filename());
            }
        }
    }
}
    
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printHelp();
        return 1;
    }

    std::__fs::filesystem::path sourceDir(argv[1]);
    
    if (!std::__fs::filesystem::exists(sourceDir) || !std::__fs::filesystem::is_directory(sourceDir))
    {
        std::cerr << "Error: Directory does not exist or is not accessible.\n";
        return 1;
    }
    
    std::vector<std::thread> threads;
    
threads.emplace_back(organizeByExtension, sourceDir, PICTURES_FOLDER,
 std::vector<std::string>{".jpg", ".jpeg", ".png", ".bmp", ".gif", ".tiff", ".svg"});
threads.emplace_back(organizeByExtension, sourceDir, VIDEOS_FOLDER,
 std::vector<std::string>{".mp4", ".avi", ".mkv", ".mov", ".flv", ".wmv", ".mpeg"});
threads.emplace_back(organizeByExtension, sourceDir, MUSIC_FOLDER,
 std::vector<std::string>{".mp3", ".wav", ".flac", ".aac", ".ogg", ".m4a"});
threads.emplace_back(organizeByExtension, sourceDir, DOCUMENTS_FOLDER,
 std::vector<std::string>{".pdf", ".doc", ".docx", ".xis", ".xlsx", ".ppt", ".pptx", ".txt", ".odt", ".rtf"});
threads.emplace_back(organizeByExtension, sourceDir, OTHERS_FOLDER,
 std::vector<std::string>{});
    
for (auto& t : threads) {
    t.join();
}
    
std::cout << "Files organized successfully.\n";
    return 0;

}
