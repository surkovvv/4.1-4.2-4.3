#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;

template <class T>
class stack {
private:
	T* buff;
	int buffSize;
public:
	int top;
	stack(int size = 1) {
		top = -1;
		buffSize = size;
		buff = new T[buffSize];
	}
	~stack() {
		delete[] buff;
	}
	void push(T element) {
		if (top + 1 == buffSize) {
			int newbuffSize = 2 * buffSize;
			T* newbuff = new T[newbuffSize];
			for (int i = 0; i < buffSize; i++) { newbuff[i] = buff[i] };
			delete[] buff;
			buffSize = newbuffSize;
			buff = newbuff;
		}
		++top;
		buff[top] = element;
	}
	T pop() {
		assert(top != -1);
		return buff[top--];
	}
};

int main() {
	return 0;
}