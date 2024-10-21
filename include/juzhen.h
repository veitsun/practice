#ifndef JUZHEN_H
#define JUZHEN_H

class Juzhen
{

public:
    Juzhen(int n);
    void Initjuzhen();
    void show();
    
    ~Juzhen();
private:
    int n; //阶数
    int *a;   //指向一维数组
};


#endif