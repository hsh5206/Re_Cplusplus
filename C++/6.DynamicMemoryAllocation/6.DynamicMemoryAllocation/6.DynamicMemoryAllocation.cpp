
#include <iostream>
using namespace std;

class Test1
{
public:
    int _hp = 4;
};

class Test2
{
public:
    int _mana = 10;
    int _power = 10;
};

class Parent
{

};

class Child : public Parent
{

};

class Hero
{
public:
    Hero() {}
    Hero(const Hero& hero) // 깊은 복사
    {
        _hp = hero._hp;
        _pet = new Pet(*hero._pet);
    }
public:
    int _hp = 10;
    Pet* _pet;
};

class Pet
{

};

int main()
{
#pragma region 메모리 영역
    /** 메모리 구조 */
    // 데이터 : 프로그램 실행/종료동안 유지
    // 스택 : 함수 실행/종료동안 유지
    // 힙 : 필요할때만 사용하고 필요없으면 반납할 수 있는, 실행/종료 시점을 관리할 수 있는

    /** 메모리 영역 */
    // 유저영역 : 사용자 어플
    // 커널영역 : 윈도우 등의 핵심코드
#pragma endregion

#pragma region 동적할당
    {
        // malloc, free, new, delete, new[], delete[]
    // API를 통해 커널영역에서 대량의 힙 메모리를 받아와서 CRT로 조금 분할하여 분배)
    // CRT(C 런타임 라이브러리)의 힙관리자를 통해 힙 영역 할당해줌 (헤더영역:메모리크기, 본영역)
    // 단, 정말 원한다면 직접 커널영역에서 제공하는 API를 통해 직접 힙생성하고 관리가능(서버 메모리 풀링)

    /** malloc&free */// C, 함수
        void* pointer = malloc(1000); // 할당받은 메모리 공간을 반환
        free(pointer); // 메모리 반환
        int* intptr = (int*)malloc(sizeof(int));
        free(intptr);

        /** new&delete */// C++, 연산자, 생성타입이 클래스일 경우 생성자와 소멸자 호출
        int* temp = new int;
        delete temp;
        int* intarr = new int[4];
        for (int i = 0; i < 4; i++)
        {
            intarr[i] = i;
            cout << intarr[i];
        }
        cout << endl << endl;
        delete[] intarr;
    }
#pragma endregion

#pragma region 타입변환
    {
        /** 유형 (비트열 재구성) */
        // 값 타입 변환 : 원본 객체와 다른 비트열로 재구성
        {
            int a = 1234567;
            float b = (float)a;
            cout << a << " -> " << b << endl;
        }
        // 참조 타입 변환 : 비트열 재구성 없이 관점만 바꿈
        {
            int a = 1234567;
            float b = (float&)a;
            cout << a << " -> " << b << endl;
        }

        /** 유형 (안전도) */
        // 안전한 변환 : 의미가 완전일치 캍은타입&크기만 더크게 (업 캐스팅)
        {
            int a = 123456789;
            __int64 b = a;
            cout << a << " -> " << b << endl;
        }
        // 불안전한 변환 : 데이터 소실 (다운 캐스팅)
        {
            int a = 123456789;
            short b = a;
            cout << a << " -> " << b;
        }

        /** 유형 (의도) */
        // 암시적 변환
        {
            int a = 123456789;
            float b = a;
        }
        // 명시적 변환
        {
            int a = 123456789;
            float b = (float)a;
        }

        cout << endl << endl;
    }
#pragma endregion

#pragma region 포인터 타입변환
    {
        /** 연관성이 없는 */
        Test1* a = new Test1();

        Test2* b = (Test2*)a; // 명시적으로 타입변환 (위험)
        cout << b->_mana << endl;
        cout << b->_power << endl; // 쓰레기 값

        delete a;

        /** 상속 관계 */// 최상위 부모의 소멸자에 virtual를 해줘야 소멸할때 가상함수로 인식
        // 원본의 소멸자를 호출하기 때문에 부모->자식이후 소멸할때 부모소멸자만 호출 따라서 virtual
        // 부모 -> 자식 (위험)
        // 자식 -> 부모
    }
#pragma endregion

#pragma region 얕은 복사 vs 깊은 복사
    {
        {
            Hero temp; // 기본 생성자
            temp._hp = 100;
            Hero temp2 = temp; // 복사 생성자
            Hero temp3; // 기본 생성자 이후,
            temp3 = temp; // 복사 대입 연산자
            // 복사 생성자 & 복사 대입 연산자 => 컴파일러가 암시적으로 만들어줌
            // But, 포인터가 있을 경우에도 그대로 복사됨
        }
        
        // 얕은 복사 : 원본 메모리에 있는 값을 비트열 단위로 그대로 복사, 포인터의 주소도 그대로 복사
        {
            Hero A;
            A._pet = new Pet();
            Hero B = A;
            Hero C;
            C = A;
        }

        // 깊은 복사 : 멤버 데이터가 참조(주소)라면, 데이터를 새로 만들어줌
        {
            Hero A;
            A._pet = new Pet();
            Hero B(A);
        }
    }
#pragma endregion

#pragma region 캐스팅
    {
        /**
        * static_cast  : 상식적인 캐스팅만 허용
        * int <-> float
        * 다운 캐스팅 (안정성 보장 X)
        */

        /**
        * dynamic_cast  : 상속관계에서의 안전한 형변환
        * RTTI (RunTime Type Information) 런타임에서 타입 관리, 다형성을 활용
        * virtual함수가 있을 경우
        * 잘못된 타입으로 캐스팅할 경우, nullptr 반환 (안전성 보장)
        */

        /**
        * const_cast  : 상식적인 캐스팅만 허용
        * const를 붙여주거나 떼주거나
        * const_cast<char*>("Hello")
        */

        /**
        * reinterpret_cast  : 상식적인 캐스팅만 허용
        * 가장 강력 But 위험
        * 포인터와 전혀 관계없는 다른 타입 변환 가능
        * 전혀 연관없는 클래스끼리의 타입 변환 가능
        */
    }
#pragma endregion
}