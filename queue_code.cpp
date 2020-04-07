#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;

template <class T>
class queue{
private:
	T* buff;
	int buffSize;
public:
	int head,tail;
	stack(int size = 1) {
		head = 0;
		tail = 0;
		buffSize = size;
		buff = new T[buffSize];
	}
	~stack() {
		delete[] buff;
	}
	void enqueue(T element) {
		if (abs(head - tail) + 1 == buffSize || abs(head - tail) == 1) {
			int newbuffSize = 2 * buffSize;
			T* newbuff = new T[newbuffSize];
			for (int i = 0; i < buffSize; i++) { newbuff[i] = buff[i] };
			delete[] buff;
			buffSize = newbuffSize;
			buff = newbuff;
		}
		buff[tail] = element;
		if (head == buffSize) head = 1;
		else tail++;
	}
	T dequeue() {
		assert(buffSize != 0);
		T x = buff[head];
		if (head == buffSize) head = 1;
		else head++;
		return x;
	}
};

int main() {
	return 0;
}