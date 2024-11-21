#include <iostream>
#include <string>
#include <vector>
#include <curses.h>
// https://t.me/easy_c_plus/376

 

int main() {
 
    std::vector makeVector = {34,34,34,4,34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334};
    
//    for (int i=0; i<makeVector.size(); i++)
//        std::cout << makeVector.at(i) << " ";

    auto start_time = std::chrono::high_resolution_clock::now();

        int sizeVec = makeVector.size();
        for (int i=0; i<sizeVec; i++)
            makeVector.pop_back();
    
    uint64_t final_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                       std::chrono::high_resolution_clock::now()-start_time).count();
    std::cout << "\n" << "makeVector.pop_bac=" << final_time / sizeVec << "\n";
 
    
    // NEW TEST makeVector.pop_back();
    {
        std::vector makeVector = {34,34,34,4,34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
            34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334
        };
        
//        for (int i=0; i<makeVector.size(); i++)
//            std::cout << makeVector.at(i) << " ";

        auto start_time = std::chrono::high_resolution_clock::now();

            int sizeVec = makeVector.size();
            for (int i=0; i<sizeVec; i++)
                makeVector.pop_back();
        
        uint64_t final_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                           std::chrono::high_resolution_clock::now()-start_time).count();
        std::cout << "\n" << sizeVec<< " makeVector.pop_bac=" << final_time / sizeVec << "\n";
        
    }
    
        // NEW TEST makeVector.pop_back();
        {
            std::vector makeVector = {34,34,34,4,34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334,
                34,4,43,5,5,4,53,4,44,24,243,23,23,32,23,334
            };
            
    //        for (int i=0; i<makeVector.size(); i++)
    //            std::cout << makeVector.at(i) << " ";

            auto start_time = std::chrono::high_resolution_clock::now();

                int sizeVec = makeVector.size();
                for (int i=0; i<sizeVec; i++)
                    makeVector.push_back(3);
            
            uint64_t final_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                               std::chrono::high_resolution_clock::now()-start_time).count();
            std::cout << "\n" << sizeVec<< " makeVector.push_back(3)=" << final_time / sizeVec << "\n";
            
            {
                auto start_time = std::chrono::high_resolution_clock::now();

                    int sizeVec = makeVector.size();
                    for (int i=0; i<sizeVec; i++)
                        makeVector.pop_back();
                
                uint64_t final_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
                                   std::chrono::high_resolution_clock::now()-start_time).count();
                std::cout << "\n" << sizeVec<< " makeVector.pop_bac=" << final_time / sizeVec << "\n";
            }
            
        }
    
    // Операция push_back в std::vector имеет амортизированную временную сложность \(O(1)\). Хотя перевыделение памяти может занять \(O(n)\) времени, это происходит редко. В среднем добавление элемента занимает постоянное время благодаря экспоненциальному увеличению емкости вектора.
    
    return 0;
}

