#include <iostream>

using namespace std;

const int N = 10;

void In(int m[N][N], int &r, int &c) {
    cout << "Enter rows and cols (max " << N << "): ";
    cin >> r >> c;
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
}

void Out(int m[N][N], int r, int c) {
    cout << "Matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void SumR(int m[N][N], int r, int c) {
    cout << "Row sums:\n";
    for (int i = 0; i < r; i++) {
        int s = 0;
        for (int j = 0; j < c; j++) {
            s += m[i][j];
        }
        cout << "Row " << i << ": " << s << endl;
    }
}

void SumC(int m[N][N], int r, int c) {
    cout << "Col sums:\n";
    for (int j = 0; j < c; j++) {
        int s = 0;
        for (int i = 0; i < r; i++) {
            s += m[i][j];
        }
        cout << "Col " << j << ": " << s << endl;
    }
}

void Add(int a[N][N], int b[N][N], int res[N][N], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void Sub(int a[N][N], int b[N][N], int res[N][N], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void Mul(int a[N][N], int b[N][N], int res[N][N], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Edit(int m[N][N], int r, int c, int i, int j, int v) {
    if (i >= 0 && i < r && j >= 0 && j < c) {
        m[i][j] = v;
        cout << "(" << i << ", " << j << ") = " << v << endl;
    } else {
        cout << "Invalid position!\n";
    }
}

bool Find(int m[N][N], int r, int c, int v) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == v) {
                cout << v << " at (" << i << ", " << j << ")\n";
                return true;
            }
        }
    }
    cout << v << " not found.\n";
    return false;
}

void Sort(int m[N][N], int r, int c) {
    for (int i = 0; i < r * c - 1; i++) {
        for (int j = 0; j < r * c - i - 1; j++) {
            int r1 = j / c, c1 = j % c;
            int r2 = (j + 1) / c, c2 = (j + 1) % c;

            if (m[r1][c1] > m[r2][c2]) {
                swap(m[r1][c1], m[r2][c2]);
            }
        }
    }
    cout << "Sorted.\n";
}

void Diag(int m[N][N], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += m[i][i];
    }
    cout << "Diagonal sum: " << s << endl;
}

void Zeros(int m[N][N], int r, int c) {
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == 0) cnt++;
        }
    }
    cout << "Zeros: " << cnt << endl;
}

void Check(int m[N][N], int r, int c) {
    bool up = true, low = true;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i > j && m[i][j] != 0) up = false;
            if (i < j && m[i][j] != 0) low = false;
        }
    }

    if (up) cout << "Upper triangular.\n";
    else if (low) cout << "Lower triangular.\n";
    else cout << "Neither.\n";
}

int main() {
    int a[N][N], b[N][N], res[N][N];
    int r1, c1, r2, c2;

    cout << "Matrix A:\n";
    In(a, r1, c1);

    cout << "Matrix B:\n";
    In(b, r2, c2);

    Out(a, r1, c1);
    Out(b, r2, c2);

    if (r1 == r2 && c1 == c2) {
        Add(a, b, res, r1, c1);
        cout << "Sum:\n";
        Out(res, r1, c1);

        Sub(a, b, res, r1, c1);
        cout << "Diff:\n";
        Out(res, r1, c1);


if (c1 == r2) {
            Mul(a, b, res, r1, c1, c2);
            cout << "Product:\n";
            Out(res, r1, c2);
        } else {
            cout << "Cannot multiply.\n";
        }
    } else {
        cout << "Cannot add or subtract.\n";
    }

    int v;
    cout << "Search in A: ";
    cin >> v;
    Find(a, r1, c1, v);

    int i, j, newV;
    cout << "Edit A (i, j): ";
    cin >> i >> j;
    cout << "New value: ";
    cin >> newV;
    Edit(a, r1, c1, i, j, newV);

    SumR(a, r1, c1);
    SumC(a, r1, c1);

    Diag(a, min(r1, c1));

    Zeros(a, r1, c1);

    Check(a, r1, c1);

    Sort(a, r1, c1);

    Out(a, r1, c1);

    return 0;
}
