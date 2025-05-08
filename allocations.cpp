#include <vector>
#include <cstdlib>

void allocations(){
    std::vector<char*> allocations;
    const size_t blockSize = 1024 * 1024 * 10;
    
    while(true){
        char* block = new char[blockSize];
        std::fill(block, block + blockSize, 0);
        allocations.push_back(block);
    }
}

int main(){
    allocations();
}