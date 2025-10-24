#include"head_math.h"

int main()
{
    Addressbooks m_book = {};
    int choice = -1;

    do
    {
        showMenu();
        choice = chooseMenu(&m_book);
        sort_book(&m_book);
        if (choice != 0)
        {
            system("pause");
            system("cls");
        }
    } while (choice != 0);

    return 0;
}


