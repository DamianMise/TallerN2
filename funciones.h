float validarFloatRango(float a, float b);
void leerCadena(char *cadena, int n);
void registrarProducto(char nombres[][50], int *demanda, float *tiempo,
                       float *recursos, int *cantidad);
void mostrarProductos(char nombres[][50], int *demanda, float *tiempo,
                      float *recursos, int inicio, int fin);
int buscarProducto(char nombres[][50], int cantidad);
void editarProducto(char nombres[][50], int *demanda, float *tiempo,
                    float *recursos, int cantidad);
void eliminarProducto(char nombres[][50], int *demanda, float *tiempo,
                      float *recursos, int *cantidad);
void calcularProduccion(int *demanda, float *tiempo, float *recursos,
                        int cantidad, float *tiempoTotal, float *recursosTotal);
void verificarCapacidad(float tiempoTotal, float recursosTotal);
