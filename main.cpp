#include <iostream>


class ServicoFrete{ // Strategy
public:
   virtual float calcula(float peso)=0;
};

class Sedex: public ServicoFrete { // Classe concreta
public:
    float calcula(float peso){
        return peso * 2.3;
    }
};

class Jadlog: public ServicoFrete { // Classe concreta
public:
    float calcula(float peso){
        return peso * 1.8;
    }
};

/* Implemente uma nova transportadora com strategy!!
class AzulCargo{

};
 */

class ConsultaFrete{ // Contexto
private:
    ServicoFrete* transportadora;

public:
    ConsultaFrete(ServicoFrete* transportadora){
        this->transportadora = transportadora;
    }

    void setTransportadora(ServicoFrete* transportadora){
        this->transportadora = transportadora;
    }

    float Consulta(float peso){
        float valorFinal = this->transportadora->calcula(peso);
        return valorFinal;
    }

};

int main() {
    Sedex sedex = Sedex();
    ConsultaFrete consulta = ConsultaFrete(&sedex);

    float peso = 6.0; // Mude o peso para mudar os valores

    std::cout << " -------Preço do Frete--------\n";
    std::cout << " Sedex -------- " << "R$" <<consulta.Consulta(peso) << "\n";
    Jadlog jadlog = Jadlog();
    consulta.setTransportadora(&jadlog);
    std::cout << " Jadlog ------- " << "R$" << consulta.Consulta(peso) << "\n";
    std::cout << " -----------------------------\n";
    return 0;
}
