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

    std::cout << std::endl << "Sobreome: ";
    std::cin >> sobrenome;

    std::cout << std::endl << "CPF: ";
    std::cin >> cpf;

    try {
        catalogo.adicionarCliente(new Cliente{nome + ' ' + sobrenome, cpf});
        std::cout << "Cliente cadastrado com sucesso" << std::endl;
    } catch (CPFInvalidoException &cpfe) {
        std::cout << "Erro de CPF: " << cpfe.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
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

    std::cout << "Qual é o tipo de veículo?" << std::endl
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
                std::cerr << e.what() << '\n';
            }

            std::cout << "Carro cadastrado com sucesso" << std::endl;

            break;

        case '2':
            int cilindrada;

            std::cout << std::endl << "Portas: ";
            std::cin >> cilindrada;

            try {
                catalogo.adicionarVeiculo(new Motocicleta(
                    marca, modelo, custo, capacidade, placa, cilindrada));
            } catch (std::exception& e) {
                std::cerr << e.what() << '\n';
            }

            break;

        default:
            std::cout << "Opção inválida" << std::endl;
            break;
    }
}

void Interface::criarContrato() {

    unsigned long cpf;
    unsigned int id, duracao;


    std::cout << "CPF do contratante: ";
    std::cin >> cpf;

    Cliente *cliente{nullptr};
    for (Cliente* c: catalogo.getClientes()) {
        if (c->getCpf() == cpf) {
            cliente = c;
            break;
        }
    }

    std::cout << "Id do veículo: ";
    std::cin >> id;

    Veiculo *veiculo{nullptr};
    for (Veiculo* v: catalogo.getVeiculos()) {
        if (v->getId() == id) {
            veiculo = v;
            break;
        }
    }

    std::cout << "Duracao: ";
    std::cin >> duracao;

    Contrato cont{cliente, veiculo, duracao};
}