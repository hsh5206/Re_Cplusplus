
#include <iostream>
using namespace std;

#include <iomanip>

void SetMsg(const char** x);
void SetMsg(const char*& x);

int main()
{
#pragma region 포인터 기본
    {
        int num = 3;
        int* ptr = &num;
        cout << ptr << " : " << *ptr << endl;
        *ptr += 2;
        cout << ptr << " : " << *ptr << endl;
    }
#pragma endregion

#pragma region 포인터 연산
    {
        /** 주소 연산자 */
        // & : type* 반환 (주소)
        int num = 1;
        int* ptr = &num;

        /** 산술 연산자 */// 해당 타입만큼의 크기를 이동
        // +, -
        ptr += 1; 

        /** 간접 연산자 */
        // * : 해당 주소의 변수값에 접근

        /** 간접 멤버 연산자 */
        // -> : (*PlayerInfo).hp = 200; => PlayerInfo->hp = 200;
        // 구조체와 클래스의 멤버에 접근
    }
#pragma endregion

#pragma region 참조
    {
        // 값
        int number = 10;

        // 주소
        int* pointer = &number;

        // 참조
        int& reference = number; // number의 다른이름 reference
    }
#pragma endregion

#pragma region 포인터 vs 참조
    {
        struct PlayerInfo
        {
            int hp = 10;
            int mana = 10;
        };

        // const 사용
        // 참조 : PrintInfo(const PlayerInfo& Info) -> 내용물 변경 불가
        // 포인터 : PrintInfo(PlayerInfo* const Info) -> 주소 변경 불가
        //        : PrintInfo(const PlayerInfo* Info) -> 내용물 변경 불가

        // 포인터는 값을 가지지 않을 수 있음
        // 참조는 무조건 값을 가져야함
        PlayerInfo info;
        PlayerInfo* pointer; // nullptr
        pointer = &info;
        PlayerInfo& reference = info;

        // 포인터의 접근
        pointer->hp;
        // 참조의 접근
        reference.hp;

        // nullptr일 수 있으면 포인터 사용
        // readonly에는 const 레퍼런스 사용
        // 그외 레퍼런스 사용 & OUT사용 (명시적으로 표시만) #define OUT

        // 포인터 -> 참조
        PlayerInfo& ref = *pointer;
        // 참조 -> 포인터
        PlayerInfo* poi = &ref;
    }
#pragma endregion

#pragma region 배열 기초
    {
        struct StatInfo
        {
            int hp = 10;
            int mana = 10;
        };

        /** 배열과 레퍼런스와 포인터 */
        StatInfo monsters[10]; // 배열의 크기는 상수여야함(vs에서)
        StatInfo players[10];
        // players = monsters; -> 배열의 이름은 배열의 시작 주소를 저장
        StatInfo* monster_0 = monsters;
        monster_0->hp = 100;
        StatInfo* monster_1 = monster_0 + 1;
        monster_1->hp = 100;
        StatInfo& monster_2 = *(monster_1 + 1);
        monster_2.hp = 100;

        /** 배열 접근 (for) */
        for (int i = 0; i < 10; i++)
        {
            StatInfo& monster = *(monsters + 1);
            monster.hp;

            monsters[i].hp;
        }
        for (auto monster : monsters)
        {
            monster.hp;
        }

        /** 배열의 초기화 */
        int numbers1[5] = { }; // 0으로
        for (auto number : numbers1)
        {
            cout << number << " ";
        }
        cout << endl;

        int numbers2[5] = { 5, }; // 설정한 애들빼고 0으로
        for (auto number : numbers2)
        {
            cout << number << " ";
        }
        cout << endl;

        int numbers3[] = { 1, 2, 3 }; // 데이터 개수 만큼의 배열
        for (auto number : numbers3)
        {
            cout << number << " ";
        }
        cout << endl;
    }
#pragma endregion

#pragma region 포인터 배열 문자열
    {
        /** 문자열 */
        char msg[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
        cout << msg << endl;
        char msg2[] = "Hello"; // "Hello" 는 ro .data영역에 있는 애를 msg2로 복사해옴
        cout << msg2 << endl;
        string str = "Hello";
        cout << str << endl;

        // 배열을 함수의 인자로 넘기면 배열의 시작 주소를 인자로 넘기는 것과 같음
        // 컴파일러가 자동으로 포인터로 해석
    }
#pragma endregion

#pragma region 다중 포인터
    {
        // 포인터를 가르키는 포인터를 생성해서
        // 해당 포인터의 주소값을 바꿔줌
        const char* msg = "HELLO";
        const char** pp;
        pp = &msg;
        SetMsg(pp); // 이중 포인터
        SetMsg(msg); // 포인터의 레퍼런스
        cout << *pp << endl;
    }
#pragma endregion

#pragma region 다차원 배열
    {
        // 2층 아파트, 한층에 3개
        int apartment2D[2][3] = { {1,2,3}, {4,5,6} };
        // [1, 2, 3, 4, 5, 6] 으로 메모리에 차례대로 저장됨
        // 사실상 일차원 배열
    }
#pragma endregion

#pragma region 포인터 마무리
    {
        // 포인터와 배열은 다르다
        int arr[2][2] = { {1,2},{3,4} };
        // int** pp = arr; -> arr은 [1,2,3,4]의 시작 주소
        // *pp == 1

        // 항상 주의해서 사용하기
    }
#pragma endregion

#pragma region 문자열 관련 함수
    // strlen : 길이구하기
    // strcyp strcpy_s : 복사하기
    // strcat : 이어붙이기
    // strcmp : 비교
    // reverse : 뒤집기
#pragma endregion

#pragma region 연습문제 : 달팽이문제
    {
        const int MAX = 100;
        int board[MAX][MAX] = {};
        int N;
        cin >> N;

        // 달팽이 모양 만들기
        // 구현
        
        // 출력
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << setfill('0') << setw(2) << board[i][j] << " ";
                // 빈공간은 0으로, 2자리수로 출력
            }
            cout << endl;
        }
    }
#pragma endregion

#pragma region 파일 분할 관리
    {
        // #pragma once
        // #ifndef #define #endif
    }
#pragma endregion
}

void SetMsg(const char** x)
{
    *x = "Bye";
}

void SetMsg(const char*& x)
{
    x = "Bye";
}