#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
int main() {
    std::ofstream file("text",ios::out);
    file.write("wewedfewfe",10);

    return 0;
}