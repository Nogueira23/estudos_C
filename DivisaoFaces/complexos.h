typedef struct {
    float real;
    float imag;
} complexo;

complexo new_complexo(float real, float imag);

complexo sum_complexo(complexo a, complexo b);

float absolute_complexo(complexo a);

complexo complexo_le();

void complexo_imprime(complexo a);

int complexos_comparacao(complexo a);

complexo multiplicacao_complexo(complexo a, complexo b);

complexo conjugado_complexo(complexo a);