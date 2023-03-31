
#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

int main()
{
#pragma region STL
	{
		/** STL(Statndard Template Library)
		* 프로그래밍할 때 필요한 자료구조/알고리즘들을 템플릿으로 제공
		* 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조)
		*	- 시퀀스 컨테이너 (벡터, 리스트, 데크)
		*	- (맵, 멀티맵, 세트, 멀티세트)
		* 반복자(Iterator) : 포인터와 유사한 개념, 컨테이너의 데이터를 가리키고 다음/이전원소로 이동 가능
		*/
	}
#pragma endregion

#pragma region 벡터(Vector)
	{
		/** 벡터 (Vector) */
		// 여유분을 두고 메모리 할당
		// v.capacity() : 총 용량
		// v.size() : 총 사이즈
		// 메모리가 초과되면 새로 메모리 할당 ( 초과시 대략 1.5배 증설)
		// 새 메모리에 기존 데이터 복사
		// v.reserve(1000) 용량을 강제로 조절
		// v.resize(1000) 사이즈를 강제로 조절(사이즈와 용량 둘다)
		// v.clear() 사이즈만 날려버림 (용량은 그대로)
		// v.swap(Vector) 백터를 바꿈
		// v.push_back
		// v.pop_back()
		// v.front()
		// v.back()
		// v.insert(v.begin()+2, 5) 중간에 삽입
		// v.erase(v.begin()+3) 중간값 삭제 v.erase(v.begin(), v.begin()+4) 범위 삭제
		vector<int> v1;
		for (int i = 0; i < 10; i++)
		{
			v1.push_back(i);
		}
		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		v1.clear();
		cout << endl << "--------------------" << endl;

		/** 이터레이터 (Iterator) : 모든 컨테이너에 동일하게 존재 */
		vector<int> v2(10, 0); // 사이즈는 10, 초기값은 모두 0
		for (int i = 0; i < v2.size(); i++)
		{
			v2[i] = i;
		}
		vector<int>::iterator it;
		// v2.begin() 시작 주소
		// v2.end() 마지막 주소 다음
		for (it = v2.begin(); it < v2.end(); ++it)
		{
			cout << *it << " ";
		}
		v2.clear();
		cout << endl << "--------------------" << endl;
	}
#pragma endregion

#pragma region 리스트(List)
	{
		/** 리스트(List) : 연결 리스트 (단일, *이중, 원형)
		* 노드의 연결
		* li.size()
		* li.push_back() & li.push_front()
		* li.pop_back() & li.pop_front()
		* li.front() & li.back()
		* li.insert() & li.erase()
		* li.remove()
		*/

		list<int> li;
		for (int i = 0; i < 10; i++)
		{
			li.push_back(i);
		}
		list<int>::iterator it;
		for (it = li.begin(); it != li.end(); ++it)
		{
			cout << *it << " ";
		}

		cout << endl << "--------------------" << endl;
	}
#pragma endregion

#pragma region 데크(deque)
	{
		/** 데크 (deque : double ended queue)
		* 양방향 큐
		* 벡터와 같이 동작, But 메모리 할당 정책이 다름
		* 초과시 새로 메모리 공간을 만들어서 이어서 push
		* block & off
		*/

		deque<int> dq;
		dq.push_back(1);
		dq.push_front(0);
		cout << dq[0];

		cout << endl << "--------------------" << endl;
	}
#pragma endregion

#pragma region 맵(Map)
	{
		/** 맵 (Map) 
		* 데이터 찾기
		* 균형 이진 트리 (AVL)
		* 키-값 매핑 데이터
		* 키에 이미 값이 있으면 추가 insert는 무시됨
		*/

		map<int, int> m;
		for (int i = 0; i < 100; i++)
		{
			m.insert(pair<int, int>(i, i * 100));
		}
		m.insert(make_pair(101, 10));

		m[13]; // 데이터가 없으면 0으로 데이터를 추가해준다.
		cout << m[14] << endl;
		m.erase(14);
		cout << m[14] << endl;

		map<int, int>::iterator findit = m.find(88);
		if (findit != m.end())
		{
			pair<const int, int>& p = *findit;
			cout << p.second;
			cout << (*findit).second;
			cout << findit->second;
		}

		cout << endl << "--------------------" << endl;
	}
#pragma endregion

#pragma region 세트(Set), 멀티맵(Multi_Map), 멀티세트(Multi_Set)
	{
		/** 세트 (Set)
		* 맵과 유사, But 패어 사용X, 키만 사용
		*/
		set<int> s;
		s.insert(10);
		s.insert(30);
		s.insert(50);
		
		s.erase(30);
		
		s.find(50);

		/** 멀티맵 (Multi_Map)
		* 맵 + 중복키 허용
		*/
		multimap<int, int> mm;
		mm.insert(make_pair(1, 100));
		mm.insert(make_pair(1, 200));
		mm.insert(make_pair(1, 300));

		mm.find(1); // 하나만 찾아줌
		//first 시작 : lower_bound() & second 끝 : upper_bound()
		pair<multimap<int,int>::iterator, multimap<int,int>::iterator> itPair = mm.equal_range(1);
		for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
		{
			cout << it->first << " " << it->second << endl;
		}
		cout << endl;

		/** 멀티세트 (Multi_Set)
		* 세트 + 중복키 허용
		*/
		multiset<int> ms;
		ms.insert(100);
		ms.insert(100);
		ms.insert(100);

		ms.find(100); // 하나만 찾아줌
		// 멀티 셋과 동일
		ms.equal_range(100);
		ms.lower_bound(100);
		ms.upper_bound(100);
	}
#pragma endregion

#pragma region Practice
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		vector<int> v;
		for (int i = 0; i < 100; i++)
		{
			int num = rand() % 100;
			v.push_back(num);
		}

		// 1
		{
			int number = 50;
			bool found = false;
			vector<int>::iterator it;
			for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it == number)
				{
					found = true;
					break;
				}
			}
			string out = found ? "true" : "false";
			cout << out << endl;
		}
		
		// 2
		{
			int found = false;
			vector<int>::iterator it;

			for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it % 11 == 0)
				{
					found = true;
					break;
				}
			}
			string out = found ? "true" : "false";
			cout << out << endl;
		}

		// 3
		{
			int count = 0;
			vector<int>::iterator it;
			for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it % 2 == 1)
				{
					count++;
					break;
				}
			}
			cout << count << endl;
		}

		// 4
		{
			vector<int>::iterator it;
			for (it = v.begin(); it != v.end(); ++it)
			{
				*it *= 3;
			}
		}
	}
#pragma endregion

#pragma region 알고리즘 (Algorithm) - Practice고치기
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		vector<int> v;
		for (int i = 0; i < 100; i++)
		{
			int num = rand() % 100;
			v.push_back(num);
		}

		// find
		// find_if
		// count
		// count_if

		// all_of : 모두?
		// any_of : 하나라도?
		// none_of : 아무도?

		// for_each
		
		// remove : 필요한 값들만 앞에서 부터 채워줌, 이후 end iter 반환
		// remove_if : 따라서 iter로 받고 v.erase(iter, v.end()); 해줘서 쓰레기값 삭제해줘야함

		// 1
		{
			int number = 50;
			bool found = false;
			vector<int>::iterator it;

			/*for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it == number)
				{
					found = true;
					break;
				}
			}*/
			it = find(v.begin(), v.end(), number);
			
			// string out = found ? "true" : "false";
			string out = it == v.end() ? "false" : "true";
			cout << out << endl;
		}

		// 2
		{
			int found = false;
			vector<int>::iterator it;

			/*for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it % 11 == 0)
				{
					found = true;
					break;
				}
			}*/
			struct CanDevideBy11
			{
				bool operator()(int n)
				{
					return n % 11 == 0;
				}
			};

			it = find_if(v.begin(), v.end(), CanDevideBy11());
			//it = find_if(v.begin(), v.end(), [](int n) { return n % 11 == 0; });

			// string out = found ? "true" : "false";
			string out = it == v.end() ? "false" : "true";
			cout << out << endl;
		}

		// 3
		{
			// int count = 0;
			vector<int>::iterator it;

			/*for (it = v.begin(); it != v.end(); ++it)
			{
				if (*it % 2 == 1)
				{
					count++;
					break;
				}
			}*/
			int count = count_if(v.begin(), v.end(), [](int n) {return n % 2 == 1; });

			cout << count << endl;
		}

		// 4
		{
			vector<int>::iterator it;
			/*for (it = v.begin(); it != v.end(); ++it)
			{
				*it *= 3;
			}*/
			for_each(v.begin(), v.end(), [](int& n) { n *= 3; });
		}
	}
#pragma endregion
}
