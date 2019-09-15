#include <string>
#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct rect{
    int id;
    int length;
    int width;
}Rect;

int cmp(Rect a,Rect b)
{
    if(a.id  != b.id)
        return a.id < b.id;
    else
    {
        if(a.length < b.length)
            return a.length < b.length;
        else
        {
            return a.width < b.width;
        }
        
    }
    
}

void print(int n)
{
    cout << n;
}

int main()
{
    // // vector的初始化和遍历
    // int a[7] = {1,2,3,4,5,6,7};
    // vector<int> ivector(a,a+7); //前开后闭
    // vector<int>::iterator iter;

    // //最常用的遍历方法
    // for(iter=ivector.begin();iter!=ivector.end();iter++)
    // {
    //     cout << *iter;
    // }
    // ivector[5] = 0; //vector是动态数组，所以可以直接进行数组操作
    // cout << ivector[5] << endl;
    // cout << ivector.size() << endl;
    // for(int i=0;i <=6; i++)
    //     cout << ivector[i] ;
    // cout << endl;

    // //比较好用的for_each遍历
    // for_each(ivector.begin(),ivector.end(),print);
    // cout <<endl;

    // 容器存放结构体，并且按照自己想要的方式进行排序
    // typedef struct rect{
    //     int id;
    //     int length;
    //     int width;
    //     // 在struct里面重载操作符，例如小于号，把你想要比较的直接赋值true就行
    //     // 然后后面用sort对容器进行排序即可
    //     bool operator < (const rect&a) const{
    //         if(id != a.id)
    //             return id < a.id;
    //         else
    //         {
    //             if(length != a.length)
    //                 return length < a.length;
    //             else
    //             {
    //                 return width < a.width;
    //             }
                
    //         }
            
    //     }
    // }Rect;
    // vector<Rect> vec;
    // Rect rect;
    // rect.id = 2;
    // rect.length = 3;
    // rect.width = 4;
    // vec.push_back(rect);
    // rect.id = 1;
    // rect.length = 2;
    // rect.width = 3;
    // vec.push_back(rect);
    // vector<Rect>::iterator iter = vec.begin();
    // cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;
    // sort(vec.begin(),vec.end());    //这里根据前面重载的操作符进行排序
    // cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;

    // // 设置一个结构体外的函数排序
    // // 容器存放结构体，并且按照自己想要的方式进行排序
    // vector<Rect> vec;
    // Rect rect;
    // rect.id = 2;
    // rect.length = 3;
    // rect.width = 4;
    // vec.push_back(rect);
    // rect.id = 1;
    // rect.length = 2;
    // rect.width = 3;
    // vec.push_back(rect);
    // vector<Rect>::iterator iter = vec.begin();
    // cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;
    // sort(vec.begin(),vec.end(),cmp);    //这里根据前面重载的操作符进行排序
    // cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;

    // vector的查找
    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);
    // vector<int>::iterator iter = find(vec.begin(),vec.end(),3);
    // if(iter == vec.end())
    //     cout << "not found " << 3;
    // else
    // {
    //     cout << "fount 3" << endl;
    // }

    // vector的删除
    // erase 删除某个位置的元素
    // pop_back删除最后一个元素
    // 使用erase删除掉某个元素
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vector<int>::iterator iter;
    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter ;
    cout << endl;
    for(iter = vec.begin(); iter != vec.end(); )
    {
        if(*iter == 3)
            iter = vec.erase(iter); //删除之后，指向下一个元素
        else
        {
            iter++;
        }
    }
    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter ;
    cout << endl;

    int values[] = {1,3,5,7};
    vector<int> v;
    v.insert(v.end(),values+1,values+3);    //插入3,5
    v.push_back(9); //容器中有 3,5,9
    v.erase(v.begin()+1);   //删除5，还有3,9
    v.insert(v.end()-1,4,6);    //在最后一个元素之前插入4个6，现在容器种有3,6,6,6,6,9
    v.erase(v.begin(),v.begin()+2); //删除3,6,9，  现在容器种还有6,6,9
    v.clear();  //清除所有元素，容器为空

    //提高使用容器效率的技巧
    //使用reverse提前设置好容器的大小，可以提前避免因为容器动态扩充带来的时间消耗
    vector<int> v;
    v.reserve(1000);
    for(int i=0;i < 1000;i++)
        v.push_back(i);
    

    return 0;
}