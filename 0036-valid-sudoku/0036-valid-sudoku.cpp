class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         unordered_map<char, set<char>> rows;
        unordered_map<char, set<char>> columns;
        map<pair<int, int>, set<char>> square;
        for (int r = 0; r < 9; ++r) { //Each row must contain the digits 1-9
            for (int c = 0; c < 9; ++c) { //Each column must contain the digits 1-9
                if (board[r][c] == '.') //board[i][j] is a digit 1-9 or '.'
                continue;
             pair<int, int> square_idx = {r/3, c/3}; //Each of the nine 3 x 3 sub-boxes
                
             //checking rows and colums for same entry if found return loop with false
             //if different return true
                if (rows[r].find(board[r][c]) != rows[r].end() || 
                    columns[c].find(board[r][c]) != columns[c].end() ||
                    square[square_idx].find(board[r][c]) != square[square_idx].end()
                )
                 return false;

                rows[r].insert(board[r][c]);
                columns[c].insert(board[r][c]);
                square[square_idx].insert(board[r][c]);
            }
        }
        return true;
    }
};