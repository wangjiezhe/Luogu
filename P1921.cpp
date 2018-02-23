#include <iostream>
#include <iomanip>

using namespace std;
int main ()
{
  // N is the number of dice, Q is the number of sides of the dice, M is the number of turns of the game
  size_t N, M, Q;
  cin >> N >> M >> Q;

  // Possibility which dice would be used in the first turn (N)
  auto *Pi = new double[N];
  // Possibility for each dice to get a certain side (N*Q)
  auto **A = new double*[N];
  for (auto i = 0; i < N; ++i) {
    A[i] = new double[Q];
  }
  // A right stochastic matrix (N*N)
  auto **B = new double*[N];
  for (auto i = 0; i < N; ++i) {
    B[i] = new double[N];
  }
  // The result (M)
  auto *O = new size_t[M];

  for (auto i = 0; i < N; ++i) {
    cin >> Pi[i];
  }

  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < Q; ++j) {
      cin >> A[i][j];
    }
  }

  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      cin >> B[i][j];
    }
  }

  for (auto i = 0; i < M; ++i) {
    cin >> O[i];
  }

  // Possibility of the existence of a certain dice in some turn (M*N)
  auto **D = new double*[M];
  for (int i = 0; i < M; ++i) {
    D[i] = new double[N];
  }

  for (auto j = 0; j < N; ++j) {
    D[0][j] = Pi[j];
  }
  for (auto i = 1; i < M; ++i) {
    for (auto j = 0; j < N; ++j) {
      D[i][j] = 0;
      for (auto k = 0; k < N; ++k) {
        D[i][j] += D[i - 1][k] * B[k][j];
      }
    }
  }

  // The final possibility
  double p = 1;
  for (auto i = 0; i < M; ++i) {
    double q = 0;
    for (auto j = 0; j < N; ++j) {
      q += D[i][j] * A[j][O[i]];
    }
    p *= q;
  }

  cout << setprecision(4) << fixed;
  cout << p;

  delete[] Pi;
  for (auto i = 0; i < N; ++i) {
    delete[] A[i];
  }
  delete[] A;
  for (auto i = 0; i < N; ++i) {
    delete[] B[i];
  }
  delete[] B;
  delete[] O;
  for (auto i = 0; i < M; ++i) {
    delete[] D[i];
  }
  delete[] D;

  return 0;
}