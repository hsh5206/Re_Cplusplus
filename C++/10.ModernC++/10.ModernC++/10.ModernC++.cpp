
#include <iostream>
using namespace std;
#include <vector>

class Item
{
public:
    Item() {} // 기본 생성자
    Item(const Item&) {} // 복사 생성자
    Item(Item&&) noexcept {} // 이동 생성자
};

void Test_Copy(Item i) {}

// 전달 참조
template<typename T>
void Test_ForwardingRef(T&& param)
{
    // 왼값 참조라면 복사
    // 오른값 참조라면 이동
    Test_Copy(std::forward<T>(param)); // 전달참조
}

//sharedptr
class RefCountBlock
{
public:
    int _refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
    SharedPtr() {}
    SharedPtr(T* ptr) : _ptr(ptr)
    {
        if (_ptr != nullptr)
        {
            _block = new RefCountBlock();
        }
    }
    SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
    {
        if (_ptr != nullptr)
        {
            _block->_refCount++;
        }
    }

    ~SharedPtr()
    {
        if (_ptr != nullptr)
        {
            _block->_refCount--;
            if (_block->_refCount == 0)
            {
                delete _ptr;
                delete _block;
            }
        }
    }

public:
    T* _ptr = nullptr;
    RefCountBlock* _block = nullptr;
};


int main()
{
    /** Modern C++ ( C++11 ~ ) */

    // auto : 기본 auto는 const와& 무시
    auto num = 3.5;

    // 중괄호 초기화 (컨테이너와 잘 어울림, 축소 변환 방지, 
    vector<int> v{ 1,2,3,4 };

    // nullptr
    
    // using
    /*template<typename T>
    using List = std::vector<T>;
    List<int> li;*/

    // enum class (scoped enum)
    enum class PlayerType :short
    {
        None,
        Knight,
        Archer
    };
    PlayerType::Knight;

    // delete : 더이상 활용하지 않을 것임을 의미
    class Player
    {
    public:
        void operator=(const Player& k) = delete;

    public:
        int _hp = 100;
    };

    // override, final

    // 오른값 참조 (rvalue reference)
    // 등장이후, 이전C++과의 속도차이가 남
    // lvalue : 단일식을 넘어서 계속 지속되는 개체
    // rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다 등)
    {
        //void Test_Copy(Player p);
        //void Test_LValueRef(Player& p);
        //void Test_RValueRef(Player&& p); // 원본을 더이상 사용하지 않으니, 이동 대상
        //Player p1;
        //Test_LValueRef(p1);
        //Test_RValueRef(Player());
        //std::move(p1); // 오른값으로 만들어줌
        //Test_RValueRef(std::move(p1));
    }

    // 보편 참조 (universal reference) C++11
    // 전달 참조 (forwarding reference) C++17
    // template이나 auto에서 타입을 추론할때 발생 (왼값 오른값 자동으로)
    Item i1;
    Test_Copy(i1); // 왼값 복사
    Test_Copy(std::move(i1)); // 오른값 이동

    // 람다 (lambda)
    // 함수 객체를 빠르게 일회성으로 만듬
    // [](인자) {구현}
    // [](int i) { return i == 1; } (자동 추론)
    // [](int i) -> int { return i == 1; }
    // auto isOne = [](int i) { return i == 1; }

    // 클로저 (closure) = 람다에 의해 만들어진 실행시점 객체
    // 캡처모드 : 복사(=) 참조(&)
    // int itemId = 4;
    // auto FindItemById = [=](Item& item) { return item._itemId == itemId; }
    // auto FindItemById = [&itemId](Item& item) { return item._itemId == itemId; }

    // 스마트 포인터 (smart pointer) : 포인터를 알맞은 정책에 따라 관리
    // shared_ptr - 카운트를 기반으로 포인터 관리
    // weak_ptr - shared의 사이클을 보안 ( expired() 메모리 유무 ) ( lock() = shared반환 )
    // unique_ptr - 카운트1만 가능
    {
        class Knight
        {
        public:
            Knight() { cout << "Knight 생성" << endl; }
            ~Knight() { cout << "Knight 소멸" << endl; }

            void Attack()
            {
                if (_target)
                {
                    _target->_hp -= _damage;
                    cout << "상대방 HP : " << _target->_hp << endl;
                }
            }
        public:
            int _hp = 100;
            int _damage = 10;
            shared_ptr<Knight> _target = nullptr;
        };

        //{
        //    Knight* k1 = new Knight();
        //    Knight* k2 = new Knight();
        //    k1->_target = k2;
        //    k1->Attack();
        //    delete k2;
        //    // k1->Attack(); 메모리 오류
        //}

        // k1이 소멸이 되어도 k2에 의해 count == 1 그래서 유지
        // 둘다 소멸되면 알아서 메모리 소멸
        shared_ptr<Knight> k1 = make_shared<Knight>();
        {
            shared_ptr<Knight> k2 = make_shared<Knight>();
            k1->_target = k2;
        }
        k1->Attack();
    }
}

