
#include <iostream>
using namespace std;

int main()
{
#pragma region 정수
    {
        // signed unsigned 음수의 유무(최상위비트 사용용도)
        char a; // 1byte
        short b; // 2byte
        int c; //4byte
        long long d; //8byte (__int64)
    }
#pragma endregion

#pragma region 실수
    {
        // 부동소수점 : .을 유동적으로 이동하여 표현
        // ex) 3.1415926535
        // 정규화 -> 0.31415926535 * 10
        // 유효숫자 = 31415926535
        // 지수 = 1 (10의 지수)
        // float = 부호(1) 지수(8) 유효숫자(23) = 4byte
        // double = 부호(1) 지수(11) 유효숫자(52) = 8byte
        float a = 3.14f;
        double b = 3.14;
    }
#pragma endregion

#pragma region 문자와 문자열
    {
        char ch = 'a'; // 아스키코드
        wchar_t wch = L'안'; // 유니코드UTF16
        // 문자 출력
        cout << ch << endl;
        wcout.imbue(locale("kor")); // 한국어 인식 명령
        wcout << wch << endl; // 유니코드 wch
        char str[] = { 'h','e','l','l','o','\0' }; //NULL문자 (문자열의 끝)
        cout << str << endl;
        char str2[] = "Hello";
        cout << str2 << endl;
    }
#pragma endregion

#pragma region 산술연산
    {
        int a = 1;
        int b = 2;

        a = b;

        a = b + 3;
        a = b - 3;
        a = b * 3;
        a = b / 3;
        a = b % 3;

        a += 3;
        a -= 3;
        a *= 3;
        a /= 3;
        a %= 3;

        a++;
        ++a;
        a--;
        --a;

        b = ++a;
        b = a++;
    }
#pragma endregion

#pragma region 비교&논리 연산
    {
        int a = 1;
        int b = 3;
        a == b;
        a < b;
        a <= b;
        a > b;
        a >= b;

        bool IsMoving = true;
        bool IsJumping = false;
        bool Result;
        !IsMoving;
        Result = IsMoving && IsJumping;
        Result = IsMoving || IsJumping;
    }
#pragma endregion

#pragma region 비트 연산 & 비트 플래그
    {
        // not -
        // and &
        // or |
        // xor ^
        // shiftL <<
        // shiftR >> (좌측 새로생기는 비트 : 부호비트가 있으면 부호비트를 따라감)

        //비트플래그
        unsigned char flag; // 0000 0000
        int state1 = 0;
        int state2 = 1;
        int state3 = 2;
        int state4 = 3;
        flag = (1 << state4); // 0000 1000
        flag = (1 << state3); // 0000 1100
        bool Is_State4 = flag & (1 << state4); //state4인지
        bool Is_State1_Or_IsState4 = (flag & (1 << state1)) | flag & (1 << state4); //State1이거나 State4인지
    }
#pragma endregion

#pragma region const & 메모리구조
    {
        // 상수화 const
        const int AIR = 0;
        const int STUN = 1;

        /** 메모리 영역 */
        // [데이터 영역] - 전역변수
        // .data : 초기값 있는 경우
        // .bss : 초기값 없는 경우
        // .rodata : 읽기 전용(const는 컴파일러 마음대로 정함)

        // [스택 영역] - 지역변수
        // 함수와 밀접하게 관련있음
    }
#pragma endregion

#pragma region 유의사항
    /** 유의사항
    * 1. 스택의 변수의 유효범위 -> {}
    * 2. 변수 이름
    * 3. 연산자 우선순위
    * 4. 타입 변환 (캐스팅)시, 데이터 변환 및 손실 주의
    * 5. 연산시, 오버플로우 주의 및 0나누기 주의
    * 6. 실수연산시(특히 나누기 나머지), 캐스팅 생각하기
    */
#pragma endregion
}
