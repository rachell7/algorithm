#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
vector <vector <char>> board(5, vector<char>(5, 'a'));

bool inRange(int y, int x) {
	if (y >= 5 || x >= 5||x<0||y<0)
		return false;
	else
		return true;
}
bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x))
		return false;
	if (board[y][x] != word[0])
		return false;
	if (word.size() == 1)
		return true;
	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if(hasWord(nextY,nextX,word.substr(1)))
			return true;
	}
	return false;
}
int main(void) {
	int case_num;
	int i;
	int r, c;
	int flag = 0;
	int word_num,w;
	string word;
	cin >> case_num;
	int y = 3, x = 3;
	for (i = 0; i < case_num; i++) {
		for (r = 0; r < 5; r++) {
			for (c = 0; c < 5; c++) {
				cin >> board[r][c];
			}
		}
		cin >> word_num;
		for (w = 0; w < word_num; w++) {
			flag = 0;
			cin >> word;
			for (y = 0; y < 5; y++) {
				for (x = 0; x < 5; x++) {
					if (hasWord(y, x, word)) {
						cout << word << ' ' << "YES" << endl;
						flag = 1;
					}
				}
				if (flag == 1)
					break;
			}
			if (flag == 0) {
				cout << word << ' ' << "NO" << endl;
			}
		}

	}

}