// smartptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Message {

public:
	int32_t Header;
	int32_t Command;
	char Body[64];

	~Message() { cout << Header << ": destructor called";  }
};

typedef Message* MessagePtr;
typedef std::shared_ptr<Message> smartMessagePtr;

int main()
{
	vector<MessagePtr> v;
	
	MessagePtr m1 = new Message{ 1, 1, "login m1" };
	v.push_back(m1);

	smartMessagePtr m2(new Message{ 1, 1, "login m2" });
	vector<smartMessagePtr> sv;
	sv.push_back(m2);
}

