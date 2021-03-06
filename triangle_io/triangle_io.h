void element_data_example ( int element_num, int element_order,
  int element_att_num, int element_node[], double element_att[] );
void element_data_read ( char *element_file, int element_num, int element_order,
  int element_att_num, int element_node[], double element_att[] );
void element_size_example ( int *element_num, int *element_order,
  int *element_att_num );
void element_size_read ( char *element_file, int *element_num,
  int *element_order, int *element_att_num );
void element_write ( char *element_file, int element_num, int element_order,
  int element_att_num, int element_node[], double element_att[] );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
void i4mat_copy ( int m, int n, int a1[], int a2[] );
void i4mat_transpose_print_some ( int m, int n, int a[], int ilo, int jlo,
  int ihi, int jhi, char *title );
void i4vec_copy ( int n, int a1[], int a2[] );
void node_data_example ( int node_num, int node_dim, int node_att_num,
  int node_marker_num, double node_coord[], double node_att[],
  int node_marker[] );
void node_data_read ( char *node_file, int node_num, int node_dim,
  int node_att_num, int node_marker_num, double node_coord[], double node_att[],
  int node_marker[] );
void node_size_example ( int *node_num, int *node_dim, int *node_att_num,
  int *node_marker_num );
void node_size_read ( char *node_file, int *node_num, int *node_dim,
  int *node_att_num, int *node_marker_num );
void node_write ( char *node_file, int node_num, int node_dim,
  int node_att_num, int node_marker_num, double node_coord[],
  double node_att[], int node_marker[] );
void r8mat_copy ( int m, int n, double a1[], double a2[] );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, char *title );
void timestamp ( void );

