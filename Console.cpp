#include "Console.hpp"

#include <iostream>
#include <iomanip>

#include "Marca.hpp"

using namespace locadora;

void Console::imprimirDadosCarro(const Carro& carro) {
    std::cout << carro;
    std::cout << "Portas: " << carro.getPortas() << '\n';
    std::cout << "Categoria: " << carro.getNomeCategoria() << '\n';
}

void Console::imprimirDadosMotocicleta(const Motocicleta& moto) {
    std::cout << moto;
    std::cout << "Cilindrada: " << moto.getCilindrada() << '\n';
}

void Console::imprimirCatalogoVeiculos(const Catalogo& catalogo) {
    for (Veiculo* v : catalogo.getVeiculos()) {
        std::cout << *v << std::endl;
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
            std::cout << *v;
            std::cout << std::endl;
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
            std::cout << *v;
            std::cout << std::endl;
        }
    }
}

void Console::imprimirCatalogoClientes(const Catalogo& catalogo) {
    for (Cliente* v : catalogo.getClientes()) {
        std::cout << *v;
        std::cout << std::endl;
    }
}

void Console::imprimirClienteCpf(const Catalogo& catalogo) {
    unsigned long cpf;
    std::cout << std::endl << "CPF do cliente: ";
    std::cin >> cpf;

    for (Cliente* c: catalogo.getClientes()) {
        if (c->getCpf().getNumero() == cpf) {
            std::cout << *c << std::endl;
            return;
        }
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