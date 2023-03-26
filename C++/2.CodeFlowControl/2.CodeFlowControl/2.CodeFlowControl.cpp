
#include <iostream>
using namespace std;

#pragma region 전처리
#define PRINT_HELLO cout << "HELLO" << endl;
#define TEMP 1 + 2 //  1+2를 그대로 복붙 (주의)
#pragma endregion

int main()
{
#pragma region 분기문
	{
		// if & else if & else
		// switch-case (정수계열만)
	}
#pragma endregion

#pragma region 반복문
	{
		// while do-while
		// for
	}
#pragma endregion

#pragma region 실습
	{
		// 별찍기
		int n = 5;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n; i < j; j--)
			{
				cout << '*';
			}
			cout << endl;
		}

		// 구구단
		for (int i = 2; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				cout << i << '*' << j << " = " << i * j << endl;
			}
			cout << endl;
		}

		// 가위 바위 보
		const int SCISSORS = 1;
		const int ROCK = 2;
		const int PAPER = 3;
		
		bool isFin = false;
		while (true)
		{
			int input = 4;
			cout << "가위(1) 바위(2) 보(3) 중에서 선택해주세요 : ";
			// cin >> input;

			srand(time(0)); // 기준값 시드 설정
			int com = rand() % 3 + 1;
			switch (input)
			{
			case ROCK:
				cout << input << "(나) vs " << com << "(컴) => ";
				if (com == ROCK) cout << "비겼습니다." << endl;
				if (com == SCISSORS) cout << "이겼습니다." << endl;
				if (com == PAPER) cout << "졌습니다." << endl;
				break;
			case SCISSORS:
				cout << input << "(나) vs " << com << "(컴) => ";
				if (com == ROCK) cout << "졌습니다." << endl;
				if (com == SCISSORS) cout << "비겼습니다." << endl;
				if (com == PAPER) cout << "이겼습니다." << endl;
				break;
			case PAPER:
				cout << input << "(나) vs " << com << "(컴) => ";
				if (com == ROCK) cout << "이겼습니다." << endl;
				if (com == SCISSORS) cout << "졌습니다." << endl;
				if (com == PAPER) cout << "비겼습니다." << endl;
				break;
			default:
				isFin = true;
				break;
			}

			if (isFin) break;
		}
		
		
	}
#pragma endregion

#pragma region 열거형
	{
		enum ERSP
		{
			ROCK = 1,
			SCISSORS,
			PAPER,
		};
		ERSP::PAPER;
	}
#pragma endregion
}
