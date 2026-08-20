# 🏥 Sistema para manutenção de fila de hospital 

#### Esse programa implementa o sistema de um hospital, que realiza o atendimento de seus pacientes baseado em seu nível de urgência.

Para isso, foram utilizados:

- Um **struct PACIENTE**, que contém os dados pessoais da pessoa;
- Uma função **menu()**, em que se encontra a tela inicial do sistema;
- As funções básicas da manutenção da fila **(adicionar paciente, remover paciente, visualizar a fila atual)**;
- Minha biblioteca **heap.h**, que implementa uma max-heap - fundamental para o atendimento baseado na urgência do paciente.

## 🧱 Conceitos aplicados

- Alocação dinâmica de memória
-  Manipulação de dados do tipo void*
-  Manutenção de max-heap
-  Criação e utilização de bibliotecas locais 

## 💻 Como utilizar o código?

Para utilizar o código na sua máquina, **abra o terminal** e siga os passos abaixo:

### 1 - Copie o repositório para a sua máquina, utilizando os seguintes comandos:

```bash 
git clone https://github.com/samuelsilva07/fila-hospital.git
cd "pasta_do_arquivo"  
```

### 2 - Após acessar a pasta do programa, compile o código com o comando gcc abaixo:

```bash
gcc fila_hospital.c -o fila_hospital
```

### 3 - A seguir, execute-o digitando:

```bash
./"fila_hospital" // obs: sem a extensão .c
```

E pronto! O programa já estará funcionando e pronto para ser utilizado.

## ⭐ Obrigado por visitar esse repositório!

