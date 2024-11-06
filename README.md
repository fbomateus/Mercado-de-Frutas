# Mercado de Frutas

Este é um projeto de um sistema simples de gerenciamento de frutas em um mercado, desenvolvido em C como parte de um trabalho prático para a disciplina de Estruturas de Dados.

## Funcionalidades

O programa simula um mercado de frutas com as seguintes funcionalidades:

1. Cadastrar fruta
2. Listar frutas cadastradas
3. Buscar fruta por código
4. Alterar dados de uma fruta
5. Excluir fruta (se a quantidade for zero)
6. Vender fruta
7. Registrar vendas em um arquivo `vendas.txt`

## Estrutura do Projeto

```
mercado_frutas/
├── src/
│   ├── main.c               // Arquivo principal
│   ├── frutas.c             // Funções relacionadas às frutas
│   ├── frutas.h             // Declaração das funções e estrutura Fruta
│   ├── lista.c              // Funções de manipulação da lista ligada
│   ├── lista.h              // Declaração das funções da lista
│   ├── vendas.c             // Funções para registrar vendas
│   └── vendas.h             // Declaração das funções de vendas
├── data/
│   └── vendas.txt           // Registro de vendas
├── .gitignore               // Arquivo para ignorar certos arquivos no Git
├── Makefile                 // Arquivo para automatizar a compilação
└── README.md                // Documentação do projeto
```

## Requisitos

- GCC (GNU Compiler Collection)
- Make

## Instalação

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/fbomateus/Mercado-de-Frutas.git
   cd mercado_frutas
   ```

2. **Compile o projeto:**
   ```bash
   make
   ```

3. **Execute o programa:**
   ```bash
   ./mercado_frutas
   ```

## Uso

Após executar o programa, você verá um menu com as opções disponíveis. Escolha a opção desejada digitando o número correspondente e seguindo as instruções na tela.

## Compilação e Execução no VSCode (Linux)

1. **Instale o GCC e Make:**
   ```bash
   sudo apt update
   sudo apt install build-essential
   ```

2. **Instale o Visual Studio Code:**
   Baixe o pacote `.deb` do [site oficial do VSCode](https://code.visualstudio.com/) e instale-o usando:
   ```bash
   sudo dpkg -i code_*.deb
   sudo apt --fix-broken install
   ```

3. **Abra o projeto no VSCode:**
   ```bash
   code .
   ```

4. **Instale a extensão C/C++ da Microsoft.**
   No VSCode, vá para o painel de extensões (`Ctrl + Shift + X`) e procure por "C/C++".

5. **Configurar `tasks.json` para automatizar a compilação:**
   - Pressione `Ctrl + Shift + P` e selecione `Tasks: Configure Task`.
   - Escolha `Create tasks.json file from template`.
   - Selecione `Others`.
   - Configure o `tasks.json`:
     ```json
     {
         "version": "2.0.0",
         "tasks": [
             {
                 "label": "build",
                 "type": "shell",
                 "command": "make",
                 "group": {
                     "kind": "build",
                     "isDefault": true
                 },
                 "problemMatcher": ["$gcc"],
                 "detail": "Compila o projeto usando o Makefile."
             },
             {
                 "label": "run",
                 "type": "shell",
                 "command": "./mercado_frutas",
                 "group": {
                     "kind": "build",
                     "isDefault": false
                 },
                 "problemMatcher": [],
                 "detail": "Roda o executável compilado."
             }
         ]
     }
     ```

6. **Configurar `launch.json` para depuração:**
   - Pressione `Ctrl + Shift + D` para abrir o painel de depuração.
   - Clique em "create a launch.json file".
   - Escolha `C++ (GDB/LLDB)`.
   - Configure o `launch.json`:
     ```json
     {
         "version": "0.2.0",
         "configurations": [
             {
                 "name": "(gdb) Launch",
                 "type": "cppdbg",
                 "request": "launch",
                 "program": "${workspaceFolder}/mercado_frutas",
                 "args": [],
                 "stopAtEntry": false,
                 "cwd": "${workspaceFolder}",
                 "environment": [],
                 "externalConsole": false,
                 "MIMode": "gdb",
                 "setupCommands": [
                     {
                         "description": "Enable pretty-printing for gdb",
                         "text": "-enable-pretty-printing",
                         "ignoreFailures": true
                     }
                 ],
                 "preLaunchTask": "build",
                 "miDebuggerPath": "/usr/bin/gdb"
             }
         ]
     }
     ```

7. **Compile e execute o projeto:**
   - Para compilar, pressione `Ctrl + Shift + B`.
   - Para executar, vá até o terminal integrado do VSCode e digite:
     ```bash
     ./mercado_frutas
     ```
