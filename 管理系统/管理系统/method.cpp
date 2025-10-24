#include"head_math.h"
#include <iomanip>
#include <cstdlib>

// 排序函数
void sort_book(Addressbooks* add)
{
    for (int i = 0; i < add->m_Size - 1; i++)
    {
        for (int k = 0; k < add->m_Size - i - 1; k++)
        {
            if (add->personArray[k].m_Age > add->personArray[k + 1].m_Age)
            {
                Person temp = add->personArray[k];
                add->personArray[k] = add->personArray[k + 1];
                add->personArray[k + 1] = temp;
            }
        }
    }
}

void showMenu()
{
    cout << "================== 通讯录 ==================\n";
    cout << "1. 添加联系人\n";
    cout << "2. 显示联系人\n";
    cout << "3. 删除联系人\n";
    cout << "4. 查找联系人\n";
    cout << "5. 修改联系人\n";
    cout << "6. 清空联系人\n";
    cout << "0. 退出通讯录\n";
    cout << "===========================================\n";
}

void print_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "通讯录为空！\n";
        return;
    }

    for (int i = 0; i < add->m_Size; i++)
    {
        cout << "编号：" << i << endl;
        cout << "名字：" << add->personArray[i].name << endl;
        cout << "电话：" << add->personArray[i].m_Phone << endl;
        cout << "年龄：" << add->personArray[i].m_Age << endl;
        cout << "性别：" << (add->personArray[i].m_Sex == man ? "man" : "woman") << endl;
        cout << "地址：" << add->personArray[i].m_Addr << endl;
        cout << "--------------------------" << endl;
    }
}

void add_Person(Addressbooks* add)
{
    if (add->m_Size >= 100)
    {
        cout << "通讯录已满！\n";
        return;
    }

    int index = add->m_Size;
    cout << "输入名字：";
    cin >> add->personArray[index].name;
    cout << "输入手机号：";
    cin >> add->personArray[index].m_Phone;

    while (true)
    {
        cout << "输入年龄：";
        cin >> add->personArray[index].m_Age;
        if (add->personArray[index].m_Age > 6 && add->personArray[index].m_Age < 120)
            break;
        cout << "不正常的年龄，请重新输入！" << endl;
    }

    while (true)
    {
        int sex_in;
        cout << "输入性别(0-woman,1-man)：";
        cin >> sex_in;
        if (sex_in == 0 || sex_in == 1)
        {
            add->personArray[index].m_Sex = (Sex)sex_in;
            break;
        }
        cout << "输入错误，请重新输入！" << endl;
    }

    cout << "输入地址：";
    cin >> add->personArray[index].m_Addr;

    add->m_Size++;
    cout << "添加成功！当前人数：" << add->m_Size << endl;
}

void delete_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "通讯录为空！" << endl;
        return;
    }

    print_Person(add);
    cout << "输入要删除的编号：";
    int id;
    cin >> id;
    if (id < 0 || id >= add->m_Size)
    {
        cout << "输入错误！" << endl;
        return;
    }

    for (int i = id; i < add->m_Size - 1; i++)
        add->personArray[i] = add->personArray[i + 1];

    add->m_Size--;
    cout << "删除成功！" << endl;
}

void remix_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "通讯录为空！" << endl;
        return;
    }

    print_Person(add);
    cout << "输入要修改的编号：";
    int id;
    cin >> id;
    if (id < 0 || id >= add->m_Size)
    {
        cout << "输入错误！" << endl;
        return;
    }

    cout << "输入新的名字：";
    cin >> add->personArray[id].name;
    cout << "输入新的手机号：";
    cin >> add->personArray[id].m_Phone;
    cout << "输入新的年龄：";
    cin >> add->personArray[id].m_Age;
    cout << "输入新的地址：";
    cin >> add->personArray[id].m_Addr;

    while (true)
    {
        int sex_in;
        cout << "输入新的性别(0-woman,1-man)：";
        cin >> sex_in;
        if (sex_in == 0 || sex_in == 1)
        {
            add->personArray[id].m_Sex = (Sex)sex_in;
            break;
        }
        cout << "输入错误，请重新输入！" << endl;
    }

    cout << "修改成功！" << endl;
}

void clear_Person(Addressbooks* add)
{
    add->m_Size = 0;
    cout << "已清空所有联系人！" << endl;
}

int chooseMenu(Addressbooks* book)
{
    int choice;
    cout << "请输入操作编号：";
    cin >> choice;

    switch (choice)
    {
    case 1: add_Person(book); break;
    case 2: print_Person(book); break;
    case 3: delete_Person(book); break;
    case 4: print_Person(book); break;
    case 5: remix_Person(book); break;
    case 6: clear_Person(book); break;
    case 0: cout << "退出通讯录！" << endl; break;
    default: cout << "输入错误，请重新输入！" << endl;
    }
    return choice;
}

