[TOC]

###  一、为什么用STL

1、c++提供了最原始的new、malloc等函数用于动态分配内存，但我们直接操作这些函数的时候，一不小心就会遇到内存溢出、野指针、内存重复释放、操作空指针、内存回收等问题。stl提供了里面提供了自动内存分配和回收的功能，帮我们绕过了使用指针遇到的坑，同时也可以享受c++的高效

2、stl提供了大量的数据结构操作，例如栈、队列、各种树、哈希表等等，同时也提供了一堆算法，例如排序、查找等等，我们在方便使用stl的时候，同时也可以看看标准的高效地实现这些算法的源代码，从中可以学习到很多很多东西。

### 二、string常见用法

1、string常用的声明和初始化赋值操作

```cpp
    string str1 = "spend all your time waiting";    //直接用常量字符串赋值
    string str2 = "for that second chance";     
    string str3(str1,6);    //str1的第六个到最后一个进行初始化赋值
    string str4(str1,6,3);  //str1的第六个开始，选择三个字符进行初始化赋值

    char ch_musix[] = "sarah mclachlan";
    char *love = "i love you";
    string str5 = ch_musix;     // 直接用字符串数组名进行初始化赋值
    string str6 = love;     //直接用字符串常量指针赋值
```



2、string转化为char*

```cpp
    char *cstr = new char[20];
    string str = "hello world";
    strncpy(cstr,str.c_str(),str.size());
```



3、string转化为int、float、double、long

```
    string str1 = "243";
    int int_str = atoi(str1.c_str());

    string str2 = "23.242313";
    double double_str = atof(str2.c_str());

    string str3 = "13232312";
    long long_str = atol(str3.c_str());
```



4、把int、float、double、long转化为string

```cpp
    int int_str = 2323;
    long long_str = 232323;
    float float_str = 1323.231;
    double double_str = 2334.1323;
    string str = to_string(int_str);
    str = to_string(long_str);
    str = to_string(float_str);
    str = to_string(double_str);
```



5、string其他常用函数

``` cpp
int capacity() const;	// 返回当前容量
int max_size() const;	// 返回string对象种可以存储的最大字符串长度
int size() const;	//返回当前字符串长度
bool empty() const;	//判断当前字符串是否为空
void resize(int len ,char c);	//把当前字符串大小设置为len，并用c补充不足的部分
```



### 三、vector常见用法

1、vector的初始化与遍历

```c++
    // vector的初始化和遍历
    int a[7] = {1,2,3,4,5,6,7};
    vector<int> ivector(a,a+7); //前开后闭
    vector<int>::iterator iter;

    //最常用的遍历方法
    for(iter=ivector.begin();iter!=ivector.end();iter++)
    {
        cout << *iter;
    }
    ivector[5] = 0; //vector是动态数组，所以可以直接进行数组操作
    cout << ivector[5] << endl;
    cout << ivector.size() << endl;
    for(int i=0;i <=6; i++)
        cout << ivector[i] ;
    cout << endl;

    //比较好用的for_each遍历
    for_each(ivector.begin(),ivector.end(),print);
    cout <<endl;
```

2、vector的排序

```c++
    // 自己定义结构体，然后在结构体内对操作符 < 进行重载
	// 然后放入容器种，就能自动排序，按照从小到大的顺序
    // 容器存放结构体，并且按照自己想要的方式进行排序
typedef struct rect{
        int id;
        int length;
        int width;
        // 在struct里面重载操作符，例如小于号，把你想要比较的直接赋值true就行
        // 然后后面用sort对容器进行排序即可
        bool operator < (const rect&a) const{
            if(id != a.id)
                return id < a.id;
            else
            {
                if(length != a.length)
                    return length < a.length;
                else
                {
                    return width < a.width;
                }
                
            }
            
        }
    }Rect;
    vector<Rect> vec;
    Rect rect;
    rect.id = 2;
    rect.length = 3;
    rect.width = 4;
    vec.push_back(rect);
    rect.id = 1;
    rect.length = 2;
    rect.width = 3;
    vec.push_back(rect);
    vector<Rect>::iterator iter = vec.begin();
    cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;
    sort(vec.begin(),vec.end());    //这里根据前面重载的操作符进行排序
    cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;

    // 设置一个结构体外的函数排序
	// 结构体外定义一个cmp函数，用于比较两个结构体对象的大小
	// 然后调用sort对容器进行排序
    // 容器存放结构体，并且按照自己想要的方式进行排序
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

    vector<Rect> vec;
    Rect rect;
    rect.id = 2;
    rect.length = 3;
    rect.width = 4;
    vec.push_back(rect);
    rect.id = 1;
    rect.length = 2;
    rect.width = 3;
    vec.push_back(rect);
    vector<Rect>::iterator iter = vec.begin();
    cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;
    sort(vec.begin(),vec.end(),cmp);    //这里根据前面重载的操作符进行排序
    cout << (*iter).id << "  " << (*iter).length << "  " << (*iter).width << endl;

```

3、vector的查找

```c++
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vector<int>::iterator iter = find(vec.begin(),vec.end(),3);
    if(iter == vec.end())
        cout << "not found " << 3;
    else
    {
        cout << "fount 3" << endl;
    }
```

4、vector删除

```c++
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

```

4、调用reverse避免vector内存不足动态扩充带来的效率的降低

```c++
    //提高使用容器效率的技巧
    //使用reverse提前设置好容器的大小，可以提前避免因为容器动态扩充带来的时间消耗
    vector<int> v;
    v.reserve(1000);
    for(int i=0;i < 1000;i++)
        v.push_back(i);
```



### 四、map常见用法

1、map插入和迭代器的使用

```c++
    // map的插入和迭代器的使用
    map<int,string> mapstudent;
    mapstudent.insert(pair<int,string>(1,"student1"));

    mapstudent.insert(map<int,string>::value_type(2,"student2"));

    mapstudent[3] = "student3";

    //从先往后遍历
    map<int,string>::iterator iter;
    for(iter=mapstudent.begin(); iter!=mapstudent.end(); iter++)
    {
        cout << iter->first << "\t" << iter->second << endl;
    }

    //从后往前反向遍历
    map<int,string >::reverse_iterator r_iter;
    for(r_iter=mapstudent.rbegin() ;r_iter!=mapstudent.rend() ;r_iter++)
        cout << r_iter->first << "\t" << r_iter->second << endl;

    //数组方式遍历
    for(int i=0; i< mapstudent.size() ; i++)
        cout << mapstudent[i] << endl;
```

2、map查找和删除

```c++

    // map查找
    map<int,string>::iterator iter = mapstudent.find(1);
    if(iter != mapstudent.end())
        cout << "found key 1" << endl;
    else
    {
        cout << "can not find key 1" << endl;
    }

    // map删除，找到某个东东，然后把它删除掉
    map<int,string>::iterator iter = mapstudent.begin();
    for(;iter != mapstudent.end(); )
    {
        if(iter->second == "student2")
        {
            cout << "found student2 and delete it" << endl;
            mapstudent.erase(iter++);
        }
        else
        {
            cout << iter->first << "\t" << iter->second << endl;
            iter++;
        }
        
    }

```

3、map的排序

```c++
    // 声明一个结构体，结构体里面对()进行重载
	// 把结构体作为参数，在初始化的时候传入map中
	// 从字符串长度大到小排序，对操作符进行重载
    // 这里默认是对key进行排序
    struct CompareByLength
    {
        bool operator() (const string& x, const string& y) const
        {
            return x.length() < y.length();
        }
    };

    // map的排序
    map<string, int, CompareByLength > mapstudent;
    mapstudent["lixing"] = 12;
    mapstudent["jsld"] = 323;
    mapstudent["bob"] = 23;

    map<string,int>::iterator iter;
    for(iter = mapstudent.begin(); iter != mapstudent.end() ; iter++)
        cout << iter->first << "\t" << iter->second << endl;	


    // 对结构体内对<号进行重载，完成对map的排序
	// 然后使用map容器放入的时候，就会自动从小到大进行排序
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
```



### 五、set常见用法

1、set的初始化的插入

```c++
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
```

2、set元素删除和查找

```c++
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
```





###  