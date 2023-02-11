#include <iostream>

#include "Catalogo.hpp"
#include "Cliente.hpp"
#include "Console.hpp"
#include "Contrato.hpp"
#include "Interface.hpp"
#include "Marca.hpp"
#include "Placa.hpp"
#include "Veiculo.hpp"

#include  <unistd.h>

using namespace locadora;

Catalogo catalogo;

int main() {

    Marca *chev = new Marca{"Chevrolet"};
    catalogo.adicionarMarca(chev);
    Marca *volks = new Marca{"Volkswagen"};
    catalogo.adicionarMarca(volks);
    Marca *honda = new Marca{"Honda"};
    catalogo.adicionarMarca(honda);

    catalogo.adicionarVeiculo(new Veiculo{volks, "Fusca", 10, 5, "BJF2353"});
    catalogo.adicionarVeiculo(new Veiculo(chev, "Vectra", 10, 5, "ADF1F86"));
    catalogo.adicionarVeiculo(new Veiculo(chev, "Celta", 5, 5, "MDF1D59"));

    catalogo.adicionarVeiculo(new Carro(chev, "S10", 15, 2, "OFK3522", 2,
                                        locadora::EnumCategoria::CAMINHONETE));
    catalogo.adicionarVeiculo(
        new Motocicleta(honda, "CG150", 15, 2, "PRF1232", 150));

    Carro *onix = new Carro(chev, "Onix", 50, 5, "ACD1E45", 4,
                            locadora::EnumCategoria::HATCH);
    catalogo.adicionarVeiculo(onix);

    std::cout << std::endl
              << "Bem-vindo ao sistema de locação :)" << std::endl
              << std::endl;

    int op;

    while (true) {
        std::cout << "O que você quer fazer?" << std::endl
                  << "1) Cadastrar veículo" << std::endl
                  << "2) Listar veículos" << std::endl
                  << "3) Cadastrar marca" << std::endl
                  << "4) Listar marcas" << std::endl
                  << "5) Cadastrar cliente" << std::endl
                  << "6) Listar clientes" << std::endl
                  << "0) Fechar programa" << std::endl
                  << std::endl;

        std::cin >> op;

        switch (op) {
            case 1:
                Interface::cadastrarVeiculo();
                break;

            case 2:
                std::cout << "Veículos cadastrados:" << std::endl;
                Console::imprimirCatalogoVeiculos(catalogo);
                break;

            case 3:
                Interface::cadastrarMarca();
                break;

            case 4:
                std::cout << "Marcas cadastradas:" << std::endl;
                Console::imprimirCatalogoMarcas(catalogo);
                std::cout << std::endl;
                break;

            case 5:
                Interface::cadastrarCliente();
                break;

            case 6:
                Console::imprimirCatalogoClientes(catalogo);
                break;

            case 0:
                std::cout << "Até mais :)" << std::endl;
                for (Veiculo *v : catalogo.getVeiculos()) {
                    catalogo.removerVeiculo(v);
                }
                for (Marca *m : catalogo.getMarcas()) {
                    catalogo.removerMarca(m);
                }
                for (Cliente *c : catalogo.getClientes()) {
                    catalogo.removerCliente(c);
                }
                exit(0);
                break;

            default:
                std::cout << "Opção inválida" << std::endl;
                break;
        }
    }

    return 0;
}
