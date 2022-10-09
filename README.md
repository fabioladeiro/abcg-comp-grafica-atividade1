# Computação Gráfica - Atividade 1
Essa atividade tem por finalidade o desenvolvimento de uma aplicação que utiliza a plataforma ABCg e explora a interface gráfica da biblioteca Dear ImGui.

Aluna: Fabiola Filgueira Deiró dos Santos

RA: 11201721084

## Explicação
Essa aplicação consiste em um jogo "Adivinhe a cor" cujo intuito é acertar o número gerado aleatoriamente. Nesta foi utilizada a biblioteca ABCg para construção da inteface. A atividade está contida na pasta `./examples/adivinheonumero`, e contém 4 arquivos principais:
- main.cpp
- window.cpp
- window.hpp
- CMakeLists.txt

Para construção do jogo, foram criados 6 botões com os números de 1 a 6 respectivamente, o objetivo é acertar o número que foi gerado randômicamente. O jogo tem 4 estados, o primeiro é quando aguarda o jogador selecionar um número, ao clicar, a aplicação verifica se o número escolhido é o número que foi gerado, se sim, é mostrado na tela que o jogador ganhou, se não, aparece a mensagem de perda. Em ambos os casos é necessário selecionar o botão "Restart Game", para jogar novamente. Esse botão fica no fim da tela, mas também é possível reiniciar o jogo através do menu inicial.

## Página web

Essa atividade está disponível em uma página web com a aplicação rodando em WebAssembly: https://fabioladeiro.github.io/abcg-comp-grafica-atividade1/project/

## Requerimentos

-   [CMake](https://cmake.org/) 3.21.
-   Um compilador C++ com suporte pelo menos parcial para C++20 (testado with GCC 11, Clang 13, MSVC 17, e emcc 3.1).
-   Um sistema com suporte para OpenGL 3.3 (OpenGL backend) or Vulkan 1.3 (Vulkan backend).

Para WebAssembly:

-   [Emscripten](https://emscripten.org/).
-   Um browser com suporte para WebGL 2.0.

Para criar aplicações de desktop:

-   [SDL](https://www.libsdl.org/) 2.0.
-   [SDL_image](https://www.libsdl.org/projects/SDL_image/) 2.0.
-   [GLEW](http://glew.sourceforge.net/) 2.2.0 (required for OpenGL-based applications).
-   [Vulkan](https://www.lunarg.com/vulkan-sdk/) 1.3 (required for Vulkan-based applications).

* * *

## Instalação e uso

Clonando o repositório:

    git clone https://github.com/fabioladeiro/abcg-comp-grafica-atividade1.git
    cd abcg

### Windows

-   Execute `build-vs.bat` para build com o Visual Studio 2022.
-   Execute `build.bat` para build com GCC (MinGW-w64).

### Linux and macOS

Execute `./build.sh`.

### WebAssembly

1.  Execute `build-wasm.bat` (Windows) ou `./build-wasm.sh` (Linux/macOS).
2.  Execute `runweb.bat` (Windows) or `./runweb.sh` (Linux/macOS) para executar o servidor web local.
3.  Abra <http://localhost:8080/adivinheonumero.html>.
