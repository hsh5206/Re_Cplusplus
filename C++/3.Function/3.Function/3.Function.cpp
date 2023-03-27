
#include <iostream>
using namespace std;

#pragma region 함수기초
void PrintHello()
{
    cout << "HEllO" << endl;
}
int MultiInt(int a, int b)
{
    return a * b;
}
#pragma endregion

#pragma region 호출스택
// 함수 선언
void Func1();
void Func2();
void Func3();

// 함수 구현
void Func1()
{
    cout << "Func1 - Start" << endl;
    Func2();
    cout << "Func1 - End" << endl;
}
void Func2()
{
    cout << "Func2 - Start" << endl;
    Func3();
    cout << "Func2 - End" << endl;
}
void Func3()
{
    cout << "Func3 - Start" << endl;
    cout << "Func3 - End" << endl;
}
#pragma endregion

#pragma region 함수기능 및 주의사항
/** 오버로딩 */// 함수이름의 재사용 (매개변수의 개수가 다르거나 타입이 다르거나)
int Add(int a, int b)
{
    return a + b;
}
float Add(float a, float b)
{
    return a + b;
}

/** 기본 인자 */// 매개변수가 없을 경우의 기본값 설정 (뒤쪽에 몰아주기)
void TempFunc(int hp, int mp, int guildid = -1)
{
    // Todo
}

/** 
* [스택 오버플로우]
* 스택 메모리가 꽉차는 상황
* 재귀함수시, 주의
*/
#pragma endregion

#pragma region +구조체
struct HeroInfo
{
    int hp = 100;
    int mana = 100;
    int power = 15;
    int agility = 5;
};
#pragma endregion

int main()
{
    // Func1();
}