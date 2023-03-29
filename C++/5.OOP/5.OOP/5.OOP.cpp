
#include <iostream>
using namespace std;

#pragma region 클래스 기본

class BaseHero
{
public:
    BaseHero(); // 생성자
   explicit BaseHero(int hp, int attack) // 기타 생성자 (explicit : 명시적인 용도로만 사용) (인자를 하나만 받으면 타입변환 생성자)
    {
        _hp = hp;
        _attack = attack;
    }
   BaseHero(const BaseHero& hero) // 복사 생성자
    {
        _hp = hero._hp;
        _attack = hero._attack;
        _posX = hero._posX;
        _posY = hero._posY;
    }
    ~BaseHero(); // 소멸자

    void Move(int x, int y);
    void Attack();
    void Die()
    {
        _hp = 0;
        cout << "Die" << endl;
    }

public:
    int _hp = 10;
    int _attack = 1;
    int _posX = 0;
    int _posY = 0;
};

BaseHero::BaseHero()
{
}

BaseHero::~BaseHero()
{
}

void BaseHero::Move(int x, int y)
{
}

void BaseHero::Attack()
{
}

#pragma endregion

#pragma region 상속성

class HeroA : public BaseHero // 상속 접근 지정자
{
public:
    HeroA(){}
    HeroA(int stamina) : BaseHero(100, 100) {} // 부모의 특정 생성자를 지정
    // 재정의
    void Move() {}
};

#pragma endregion

#pragma region 은닉성(캡슐화)

class Temp
{
// 접근 지정자 & 상속 접근 지정자
private:
protected:
public:
};

#pragma endregion

#pragma region 다형성

// 오버로딩 : 함수 이름 중복 정의

// 오버라이딩 : 함수 재정의
class Parent
{
public:
    virtual void Print();
};

void Parent::Print()
{
    cout << "Hello";
}

class Child : public Parent
{
public:
    virtual void Print() override;
};

void Child::Print()
{
    __super::Print();
    cout << " World" << endl;
}

/** 바인딩 */
// 정적 바인딩 : 컴파일 시점에 결정 (기본)
// 동적 바인딩 : 실행 시점에 결정 (가상함수를 이용하여 overrdie)
// 가상함수로 정의를 하면 실행 시점에 가상함수 테이블(.vftable)을 만듬
// 첫 주소에 가상함수 테이블의 첫 주소값이 추가됨 (생성자가 주도함)
// 순수 가상 함수 : 함수 인터페이스만 virtual void Attack() = 0; -> 무조건 재정의해라
// 추상 클래스 : 순수가상함수가 1개라도 존재 => 직접 객체를 만들 수 없음( 상속 전용 )
#pragma endregion

#pragma region 클래스의 초기화

class Inventory
{
public:
    Inventory() {}
    Inventory(int x) {}
};

class Test
{
public:
    Test() :
        /** 초기화 리스트(선처리 영역) */
        _mana(100), // 기본
        _Inventory(20), // 소유중인 클래스의 생성자 선택
        //정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)
        _hpRef(_hp),
        _hpConst(100)
    {
        _hp = 20;
        // Inventory를 생성자 내부에서 초기화해줄 경우, 기본생성자와 해당생성자 총 두개 호출
    }
public:
    int _hp = 20; // C++11문법
    int _mana;

    Inventory _Inventory; // 클래스를 소유중일 경우
    // 초기화 리스트에서 자동으로 해당 클래스의 생성자 호출

    int& _hpRef;
    const int _hpConst;
};

#pragma endregion

#pragma region 연산자 오버로딩

class Position
{
public:

    // 멤버 연산자 함수 : 왼쪽 피연산자가 항상 클래스여야함
    Position operator+(const Position& arg)
    {
        Position pos;
        pos._x = _x + arg._x;
        pos._y = _y + arg._y;
        return pos;
    }

    int _x;
    int _y;
};

// 전역 연산자 함수
Position operator+(int a, const Position& b)
{
    Position ret;

    ret._x = b._x + a;
    ret._y = b._y + a;

    return ret;
}

#pragma endregion

#pragma region static
// 데이터 영역
/** static 변수 */// 클래스에 종속적으로 고정    
/** static 함수 */// static변수를 바꿔주는 용도로 사용
// 스택에서 static변수 : 생명주기가 프로그램 시작/종료
class Marine
{
public:
    int _hp;

    static int s_attack;
};

int Marine::s_attack = 0;

#pragma endregion

int main()
{
    BaseHero BaseHero; // 인스턴스화
    HeroA HeroA;
    HeroA.Attack();

    Child ch;
    ch.Print();

    Position a;
    Position b;
    Position c = a + b; // c = a.operater+(b);
    Position d = 1 + c; // 전역 연산자 함수
}

