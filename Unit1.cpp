// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;

int exitflag = 0;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
}

#define realhere long double

// typedef struct
// {
// int ref1_on_step[100000];
// } TLayer;
//
// TLayer layers[10000];
// ---------------------------------------------------------------------------

#define REFLECTONE(DEEP) (pow(q,DEEP-1)*a*pow(q,DEEP-1)) // DEEP from 1

#define REFL_MAX 7

#define MAXDEEPN 1000000

realhere powbuff[(MAXDEEPN + 1) * 7];

int powbuffinit(realhere q, int maxdeep1)
{
  if (maxdeep1 * REFL_MAX > MAXDEEPN - 1)
  {
    ShowMessage(
      "Error   void powbuffinit(realhere q, int maxdeep1)  MAXDEEPN 1000000 ");
    return -1;
  }
  for (int i = 0; i < maxdeep1 * REFL_MAX; i++)
    powbuff[i] = pow(q, i);
  return 0;

}

#define powb(q, deep1) (powbuff[deep1])

long long sumofsamedeep[(MAXDEEPN + 1) * 7];

realhere m_3 = 0.0;
realhere m_5 = 0.0;
realhere m_7 = 0.0;

realhere pow2(realhere x, realhere y)
{
  return pow(x, y);
}

void fast(realhere N, realhere q)
{
  m_3 = (0.1e1 - pow2(q, 0.2e1 * N) * pow2(N + 0.1e1, 0.2e1) * q * q + pow2(q,
    0.4e1 * N) * (N + 0.1e1) * q * q - pow2(q, 0.2e1 * N) * pow2(N + 0.1e1,
    0.2e1) * pow2(q, 0.6e1) + 0.2e1 * pow2(q, 0.2e1 * N) * pow2(N + 0.1e1,
    0.2e1) * pow2(q, 0.4e1) - pow2(q, 0.4e1 * N) * (N + 0.1e1) * pow2(q,
    0.4e1) + 0.2e1 * pow2(q, 0.2e1 * N) * pow2(q, 0.6e1) * (N + 0.1e1) -
    0.6e1 * pow2(q, 0.2e1 * N) * pow2(q, 0.4e1) * (N + 0.1e1) + 0.6e1 * pow2(q,
    0.2e1 * N) * (N + 0.1e1) * q * q + 0.3e1 * N - 0.2e1 * pow2(q,
    0.2e1 * N) * (N + 0.1e1) + pow2(N + 0.1e1, 0.3e1) * pow2(q, 0.8e1) -
    0.2e1 * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.8e1) - 0.3e1 * pow2(N + 0.1e1,
    0.3e1) * pow2(q, 0.6e1) + (N + 0.1e1) * pow2(q, 0.8e1) +
    0.3e1 * pow2(N + 0.1e1, 0.3e1) * pow2(q, 0.4e1) - pow2(N + 0.1e1,
    0.3e1) * q * q + 0.8e1 * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.6e1) -
    0.5e1 * (N + 0.1e1) * pow2(q, 0.6e1) - 0.11e2 * pow2(N + 0.1e1,
    0.2e1) * pow2(q, 0.4e1) + 0.11e2 * (N + 0.1e1) * pow2(q, 0.4e1) +
    0.6e1 * pow2(N + 0.1e1, 0.2e1) * q * q - 0.10e2 * q * q * (N + 0.1e1) +
    0.5e1 * q * q - 0.2e1 * pow2(q, 0.4e1) + 0.3e1 * pow2(q, 0.2e1 * N) -
    pow2(q, 0.4e1 * N) + 0.4e1 * pow2(q, 0.2e1 * N) * pow2(q, 0.4e1) -
    0.7e1 * pow2(q, 0.2e1 * N) * q * q - pow2(q, 0.2e1 * N) * pow2(q, 0.6e1) +
    pow2(q, 0.4e1 * N) * pow2(q, 0.2e1 * N) * q * q - pow2(N + 0.1e1, 0.2e1)) /
    (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / (-q * q * (N + 0.1e1) + pow2(q,
    0.2e1 * N) + N) / (-q * q * (N + 0.1e1) + q * q + pow2(q, 0.2e1 * N) + N -
    0.1e1) * (-pow2(q, -0.2e1) * pow2(q * q - 0.1e1, -0.2e1) * pow2(q * q,
    N + 0.1e1) - (N + 0.1e1) * pow2(q, -0.4e1) * pow2(q * q,
    N + 0.2e1) / (q * q - 0.1e1) + q * q * pow2(q * q - 0.1e1, -0.2e1) * pow2(q,
    0.2e1 * N - 0.4e1) * pow2(q * q, N + 0.1e1) + pow2(q, 0.2e1 * N - 0.4e1)
    * pow2(q, 0.4e1) / (q * q - 0.1e1)) -
    (-pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.4e1) + 0.2e1 * (N + 0.1e1) * pow2(q,
    0.4e1) + 0.2e1 * pow2(N + 0.1e1, 0.2e1) * q * q - pow2(q, 0.4e1) -
    0.4e1 * q * q * (N + 0.1e1) - pow2(N + 0.1e1, 0.2e1) + q * q + pow2(q,
    0.4e1 * N) + 0.2e1 * N + 0.1e1) / (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) /
    (-q * q * (N + 0.1e1) + pow2(q, 0.2e1 * N) + N) *
    (-pow2(q, -0.2e1) * pow2(q * q - 0.1e1, -0.2e1) * pow2(q * q, N + 0.1e1) -
    (N + 0.2e1) * pow2(q, -0.4e1) * pow2(q * q, N + 0.3e1) / (q * q - 0.1e1) +
    q * q * pow2(q * q - 0.1e1, -0.2e1) * pow2(q, 0.2e1 * N - 0.2e1) * pow2
    (q * q, N + 0.1e1) + pow2(q, 0.2e1 * N - 0.2e1) * pow2(q,
    0.4e1) / (q * q - 0.1e1)) - (0.2e1 * pow2(q, 0.4e1 * N) * q * q -
    0.2e1 * pow2(q, 0.4e1 * N) * pow2(q, 0.4e1) + q * q - 0.2e1 * pow2(q,
    0.6e1) - pow2(q, 0.2e1 * N) - pow2(q, 0.4e1 * N) + pow2(q,
    0.2e1 * N) * q * q - pow2(q, 0.2e1 * N) * pow2(q, 0.6e1) + pow2(q,
    0.4e1 * N) * pow2(q, 0.2e1 * N) * q * q + 0.2e1 * pow2(q, 0.8e1)) /
    (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / (-0.2e1 * q * q + pow2(q,
    0.2e1 * N) + 0.1e1) / (-q * q + pow2(q, 0.2e1 * N)) *
    (-pow2(q, -0.2e1) * pow2(q * q - 0.1e1, -0.2e1) * pow2(q * q, N + 0.1e1) -
    q * q / (q * q - 0.1e1) + pow2(q * q - 0.1e1, -0.2e1) * pow2(q * q,
    N + 0.1e1)) + (-pow2(q, 0.4e1) + q * q - 0.1e1 + pow2(q, 0.4e1 * N)) /
    (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / (-0.2e1 * q * q + pow2(q,
    0.2e1 * N) + 0.1e1) * (-pow2(q, -0.2e1) * pow2(q * q - 0.1e1,
    -0.2e1) * pow2(q * q, N + 0.1e1) - 0.2e1 * pow2(q, 0.4e1) / (q * q - 0.1e1)
    + q * q * pow2(q * q - 0.1e1, -0.2e1) * pow2(q * q, N + 0.1e1));
  m_5 = (0.4e1 * pow2(q * q, N + 0.1e1) * pow2(q, 0.4e1) - 0.4e1 * N * pow2
    (q * q, N + 0.1e1) * pow2(q, 0.8e1) * pow2(q, 0.2e1 * N - 0.6e1) -
    0.2e1 * pow2(pow2(q, N), 0.2e1) * pow2(q * q, N + 0.1e1) * (N + 0.1e1)
    * q * q + 0.4e1 * N * pow2(q * q, N + 0.1e1) * pow2(q, 0.2e1 * N - 0.6e1)
    * pow2(q, 0.6e1) + 0.4e1 * N * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * pow2
    (q, 0.6e1) - 0.8e1 * N * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * pow2(q,
    0.4e1) + 0.4e1 * N * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * q * q +
    0.2e1 * pow2(pow2(q * q, N + 0.1e1), 0.2e1) * pow2(q, 0.2e1 * N - 0.8e1)
    * pow2(q, 0.6e1) + 0.4e1 * pow2(q * q, N + 0.1e1) * pow2(q,
    0.2e1 * N - 0.6e1) * pow2(q, 0.6e1) + 0.2e1 * pow2(pow2(q, N),
    0.2e1) * pow2(q * q, N + 0.1e1) * q * q + 0.3e1 * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * q * q + 0.2e1 * pow2(pow2(q, N), 0.2e1) * pow2(q * q,
    N + 0.1e1) * (N + 0.1e1) - pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * pow2(q,
    0.6e1) - 0.2e1 * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * pow2(q, 0.4e1) -
    pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.6e1) -
    0.2e1 * pow2(pow2(q, N), 0.4e1) * (N + 0.1e1) * pow2(q, 0.4e1) +
    0.2e1 * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.4e1) -
    0.5e1 * pow2(q * q, N + 0.1e1) * pow2(q, 0.4e1) * (N + 0.1e1) +
    0.2e1 * pow2(q * q, N + 0.1e1) * pow2(q, 0.10e2) * pow2(q,
    0.2e1 * N - 0.8e1) - 0.2e1 * pow2(q * q, N + 0.1e1) * pow2(q,
    0.8e1) * pow2(q, 0.2e1 * N - 0.6e1) + 0.6e1 * pow2(q * q,
    N) * q * q * pow2(pow2(q, N + 0.1e1), 0.2e1) + pow2(q * q,
    N + 0.1e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.4e1) - 0.2e1 * pow2(q * q,
    N + 0.1e1) * pow2(N + 0.1e1, 0.2e1) * q * q + 0.6e1 * (N + 0.1e1) * pow2
    (q * q, N + 0.1e1) * q * q + 0.2e1 * pow2(pow2(q, N), 0.4e1) * (N + 0.1e1)
    * q * q - pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.2e1) * q * q -
    0.2e1 * pow2(q * q, N + 0.1e1) * pow2(q, 0.2e1 * N - 0.8e1) * pow2(q,
    0.8e1) - pow2(q * q, N + 0.1e1) * (N + 0.1e1) + pow2(q * q,
    N + 0.1e1) * pow2(N + 0.1e1, 0.2e1) + 0.2e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) - 0.2e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * q * q -
    0.4e1 * pow2(q * q, N) * pow2(pow2(q, N + 0.1e1), 0.2e1)) * pow2(q, -0.2e1)
    * pow2(q * q - 0.1e1, -0.3e1) / (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1)
    / 0.2e1 - (0.2e1 * pow2(q, 0.4e1) + 0.2e1 * pow2(q, 0.6e1) -
    0.8e1 * pow2(pow2(q, N), 0.2e1) * pow2(q, 0.6e1) + 0.8e1 * N * pow2(pow2(q,
    N), 0.2e1) * pow2(q, 0.6e1) - 0.16e2 * N * pow2(pow2(q, N), 0.2e1) * pow2(q,
    0.4e1) + 0.8e1 * N * pow2(pow2(q, N), 0.2e1) * q * q + 0.2e1 * pow2(pow2(q,
    N), 0.2e1) * q * q + 0.8e1 * pow2(pow2(q, N), 0.2e1) * pow2(q, 0.4e1) -
    0.4e1 * pow2(pow2(q, N), 0.4e1) * pow2(q, 0.4e1) + 0.4e1 * pow2(pow2(q, N),
    0.4e1) * q * q - 0.4e1 * pow2(q, 0.4e1) * pow2(q * q, N) +
    0.2e1 * pow2(pow2(q * q, N + 0.1e1), 0.2e1) - 0.4e1 * N * pow2(q * q,
    N + 0.1e1) * pow2(q, 0.4e1) + 0.4e1 * N * pow2(q * q, N + 0.1e1) * q * q +
    0.6e1 * pow2(q * q, N) * pow2(q, 0.6e1) + 0.2e1 * pow2(q * q,
    N + 0.1e1) * q * q) * pow2(q, -0.2e1) * pow2(q * q - 0.1e1, -0.3e1) /
    (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / 0.2e1;

  m_7 = -(0.6e1 * pow2(q * q, N + 0.1e1) * q * q + 0.36e2 * N * N * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * pow2(q, 0.4e1) - 0.18e2 * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.4e1) - 0.24e2 * N * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * (N + 0.1e1) * q * q + 0.36e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) * N * pow2(pow2(q, N), 0.2e1) * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * (N + 0.1e1) - 0.12e2 * N * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * q * q + 0.6e1 * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) * q * q - 0.24e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * q * q * N * pow2(pow2(q, N), 0.2e1) * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * (N + 0.1e1) + 0.12e2 * N * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * pow2(q, 0.8e1) - 0.6e1 * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.8e1) - 0.24e2 * N * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * (N + 0.1e1) * pow2(q, 0.6e1) - 0.12e2 * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * pow2(q, 0.8e1) - 0.36e2 * N * N * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * pow2(q, 0.6e1) + 0.18e2 * N * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.6e1) + 0.48e2 * N * pow2(pow2(q,
    -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * (N + 0.1e1) * pow2(q, 0.4e1) + 0.12e2 * N * pow2(pow2(q,
    N + 0.1e1), 0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(q, 0.4e1) +
    0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * (N + 0.1e1) * q * q + 0.27e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) -
    0.12e2 * N * N * pow2(q * q, N + 0.1e1) * pow2(q * q, N) * pow2(q, 0.4e1) +
    0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * q * q * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) + 0.42e2 * N * pow2(q * q,
    N + 0.1e1) * pow2(q * q, N) * pow2(q, 0.4e1) - 0.12e2 * N * pow2(pow2(q,
    N + 0.1e1), 0.2e1) * pow2(pow2(q, N), 0.2e1) * q * q - 0.30e2 * pow2(pow2(q,
    N + 0.1e1), 0.2e1) * q * q * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) +
    0.24e2 * N * N * pow2(q * q, N + 0.1e1) * pow2(q * q, N) * q * q +
    0.12e2 * N * pow2(q * q, N + 0.1e1) * pow2(pow2(q * q, N), 0.2e1) * q * q -
    0.12e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * N * (N + 0.1e1) * pow2(pow2(q,
    N), 0.2e1) - 0.18e2 * pow2(q * q, N + 0.1e1) * pow2(q * q,
    N) * pow2(pow2(q, N), 0.2e1) * q * q - 0.12e2 * N * pow2(q * q,
    N + 0.1e1) * pow2(q * q, N) * pow2(pow2(q, N), 0.2e1) - 0.48e2 * N * pow2
    (q * q, N + 0.1e1) * pow2(q * q, N) * q * q - 0.3e1 * pow2(pow2(q,
    N + 0.1e1), 0.2e1) * pow2(q, 0.4e1) * pow2(pow2(q, N),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) + 0.15e2 * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) * pow2(q, 0.6e1) + 0.3e1 * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * pow2(N + 0.1e1, 0.2e1) * q * q - 0.9e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) * pow2(pow2(q, N), 0.2e1) * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(N + 0.1e1, 0.2e1) - 0.12e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) * N * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) -
    0.9e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * q * q * pow2(pow2(q, N),
    0.4e1) * pow2(pow2(q, -0.2e1), N + 0.1e1) * (N + 0.1e1) -
    pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.3e1) * q * q -
    0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q, 0.4e1) * pow2(pow2(q, N),
    0.2e1) * pow2(pow2(q, -0.2e1), N + 0.1e1) * (N + 0.1e1) +
    0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * q * q * pow2(pow2(q, N),
    0.2e1) * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(N + 0.1e1, 0.2e1) +
    0.24e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * q * q * N * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) - 0.11e2 * pow2(pow2(q, -0.2e1),
    N + 0.1e1) * pow2(pow2(q, N), 0.2e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * (N + 0.1e1) * q * q + 0.12e2 * N * pow2(q * q,
    N + 0.1e1) * pow2(q * q, N) * pow2(pow2(q, N), 0.2e1) * q * q +
    pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.3e1) * pow2(q, 0.8e1) +
    0.3e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.4e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.6e1) +
    0.3e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.8e1) +
    0.6e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.6e1) * (N + 0.1e1) * pow2(q, 0.4e1) +
    0.15e2 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.4e1) * (N + 0.1e1) * pow2(q, 0.6e1) -
    0.3e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.3e1) * pow2(q, 0.6e1) +
    0.2e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * (N + 0.1e1) * pow2(q, 0.8e1) -
    0.6e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.4e1) * pow2(N + 0.1e1, 0.2e1) * pow2(q, 0.4e1) -
    0.6e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.6e1) * (N + 0.1e1) * q * q -
    0.6e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.4e1) * (N + 0.1e1) * pow2(q, 0.4e1) +
    0.3e1 * pow2(pow2(q, -0.2e1), N + 0.1e1) * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(N + 0.1e1, 0.3e1) * pow2(q, 0.4e1) -
    0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N), 0.4e1) * q * q -
    0.24e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N), 0.2e1) * pow2(q,
    0.4e1) - 0.6e1 * pow2(q * q, N + 0.1e1) * pow2(pow2(q, N), 0.2e1) * pow2(q,
    0.4e1) - 0.6e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.4e1) * (N + 0.1e1) - 0.30e2 * pow2(q * q, N + 0.1e1) * pow2(q * q,
    N) * pow2(q, 0.4e1) - 0.3e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(N + 0.1e1, 0.2e1) * pow2(pow2(q, N), 0.2e1) -
    0.6e1 * pow2(q * q, N + 0.1e1) * pow2(pow2(q * q, N), 0.2e1) * pow2(pow2(q,
    N), 0.2e1) - 0.12e2 * pow2(q * q, N + 0.1e1) * pow2(pow2(q * q, N),
    0.2e1) * q * q + 0.3e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(pow2(q, N),
    0.2e1) * (N + 0.1e1) - 0.12e2 * N * N * pow2(q * q, N + 0.1e1) * pow2(q * q,
    N) - 0.12e2 * N * pow2(q * q, N + 0.1e1) * pow2(pow2(q * q, N), 0.2e1) +
    0.6e1 * pow2(q * q, N + 0.1e1) * pow2(q * q, N) * pow2(pow2(q, N), 0.2e1) +
    0.6e1 * N * pow2(q * q, N + 0.1e1) * pow2(q * q, N) - 0.9e1 * pow2(pow2(q,
    N + 0.1e1), 0.2e1) * pow2(q, 0.6e1) * pow2(N + 0.1e1, 0.2e1) -
    0.3e1 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q, 0.4e1) * pow2(N + 0.1e1,
    0.3e1) + 0.26e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q,
    0.6e1) * (N + 0.1e1) + 0.18e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q,
    0.4e1) * pow2(N + 0.1e1, 0.2e1) + 0.3e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * q * q * pow2(N + 0.1e1, 0.3e1) - 0.21e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) * (N + 0.1e1) - 0.9e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * q * q * pow2(N + 0.1e1, 0.2e1) - 0.6e1 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * q * q * (N + 0.1e1) + pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q,
    0.6e1) * pow2(N + 0.1e1, 0.3e1) + 0.6e1 * pow2(pow2(q, N),
    0.2e1) * pow2(q * q, N + 0.1e1) * q * q - 0.12e2 * pow2(pow2(q, N + 0.1e1),
    0.2e1) * pow2(q, 0.4e1) - pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(N + 0.1e1,
    0.3e1) + pow2(pow2(q, N + 0.1e1), 0.2e1) * (N + 0.1e1) -
    0.18e2 * pow2(pow2(q, N + 0.1e1), 0.2e1) * pow2(q, 0.6e1) -
    0.6e1 * pow2(q * q, N + 0.1e1) * pow2(q, 0.6e1)) * pow2(q, -0.2e1) * pow2
    (q * q - 0.1e1, -0.2e1) / (pow2(q, 0.6e1) - 0.3e1 * pow2(q, 0.4e1) +
    0.3e1 * q * q - 0.1e1) / (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / 0.6e1 +
    (-0.6e1 * pow2(q, 0.4e1) - 0.18e2 * pow2(q, 0.6e1) - 0.12e2 * N * N * pow2
    (q * q, N) * pow2(q, 0.4e1) + 0.6e1 * pow2(q, 0.4e1) * N * pow2(q * q, N) +
    0.12e2 * N * pow2(q, 0.6e1) * pow2(q * q, N) * pow2(pow2(q, N), 0.2e1) -
    0.6e1 * pow2(q, 0.8e1) - 0.12e2 * N * N * pow2(q, 0.8e1) * pow2(q * q, N) +
    0.42e2 * N * pow2(q, 0.8e1) * pow2(q * q, N) + 0.12e2 * N * pow2(q,
    0.6e1) * pow2(pow2(q * q, N), 0.2e1) - 0.18e2 * pow2(q, 0.6e1) * pow2(q * q,
    N) * pow2(pow2(q, N), 0.2e1) - 0.60e2 * N * pow2(q, 0.8e1) * pow2(pow2(q,
    N), 0.2e1) - 0.72e2 * N * N * pow2(q, 0.6e1) * pow2(pow2(q, N), 0.2e1) +
    0.96e2 * N * pow2(q, 0.4e1) * pow2(pow2(q, N), 0.4e1) +
    0.72e2 * N * N * pow2(q, 0.4e1) * pow2(pow2(q, N), 0.2e1) -
    0.48e2 * N * q * q * pow2(pow2(q, N), 0.4e1) - 0.24e2 * N * N * q * q * pow2
    (pow2(q, N), 0.2e1) + 0.24e2 * N * N * pow2(q, 0.8e1) * pow2(pow2(q, N),
    0.2e1) - 0.48e2 * N * pow2(q, 0.6e1) * pow2(pow2(q, N), 0.4e1) -
    0.6e1 * pow2(q, 0.4e1) * pow2(pow2(q * q, N), 0.2e1) * pow2(pow2(q, N),
    0.2e1) + 0.108e3 * N * pow2(pow2(q, N), 0.2e1) * pow2(q, 0.6e1) -
    0.24e2 * N * pow2(pow2(q, N), 0.2e1) * pow2(q, 0.4e1) - 0.24e2 * N * pow2
    (pow2(q, N), 0.2e1) * q * q - 0.24e2 * pow2(pow2(q, N), 0.2e1) * pow2(q,
    0.6e1) - 0.6e1 * pow2(pow2(q, N), 0.2e1) * q * q - 0.30e2 * pow2(pow2(q, N),
    0.2e1) * pow2(q, 0.4e1) - 0.48e2 * pow2(pow2(q, N), 0.4e1) * pow2(q,
    0.4e1) - 0.6e1 * pow2(pow2(q, N), 0.4e1) * q * q - 0.30e2 * pow2(q,
    0.8e1) * pow2(q * q, N) - 0.12e2 * pow2(q, 0.6e1) * pow2(pow2(q * q, N),
    0.2e1) + 0.48e2 * pow2(q, 0.6e1) * pow2(pow2(q, N), 0.4e1) +
    0.36e2 * pow2(q, 0.8e1) * pow2(pow2(q, N), 0.2e1) + 0.12e2 * pow2(q,
    0.4e1) * pow2(pow2(q, N), 0.6e1) - 0.12e2 * q * q * pow2(pow2(q, N),
    0.6e1) + 0.24e2 * pow2(q, 0.6e1) * N * N * pow2(q * q, N) - 0.12e2 * pow2(q,
    0.4e1) * N * pow2(pow2(q * q, N), 0.2e1) + 0.6e1 * pow2(q,
    0.4e1) * pow2(q * q, N) * pow2(pow2(q, N), 0.2e1) - 0.48e2 * pow2(q,
    0.6e1) * N * pow2(q * q, N) - 0.12e2 * pow2(q, 0.4e1) * N * pow2(q * q,
    N) * pow2(pow2(q, N), 0.2e1)) * pow2(q, -0.2e1) * pow2(q * q - 0.1e1,
    -0.2e1) / (pow2(q, 0.6e1) - 0.3e1 * pow2(q, 0.4e1) + 0.3e1 * q * q - 0.1e1)
    / (pow2(q, 0.4e1) - 0.2e1 * q * q + 0.1e1) / 0.6e1;

}

void __fastcall TForm1::Button1Click(TObject *Sender)
{

  int fastmethod = 1;
  if (!CheckBox1->Checked)
    fastmethod = 0;

  int i1, i2, i3, i4, i5, i6, i7;
  // memset(layers,0,sizeof(layers));
  int maxrefs = Form1->CSpinEdit1->Value;

  FormatSettings.DecimalSeparator = '.';
  realhere a = StrToFloat(Edit1->Text);
  realhere q = 1.0 - a;
//  int N = StrToInt(Edit2->Text);
  int N = Form1->CSpinEdit2->Value;;
  if (!fastmethod)
  {
    if (powbuffinit(q, N))
      return;
  }

  long long iters = 0;

  realhere relf = 0.0;

  for (int i = 1; i <= N; i++)
  { // 1 relf
    // relf = relf + powb(q,i-1)*a*powb(q,i-1);
    relf = relf + REFLECTONE(i);
    iters++;

  }

  realhere localpowb;
  realhere a3 = a * a * a;
  realhere a5 = a * a * a * a * a;
  realhere a7 = a * a * a * a * a * a * a;

  fast((realhere)N, q);

  if (!fastmethod)
  {

    memset(sumofsamedeep, 0, sizeof(sumofsamedeep));
    for (i1 = 2; i1 <= N; i1++)
    { // 1 relf
      for (i2 = 1; i2 <= i1 - 1; i2++)
      { // 2 relf
        for (i3 = i2 + 1; i3 <= N; i3++)
        { // 3 relf
          sumofsamedeep[(i1 - 1) + (i1 - i2 - 1) + (i3 - i2 - 1) + (i3 - 1)]++;
          iters++;
        }
        if (exitflag)
          return;

      }
      Application->ProcessMessages();
      Form1->Caption = "3reflections = " + IntToStr(i1 * 100 / N) + " %";
      Application->ProcessMessages();
    }

    localpowb = 0.0;
    for (int i = 0; i < N * 3; i++)
      localpowb = localpowb + (realhere)sumofsamedeep[i] * powb(q, i);
  }
  else
  {
  localpowb = m_3;
  }

  relf = relf + a3 * localpowb;

  if (maxrefs < 5)
    goto finish;

  if (!fastmethod)
  {

    memset(sumofsamedeep, 0, sizeof(sumofsamedeep));
    for (i1 = 2; i1 <= N; i1++)
    { // 1 relf
      for (i2 = 1; i2 <= i1 - 1; i2++)
      { // 2 relf
        for (i3 = i2 + 1; i3 <= N; i3++)
        { // 3 relf
          for (i4 = 1; i4 <= i3 - 1; i4++)
          { // 4 relf
            for (i5 = i4 + 1; i5 <= N; i5++)
            { // 5 relf
              sumofsamedeep[(i1 - 1) + (i1 - i2 - 1) + (i3 - i2 - 1) +
                (i3 - i4 - 1) + (i5 - i4 - 1) + (i5 - 1)]++;
              iters++;
            }
          }
        }
        if (exitflag)
          return;

      }
      Application->ProcessMessages();
      Form1->Caption = "5reflections = " + IntToStr(i1 * 100 / N) + " %";
      Application->ProcessMessages();
    }

    localpowb = 0.0;
    for (int i = 0; i < N * 5; i++)
      localpowb = localpowb + (realhere)sumofsamedeep[i] * powb(q, i);
  }
  else
  {
  localpowb = m_5;
  }
  relf = relf + a5 * localpowb;

  if (maxrefs < 7)
    goto finish;

  if (!fastmethod)
  {

    memset(sumofsamedeep, 0, sizeof(sumofsamedeep));
    for (i1 = 2; i1 <= N; i1++)
    { // 1 relf
      for (i2 = 1; i2 <= i1 - 1; i2++)
      { // 2 relf
        for (i3 = i2 + 1; i3 <= N; i3++)
        { // 3 relf
          for (i4 = 1; i4 <= i3 - 1; i4++)
          { // 4 relf
            for (i5 = i4 + 1; i5 <= N; i5++)
            { // 5 relf
              for (i6 = 1; i6 <= i5 - 1; i6++)
              { // 6 relf
                for (i7 = i6 + 1; i7 <= N; i7++)
                { // 7 relf
                  sumofsamedeep[(i1 - 1) + (i1 - i2 - 1) + (i3 - i2 - 1) +
                    (i3 - i4 - 1) + (i5 - i4 - 1) + (i5 - i6 - 1) +
                    (i7 - i6 - 1) + (i7 - 1)]++;
                  iters++;
                }
              }
            }
          }
        }
        if (exitflag)
          return;
      }
      if (exitflag)
        return;
      Application->ProcessMessages();
      Form1->Caption = "7reflections = " + IntToStr(i1 * 100 / N) + " %";
      Application->ProcessMessages();
    }

    // relf = relf + a7 *
    localpowb = 0.0;
    for (int i = 0; i < N * 7; i++)
      localpowb = localpowb + (realhere)sumofsamedeep[i] * powb(q, i);
  }
  else
  {
  localpowb = m_7;
  }

  relf = relf + a7 * localpowb;

finish:

  Memo1->Lines->Add(" ========= ");
  Memo1->Lines->Add("maxrefs = " + IntToStr(maxrefs));
  Memo1->Lines->Add("a = " + FloatToStr(a));
  Memo1->Lines->Add("N = " + IntToStr(N));
  Memo1->Lines->Add("members\\rays count = " + IntToStr(iters));
  Memo1->Lines->Add("relf = " + FloatToStr(relf));

}

// #undef powb(q, deep1)

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
  static int first = 1;
  if (first)
  {
    first = 0;
    Memo1->Clear();

  }
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  exitflag = 1;
}
// ---------------------------------------------------------------------------
