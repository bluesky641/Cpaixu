#include <iostream>
using namespace std;
#pragma warning(disable:4996)

#define NUM 400000
string words[NUM];
int _count[NUM];
int totalWords = 0;

int _Hash(string word) {
	long n = 1;
	for (int i = 0; i < word.size(); i++) {
		n = n * (word[i] - ' ');
		n = n % (NUM - 3);
	}
	return n;
}

void _count_word2(string word) {
	int pos = _Hash(word);
	while (words[pos] != word && words[pos] != "") {
		pos++;
		pos = pos % (NUM - 3);
	}
	if (words[pos] == word) {
		_count[pos]++;
	}
	else {
		words[pos] = word;
		_count[pos] = 1;
	}
}

int main() {
	int n = 0;
	freopen("words", "r", stdin);
	for (int i = 0; i < NUM; i++) {
		_count[i] = -1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		_count_word2(word);
	}
	freopen("words.out", "w", stdout);
	for (int i = 0; i < NUM; i++) {
		if (_count[i] != -1) {
			cout << words[i] << "    " << _count[i] << endl;
		}
	}
	return 0;
}
