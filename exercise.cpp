#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000005;

int f, s, g, u, d;
int number[MAX]; // Lưu số lần bấm nút nhỏ nhất để đi đến mỗi tầng

// mảng đóng vai trò là hàng đợi - queue,
// để triển khai thuật toán tìm kiếm theo chiều rộng.
queue<int> wait;

void BFS(int start)
{

    // Cho tầng đầu tiên vào hàng đợi, giá trị số lần bấm nút sẽ là 0
    number[start] = 0;
    wait.push(start);

    while (!wait.empty())
    {
        // Lần lượt pop ra và cập nhật trạng thái mới
        int tmp = wait.front();
        wait.pop();

        // Nếu gặp phải tầng đích thì dừng luôn
        if (tmp == g)
            break;

        // Nếu bấm lên trên
        if (tmp + u <= f && number[tmp + u] == -1)
        {
            number[tmp + u] = number[tmp] + 1;
            wait.push(tmp + u);
        }

        // Nếu bấm xuống dưới
        if (tmp - d >= 1 && number[tmp - d] == -1)
        {
            number[tmp - d] = number[tmp] + 1;
            wait.push(tmp - d);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;

    for (int i = 1; i <= f; i++)
        number[i] = -1;

    BFS(s);

    if (number[g] == -1)
        cout << "use the stairs" << endl;
    else
        cout << number[g] << endl;

    return 0;
}