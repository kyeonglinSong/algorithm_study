// 1990929 게임판 덮기

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 조각 모양
const int coverType[4][3][2] = {  // [타입][세칸중 몇번짼지][y/x];
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

bool set(int board[][20], int y, int x, int H, int W, int type, int push)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) // 범위 초과
			ok = false;
		else if ((board[ny][nx] += push) > 1) //겹쳐질 경우
			ok = false;
	}
	return ok;
}

int cover(int board[][20], int H, int W)
{
	int y = -1, x = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			if (!board[i][j]) // 아직 안채워져있으면
			{
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}

	if (y == -1)  // 기저 사례 : 모두 채워져있다면 1 반환
		return 1;
	int result = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, H, W, type, 1))
			result += cover(board, H, W);
		set(board, y, x, H, W, type, -1);  // 다른 경우의 수를 위해 덮었던 블록 치움
	}
	return result;
}

int main()
{
	int test, H, W;
	int board[20][20]; // black=1, white=0
	char bw[20]; // black인지 white인지
	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> H >> W;
		for (int j = 0; j < H; j++)
		{
			cin >> bw;
			for (int k = 0; k < W; k++)
				board[j][k] = (bw[k] == '#') ? 1 : 0;
		}

		cout << cover(board, H, W) << endl;
	}
	return 0;
}