# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# include "linpack_d.h"
# include "blas1_d.h"

int main ( void );
void test01 ( void );
void test02 ( void );
void test03 ( void );
void test04 ( void );
void test05 ( void );
void test06 ( void );
void test07 ( void );
void test08 ( void );
void test09 ( void );
void test10 ( void );
void test11 ( void );
void test12 ( void );
void test13 ( void );
void test14 ( void );
void test15 ( void );
void test16 ( void );
void test17 ( void );
void test18 ( void );
void test19 ( void );
void test20 ( void );
void test21 ( void );
void test22 ( void );
void test23 ( void );
void test24 ( void );
void test25 ( void );
void test26 ( void );
void test27 ( void );
void test28 ( void );
void test29 ( void );
void test30 ( void );
void test31 ( void );
void r8mat_uniform_01 ( int m, int n, int *seed, double r[] );
void timestamp ( void );

/******************************************************************************/

int main ( void )

/******************************************************************************/
/*
  Purpose:

    LINPACK_D_PRB tests the double precision real LINPACK routines.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
  timestamp ( );

  printf ( "\n" );
  printf ( "LINPACK_D_PRB\n" );
  printf ( "  C version\n" );
  printf ( "  Test the LINPACK_D library.\n" );

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );

  test10 ( );
  test11 ( );
  test12 ( );
  test13 ( );
  test14 ( );
  test15 ( );
  test16 ( );
  test17 ( );
  test18 ( );
  test19 ( );

  test20 ( );
  test21 ( );
  test22 ( );
  test23 ( );
  test24 ( );
  test25 ( );
  test26 ( );
  test27 ( );
  test28 ( );
  test29 ( );

  test30 ( );
  test31 ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "LINPACK_D_PRB\n" );
  printf ( "  Normal end of execution.\n" );

  printf ( "\n" );
  timestamp ( );

  return 0;
}
/******************************************************************************/

void test01 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST01 tests DCHDC.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 4
# define LDA N

  double a[LDA*N];
  double b[LDA*N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  int k;
  double work[N];

  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  For a general matrix,\n" );
  printf ( "  DCHDC computes the Cholesky decomposition.\n" );
  printf ( "\n" );
  printf ( "  The number of equations is N = %d\n", N );
/*
  Set the values of the matrix A.
*/
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j-1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( i == j+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }

  printf ( "\n" );
  printf ( "  The matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Decompose the matrix.
*/
  printf ( "\n" );
  printf ( "  Decompose the matrix.\n" );

  job = 0;

  for ( i = 0; i < N; i++ )
  {
    ipvt[i] = 0;
  }

  info = dchdc ( a, LDA, N, work, ipvt, job );

  if ( info != N )
  {
    printf ( "\n" );
    printf ( "  DCHDC returned INFO = %d\n", info );
    printf ( "  This means the matrix is not positive definite.\n" );
    return;
  }
/*
  Zero out the lower diagonal.
*/
  for ( i = 2; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }
/*
  Print the factorization.
*/
  printf ( "\n" );
  printf ( "  The Cholesky factor U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Compute the Cholesky product.
*/
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + a[k-1+(i-1)*LDA] * a[k-1+(j-1)*LDA];
      }
    }
  }
  printf ( "\n" );
  printf ( "  The product U' * U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", b[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test02 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST02 tests DCHEX.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA N
# define NZ 1

  double a[LDA*N];
  double b[LDA*N];
  double c[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  int k;
  int l;
  double s[N];
  int seed;
  double work[N];
  double z[N];

  printf ( "\n" );
  printf ( "TEST02\n" );
  printf ( "  For a general matrix,\n" );
  printf ( "  DCHEX can shift columns in a Cholesky factorization.\n" );
  printf ( "\n" );
  printf ( "  The number of equations is N = %d\n", N );
/*
  Set the values of the matrix A.
*/
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j-1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( i == j+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
  for ( i = 1; i <= N; i++ )
  {
    z[i-1] = ( double ) i;
  }

  printf ( "\n" );
  printf ( "  The matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "  The vector Z:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %12f\n", z[i-1] );
  }
/*
  Decompose the matrix.
*/
  printf ( "\n" );
  printf ( "  Decompose the matrix.\n" );

  job = 0;

  for ( i = 0; i < N; i++ )
  {
    ipvt[i] = 0;
  }

  info = dchdc ( a, LDA, N, work, ipvt, job );

  if ( info != N )
  {
    printf ( "\n" );
    printf ( "  DCHDC returned INFO = %d\n", info );
    printf ( "  This means the matrix is not positive definite.\n" );
    return;
  }
/*
  Zero out the lower diagonal.
*/
  for ( i = 2; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }
/*
  Print the factorization.
*/
  printf ( "\n" );
  printf ( "  The Cholesky factor U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Right circular shift columns L through K.
*/
  k = 1;
  l = 3;

  printf ( "\n" );
  printf ( "  Right circular shift columns K = %d through L = %d\n", k, l );

  job = 1;
  dchex ( a, LDA, N, k, l, z, N, NZ, c, s, job );
/*
  Left circular shift columns K+1 through L.
*/
  printf ( "\n" );
  printf ( "  Left circular shift columns K+1 = %d through L = %d\n", k + 1, l );

  job = 2;
  dchex ( a, LDA, N, k+1, l, z, N, NZ, c, s, job );
/*
  Print the factorization.
*/
  printf ( "\n" );
  printf ( "  The shifted Cholesky factor U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "  The shifted vector Z:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %12f\n", z[i-1] );
  }
/*
 Compute the Cholesky product.
*/
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + a[k-1+(i-1)*LDA] * a[k-1+(j-1)*LDA];
      }
    }
  }

  printf ( "\n" );
  printf ( "  The shifted product U' * U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", b[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef N
# undef NZ
}
/******************************************************************************/

void test03 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST03 tests DCHUD.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define P 20
# define LDR P
# define NZ 1

  double b[P];
  double beta[P];
  double c[P];
  int i;
  int info;
  int j;
  int job;
  double r[LDR*P];
  double rho[NZ];
  double row[P];
  double s[P];
  int seed;
  double x[P];
  double y[NZ];
  double z[P*NZ];

  printf ( "\n" );
  printf ( "TEST03\n" );
  printf ( "  For a general matrix,\n" );
  printf ( "  DCHUD updates a Cholesky decomposition.\n" );
  printf ( "\n" );
  printf ( "  In this example, we use DCHUD to solve a\n" );
  printf ( "  least squares problem R * b = z.\n" );
  printf ( "\n" );
  printf ( "  The number of equations is P = %d\n", P );
/*
  Initialize.
*/
  for ( j = 1; j <= P; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      r[i-1+(j-1)*LDR] = 0.0;
    }
  }
  for ( j = 1; j <= NZ; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      z[i-1+(j-1)*P] = 0.0;
    }
  }

  for ( i = 1; i <= P; i++ )
  {
    x[i-1] = ( double ) i;
  }
/*
  Use DCHUD to form R, Z and RHO by adding X and Y a row at a time.
  X is a row of the least squares matrix and Y the right hand side.
*/
  seed = 123456789;

  for ( i = 1; i <= P; i++ )
  {
    r8mat_uniform_01 ( 1, P, &seed, row );
    y[0] = 0.0;
    for ( j = 1; j <= P; j++ )
    {
      y[0] = y[0] + row[j-1] * x[j-1];
    }
    rho[0] = 0.0;
    dchud ( r, LDR, P, row, z, P, NZ, y, rho, c, s );
  }
/*
  Generate the least squares solution, b = inverse ( R ) * Z.
*/
  for ( j = 1; j <= NZ; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      b[i-1] = z[i-1+(j-1)*P];
    }
    job = 01;

    info = dtrsl ( r, LDR, P, b, job );

    printf ( "\n" );
    printf ( "  Solution vector # %d\n", j );
    printf ( "  (Should be (1,2,3...,n))\n" );
    printf ( "\n" );

    for ( i = 1; i <= P; i++ )
    {
      if ( i <= 5 || P-5 < i )
      {
        printf ( "  %6d  %14f\n", i, b[i-1] );
      }
      if ( i == 5 )
      {
        printf ( "  ......  ..............\n" );
      }
    }
  }

  return;
# undef LDR
# undef NZ
# undef P
}
/******************************************************************************/

void test04 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST04 tests DGBCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 10
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  double a[LDA*N];
  int i;
  int ipivot[N];
  int j;
  int m;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST04\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGBCO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  m = ML + MU + 1;
  printf ( "  The bandwidth of the matrix is %d\n", m );

  for ( j = 1; j <= N; j++ )
  {
    a[m-2+(j-1)*LDA] = -1.0;
    a[m-1+(j-1)*LDA] =  2.0;
    a[m  +(j-1)*LDA] = -1.0;
  }
/*
  Estimate the condition.
*/
  printf ( "\n" );
  printf ( "  Estimate the condition.\n" );

  rcond = dgbco ( a, LDA, N, ML, MU, ipivot, z );

  printf ( "\n" );
  printf ( "  Estimated reciprocal condition = %f\n", rcond );

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
/******************************************************************************/

void test05 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST05 tests DGBFA and DGBSL.

  Discussion:

    The problem solved here is a larger version of this one:

    Matrix A is ( 2 -1  0  0  0)    right hand side B is  (1)
                (-1  2 -1  0  0)                          (0)
                ( 0 -1  2 -1  0)                          (0)
                ( 0  0 -1  2 -1)                          (0)
                ( 0  0  0 -1  2)                          (1)


    Solution is   (1)
                  (1)
                  (1)
                  (1)
                  (1)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Local Parameters:

    N is the number of equations.

    ML is the number of subdiagonals,
    MU the number of superdiagonals.

    LDA is the leading dimension of the array used to store the
    matrix, which must be at least 2*ML+MU+1.
*/
{
# define N 10
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int ipivot[N];
  int j;
  int job;
  int m;

  printf ( "\n" );
  printf ( "TEST05\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGBFA computes the LU factors,\n" );
  printf ( "  DGBSL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the right hand side B.
*/
  b[0] = 1.0;
  for ( i = 2; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = 1.0;
/*
  Set the matrix A.
*/
  m = ML + MU + 1;
  printf ( "  The bandwidth of the matrix is %d\n", m );

  for ( j = 1; j <= N; j++ )
  {
    a[m-2+(j-1)*LDA] = -1.0;
    a[m-1+(j-1)*LDA] =  2.0;
    a[m  +(j-1)*LDA] = -1.0;
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dgbfa ( a, LDA, N, ML, MU, ipivot );

  if ( info != 0 )
  {
    printf ( "  Error!  DGBFA returns INFO = %d\n", info );
    return;
  }
/*
  Call DGBSL to solve the linear system.  The solution
  is returned in B, that is, it overwrites the right hand side.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  job = 0;
  dgbsl ( a, LDA, N, ML, MU, ipivot, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,1,1,1,1,...,1,1))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
/******************************************************************************/

void test06 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST06 tests DGBFA and DGBDI.

  Discussion:

    Matrix A is ( 2 -1  0  0  0)
                (-1  2 -1  0  0)
                ( 0 -1  2 -1  0)
                ( 0  0 -1  2 -1)
                ( 0  0  0 -1  2)

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Local Parameters:

    N is the number of equations.

    ML is the number of subdiagonals,
    MU the number of superdiagonals.

    LDA is the leading dimension of the array used to store the
    matrix, which must be at least 2*ML+MU+1.
*/
{
# define N_MAX 128
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  double a[LDA*N_MAX];
  double det[2];
  int i;
  int ihi;
  int ilo;
  int info;
  int ipivot[N_MAX];
  int j;
  int m;
  int n;
  int n_log;

  printf ( "\n" );
  printf ( "TEST06\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGBFA factors the matrix,\n" );
  printf ( "  DGBDI computes the determinant as\n" );
  printf ( "    det = MANTISSA * 10^EXPONENT\n" );
  printf ( "\n" );
  printf ( "  Find the determinant of the -1,2,-1 matrix\n" );
  printf ( "  for N = 2, 4, 8, 16, 32, 64, 128.\n" );
  printf ( "\n" );
  printf ( "  (For this matrix, det ( A ) = N + 1.)\n" );
/*
  Set the matrix A.
*/
  m = ML + MU + 1;
  printf ( "  The bandwidth of the matrix is %d\n", m );
  printf ( "\n" );
  printf ( "       N    Mantissa       Exponent\n" );
  printf ( "\n" );

  n = 1;

  for ( n_log = 1; n_log <= 7; n_log++ )
  {
    n = 2 * n;

    for ( j = 1; j <= n; j++ )
    {
      for ( i = 1; i <= LDA; i++ )
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }

    for ( j = 1; j <= n; j++ )
    {
      i = j;
      a[i-j+ML+MU+(j-1)*LDA] = 2.0;
    }

    for ( j = 2; j <= n; j++ )
    {
      i = j - 1;
      a[i-j+ML+MU+(j-1)*LDA] = -1.0;
    }

    for ( j = 1; j <= n-1; j++ )
    {
      i = j + 1;
      a[i-j+ML+MU+(j-1)*LDA] = -1.0;
    }

    info = dgbfa ( a, LDA, n, ML, MU, ipivot );

    if ( info != 0 )
    {
      printf ( "  Error!  DGBFA returns INFO = %d\n", info );
      return;
    }

    dgbdi ( a, LDA, n, ML, MU, ipivot, det );

    printf ( "  %6d  %14f  %14f\n", n, det[0], det[1] );
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N_MAX
}
/******************************************************************************/

void test07 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST07 tests DGBFA and DGBSL.

  Discussion:

    DGBFA and DGBSL are for general banded matrices.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100
# define ML 25
# define MU 25
# define LDA ( 2 * ML + MU + 1 )

  double a[LDA*N];
  double b[N];
  int i;
  int ihi;
  int ilo;
  int info;
  int ipivot[N];
  int j;
  int job;
  int m;
  double temp;

  printf ( "\n" );
  printf ( "TEST07\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGBFA computes the LU factors,\n" );
  printf ( "  DGBSL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to matrix A and right hand side B.

  We want to try a problem with a significant bandwidth.
*/
  m = ML + MU + 1;
  printf ( "  The bandwidth of the matrix is %d\n", m );

  for ( j = 1; j <= N; j++ )
  {
    ilo = i4_max ( 1, j - MU );
    ihi = i4_min ( N, j + ML );

    temp = 0.0;
    for ( i = ilo; i <= ihi; i++ )
    {
      a[i-j+m-1+(j-1)*LDA] = -1.0;
      temp = temp - 1.0;
    }
    temp = temp + 1.0;
    a[m-1+(j-1)*LDA] = 4.0 - temp;
    b[j-1] = 4.0;
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dgbfa ( a, LDA, N, ML, MU, ipivot );

  if ( info != 0 )
  {
    printf ( "  Error!  DGBFA returns INFO = %d\n", info );
    return;
  }
/*
  Call DGBSL to solve the linear system.  The solution
  is returned in B, that is, it overwrites the right hand side.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  job = 0;
  dgbsl ( a, LDA, N, ML, MU, ipivot, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,1,1,1,1,...,1,1))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
/******************************************************************************/

void test08 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST08 calls DGECO and DGESL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt

  Local Parameters:

    LDA defines the maximum matrix size we will use.
*/
{
# define LDA 10

  double a[LDA*LDA];
  double b[LDA];
  int i;
  int ipvt[LDA];
  int job;
  int n;
  double rcond;
  double z[LDA];

  n = 3;

  printf ( "\n" );
  printf ( "TEST08\n" );
  printf ( "  For a general matrix,\n" );
  printf ( "  DGECO computes the LU factors and computes\n" );
  printf ( "  its reciprocal condition number;\n" );
  printf ( "  DGESL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", n );
/*
  Set the values of the matrix A.
*/
  a[0+0*LDA] = 1.0;
  a[0+1*LDA] = 2.0;
  a[0+2*LDA] = 3.0;

  a[1+0*LDA] = 4.0;
  a[1+1*LDA] = 5.0;
  a[1+2*LDA] = 6.0;

  a[2+0*LDA] = 7.0;
  a[2+1*LDA] = 8.0;
  a[2+2*LDA] = 0.0;
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  rcond = dgeco ( a, LDA, n, ipvt, z );

  printf ( "  The reciprocal matrix condition number = %f\n", rcond );

  if ( rcond + 1.0 == 1.0 )
  {
    printf ( "  Error!  The matrix is nearly singular!\n" );
    return;
  }
/*
  Set a right hand side.
*/
  b[0] = 6.0;
  b[1] = 15.0;
  b[2] = 15.0;
/*
  Solve the linear system.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  job = 0;
  dgesl ( a, LDA, n, ipvt, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Solution returned by DGESL\n" );
  printf ( "  (Should be (1,1,1))\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    printf ( "  %14f\n", b[i-1] );
  }
/*
  A second right hand side can be solved without refactoring a.
*/
  printf ( "\n" );
  printf ( "  Call DGESL for a new right hand\n" );
  printf ( "  side for the same, factored matrix.\n" );
/*
  Set the right hand side.
*/
  b[0] = 1.0;
  b[1] = 4.0;
  b[2] = 7.0;
/*
  Solve the system.
*/
  printf ( "\n" );
  printf ( "  Solve a linear system.\n" );

  job = 0;
  dgesl ( a, LDA, n, ipvt, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Solution returned by DGESL\n" );
  printf ( "  (should be (1,0,0))\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    printf ( "  %14f\n", b[i-1] );
  }
/*
  The transposed problem A'*X = B can be solved by DGESL
  as well, without any refactoring.
*/
  printf ( "\n" );
  printf ( "  Call DGESL for transposed problem.\n" );
/*
  Set the right hand side.
*/
  b[0] = 6.0;
  b[1] = 6.0;
  b[2] = -3.0;
/*
  Solve the transposed system.
*/
  printf ( "\n" );
  printf ( "  Call DGESL to solve a transposed linear system.\n" );

  job = 1;
  dgesl ( a, LDA, n, ipvt, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Solution returned by DGESL\n" );
  printf ( "  (should be (-1,0,1))\n" );
  printf ( "\n" );
  for ( i = 1; i <= n; i++ )
  {
    printf ( "  %14f\n", b[i-1] );
  }

  return;
# undef LDA
}
/******************************************************************************/

void test09 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST09 tests DGEFA and DGEDI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 3
# define LDA 3
/*
  Matrix listed by columns.
*/
  double a[LDA*N] = {
    1.0, 4.0, 7.0,
    2.0, 5.0, 8.0,
    3.0, 6.0, 0.0 };
  double det[2];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  double work[N];

  printf ( "\n" );
  printf ( "TEST09\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGEFA computes the LU factors;\n" );
  printf ( "  DGEDI computes the inverse and determinant.\n" );
  printf ( "  The matrix size is N = %d\n", N  );
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    printf ( "  Error!  The matrix is nearly singular!\n" );
    return;
  }
/*
  Get the inverse and determinant.
*/
  printf ( "\n" );
  printf ( "  Get the inverse and determinant.\n" );

  job = 11;
  dgedi ( a, LDA, N, ipvt, det, work, job );

  printf ( "\n" );
  printf ( "  The determinant = %f * 10^%f\n", det[0], det[1] );

  printf ( "\n" );
  printf ( "  The inverse matrix:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test10 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST10 tests DGEFA and DGESL.

  Discussion:

    Solve A*x = b where A is a given matrix, and B a right hand side.

    We will also assume that A is stored in the simplest
    possible way.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 3
# define LDA N
/*
  The entries of the matrix A are listed by columns.
*/
  double a[LDA*N] = {
    1.0, 4.0, 7.0,
    2.0, 5.0, 8.0,
    3.0, 6.0, 0.0 };
  double b[N] = { 6.0, 15.0, 15.0 };
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;

  printf ( "\n" );
  printf ( "TEST10\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGEFA computes the LU factors;\n" );
  printf ( "  DGESL solves a factored linear system;\n" );
  printf ( "\n" );
  printf ( "  The number of equations is N = %d\n", N );

  printf ( "\n" );
  printf ( "  The matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %14f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "  The right hand side B:\n" );
  printf ( "\n" );
  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %14f", b[i-1] );
  }
  printf ( "\n" );
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    printf ( "  DGEFA returned an error flag INFO = %d\n", info );
    return;
  }
/*
  Solve the system.
*/
  job = 0;
  dgesl ( a, LDA, N, ipvt, b, job );

  printf ( "\n" );
  printf ( "  DGESL returns the solution:\n" );
  printf ( "  (Should be (1,1,1))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %14f", b[i-1] );
  }
  printf ( "\n" );

  return;
# undef N
# undef LDA
}
/******************************************************************************/

void test11 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST11 tests DGEFA and DGESL.

  Discussion:

    In this example, we solve a relatively large linear system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100
# define LDA N

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;

  printf ( "\n" );
  printf ( "TEST11\n" );
  printf ( "  For a general banded matrix,\n" );
  printf ( "  DGEFA computes the LU factors;\n" );
  printf ( "  DGESL solves a factored linear system;\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to the matrix A and the right hand side B.

  The problem is just an enlarged version of the
  problem for N = 5, which is:

  Matrix A is ( n -1 -1 -1 -1)    Right hand side B is  (1)
              (-1  n -1 -1 -1)                          (1)
              (-1 -1  n -1 -1)                          (1)
              (-1 -1 -1  n -1)                          (1)
              (-1 -1 -1 -1  n)                          (1)

  Solution is   (1)
                (1)
                (1)
                (1)
                (1)
*/
  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 1.0;
  }

  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = ( double ) N;
      }
      else
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
    }
   }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    printf ( "  DGEFA returned an error flag INFO = %d\n", info );
    return;
  }
/*
  Solve the system.
*/
  printf ( "\n" );
  printf ( "  Solve the factored system.\n" );

  job = 0;
  dgesl ( a, LDA, N, ipvt, b, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,1,1,1,1,...,1,1))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test12 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST12 tests DGTSL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100

  double b[N];
  double c[N];
  double d[N];
  double e[N];
  int i;
  int info;

  printf ( "\n" );
  printf ( "TEST12\n" );
  printf ( "  For a general tridiagonal matrix,\n" );
  printf ( "  DGTSL factors and solves a linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
  printf ( "\n" );
/*
  Set up the linear system, by storing the values of the
  subdiagonal, diagonal, and superdiagonal in C, D, and E,
  and the right hand side in B.
*/
  c[0] = 0.0;
  for ( i = 2; i <= N; i++ )
  {
    c[i-1] = -1.0;
  }

  for ( i = 1; i <= N; i++ )
  {
    d[i-1] = 2.0;
  }

  for ( i = 1; i <= N-1; i++ )
  {
    e[i-1] = -1.0;
  }
  e[N-1] = 0.0;

  for ( i = 1; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( double ) ( N + 1 );
/*
 Factor the matrix and solve the system.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix and solve the system.\n" );

  info = dgtsl ( N, c, d, e, b );

  if ( info != 0 )
  {
    printf ( "\n" );
    printf ( "  DGTSL returns nonzero INFO = %d\n", info );
    return;
  }
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef N
}
/******************************************************************************/

void test13 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST13 tests DPBCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 10
# define LDA 2

  double a[LDA*N];
  int i;
  int info;
  int j;
  int m;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST13\n" );
  printf ( "  For a positive definite symmetric banded matrix,\n" );
  printf ( "  DPBCO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the number of nonzero diagonals.
*/
  m = 1;
/*
  Set the value of the subdiagonal and diagonal.
*/
  for ( j = 1; j <= N; j++ )
  {
    a[0+(j-1)*LDA] = -1.0;
    a[1+(j-1)*LDA] = 2.0;
  }

  printf ( "\n" );
  printf ( "  Estimate the condition.\n" );

  rcond = dpbco ( a, LDA, N, m, z );

  printf ( "\n" );
  printf ( "  Reciprocal condition  = %f\n", rcond );

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test14 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST14 tests DPBDI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N_MAX 128
# define LDA 2

  double a[LDA*N_MAX];
  double det[2];
  int i;
  int info;
  int j;
  int m;
  int n;
  int n_log;

  printf ( "\n" );
  printf ( "TEST14\n" );
  printf ( "  For a positive definite symmetric banded matrix,\n" );
  printf ( "  DPBDI computes the determinant as\n" );
  printf ( "    det = MANTISSA * 10^EXPONENT\n" );
  printf ( "\n" );
  printf ( "  Find the determinant of the -1,2,-1 matrix\n" );
  printf ( "  for N = 2, 4, 8, 16, 32, 64, 128.\n" );
  printf ( "\n" );
  printf ( "  (For this matrix, det ( A ) = N + 1.)\n" );
/*
  Set the number of  nonzero diagonals.
*/
  m = 1;

  printf ( "\n" );
  printf ( "       N    Mantissa       Exponent\n" );
  printf ( "\n" );

  n = 1;

  for ( n_log = 1; n_log <= 7; n_log++ )
  {
    n = 2 * n;

    a[0+0*LDA] =  0.0;
    for ( j = 2; j <= n; j++ )
    {
      a[0+(j-1)*LDA] = -1.0;
    }
    for ( j = 1; j <= n; j++ )
    {
      a[1+(j-1)*LDA] = 2.0;
    }

    info = dpbfa ( a, LDA, n, m );

    if ( info != 0 )
    {
      printf ( "  Error!  DPBFA returns INFO = %d\n", info );
      return;
    }

    dpbdi ( a, LDA, n, m, det );

    printf ( "  %6d  %14f  %14f\n", n, det[0], det[1] );
  }

  return;
# undef LDA
# undef N_MAX
}
/******************************************************************************/

void test15 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST15 tests DPBFA and DPBSL.

  Discussion:

    DPBFA and DPBSL are for a positive definite symmetric band matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 10
# define LDA 2

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int j;
  int m;

  printf ( "\n" );
  printf ( "TEST15\n" );
  printf ( "  For a positive definite symmetric banded matrix,\n" );
  printf ( "  DPBFA computes the LU factors.\n" );
  printf ( "  DPBSL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to matrix A and right hand side B.

  The problem is just an enlarged version of the
  problem for N = 5, which is:

  Matrix A is ( 2 -1  0  0  0)    right hand side B is  (1)
              (-1  2 -1  0  0)                          (0)
              ( 0 -1  2 -1  0)                          (0)
              ( 0  0 -1  2 -1)                          (0)
              ( 0  0  0 -1  2)                          (1)


  solution is   (1)
                (1)
                (1)
                (1)
                (1)

  Set the right hand side.
*/
  b[0] = 1.0;
  for ( i = 2; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = 1.0;
/*
  Set the number of nonzero diagonals.
*/
  m = 1;
/*
  Set the value of the subdiagonal and diagonal.
*/
  for ( j = 1; j <= N; j++ )
  {
    a[0+(j-1)*LDA] = -1.0;
    a[1+(j-1)*LDA] = 2.0;
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dpbfa ( a, LDA, N, m );

  if ( info != 0 )
  {
    printf ( "  Error!  DPBFA returns INFO = %d\n", info );
    return;
  }
/*
  Solve the linear system.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  dpbsl ( a, LDA, N, m, b );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,1,1,1,1,...,1,1))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }
  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test16 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST16 tests DPOCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA N

  double a[LDA*N];
  int i;
  int info;
  int j;
  int job;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST16\n" );
  printf ( "  For a positive definite symmetric banded matrix,\n" );
  printf ( "  DPOCO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }

  printf ( "\n" );
  printf ( "  Estimate the condition.\n" );

  rcond = dpoco ( a, LDA, N, z );

  printf ( "\n" );
  printf ( "  Reciprocal condition  = %f\n", rcond );

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test17 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST17 tests DPOFA and DPODI.

  Discussion:

    DPOFA factors a positive definite symmetric matrix,
    and DPODI can compute the determinant or the inverse.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA N

  double a[LDA*N];
  double det[2];
  int i;
  int info;
  int j;
  int job;

  printf ( "\n" );
  printf ( "TEST17\n" );
  printf ( "  For a positive definite symmetric matrix,\n" );
  printf ( "  DPOFA computes the LU factors.\n" );
  printf ( "  DPODI computes the inverse or determinant.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dpofa ( a, LDA, N );

  if ( info != 0 )
  {
    printf ( "  Error, DPOFA returns INFO = %d\n", info );
    return;
  }
/*
  Invert the matrix.
*/
  printf ( "\n" );
  printf ( "  Get the determinant and inverse.\n" );

  job = 11;
  dpodi ( a, LDA, N, det, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Determinant = %f * 10^%f\n", det[0], det[1] );
/*
  DPODI produces only the 'upper half triangle' of the inverse,
  which is actually symmetric.  Thus, the lower half could be
  produced by copying from the upper half.  However, the first row
  of A, as returned, is exactly the first row of the inverse.
*/
  printf ( "\n" );
  printf ( "  First row of inverse:\n" );
  printf ( "\n" );
  for ( j = 1; j <= N; j++ )
  {
    printf ( "  %12f", a[0+(j-1)*LDA] );
  }
  printf ( "\n" );

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test18 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST18 tests DPOFA and DPOSL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 20
# define LDA N

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int j;
  int job;
  double x[N];

  printf ( "\n" );
  printf ( "TEST18\n" );
  printf ( "  For a positive definite symmetric matrix,\n" );
  printf ( "  DPOFA computes the LU factors.\n" );
  printf ( "  DPOSL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }
/*
  Set the right hand side.
*/
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( double ) i;
  }
  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dpofa ( a, LDA, N );

  if ( info != 0 )
  {
    printf ( "  Error, DPOFA returns INFO = %d\n", info );
    return;
  }
/*
  Solve the linear system.
*/
  dposl ( a, LDA, N, b );
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test19 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST19 tests DPPCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5

  double a[(N*(N+1))/2];
  int i;
  int j;
  int k;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST19\n" );
  printf ( "  For a positive definite symmetric packed matrix,\n" );
  printf ( "  DPPCO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
/*
  Estimate the condition.
*/
  printf ( "\n" );
  printf ( "  Estimate the condition number.\n" );

  rcond = dppco ( a, N, z );

  printf ( "\n" );
  printf ( "  Reciprocal condition number = %f\n", rcond );

  return;
# undef N
}
/******************************************************************************/

void test20 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST20 tests DPPFA and DPPDI.

  Discussion:

    DPPFA factors a packed positive definite symmetric matrix,
    and DPPDI can compute the determinant or the inverse.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5

  double a[(N*(N+1))/2];
  double b[N*N];
  double det[2];
  int i;
  int info;
  int j;
  int job;
  int k;

  printf ( "\n" );
  printf ( "TEST20\n" );
  printf ( "  For a positive definite symmetric packed matrix,\n" );
  printf ( "  DPPFA computes the LU factors.\n" );
  printf ( "  DPPDI computes the inverse or determinant.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dppfa ( a, N );

  if ( info != 0 )
  {
    printf ( "\n" );
    printf ( "  Error, DPPFA returns INFO = %d\n", info );
    return;
  }
/*
  Invert the matrix.
*/
  printf ( "\n" );
  printf ( "  Get the determinant and inverse.\n" );

  job = 11;
  dppdi ( a, N, det, job );
/*
  Print the results.
*/
  printf ( "\n" );
  printf ( "  Determinant = %f * 10^%f\n", det[0], det[1] );
/*
  DPPDI produces only the 'upper half triangle' of the inverse,
  which is actually symmetric.  Thus, the lower half could be
  produced by copying from the upper half.  However, the first row
  of A, as returned, is exactly the first row of the inverse.
*/
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      b[i-1+(j-1)*N] = a[k-1];
      b[j-1+(i-1)*N] = a[k-1];
    }
  }

  printf ( "\n" );
  printf ( "  The inverse matrix:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %14f", b[i-1+(j-1)*N] );
    }
    printf ( "\n" );
  }

  return;
# undef N
}
/******************************************************************************/

void test21 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST21 tests DPPFA and DPPSL.

  Discussion:

    DPOFA factors a positive definite symmetric matrix,
    and DPOSL can solve a factored linear system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 20

  double a[(N*(N+1))/2];
  double b[N];
  int i;
  int info;
  int j;
  int job;
  int k;
  double x[N];

  printf ( "\n" );
  printf ( "TEST21\n" );
  printf ( "  For a positive definite symmetric packed matrix,\n" );
  printf ( "  DPPFA computes the LU factors.\n" );
  printf ( "  DPPSL solves a factored linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( double ) i;
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
  }
/*
  Set the matrix A.
*/
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
        b[i-1] = b[i-1] + a[k-1] * x[j-1];
        b[j-1] = b[j-1] + a[k-1] * x[i-1];
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
        b[i-1] = b[i-1] + a[k-1] * x[i-1];
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dppfa ( a, N );

  if ( info != 0 )
  {
    printf ( "\n" );
    printf ( "  Error, DPPFA returns INFO = %d\n", info );
    return;
  }
/*
  Solve the linear system.
*/
  dppsl ( a, N, b );
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }
  return;
# undef N
}
/******************************************************************************/

void test22 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST22 tests DPTSL.

  Discussion:

    DPTSL factors and solves a positive definite symmetric tridiagonal system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 20

  double b[N];
  double d[N];
  double e[N];
  int i;
  double x[N];

  printf ( "\n" );
  printf ( "TEST22\n" );
  printf ( "  For a positive definite symmetric tridiagonal matrix,\n" );
  printf ( "  DPTSL factors and solves a linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Set the matrix A.
*/
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( double ) i;
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
  }
  for ( i = 1; i <= N; i++ )
  {
    d[i-1] = 2.0;
  }
  for ( i = 1; i <= N-1; i++ )
  {
    e[i-1] = -1.0;
  }
  e[N-1] = 0.0;

  for ( i = 1; i <= N; i++ )
  {
    if ( 1 < i )
    {
      b[i-1] = b[i-1] + e[i-2] * x[i-2];
    }
    b[i-1] = b[i-1] + d[i-1] * x[i-1];
    if ( i < N )
    {
      b[i-1] = b[i-1] + e[i-1] * x[i];
    }
  }
/*
  Factor and solve the system.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix and solve the system.\n" );

  dptsl ( N, d, e, b );
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef N
}
/******************************************************************************/

void test23 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST23 tests DQRDC and DQRSL.

  Discussion:

    DQRDC and DQRSL compute the QR factorization, and use it
    to solve linear systems.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 3
# define P 3
# define LDA N

  double a[LDA*P] = {
    1.0, 1.0, 0.0,
    1.0, 0.0, 1.0,
    0.0, 1.0, 1.0 };
  double b[LDA*P];
  int i;
  int info;
  int ipvt[P];
  int j;
  int job;
  int k;
  double q[N*N];
  double qraux[P];
  double qty[N];
  double qy[N];
  double r[N*P];
  double rsd[N];
  double work[P];
  double xb[N];
  double y[N];

  printf ( "\n" );
  printf ( "TEST23\n" );
  printf ( "  For a general rectangular matrix,\n" );
  printf ( "  DQRDC computes the QR decomposition of a\n" );
  printf ( "  matrix, but does not return Q and R explicitly.\n" );
  printf ( "\n" );
  printf ( "  Show how Q and R can be recovered using DQRSL.\n" );
/*
  Print the matrix A.
*/
  printf ( "\n" );
  printf ( "  The matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Decompose the matrix.
*/
  printf ( "\n" );
  printf ( "  Decompose the matrix.\n" );

  job = 0;
  for ( j = 1; j <= P; j++ )
  {
    ipvt[j] = 0;
  }

  dqrdc ( a, LDA, N, P, qraux, ipvt, work, job );
/*
  Print out what DQRDC has stored in A...
*/
  printf ( "\n" );
  printf ( "  The packed matrix A which describes Q and R:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  ...and in QRAUX.
*/
  printf ( "\n" );
  printf ( "  The QRAUX vector, containing some additional\n" );
  printf ( "  information defining Q:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %12f", qraux[i-1] );
  }
  printf ( "\n" );
/*
  Print out the resulting R factor.
*/
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      if ( j < i )
      {
        r[i-1+(j-1)*N] = 0.0;
      }
      else
      {
        r[i-1+(j-1)*N] = a[i-1+(j-1)*LDA];
      }
    }
  }

  printf ( "\n" );
  printf ( "  The R factor:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      printf ( "  %12f", r[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Call DQRSL to extract the information about the Q matrix.
  We do this, essentially, by asking DQRSL to tell us the
  value of Q*Y, where Y is a column of the identity matrix.
*/
  job = 10000;

  for ( i = 1; i <= N; i++ )
  {
/*
  Set the vector Y.
*/
    for ( j = 1; j <= N; j++ )
    {
      y[j-1] = 0.0;
    }
    y[i-1] = 1.0;
/*
  Ask DQRSL to tell us what Q*Y is.
*/
    info = dqrsl ( a, LDA, N, P, qraux, y, qy, qty, b, rsd, xb, job );

    if ( info != 0 )
    {
      printf ( "  Error!  DQRSL returns INFO = %d\n", info );
      return;
    }
/*
  Copy QY into the appropriate column of Q.
*/
    for ( j = 1; j <= N; j++ )
    {
      q[j-1+(i-1)*N] = qy[j-1];
    }
  }
/*
  Now print out the Q matrix we have extracted.
*/
  printf ( "\n" );
  printf ( "  The Q factor:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", q[i-1+(j-1)*N] );
    }
    printf ( "\n" );
  }
/*
  Compute Q*R to verify that it equals A.
*/
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + q[i-1+(k-1)*N] * r[k-1+(j-1)*N];
      }
    }
  }
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The product Q * R:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      printf ( "  %12f", b[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef N
# undef P
}
/******************************************************************************/

void test24 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST24 tests DSICO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100
# define LDA N

  double a[LDA*N];
  int i;
  int ipvt[N];
  int j;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST24\n" );
  printf ( "  For a symmetric indefinite matrix,\n" );
  printf ( "  DSICO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to the matrix A and the right hand side B.
*/
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
/*
  Estimate the condition.
*/
  printf ( "\n" );
  printf ( "  Estimate the condition.\n" );

  rcond = dsico ( a, LDA, N, ipvt, z );

  printf ( "\n" );
  printf ( "  Estimated reciprocal condition = %f\n", rcond );

  return;
}
/******************************************************************************/

void test25 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST25 tests DSIFA and DSISL.

  Discussion:

    DSIFA and DSISL are for symmetric indefinite matrices.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100
# define LDA N

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int ipvt[N];
  int j;

  printf ( "\n" );
  printf ( "TEST25\n" );
  printf ( "  For a symmetric indefinite matrix,\n" );
  printf ( "  DSIFA factor a symmetric indefinite matrix;\n" );
  printf ( "  DSISL solves a factored linear system,\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to the matrix A and the right hand side B.
*/
  for ( i = 1; i < N; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( double ) ( N + 1 );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
/*
  Factor the matrix A.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dsifa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    printf ( "  Error!  DSIFA returns INFO = %d\n", info );
    return;
  }
/*
  Solve the linear system.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  dsisl ( a, LDA, N, ipvt, b );
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test26 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST26 tests DSPCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100

  double a[(N*(N+1))/2];
  int i;
  int ipvt[N];
  int j;
  int k;
  double rcond;
  double z[N];

  printf ( "\n" );
  printf ( "TEST26\n" );
  printf ( "  For a symmetric indefinite packed matrix,\n" );
  printf ( "  DSPCO estimates the reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to the matrix A.
*/
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[k-1] = -1.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
/*
  Estimate the condition.
*/
  printf ( "\n" );
  printf ( "  Estimate the condition.\n" );

  rcond = dspco ( a, N, ipvt, z );

  printf ( "\n" );
  printf ( "  Estimated reciprocal condition = %f\n", rcond );

  return;
# undef N
}
/******************************************************************************/

void test27 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST27 tests DSPFA and DSPSL.

  Discussion:

    DSPFA and DSPSL are for packed symmetric indefinite matrices.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 100

  double a[(N*(N+1))/2];
  double b[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int k;

  printf ( "\n" );
  printf ( "TEST27\n" );
  printf ( "  For a symmetric indefinite packed matrix,\n" );
  printf ( "  DSPFA computes the LU factors,\n" );
  printf ( "  DSPSL solves a factored linear system,\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Assign values to the matrix A and the right hand side B.
*/
  for ( i = 1; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( double ) ( N + 1 );

  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[k-1] = -1.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
/*
  Factor the matrix.
*/
  printf ( "\n" );
  printf ( "  Factor the matrix.\n" );

  info = dspfa ( a, N, ipvt );

  if ( info != 0 )
  {
    printf ( "  Error!  DSPFA returns INFO = %d\n", info );
    return;
  }
/*
  Solve the linear system.
*/
  printf ( "\n" );
  printf ( "  Solve the linear system.\n" );

  dspsl ( a, N, ipvt, b );
/*
  Print the result.
*/
  printf ( "\n" );
  printf ( "  The first and last 5 entries of solution:\n" );
  printf ( "  (Should be (1,2,3,4,5,...,n-1,n))\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      printf ( "  %6d  %14f\n", i, b[i-1] );
    }
    if ( i == 5 )
    {
      printf ( "  ......  ..............\n" );
    }
  }

  return;
# undef N
}
/******************************************************************************/

void test28 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST28 tests DSVDC.

  Discussion:

    DSVDC computes the singular value decomposition:

      A = U * S * V'

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define M 6
# define N 4

  double a[M*N];
  double b[M*N];
/*
  E must be dimensioned at least maximum(M+1,N).
*/
  double e[M+N];
  int i;
  int info;
  int j;
  int job;
  int k;
  int lda;
  int ldu;
  int ldv;
/*
  S must be dimensioned at least maximum(M+1,N).
*/
  double s[M+N];
  int seed;
  double sigma[M*N];
  double u[M*M];
  double v[N*N];
  double work[M];

  printf ( "\n" );
  printf ( "TEST28\n" );
  printf ( "  For an MxN matrix A in general storage,\n" );
  printf ( "  DSVDC computes the singular value decomposition:\n" );
  printf ( "    A = U * S * V'\n" );
  printf ( "\n" );
  printf ( "  Matrix rows M =    %d\n", M );
  printf ( "  Matrix columns N = %d\n", N );
/*
  Set A.
*/
  seed = 123456789;

  r8mat_uniform_01 ( M, N, &seed, a );

  printf ( "\n" );
  printf ( "  The matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %10f", a[(i-1)+(j-1)*M] );
    }
    printf ( "\n" );
  }
/*
  Decompose the matrix.
*/
  printf ( "\n" );
  printf ( "  Decompose the matrix.\n" );

  job = 11;
  lda = M;
  ldu = M;
  ldv = N;

  info = dsvdc ( a, lda, M, N, s, e, u, ldu, v, ldv, work, job );

  if ( info != 0 )
  {
    printf ( "\n" );
    printf ( "Warning:\n" );
    printf ( "  DSVDC returned nonzero INFO = %d\n", info );
    return;
  }

  printf ( "\n" );
  printf ( "  Singular values:\n" );
  printf ( "\n" );

  for ( i = 1; i <= i4_min ( M, N ); i++ )
  {
    printf ( "  %4d  %14f\n", i+1, s[i-1] );
  }

  printf ( "\n" );
  printf ( "  Left Singular Vector Matrix U:\n" );
  printf ( "\n" );

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= M; j++ )
    {
      printf ( "  %10f", u[(i-1)+(j-1)*M] );
    }
    printf ( "\n" );
  }

  printf ( "\n" );
  printf ( "  Right Singular Vector Matrix V:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %10f", v[(i-1)+(j-1)*N] );
    }
    printf ( "\n" );
  }

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        sigma[(i-1)+(j-1)*M] = s[i-1];
      }
      else
      {
        sigma[(i-1)+(j-1)*M] = 0.0;
      }
    }
  }
/*
  Verify that A = U * S * V'.
*/
  for ( i = 1; i <= M; i++ )
  {
    for ( k = 1; k <= N; k++ )
    {
      b[(i-1)+(k-1)*M] = 0.0;
      for ( j = 1; j <= N; j++ )
      {
      b[(i-1)+(k-1)*M] = b[(i-1)+(k-1)*M] + sigma[i-1+(j-1)*M] * v[k-1+(j-1)*N];
      }
    }
  }

  for ( i = 1; i <= M; i++ )
  {
    for ( k = 1; k <= N; k++ )
    {
      a[(i-1)+(k-1)*M] = 0.0;
      for ( j = 1; j <= M; j++ )
      {
      a[(i-1)+(k-1)*M] = a[(i-1)+(k-1)*M] + u[i-1+(j-1)*M] * b[j-1+(k-1)*M];
      }
    }
  }

  printf ( "\n" );
  printf ( "  The product U * S * V' (should equal A):\n" );
  printf ( "\n" );

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %10f", a[(i-1)+(j-1)*M] );
    }
    printf ( "\n" );
  }

  return;
# undef M
# undef N
}
/******************************************************************************/

void test29 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST29 tests DTRCO.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA N

  double a[LDA*N];
  int i;
  int j;
  int job;
  double rcond;
  int  seed = 123456789;
  double z[N];

  printf ( "\n" );
  printf ( "TEST29\n" );
  printf ( "  For a triangular matrix,\n" );
  printf ( "  DTRCO computes the LU factors and\n" );
  printf ( "  computes its reciprocal condition number.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Lower triangular matrix A.
*/
  r8mat_uniform_01 ( LDA, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  printf ( "\n" );
  printf ( "  Lower triangular matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  job = 0;
  rcond = dtrco ( a, LDA, N, z, job );

  printf ( "\n" );
  printf ( "  The reciprocal condition number = %f\n", rcond );
/*
  Upper triangular matrix A.
*/
  r8mat_uniform_01 ( LDA, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  printf ( "\n" );
  printf ( "  Upper triangular matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  job = 1;

  rcond = dtrco ( a, LDA, N, z, job );

  printf ( "\n" );
  printf ( "  The reciprocal condition number = %f\n", rcond );

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test30 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST30 tests DTRDI.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA N

  double a[LDA*N];
  double det[2];
  int i;
  int info;
  int j;
  int job;
  int seed = 123456789;

  printf ( "\n" );
  printf ( "TEST30\n" );
  printf ( "  For a triangular matrix,\n" );
  printf ( "  DTRDI computes the determinant or inverse.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Lower triangular matrix A.
*/
  r8mat_uniform_01 ( N, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  printf ( "\n" );
  printf ( "  Lower triangular matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  job = 110;

  info = dtrdi ( a, LDA, N, det, job );

  printf ( "\n" );
  printf ( "  The determinant = %f * 10^(%f).\n", det[0], det[1] );

  printf ( "\n" );
  printf ( "  The inverse matrix:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }
/*
  Upper triangular matrix A.
*/
  r8mat_uniform_01 ( N, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  printf ( "\n" );
  printf ( "  Upper triangular matrix A:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  job = 111;

  info = dtrdi ( a, LDA, N, det, job );

  printf ( "\n" );
  printf ( "  The determinant = %f * 10^(%f).\n", det[0], det[1] );

  printf ( "\n" );
  printf ( "  The inverse matrix:\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      printf ( "  %12f", a[i-1+(j-1)*LDA] );
    }
    printf ( "\n" );
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void test31 ( void )

/******************************************************************************/
/*
  Purpose:

    TEST31 tests DTRSL.

  Discussion:

    DTRSL solves triangular linear systems.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    26 July 2008

  Author:

    John Burkardt
*/
{
# define N 5
# define LDA 5

  double a[LDA*N];
  double b[N];
  int i;
  int info;
  int j;
  int job;
  int seed = 123456789;
  double x[N];

  printf ( "\n" );
  printf ( "TEST31\n" );
  printf ( "  For a triangular matrix,\n" );
  printf ( "  DTRSL solves a linear system.\n" );
  printf ( "  The matrix size is N = %d\n", N );
/*
  Lower triangular matrix A.
*/
  r8mat_uniform_01 ( N, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++)
  {
    x[i-1] = ( double ) ( i );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }

  printf ( "\n" );
  printf ( "  For a lower triangular matrix A,\n" );
  printf ( "  solve A * x = b\n" );

  job = 00;

  info = dtrsl ( a, LDA, N, b, job );

  printf ( "\n" );
  printf ( "  The solution (should be 1,2,3,4,5):\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %6d  %14f\n", i, b[i-1] );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[j-1+(i-1)*LDA] * x[j-1];
    }
  }

  printf ( "\n" );
  printf ( "  For a lower triangular matrix A,\n" );
  printf ( "  solve A' * x = b\n" );

  job = 10;

  info = dtrsl ( a, LDA, N, b, job );

  printf ( "\n" );
  printf ( "  The solution (should be 1,2,3,4,5):\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %6d  %14f\n", i, b[i-1] );
  }
/*
  Upper triangular matrix A.
*/
  r8mat_uniform_01 ( N, N, &seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++)
  {
    x[i-1] = ( double ) ( i );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }

  printf ( "\n" );
  printf ( "  For an upper triangular matrix A,\n" );
  printf ( "  solve A * x = b\n" );

  job = 01;

  info = dtrsl ( a, LDA, N, b, job );

  printf ( "\n" );
  printf ( "  The solution (should be 1,2,3,4,5):\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %6d  %14f\n", i, b[i-1] );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[j-1+(i-1)*LDA] * x[j-1];
    }
  }
  printf ( "\n" );
  printf ( "  For an upper triangular matrix A,\n" );
  printf ( "  solve A' * x = b\n" );

  job = 11;

  info = dtrsl ( a, LDA, N, b, job );

  printf ( "\n" );
  printf ( "  The solution (should be 1,2,3,4,5):\n" );
  printf ( "\n" );

  for ( i = 1; i <= N; i++ )
  {
    printf ( "  %6d  %14f\n", i, b[i-1] );
  }

  return;
# undef LDA
# undef N
}
/******************************************************************************/

void r8mat_uniform_01 ( int m, int n, int *seed, double r[] )

/******************************************************************************/
/*
  Purpose:

    R8MAT_UNIFORM_01 returns a unit pseudorandom R8MAT.

  Discussion:

    This routine implements the recursion

      seed = 16807 * seed mod ( 2**31 - 1 )
      unif = seed / ( 2**31 - 1 )

    The integer arithmetic never requires more than 32 bits,
    including a sign bit.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 October 2005

  Author:

    John Burkardt

  Reference:

    Paul Bratley, Bennett Fox, Linus Schrage,
    A Guide to Simulation,
    Second Edition,
    Springer, 1987,
    ISBN: 0387964673,
    LC: QA76.9.C65.B73.

    Bennett Fox,
    Algorithm 647:
    Implementation and Relative Efficiency of Quasirandom
    Sequence Generators,
    ACM Transactions on Mathematical Software,
    Volume 12, Number 4, December 1986, pages 362-376.

    Pierre L'Ecuyer,
    Random Number Generation,
    in Handbook of Simulation,
    edited by Jerry Banks,
    Wiley, 1998,
    ISBN: 0471134031,
    LC: T57.62.H37.

    Peter Lewis, Allen Goodman, James Miller,
    A Pseudo-Random Number Generator for the System/360,
    IBM Systems Journal,
    Volume 8, Number 2, 1969, pages 136-143.

  Parameters:

    Input, int M, N, the number of rows and columns.

    Input/output, int *SEED, the "seed" value.  Normally, this
    value should not be 0.  On output, SEED has
    been updated.

    Output, double R[M*N], a matrix of pseudorandom values.
*/
{
  int i;
  int i4_huge = 2147483647;
  int j;
  int k;

  if ( *seed == 0 )
  {
    printf ( "\n" );
    printf ( "R8MAT_UNIFORM_01 - Fatal error!\n" );
    printf ( "  Input value of SEED = 0.\n" );
    exit ( 1 );
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )
      {
        *seed = *seed + i4_huge;
      }
/*
  Although SEED can be represented exactly as a 32 bit integer,
  it generally cannot be represented exactly as a 32 bit real number!
*/
      r[i+j*m] = ( double ) ( *seed ) * 4.656612875E-10;
    }
  }

  return;
}
/******************************************************************************/

void timestamp ( void )

/******************************************************************************/
/*
  Purpose:

    TIMESTAMP prints the current YMDHMS date as a time stamp.

  Example:

    May 31 2001 09:45:54 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 October 2003

  Author:

    John Burkardt

  Parameters:

    None
*/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  size_t len;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  len = strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
