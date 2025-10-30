// 封装一个show_menu的函数，并使用main函数调用他来显示通讯录菜单

#include <iostream>
#include <string>
using namespace std;

// 创建一个结构体（用于储存联系人）
struct Person
{
    string M_name;    // 姓名
    int M_gender;     // 性别：1男，2女
    int M_age;        // 年龄
    string M_number;  // 电话号码
    string M_address; // 住址
};

#define Number 1001
// 创建一个结构体（用于储存通讯录）
struct List
{
    struct Person personarray[Number];
    int M_size; // 记录通讯录中人员个数
};

// case 1
// 添加联系人
void AddPerson(List *abs)
{
    if (abs->M_size == Number)
    {
        cout << "通讯录已满，无法添加！";
    }
    else
    {
        // 姓名
        string name;
        cout << "请输入姓名: ";
        cin >> name;
        abs->personarray[abs->M_size].M_name = name;

        // 性别
        int gender;
        cout << "请输入性别: " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || 2)
            {
                abs->personarray[abs->M_size].M_gender = gender;
                break;
            }
            cout << "输入有误, 请重新输入." << endl;
        }

        // 年龄
        int age;
        cout << "请输入年龄: ";
        cin >> age;
        abs->personarray[abs->M_size].M_age = age;

        // 电话
        string phone_number;
        cout << "请输入电话: ";
        cin >> phone_number;
        abs->personarray[abs->M_size].M_number = phone_number;

        // 住址
        string address;
        cout << "请输入地址: ";
        cin >> address;
        abs->personarray[abs->M_size].M_address = address;

        abs->M_size++;
        cout << "添加成功" << endl;

        system("read -p 'Press Enter to continue...'");
        cin.get();
    }
}

// 封装第二个函数: 显示联系人
void showperson(List *abs)
{
    if (abs->M_size == 0)
    {
        cout << "当前通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->M_size; i++)
        {
            cout << "姓名: " << abs->personarray[i].M_name << "\t";
            cout << "性别: " << (abs->personarray[i].M_gender == 1 ? "男" : "女") << "\t";
            cout << "年龄: " << abs->personarray[i].M_age << "\t";
            cout << "电话: " << abs->personarray[i].M_number << "\t";
            cout << "住址: " << abs->personarray[i].M_address << endl;
        }
    }
    system("read -p 'Press Enter to continue...'");
    cin.get();
    system("clear");
}

// 封装第三个函数: 查找联系人
// 检查联系人是否存在
// 如果存在就返回联系人所在数组中的具体位置
// 如果不存在则返回 -1;
int isExist(List *abs, string name)
{
    for (int i = 0; i < abs->M_size; i++)
    {
        if (abs->personarray[i].M_name == name)
        {
            return i;
        }
    }
    return -1;
}

// 封装第四个函数: 删除联系人
void deleteperson(List *abs)
{
    cout << "请输入要删除的联系人姓名: ";
    string name;
    cin >> name;

    int result = isExist(abs, name);
    if (result == -1)
    {
        cout << "查无此人" << endl;
    }
    else
    {
        for (int i = result; i < abs->M_size; i++)
        {
            abs->personarray[i] = abs->personarray[i + 1];
        }
        abs->M_size--;
        cout << "删除成功" << endl;
    }
    system("read -p 'Press enter to continue...'");
}

// 封装第五个函数: 查找指定联系人信息
void findperson(List *abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    // 判断指定的联系人是否存在
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personarray[ret].M_name << "\t";
        cout << "性别: " << abs->personarray[ret].M_gender << "\t";
        cout << "年龄: " << abs->personarray[ret].M_age << "\t";
        cout << "电话: " << abs->personarray[ret].M_number << "\t";
        cout << "住址: " << abs->personarray[ret].M_address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("read -p 'Press enter to continue...'");
}

// 封装第六个函数: 修改指定联系人在通讯录中的信息
void modifyperson(List *abs)
{
    cout << "请输入您要修改信息的联系人姓名: ";
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != 1)
    {
        // 姓名
        string name;
        cout << "请输入姓名: ";
        cin >> name;
        abs->personarray[ret].M_name = name;

        // 性别
        int gender;
        cout << "请输入性别: " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {
            cin >> gender;
            if (gender == 1 || 2)
            {
                abs->personarray[ret].M_gender = gender;
                break;
            }
            cout << "输入有误, 请重新输入." << endl;
        }

        // 年龄
        int age;
        cout << "请输入年龄: ";
        cin >> age;
        abs->personarray[ret].M_age = age;

        // 电话
        string phone_number;
        cout << "请输入电话: ";
        cin >> phone_number;
        abs->personarray[ret].M_number = phone_number;

        // 住址
        string address;
        cout << "请输入地址: ";
        cin >> address;
        abs->personarray[ret].M_address = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("read -p 'Press enter to continue...'");
}

// 封装第七个函数: 清空通讯录
void cleanperson(List * abs){
    cout << "确定要清空此通讯录吗?" << endl;
    cout << "请输入“2025”以确认执行此操作" << endl;
    int x;
    cin >> x;
    if(x != 2025){
        cout << "操作撤销" << endl;
    }else{
        abs->M_size = 0;
    cout << "通讯录已清空" << endl;
    }
    system("read -p 'Press enter to continue...'");
}
void show_Menu()
{
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "******** 1. 添加联系人 ********" << endl;
    cout << "******** 2. 显示联系人 ********" << endl;
    cout << "******** 3. 删除联系人 ********" << endl;
    cout << "******** 4. 查找联系人 ********" << endl;
    cout << "******** 5. 修改联系人 ********" << endl;
    cout << "******** 6. 清空通讯录 ********" << endl;
    cout << "******** 0. 退出通讯录 ********" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
}

int main()
{
    // 创建通讯录结构体变量
    List abs;
    // 初始化通讯录中当前人员个数
    abs.M_size = 0;

    show_Menu();
    int select = 0;
    while (true)
    {
        cin >> select;

        switch (select)
        {
        case 1: // 添加联系人
            AddPerson(&abs);
            break;
        case 2: // 显示联系人
            showperson(&abs);
            break;
        case 3: // 删除联系人
            deleteperson(&abs);
            break;
        case 4: // 查找联系人
            findperson(&abs);
            break;
        case 5: // 修改联系人
            modifyperson(&abs);
            break;
        case 6: // 清空通讯录
            cleanperson(&abs);
            break;
        default: // 退出通讯录
            cout << "欢迎下次使用" << endl;
            return 0;
        }
        system("clear");
        show_Menu();
    }
}