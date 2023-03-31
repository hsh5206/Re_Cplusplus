
#include <iostream>
using namespace std;

// 함수 포인터
int Add(int a, int b)
{
    return a + b;
}

class Item
{
public:
    int Add(int a, int b)
    {
        return a + b;
    }

public:
    int _itemId;
    int _rarity;
    int _ownerId;
};

using ITEM_SELECTOR = bool(Item*);
Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector /*bool(*selector)(Item* item)*/)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];

        if(selector(item))
            return item;
    }

    return nullptr;
}

bool IsRareItem(Item* item)
{
    return item->_rarity >= 2;
}

// 함수 객체
class Functor
{
public:
    void operator()()
    {
        cout << "Functor" << endl;
    }

    bool operator()(int num)
    {
        cout << "Functor" << endl;
        _value += num;
        cout << _value << endl;

        return true;
    }

public:
    int _value = 0;
};

// 함수 템플릿 : 컴파일 단계에서 타입별 함수정의해줌
class Hero
{
public:
    int _hp = 100;
    int _mana = 100;
};
template<typename T>
void Print(T value)
{
    cout << value << endl;
}
template<typename T>
T Add(T a, T b)
{
    return a + b;
}
template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

// 템플릿 특수화 : 특정 타입에 관해서 다르게 작동
template<>
void Print(Hero hero)
{
    cout << "Hero : " << hero._hp << ", " << hero._mana << endl;
}

// 클래스 템플릿
template<typename T, int SIZE>
class RandomBox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

// 콜백 함수
class NewItem
{
public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;
};

template <typename T>
NewItem* FindNewItem(NewItem items[], int itemCount, T selector)
{
    for (int i = 0; i < itemCount; i++)
    {
        NewItem* item = &items[i];
        
        if(selector(item))
            return item;
    }

    return nullptr;
}

class FindByOwnerId
{
public:
    bool operator()(const NewItem* item)
    {
        return item->_ownerId == _ownerId;
    }

public:
    int _ownerId;
};

class FindByRarity
{
public:
    bool operator()(const NewItem* item)
    {
        return item->_rarity >= _rarity;
    }

public:
    int _rarity;
};

int main()
{
#pragma region 함수 포인터
    {
        /** 전역 / 정적 함수 */
        typedef int(FUNC_TYPE1)(int, int);
        using FUNC_TYPE1 = int(int, int);

        int result = Add(1, 2); // 함수의 이름은 함수의 시작 주소
        FUNC_TYPE1* fn;
        fn = &Add; // &생략 가능 (C언어 호환성 때문에)
        int result2 = fn(1, 2); // 함수 포인터는 *을 붙여도 주소 (*fn)해줘도 같음
        
        cout << result << " == " << result2 << endl;

        Item items[10] = {};
        items[3]._itemId = 3;
        items[3]._rarity = 2;

        cout << FindItem(items, 10, IsRareItem)->_itemId << endl;


        /** 멤버 함수 */
        Item item;
        typedef int(Item::* FUNC_TYPE2)(int, int);
        FUNC_TYPE2 fn2;
        fn2 = &Item::Add; // &생략 불가능
        cout << (item.*fn2)(1, 2) << endl;

        Item* item2 = new Item();
        cout << (item2->*fn2)(1, 2) << endl;

        cout << "-----------------------------------" << endl;
    }
#pragma endregion

#pragma region 함수 객체
    {
        // 함수포인터의 단점 : 시그니처가 맞아야함, 상태를 가질 수 없음
        // 함수 객체 : 함수처럼 동작하는 객체
        // 1. 객체 생성
        // 2. () 연산자 오버로딩
        Functor functor;
        functor();
        bool ret = functor(3);
        cout << ret << endl;
        cout << "-----------------------------------" << endl;
    }
#pragma endregion

#pragma region 템플릿 기본
    {
        /** 
        * 템플릿 : 함수나 클래스를 찍어내는 틀
        * 함수 템플릿
        * 클래스 템플릿
        */
        Print(3); // 컴파일러가 추론해서 호출
        Print<int>(3.0); // 명시적으로 호출
        Print('a');
        Print("Hello");

        Add(1, 3);
        Add<float>(1.1f, 2.1f);
        Print<string, int>("Hello", 100);

        Hero hero;
        Print(hero);
        
        srand(static_cast<unsigned int>(time(nullptr)));
        RandomBox<int, 10> rb1;
        for (int i = 0; i < 10; i++)
        {
            rb1._data[i] = i;
        }
        cout << "Random : " << rb1.GetRandomData() << endl;

        cout << "-----------------------------------" << endl;
    }
#pragma endregion

#pragma region 콜백함수
    {
        NewItem items[10];
        items[3]._ownerId = 3;
        items[8]._rarity = 2;

        FindByOwnerId find1;
        find1._ownerId = 3;
        FindByRarity find2;
        find2._rarity = 1;

        NewItem* item1 = FindNewItem(items, 10, find1);
        NewItem* item2 = FindNewItem(items, 10, find2);

        cout << item1->_ownerId << " & " << item2->_rarity << endl;
    }
#pragma endregion
}