#include <iostream>
using namespace std;
#include "math.h"
int arrA[15], arrB[15], arrC[15];   // �ֱ�ΪA��B��C
int length;
int count;
int lenA, lenB, lenC;
char plate[32];
// Make
void makeplate(int n)
{
    int i;
    if (n == length + 1)
    {
        for (i = 0; i < 2 * length + 3; i++)
        {
            if (i == length + 1)
            {
                plate[i] = ' ';
            }
            else
            {
                plate[i] = ' ';
            }
        }
    }
    else
    {
        if (n == 0)
        {
            for (i = 0; i < 2 * length + 3; i++)
            {
                if (i == length + 1)
                {
                    plate[i] = '|';
                }
                else
                {
                    plate[i] = ' ';
                }
            }
        }
        else
        {
            for (i = 0; i < 2 * length + 3; i++)
            {
                if (i == length + 1)
                {
                    plate[i] = '|';
                }
                else
                {
                   // if (i >= length + 1 - n && i <= length || i > length + 1
					if (i > length + 1
                        && i <= length + 1 + n)
                    {
                        plate[i] = '_';
                    }
                    else
                    {
                        plate[i] = ' ';
                    }
                }
            }
        }
    }
    plate[i] = '\0';
}
// Draw
void drawtower()
{
    int i;
    cout<<" ";
    for (i = length; i >= 0; i--)
    {
        if (i <= lenA)
        {
            makeplate(arrA[i]);
			cout<<plate;
        }
        else
        {
            makeplate(0);
			cout<<plate;
        }
        if (i <= lenB)
        {
            makeplate(arrB[i]);
			cout<<plate;
        }
        else
        {
            makeplate(0);
			cout<<plate;
        }
        if (i <= lenC)
        {
            makeplate(arrC[i]);
			cout<<plate;
        }
        else
        {
            makeplate(0);
			cout<<plate;
        }
		cout<<"\n ";
    }
}
// Move
void moveplate(int n, char x, char y)
{
    int i, j;
    if (x == 'A')
    {
        lenA--;
    }
    else
    {
        if (x == 'B')
        {
            lenB--;
        }
        else
        {
            lenC--;
        }
    }
    if (y == 'A')
    {
        lenA++;
        arrA[lenA] = n;
    }
    else
    {
        if (y == 'B')
        {
            lenB++;
            arrB[lenB] = n;
        }
        else
        {
            lenC++;
            arrC[lenC] = n;
        }
    }
    drawtower();                // ����ƶ�һ�κ�ŵ����״̬
}
// Print And Move
void printandmove(int n, char x, char y)
{   count++;
	cout<<"\n��"<< count <<"���ƶ�:"<< n <<"���̴�"<< x <<"���Ƶ�"<< y <<"��\n\n";
    moveplate(n, x, y);
}
// Hanoi
void hanoi(int n, char one, char two, char three)
{
    if (n == 1)
    {
        printandmove(n, one, three);
    }
    else
    {
        hanoi(n - 1, one, three, two);
        printandmove(n, one, three);
        hanoi(n - 1, two, one, three);
    }
}
// Main
int main()
{
    int n, i;                   // nΪ��ŵ������������Ҫ�ı䣬ֻ����ĳ�ʼֵ���ɡ�
    char one = 'A', two = 'B', three = 'C';
    cout<<"���������Ӹ���[1��12]��";
	cin>>n;
    if (n >= 1 && n <= 12)
    {
        length = n;
        lenA = n;
        for (i = 0; i <= lenA; i++)
        {
            arrA[i] = n + 1 - i;
        }
        lenB = lenC = 0;
        arrB[0] = arrC[0] = n + 1;
        cout<<" ��ŵ��ģ���ƶ�����"<<n<<"����\n\n";
        drawtower();            // �����ŵ����ʼ״̬
        hanoi(n, one, two, three);
		cout<<"\n ģ�����,���ƶ�"<<(long)pow(2, n) - 1<<"��\n";
    }
    else
    {
        cout<<"���ݴ���\n";
    }
}