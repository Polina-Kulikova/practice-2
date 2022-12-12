//Даны 2 числа A и B, количество цифр в которых может достигать 1000.
// Необходимо реализовать операцию сложения и умножения над этими числами.
#include <iostream>
#include <cmath>
#include <string>

int main()
{
    std::string A;
    std::string B;
    std::cin >> A;
    std::cin >> B;
    std::reverse(A.begin(),A.end());//переворачивает строку A
    std::reverse(B.begin(),B.end());//переворачивает строку B
    int mas[10000] = {0};
    std::string MultResult;
    std::string AddResult;
    int a[1000] = {0};
    int b[1000] = {0};
    int c[1000] = {0};

    for (int i = 0; i <A.size(); i++)
        a[i] = int (A[i]) - 48; // строку превращаем в int массив

    for (int i = 0; i <B.size(); i++)
    {
        b[i] = int (B[i]) - 48; // строку превращаем в int массив
        c[i] = int (B[i]) - 48;
    }

    int len = 0;
    if (A.size() > B.size())
        len = A.size() + 1;
    else
        len = B.size() + 1;

    for (int i = 0; i < len; i++)
    {
        c[i] += a[i];
        c[i + 1] += (c[i] / 10);
        c[i] %= 10;
    }
    if (c[len- 1] == 0)
        len = len - 1; //убираем впередистоящий 0 (он получается, если цифры несколько раз переходят в разряды)

    for (int i = 0; i < len; i++)
        AddResult += std::to_string(c[i]);//int превращаем в string

    std::reverse(AddResult.begin(),AddResult.end()); //переворачиваем строку обратно
    std::cout<<"Addition: "<<AddResult<<std::endl;

    int len2 = A.size() + B.size() + 1; //длина преполагаемого результата(т.к. не знаем будет ли длина результата = сумме длин чисел, поэтому берем с запасом(+1))

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B.size(); j++)
            mas[i + j] += a[i] * b[j];

    for (int i = 0; i < len2; i++)
    {
        mas[i + 1] +=  mas[i] / 10;
        mas[i] %= 10;
    }

    while (mas[len2-1] == 0)
        len2 = len2 - 1;

    for (int i = 0; i < len2; i++)
        MultResult += std::to_string(mas[i]);

    std::reverse(MultResult.begin(),MultResult.end()); //переворачиваем строку обратно
    std::cout<<"Multiplication: "<<MultResult<<std::endl;
    return 0;
}