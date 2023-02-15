#include "Console.hpp"

#include <iostream>
#include <iomanip>

#include "CPFInvalidoException.hpp"
#include "Marca.hpp"

using namespace locadora;

void Console::imprimirCatalogoVeiculos(const Catalogo& catalogo) {
    for (Veiculo* v : catalogo.getVeiculos()) {
        v->imprimirVeiculo();
    }
}

void Console::imprimirCatalogoMarcas(const Catalogo& catalogo) {
    for (Marca* m : catalogo.getMarcas()) {
        std::cout << m->getId() << ") " << m->getNome() << std::endl;
    }
}

void Console::imprimirVeiculosDisponiveis(const Catalogo& catalogo) {
    for (Veiculo* v : catalogo.getVeiculos()) {
        if (v->getStatus() == EnumStatus::DISPONIVEL) {
            v->imprimirVeiculo();
        }
    }
}

void Console::imprimirVeiculosMarca(const Catalogo& catalogo) {
    int id;
    std::cout << std::endl << "Marcas cadastradas:" << std::endl;
    Console::imprimirCatalogoMarcas(catalogo);
    std::cout << std::endl << "Escolha uma marca: ";
    std::cin >> id;
    Marca* marca = catalogo.getMarcaById(id);

    if (marca != nullptr) {
        for (Veiculo* v : (*marca).getVeiculos()) {
            v->imprimirVeiculo();
        }
    }
}

void Console::imprimirCatalogoClientes(const Catalogo& catalogo) {
    for (Cliente* c : catalogo.getClientes()) {
        std::cout << *c;
        std::cout << std::endl;
    }
}

void Console::imprimirClienteCpf(const Catalogo& catalogo) {
    Cliente* c;
    unsigned long cpf;
    std::cout << std::endl << "CPF do cliente: ";
    std::cin >> cpf;

    try {
        c = catalogo.getClienteByCPF(cpf);
        if (c != nullptr) {
            std::cout << (*c);
            return;
        }
    } catch (CPFInvalidoException &cpfe) {
        std::cout << "\033[31mErro de CPF: " << cpfe.what() << "\033[0m"
                  << std::endl;
        return;
    } catch (std::exception& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
        return;
    }

    std::cout << "\033[31mCliente não cadastrado!\033[0m" << std::endl;
}

void Console::imprimirContratosCliente(const Catalogo& catalogo) {
    unsigned long cpf;
    std::cout << std::endl << "CPF do cliente: ";
    std::cin >> cpf;
    Cliente* cliente = catalogo.getClienteByCPF(cpf);

    if (cliente != nullptr) {
        for (Contrato* c : (*cliente).getContratos()) {
            std::cout << *c << std::endl;
        }
    }
}