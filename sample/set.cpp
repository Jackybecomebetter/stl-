#include <string>
#include <set>
#include <string.h>
#include <iterator>
#include<iostream>

using namespace std;

struct strLess{
    bool operator() (const char *s1, const char *s2) const{
        return strcmp(s1,s2) < 0;
    };
};

void printSet(set<int> s)
{
    // copy(s.begin(),s.end(),ostream_iterator<int>(cout, ",  "));
    
    set<int>::iterator iter;
    for(iter = s.begin(); iter !=s.end(); iter++)
        cout << *iter << ", ";
        // cout << "set[" << iter - s.begin() << "]="  << *iter << ",  ";
    // cout << *iter << ", ";
    cout << endl;
}

int main()
{
    set<int> s1;    //创建空的set对象，类型为int
    set<const char*,strLess> s2(strLess);   //创建空的set对象，元素类型为char×，比较函数为自动以的strless
    set<int> s3(s1);    //创建set对象s3，是由s1拷贝构造生成的

    int array[] = {13,34,52};
    set<int> s4(array,array+3); //前闭后开

    const char * szArray[] = {"hello", "dog", "bird"};
    set<const char* , strLess> s5(szArray,szArray+3, strLess());

    //元素插入
    for(int i=0; i<5; i++)
    {
        s1.insert(i*10);
    }
    printSet(s1);

    cout << "s1.insert(20).second = " << endl;
    // 不能插入重复的key值，所以插入失败
    if(s1.insert(20).second)    //insert之后，通过second判断是否插入ok
        cout << "insert scuess" << endl;
    else
    {
        cout << "insert failed" << endl;
    }
    
    //通过cout判断插入是否成功
    pair<set<int>::iterator, bool> p;
    p = s1.insert(60);
    if(p.second)
    {
        cout << "insert scuess" << endl;
        printSet(s1);
    }
    else
    {
        cout << "insert failed" << endl;
    }

    // 元素删除
    s1.erase(60);
    printSet(s1);

    set<int>::iterator iter = s1.begin();
    s1.erase(iter);
    printSet(s1);

    // 元素查找
    if(s1.find(10) != s1.end())
        cout << "find 10" << endl;
    else
    {
        cout << "can not find 10" << endl;
    }

    // 其他常用函数
    set<int> s9;
    s9.insert(1000);
    s1.swap(s9);    //交换s1和s9种容器的元素
    cout << "s1 = "<< endl;
    printSet(s1);
    cout << "s9 = " << endl;
    printSet(s9);
    return 0;
    
}