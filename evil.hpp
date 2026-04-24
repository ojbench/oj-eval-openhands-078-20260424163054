#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    //构造函数
    Evil(int s = 0, int e = 0, int v = 0) : st(s), ed(e), val(v) {
        if (st <= ed) {
            data = new int[ed - st + 1];
            for (int i = 0; i < ed - st + 1; ++i) {
                data[i] = 0;
            }
        } else {
            data = new int[1];
            data[0] = 0;
        }
    }
    
    //拷贝构造函数（用于赋值运算符）
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        if (st <= ed) {
            data = new int[ed - st + 1];
            for (int i = 0; i < ed - st + 1; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = new int[1];
            data[0] = other.data[0];
        }
    }
    
    //下标运算符重载
    int& operator[](int i) {
        if (i >= st && i <= ed) {
            return data[i - st];
        } else {
            return data[0];
        }
    }
    
    //赋值运算符重载
    Evil& operator=(const Evil& other) {
        if (this != &other) {
            //释放原有内存
            delete[] data;
            
            //复制基本成员
            st = other.st;
            ed = other.ed;
            val = other.val;
            
            //分配新内存并复制数据
            if (st <= ed) {
                data = new int[ed - st + 1];
                for (int i = 0; i < ed - st + 1; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                data = new int[1];
                data[0] = other.data[0];
            }
        }
        return *this;
    }
    
    //前缀++重载
    Evil& operator++() {
        val++;
        return *this;
    }
    
    //后缀++重载
    Evil operator++(int) {
        Evil temp = *this;
        val++;
        return temp;
    }
    
    //输出重载
    friend ostream& operator<<(ostream& os, const Evil& evil) {
        os << evil.val << " ";
        for (int i = 0; i < evil.ed - evil.st + 1; ++i) {
            os << evil.data[i] << " ";
        }
        os << endl;
        return os;
    }
    
    //析构函数
    ~Evil() {
        delete[] data;
    }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif//EVIL_HPP