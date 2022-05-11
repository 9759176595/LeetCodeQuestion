class Solution {
public:
    int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
	int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

	void dfs (int x, int y, vector<vector<char>>& board, vector<vector<char>>& temp) {
		if (temp[x][y] != 'E') {
			board[x][y] = temp[x][y];
			return;
		}
		board[x][y] = 'B';
		for (int i=0; i<8; i++) {
			int l = x+dx[i];
			int m = y+dy[i];
			if (l < 0 || l > board.size()-1) continue;
			if (m < 0 || m > board[0].size()-1) continue;
			if (board[l][m] == 'B') continue;
			dfs (l, m, board, temp);
		}
	}

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}
		vector<vector<char>> temp = board;

		for (int i=0; i<board.size(); i++) {
			for (int j=0; j<board[0].size(); j++) {
				if (temp[i][j] == 'B') temp[i][j] = 'E';
				if (temp[i][j] != 'B' && temp[i][j] != 'E' && temp[i][j] != 'M') temp[i][j] = 'E';
			}
		}

		for (int i=0; i<board.size(); i++) {
			for (int j=0; j<board[0].size(); j++) {
				if (temp[i][j] == 'M') {
					for (int l=0; l<8; l++) {
						int x = i+dx[l];
						int y = j+dy[l];
						if (x < 0 || x > board.size()-1) continue;
						if (y < 0 || y > board[0].size()-1) continue;
						if (temp[x][y] == 'M') continue;
						if (temp[x][y] == 'E') temp[x][y] = '0';
						temp[x][y] = char(temp[x][y]+1);
					}
				}
			}
		}
		dfs (click[0], click[1], board, temp);
		return board;
    }
};
