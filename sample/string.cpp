#include <string>
#include <iostream>
#include<string.h>
#include<vector>

using namespace std;

int main()
{
    /*   string的声明和初始化   */
    // string str1 = "spend all your time waiting";    //直接用常量字符串赋值
    // string str2 = "for that second chance";     
    // string str3(str1,6);    //str1的第六个到最后一个进行初始化赋值
    // string str4(str1,6,3);  //str1的第六个开始，选择三个字符进行初始化赋值

    // char ch_musix[] = "sarah mclachlan";
    // char *love = "i love you";
    // string str5 = ch_musix;     // 直接用字符串数组名进行初始化赋值
    // string str6 = love;     //直接用字符串常量指针赋值

    // cout << "str1: " << str1 << endl;
    // cout << "str2: " << str2 << endl;
    // cout << "str3: " << str3 << endl;
    // cout << "str4: " << str4 << endl;
    // cout << "str5: " << str5 << endl;
    // cout << "str6: " << str6 << endl;

    // /*   string转化为char×   */
    // char *cstr = new char[20];
    // string str = "hello world";
    // strncpy(cstr,str.c_str(),str.size());
    // cout << cstr << endl;

    //string 转化为int、long、float、double
    // string str1 = "243";
    // int int_str = atoi(str1.c_str());
    // cout << int_str << endl;

    // string str2 = "23.242313";
    // double double_str = atof(str2.c_str());
    // cout << double_str << endl;

    // string str3 = "13232312";
    // long long_str = atol(str3.c_str());
    // cout << long_str << endl;

    // 把int long doubel float转化为string
    // int int_str = 2323;
    // long long_str = 232323;
    // float float_str = 1323.231;
    // double double_str = 2334.1323;
    // string str = to_string(int_str);
    // cout << str << endl;
    // str = to_string(long_str);
    // cout << str << endl;
    // str = to_string(float_str);
    // cout << str << endl;
    // str = to_string(double_str);
    // cout << str << endl;
    
    return 0;
}