# 🏥 Simulação de fila de hospital 

#### Esse programa simula o sistema de uma hospital fictícia, que realiza o atendimento de seus pacientes baseado em seu nível de urgência.

Para isso, foram utilizados:
<ul>
    <li> Um <strong>struct PACIENTE</strong>, que contém os dados pessoais da pessoa;
    <li> Uma função <strong>menu()</strong>, em que se encontra a tela inicial do sistema;
    <li> As funções básicas da manutenção da fila <strong>(adicionar paciente, remover paciente, visualizar a fila atual)</strong>;
    <li> Minha biblioteca <strong>heap.h</strong>, que implementa uma max-heap - fundamental para o atendimento baseado na urgência do paciente.
</ul> 

## 🧱 Conceitos aplicados

<ul>
    <li> Alocação dinâmica de memória 
    <li> Manipulação de dados do tipo void*
    <li> Manutenção de max-heap
    <li> Criação e utilização de bibliotecas locais 
</ul>

## 💻 Como utilizar o código?

Para utilizar o código na sua máquina, <ins>abra o terminal</ins> e siga os passos abaixo:


### 1 - Copie o repositório para a sua máquina, utilizando os seguintes comandos:

```bash 
$ git clone https://github.com/samuelsilva07/fila-hospital.git
$ cd "pasta_do_arquivo" // obs: sem a extensão .c 
```

### 2 - Após acessar a pasta do programa, compile o código com o comando gcc abaixo:

```bash
gcc fila_hospital.c -o fila_hospital
```

### 3 - A seguir, execute-o digitando:

```bash
./"fila_hospital"
```

E pronto! O programa já estará funcionando e pronto para ser utilizado.

## ⭐ Obrigado por vistar esse repositório!

