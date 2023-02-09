#include <iostream>

#include "Marca.hpp"
#include "Veiculo.hpp"
#include "Cliente.hpp"
#include "Placa.hpp"
#include "Contrato.hpp"

using namespace locadora;

int main() {
    
    Placa p{"ABC1234"};
    Marca m{"Chevrolet"};
    Veiculo *v = new Veiculo{&m, "Astra", 10, 5, p};
    Cliente c{"Padre Kelson", 11111111111};
    Contrato *contrato = new Contrato{&c, v, 5};

    std::cout << "----- DADOS CONTRATO -----" << std::endl;
    std::cout << contrato->getCliente()->getNome() << " - " << contrato->getCliente()->getCpf() << std::endl;
    std::cout << contrato->getVeiculo()->getMarca()->getNome() << " - " 
        << contrato->getVeiculo()->getModelo() << " - " 
        << contrato->getVeiculo()->getPlaca() << std::endl;
    std::cout << "R$" << contrato->getPreco() << " (" << contrato->getDuracao() << " dias)" << std::endl;
    std::cout << "--------------------------" << std::endl;

    return 0;
}
