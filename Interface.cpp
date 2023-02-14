#include "Interface.hpp"

#include <iostream>

#include "Cliente.hpp"
#include "CPF.hpp"
#include "Carro.hpp"
#include "Console.hpp"
#include "Contrato.hpp"
#include "Marca.hpp"
#include "Motocicleta.hpp"
#include "CPFInvalidoException.hpp"

using namespace locadora;

extern Catalogo catalogo;

void Interface::cadastrarCliente() {
    std::string nome, sobrenome;
    unsigned long cpf;

    std::cout << std::endl << "Nome: ";
    std::cin >> nome;

    std::cout << std::endl << "Sobrenome: ";
    std::cin >> sobrenome;

    std::cout << std::endl << "CPF: ";
    std::cin >> cpf;

    try {
        catalogo.adicionarCliente(new Cliente{nome + ' ' + sobrenome, cpf});
        std::cout << "\033[32mCliente cadastrado com sucesso\033[0m" << std::endl;
    } catch (CPFInvalidoException &cpfe) {
        std::cout << "\033[31mErro de CPF: " << cpfe.what() << "\033[0m" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }
}

void Interface::cadastrarMarca() {
    std::string nome;

    std::cout << std::endl << "Nome: ";
    std::cin >> nome;

    catalogo.adicionarMarca(new Marca{nome});
}

void Interface::cadastrarVeiculo() {
    char op;
    int capacidade, id;
    std::string modelo, placa;
    float custo;

    std::cout << std::endl << "Marcas cadastradas:" << std::endl;
    Console::imprimirCatalogoMarcas(catalogo);
    std::cout << std::endl << "Escolha uma marca: ";
    std::cin >> id;
    Marca* marca = catalogo.getMarcaById(id);

    std::cout << std::endl << "Modelo: ";
    std::cin >> modelo;

    std::cout << std::endl << "Custo: ";
    std::cin >> custo;

    std::cout << std::endl << "Capacidade: ";
    std::cin >> capacidade;

    std::cout << std::endl << "Placa (sem -): ";
    std::cin >> placa;

    std::cout << std::endl
              << "Qual é o tipo de veículo?" << std::endl
              << "1) Carro" << std::endl
              << "2) Motocicleta" << std::endl
              << std::endl;

    std::cin >> op;

    switch (op) {
        case '1':
            int portas, categoria;

            std::cout << std::endl << "Portas: ";
            std::cin >> portas;

            std::cout << std::endl << "Categorias:" << std::endl;
            for (int i = 0; i <= (int)EnumCategoria::SUV; i++) {
                std::cout << i << ") " << nomeCategoria[(EnumCategoria)i]
                          << std::endl;
            }
            std::cout << std::endl << "Escolha uma categoria: ";
            std::cin >> categoria;

            try {
                catalogo.adicionarVeiculo(new Carro(marca, modelo, custo,
                                                    capacidade, placa, portas,
                                                    (EnumCategoria)categoria));
            } catch (std::exception& e) {
                std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
                return;
            }

            std::cout << "\033[32mCarro cadastrado com sucesso\033[0m" << std::endl;

            break;

        case '2':
            int cilindrada;

            std::cout << std::endl << "Cilindrada: ";
            std::cin >> cilindrada;

            try {
                catalogo.adicionarVeiculo(new Motocicleta(
                    marca, modelo, custo, capacidade, placa, cilindrada));
            } catch (std::exception& e) {
                std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
                return;
            }

            std::cout << "\033[32mMotocicleta cadastrada com sucesso\033[0m" << std::endl;

            break;

        default:
            std::cout << "\033[31mOpção inválida\033[0m" << std::endl;
            break;
    }
}

void Interface::criarContrato() {
    unsigned long cpf;
    unsigned int id, duracao;

    std::cout << "CPF do contratante: ";
    std::cin >> cpf;

    Cliente* cliente{nullptr};
    for (Cliente* c : catalogo.getClientes()) {
        if (c->getCpf() == cpf) {
            cliente = c;
            break;
        }
    }
    if (cliente == nullptr) {
        std::cout << "\033[31mCliente não existe\033[0m" << std::endl;
        return;
    }

    std::cout << "ID do veículo: ";
    std::cin >> id;

    Veiculo* veiculo{nullptr};
    for (Veiculo* v : catalogo.getVeiculos()) {
        if (v->getId() == id) {
            veiculo = v;
            break;
        }
    }
    if (veiculo == nullptr) {
        std::cout << "\033[31mVeículo não existe\033[0m" << std::endl;
        return;
    }

    std::cout << "Duracao: ";
    std::cin >> duracao;

    new Contrato{cliente, veiculo, duracao};
}