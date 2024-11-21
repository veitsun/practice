#ifndef CACHEFILE_H
#define CACHEFILE_H
#include<iostream>
#include<cstdio>
#include<random>
#include <fstream>
#include <vector>


using namespace std;

// 任务:编写一个带缓存的文件操作类
// 从执行体程序库中的CLLogger类可知，通过缓存要写入文件中的数据，能够提高读写磁盘的性能
// 其要求如下:
// 需要提供open/read/write/lseek/close等函数的封装函数

// 该类要提供数据缓存服务:
// 调用该类的写操作接口时，数据要首先写到缓存，然后再根据策略写到文件中。
// 调用该类的读操作接口时，该类能根据策略缓存读出的数据
class CacheFile
{
public:
    CacheFile(const std::string &file, size_t buffersize ): fileName(file),bufferSize(buffersize),buffer_Position(0){
        buffer.resize(buffersize);
    }

    // 打开读文件
    bool openFileForRead();
    // 打开写文件
    bool openFileForWrite();

    //read操作
    size_t read(char* destination , size_t size);


    // 在写入文件，缓存先暂存要写入的数据，待缓存达到一定量（如达到设定的缓存阈值大小）时，
    // 再一次性将缓存中的数据写入磁盘，相较于每次产生少量数据就立刻写入磁盘，减少了磁盘写入的次数，
    // 从而提高整体写入效率。因为磁盘写入操作本身相对耗时，批量写入能够更充分利用磁盘写入的带宽等资源
    // 只有在特定时候（如手动保存、定时自动保存等情况）才将缓存数据写入磁盘
    //write操作  
    size_t write(char* data, size_t numbytes);

    //lseek操作 offset:偏移量 whence:什么方式进行偏移
    std::streampos lseek(std::streampos offset , std::ios_base::seek_dir whence);


    //手动保存缓冲区数据到文件中
    void flushBuffer();

   
   
    

private:

    std::ifstream inputfile;    //用于读取文件的输入流
    std::ofstream outputfile;   //用于写入文件的输出流
    std::vector<char> buffer;   //缓冲区
    size_t bufferSize;          //缓冲区大小
    size_t buffer_Position;     //当前在缓冲区的位置
    std::string fileName;       //文件名字
    
};
   
#endif