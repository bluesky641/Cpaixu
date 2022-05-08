#include <iostream>
using namespace std;
#pragma warning(disable:4996)

#define NUM 100000*4
string words[NUM];
int _count[NUM];
int totalWords = 0;

int FindWord(string w) {
	int pos = -1;
	for (int i = 0; i < totalWords; i++) {
		if (words[i] == w) {
			pos = i;
			break;
		}
	}
	return pos;
}

int main() {
	int n = 0;
	freopen("words", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		int pos = FindWord(word);
		if (pos == -1) {
			words[totalWords] = word;
			_count[totalWords] = 1;
			totalWords++;
		}
		else {
			_count[pos]++;
		}
	}
	freopen("words.out", "w", stdout);
	for (int i = 0; i < totalWords; i++) {
		cout << words[i] << "    " << _count[i] << endl;
	}
	return 0;
}
