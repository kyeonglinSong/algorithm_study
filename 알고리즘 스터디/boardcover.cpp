// 1990929 ������ ����

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// ���� ���
const int coverType[4][3][2] = {  // [Ÿ��][��ĭ�� ���²��][y/x];
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
		if (ny < 0 || ny >= H || nx < 0 || nx >= W) // ���� �ʰ�
			ok = false;
		else if ((board[ny][nx] += push) > 1) //������ ���
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
			if (!board[i][j]) // ���� ��ä����������
			{
				y = i;
				x = j;
				break;
			}
		if (y != -1)
			break;
	}

	if (y == -1)  // ���� ��� : ��� ä�����ִٸ� 1 ��ȯ
		return 1;
	int result = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, H, W, type, 1))
			result += cover(board, H, W);
		set(board, y, x, H, W, type, -1);  // �ٸ� ����� ���� ���� ������ ��� ġ��
	}
	return result;
}

int main()
{
	int test, H, W;
	int board[20][20]; // black=1, white=0
	char bw[20]; // black���� white����
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