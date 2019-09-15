#include<map>
#include<string>
#include<iostream>

using namespace std;

// 从字符串长度大到小排序，对操作符进行重载
// 这里默认是对key进行排序
struct CompareByLength
{
    bool operator() (const string& x, const string& y) const
    {
        return x.length() < y.length();
    }
};

int main()
{
    // map的插入和迭代器的使用
    // map<int,string> mapstudent;
    // mapstudent.insert(pair<int,string>(1,"student1"));

    // mapstudent.insert(map<int,string>::value_type(2,"student2"));

    // mapstudent[3] = "student3";

    // //从先往后遍历
    // map<int,string>::iterator iter;
    // for(iter=mapstudent.begin(); iter!=mapstudent.end(); iter++)
    // {
    //     cout << iter->first << "\t" << iter->second << endl;
    // }

    // //从后往前反向遍历
    // map<int,string >::reverse_iterator r_iter;
    // for(r_iter=mapstudent.rbegin() ;r_iter!=mapstudent.rend() ;r_iter++)
    //     cout << r_iter->first << "\t" << r_iter->second << endl;

    // //数组方式遍历
    // for(int i=0; i< mapstudent.size() ; i++)
    //     cout << mapstudent[i] << endl;

    // // map查找
    // map<int,string>::iterator iter = mapstudent.find(1);
    // if(iter != mapstudent.end())
    //     cout << "found key 1" << endl;
    // else
    // {
    //     cout << "can not find key 1" << endl;
    // }

    // // map删除，找到某个东东，然后把它删除掉
    // map<int,string>::iterator iter = mapstudent.begin();
    // for(;iter != mapstudent.end(); )
    // {
    //     if(iter->second == "student2")
    //     {
    //         cout << "found student2 and delete it" << endl;
    //         mapstudent.erase(iter++);
    //     }
    //     else
    //     {
    //         cout << iter->first << "\t" << iter->second << endl;
    //         iter++;
    //     }
        
    // }

    // map的排序
    map<string, int, CompareByLength > mapstudent;
    mapstudent["lixing"] = 12;
    mapstudent["jsld"] = 323;
    mapstudent["bob"] = 23;

    map<string,int>::iterator iter;
    for(iter = mapstudent.begin(); iter != mapstudent.end() ; iter++)
        cout << iter->first << "\t" << iter->second << endl;
    

    // 对<号进行重载，完成对map的排序
    typedef struct StudentInfo
    {
        int id;
        string strName;
        // 按照ID进行排序，如果id相等，按照strname进行排序
        bool operator < (StudentInfo const & r) const{
            if(id < r.id)
                return true;
            if(id == r.id)
                return strName.compare(r.strName) < 0;
            return false;
            
        }
    }StudentInfo;

    map<StudentInfo,int> mapstudent;
    StudentInfo student_info;
    student_info.id = 1;
    student_info.strName = "huanglixing";
    mapstudent[student_info] = 90;

    student_info.id = 2;
    student_info.strName = "suyukun"; 
    mapstudent[student_info] = 80;

    map<StudentInfo,int>::iterator iter = mapstudent.begin();
    for(;iter != mapstudent.end(); iter++)
    {
        cout << iter->first.id << "\t" << iter->first.strName << "\t" << iter->second << endl;
    }
}