#include"head_math.h"
#include <iomanip>
#include <cstdlib>

// ������
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
    cout << "================== ͨѶ¼ ==================\n";
    cout << "1. �����ϵ��\n";
    cout << "2. ��ʾ��ϵ��\n";
    cout << "3. ɾ����ϵ��\n";
    cout << "4. ������ϵ��\n";
    cout << "5. �޸���ϵ��\n";
    cout << "6. �����ϵ��\n";
    cout << "0. �˳�ͨѶ¼\n";
    cout << "===========================================\n";
}

void print_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "ͨѶ¼Ϊ�գ�\n";
        return;
    }

    for (int i = 0; i < add->m_Size; i++)
    {
        cout << "��ţ�" << i << endl;
        cout << "���֣�" << add->personArray[i].name << endl;
        cout << "�绰��" << add->personArray[i].m_Phone << endl;
        cout << "���䣺" << add->personArray[i].m_Age << endl;
        cout << "�Ա�" << (add->personArray[i].m_Sex == man ? "man" : "woman") << endl;
        cout << "��ַ��" << add->personArray[i].m_Addr << endl;
        cout << "--------------------------" << endl;
    }
}

void add_Person(Addressbooks* add)
{
    if (add->m_Size >= 100)
    {
        cout << "ͨѶ¼������\n";
        return;
    }

    int index = add->m_Size;
    cout << "�������֣�";
    cin >> add->personArray[index].name;
    cout << "�����ֻ��ţ�";
    cin >> add->personArray[index].m_Phone;

    while (true)
    {
        cout << "�������䣺";
        cin >> add->personArray[index].m_Age;
        if (add->personArray[index].m_Age > 6 && add->personArray[index].m_Age < 120)
            break;
        cout << "�����������䣬���������룡" << endl;
    }

    while (true)
    {
        int sex_in;
        cout << "�����Ա�(0-woman,1-man)��";
        cin >> sex_in;
        if (sex_in == 0 || sex_in == 1)
        {
            add->personArray[index].m_Sex = (Sex)sex_in;
            break;
        }
        cout << "����������������룡" << endl;
    }

    cout << "�����ַ��";
    cin >> add->personArray[index].m_Addr;

    add->m_Size++;
    cout << "��ӳɹ�����ǰ������" << add->m_Size << endl;
}

void delete_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "ͨѶ¼Ϊ�գ�" << endl;
        return;
    }

    print_Person(add);
    cout << "����Ҫɾ���ı�ţ�";
    int id;
    cin >> id;
    if (id < 0 || id >= add->m_Size)
    {
        cout << "�������" << endl;
        return;
    }

    for (int i = id; i < add->m_Size - 1; i++)
        add->personArray[i] = add->personArray[i + 1];

    add->m_Size--;
    cout << "ɾ���ɹ���" << endl;
}

void remix_Person(Addressbooks* add)
{
    if (add->m_Size == 0)
    {
        cout << "ͨѶ¼Ϊ�գ�" << endl;
        return;
    }

    print_Person(add);
    cout << "����Ҫ�޸ĵı�ţ�";
    int id;
    cin >> id;
    if (id < 0 || id >= add->m_Size)
    {
        cout << "�������" << endl;
        return;
    }

    cout << "�����µ����֣�";
    cin >> add->personArray[id].name;
    cout << "�����µ��ֻ��ţ�";
    cin >> add->personArray[id].m_Phone;
    cout << "�����µ����䣺";
    cin >> add->personArray[id].m_Age;
    cout << "�����µĵ�ַ��";
    cin >> add->personArray[id].m_Addr;

    while (true)
    {
        int sex_in;
        cout << "�����µ��Ա�(0-woman,1-man)��";
        cin >> sex_in;
        if (sex_in == 0 || sex_in == 1)
        {
            add->personArray[id].m_Sex = (Sex)sex_in;
            break;
        }
        cout << "����������������룡" << endl;
    }

    cout << "�޸ĳɹ���" << endl;
}

void clear_Person(Addressbooks* add)
{
    add->m_Size = 0;
    cout << "�����������ϵ�ˣ�" << endl;
}

int chooseMenu(Addressbooks* book)
{
    int choice;
    cout << "�����������ţ�";
    cin >> choice;

    switch (choice)
    {
    case 1: add_Person(book); break;
    case 2: print_Person(book); break;
    case 3: delete_Person(book); break;
    case 4: print_Person(book); break;
    case 5: remix_Person(book); break;
    case 6: clear_Person(book); break;
    case 0: cout << "�˳�ͨѶ¼��" << endl; break;
    default: cout << "����������������룡" << endl;
    }
    return choice;
}

