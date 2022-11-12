#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(Addressbooks *abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {

        cout << "请输入姓名： ";
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别： " << endl;
        cout << "1----男" << endl;
        cout << "2----女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        cout << "请输入年龄： ";
        int age;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话： ";
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入地址： ";
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;
        //更新通讯录人数
        abs->m_Size++;
        cout << "添加成功！" << endl;
    }
}

void showPerson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前的记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名： " << abs->personArray[i].m_Name << "\t";
            cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄： " << abs->personArray[i].m_Age << "\t";
            cout << "电话： " << abs->personArray[i].m_Phone << "\t";
            cout << "地址： " << abs->personArray[i].m_Addr << endl;
        }
    }
}
//检测联系人是否存在，如果存在返回联系人所在数组中的位置 不存在返回-1
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    //如果遍历结束都没有找到，返回-1
    return -1;
}
void deletePerson(Addressbooks *abs)
{
    cout << "请输入您要删除的联系人：";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
}
void findPerson(Addressbooks *abs)
{
    cout << "请输入您要查找的联系人：";
    string name;
    cin >> name;
    int let = isExist(abs, name);
    if (let != -1)
    {
        cout << "姓名： " << abs->personArray[let].m_Name << "\t";
        cout << "性别： " << (abs->personArray[let].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄： " << abs->personArray[let].m_Age << "\t";
        cout << "电话： " << abs->personArray[let].m_Phone << "\t";
        cout << "地址： " << abs->personArray[let].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}
void modifyPerson(Addressbooks *abs)
{
    cout << "请输入您要修改的联系人：";
    string name;
    cin >> name;
    int let = isExist(abs, name);
    if (let != -1)
    {
        string name;
        cout << "请输入姓名：";
        cin >> name;
        abs->personArray[let].m_Name = name;

        cout << "请输入性别： " << endl;
        cout << "1----男" << endl;
        cout << "2----女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[let].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }
        cout << "请输入年龄： ";
        int age;
        cin >> age;
        abs->personArray[let].m_Age = age;

        cout << "请输入电话： ";
        string phone;
        cin >> phone;
        abs->personArray[let].m_Phone = phone;

        cout << "请输入地址： ";
        string addr;
        cin >> addr;
        abs->personArray[let].m_Addr = addr;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录以清空！" << endl;
}

void showMenu()
{
    cout << endl;
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}
int main()
{
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1: //添加联系人
            addPerson(&abs);
            break;
        case 2: //显示联系人
            showPerson(&abs);
            break;
        case 3: //删除联系人
            deletePerson(&abs);
            break;

        case 4: //查找联系人
            findPerson(&abs);
            break;
        case 5: //修改联系人
            modifyPerson(&abs);
            break;
        case 6: //清空联系人
            cleanPerson(&abs);
            break;
        case 0: //退出通讯录
            cout << "欢迎下次使用！" << endl;
            return 0;
            break;
        }
    }

    return 0;
}