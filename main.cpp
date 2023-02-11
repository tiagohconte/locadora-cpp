#include <iostream>

#include "Marca.hpp"
#include "Veiculo.hpp"
#include "Cliente.hpp"
#include "Placa.hpp"
#include "Contrato.hpp"
#include "Catalogo.hpp"
#include "Console.hpp"

using namespace locadora;

int main() {
    
    Catalogo catalogo;
    Placa p{"ABC1234"};
    Marca m{"Chevrolet"};
    Veiculo *v1 = new Veiculo{&m, "Astra", 10, 5, p};
    catalogo.adicionaVeiculo(v1);
    Veiculo *v2 = new Veiculo(&m, "Vectra", 10, 5, p);
    catalogo.adicionaVeiculo(v2);
    Veiculo *v3 = new Veiculo(&m, "Celta", 5, 5, p);
    catalogo.adicionaVeiculo(v3);
    Veiculo *v4 = new Veiculo(&m, "S10", 15, 2, p);
    catalogo.adicionaVeiculo(v4);

    for (Veiculo *v: catalogo.getCatalogo()) {
        Console::imprimirDadosVeiculo(*v);
        std::cout << std::endl;
    }
    
    return 0;
}
