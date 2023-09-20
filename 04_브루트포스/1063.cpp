#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> string_to_integer;

    //switch문을 위해 문자열과 정수를 연결
    string_to_integer["R"] = 1;
    string_to_integer["L"] = 2;
    string_to_integer["B"] = 3;
    string_to_integer["T"] = 4;
    string_to_integer["RT"] = 5;
    string_to_integer["LT"] = 6;
    string_to_integer["RB"] = 7;
    string_to_integer["LB"] = 8;

    //king과 stone의 위치를 입력받음
    string king, stone;
    int n;
    string move;

    cin >> king >> stone >> n;

    while (n--) {
        cin >> move;

        int king_x = king[0] - 'A';  // 킹의 열 위치를 숫자로 변환
        int king_y = king[1] - '1';  // 킹의 행 위치를 숫자로 변환
        int stone_x = stone[0] - 'A';  // 돌의 열 위치를 숫자로 변환
        int stone_y = stone[1] - '1';  // 돌의 행 위치를 숫자로 변환

        switch (string_to_integer[move]) {
        case 1:
            // 움직였을 때 체스판을 벗어나는지 범위 체크
            if (king_x + 1 < 8) {
                king_x++;
                // king과 stone이 같은 위치에 있게 되면 stone을 king이 움직인 방향과 같은 방향으로 한 칸 이동
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x + 1 < 8) stone_x++;
                    // stone을 이동시켰을 때 체스판 범위를 벗어난다면 king도 원래 위치로 되돌린다
                    else king_x--;
                }
            }
            break;
        case 2:
            if (king_x - 1 >= 0) {
                king_x--;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x - 1 >= 0) stone_x--;
                    else king_x++;
                }
            }
            break;
        case 3:
            if (king_y - 1 >= 0) {
                king_y--;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_y - 1 >= 0) stone_y--;
                    else king_y++;
                }
            }
            break;
        case 4:
            if (king_y + 1 < 8) {
                king_y++;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_y + 1 < 8) stone_y++;
                    else king_y--;
                }
            }
            break;
        case 5:
            if (king_x + 1 < 8 && king_y + 1 < 8) {
                king_x++;
                king_y++;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x + 1 < 8 && stone_y + 1 < 8) {
                        stone_x++;
                        stone_y++;
                    }
                    else {
                        king_x--;
                        king_y--;
                    }
                }
            }
            break;
        case 6:
            if (king_x - 1 >= 0 && king_y + 1 < 8) {
                king_x--;
                king_y++;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x - 1 >= 0 && stone_y + 1 < 8) {
                        stone_x--;
                        stone_y++;
                    }
                    else {
                        king_x++;
                        king_y--;
                    }
                }
            }
            break;
        case 7:
            if (king_x + 1 < 8 && king_y - 1 >= 0) {
                king_x++;
                king_y--;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x + 1 < 8 && stone_y - 1 >= 0) {
                        stone_x++;
                        stone_y--;
                    }
                    else {
                        king_x--;
                        king_y++;
                    }
                }
            }
            break;
        case 8:
            if (king_x - 1 >= 0 && king_y - 1 >= 0) {
                king_x--;
                king_y--;
                if (king_x == stone_x && king_y == stone_y) {
                    if (stone_x - 1 >= 0 && stone_y - 1 >= 0) {
                        stone_x--;
                        stone_y--;
                    }
                    else {
                        king_x++;
                        king_y++;
                    }
                }
            }
            break;
        default:
            cout << "Wrong Input";
        }

        // 킹과 돌의 위치 업데이트
        king = char('A' + king_x) + to_string(king_y + 1);
        stone = char('A' + stone_x) + to_string(stone_y + 1);
    }

    cout << king << endl;
    cout << stone << endl;
    return 0;
}
