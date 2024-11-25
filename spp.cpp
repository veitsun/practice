// #include "include/Harem.h"
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// #include <iostream>
// #include <pthread.h>
// #include <thread>
// #include <unistd.h>
// #include <memory>
// #include <mutex>
// #include <queue>
// #include <functional>
// #include <condition_variable>
// using namespace std;

// class ThreadPoll
// {
// public:
//     ThreadPoll(int numthread):stop(false)
//     {
//         for (int i = 0; i < numthread; i++)
//         {
//             threads.emplace_back([this]{  //threads 是一个容器，emplace_back 就地创造一个thread变量
//                 while (true)   //线程一直执行
//                 {
//                     std::unique_lock<std::mutex> lock(mtx);
//                     cv.wait(lock,[this]{   //不阻塞的条件
//                         return stop || !tasks.empty();  //线程终止 继续向下走
//                     });

//                     if(stop && tasks.empty())
//                     {
//                         return;
//                     }

//                     std::function<void()> task(std::move(tasks.front()));
//                     tasks.pop();
//                     lock.unlock();
//                     task();
//                 }
                
//             });
//         }
        
//     }

//     ~ThreadPoll()
//     {
//         {
//         std::unique_lock<std::mutex> lock(mtx);
//         stop = true;   //标记线程池需要停止
//         }
//         cv.notify_all();  //检查stop

//         for (auto& a :threads)
//         {
        
//                 a.join();  //等待线程运行完结束，否则会有错误

            
//         }

//     }

//     template<class T,class... Args>
//     void enqueue(T&& t , Args&&... args) //万能引用
//     {
//         std::function<void()> task =
//             std::bind(std::forward<T>(t) ,std::forward<Args>(args)...);

//         {
//             std::unique_lock<std::mutex> lock(mtx);
//             tasks.emplace(std::move(task));
//         }

//         cv.notify_one();
//     }

// private:
//     std::vector<std::thread> threads;
//     std::queue<std::function <void()>> tasks;
//     std::mutex mtx;
//     bool stop; //线程池是否停止
//     std::condition_variable cv; //条件变量
// };

// void myswap(int *a,int *b)
// {
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }

// int main()
// {
//     // ThreadPoll threadpoll(4);

//     // for (int i = 0; i < 10; i++)
//     // {
        
//     // }

//     int a[2]={1,2};
//     myswap(&a[1],&a[0]);

//     cout<< a[0]<<endl;
    
//      cout<< a[1]<<endl;
//     return 0;
// }

#include<iostream>
#include<cstdio>
#include "include/CacheFile.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

//   测试带有缓存的文件类

int main()
{
    
    
    // const std::string & filename = "text.txt";

    // CacheFile file(filename,20);

    
    // if(file.openFileForRead())
    // {
    //      cout<<"打开文件成功"<<endl;
    //     // 每次缓存读取bufferSize大小的数据，每次读写时不需要每次都访问磁盘
    //     // 只需要在buffer中获取，
    //     char des[100];
    //     size_t num = file.read(&des[0],10);
    //     size_t num1 = file.read(&des[10],10);
    //     size_t num2 = file.read(&des[20],15);
    
    //     cout<<des<<endl;
    // }
       
  
    // if (file.openFileForWrite())
    // {
    //     char *data = "1234567890";
    
    //     char *data1 = "zhuijiadeshuju";
        
    //     size_t num = file.write(data,10); //先读10字节存起来

    //      size_t num1 = file.write(data1,14); //追加14字节

    //     file.flushBuffer(); //最后刷新缓存内的数据

    //     cout<< "num: "<<num <<endl;
    //     cout<< "num1: "<<num1 <<endl;

    // }
    
    // if (file.openFileForRead())
    // {
    //     char data[100];
    //     std::streampos new_pos =  file.lseek(10,std::ios_base::beg);
    //     file.read(&data[0],10);
    //     cout<<"new_pos: " <<new_pos<<endl;
    //     cout<<data<<endl;
    // }
    

    
    
    return 0;
}
