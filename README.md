# 2022-1-TN-grupo02

Este projeto tem objetivo de desenvolver um protótipo de jogo no estilo RPG/Puzzle.

Utilizando conceitos de Programação Orientada à Objetos, foi criada uma base de código com as funcionalidades e mecânicas de um jogo 2d _top view_, junto com uma demonstração jogável.

- [Delimitação do Problema](#delimitação-do-problema)
- [Visão Geral sobre o Sistema](#visão-geral-sobre-o-sistema)
- [Classes e Funcionalidades](#classes-e-funcionalidades)
- [Organização do Projeto](#organização-do-projeto)
- [Execução e Compilação](#execução-e-compilação)
- [Testando a Demo](#testando-a-demo)
- [Pessoas Envolvidas](#pessoas-envolvidas)

![image](https://user-images.githubusercontent.com/47651648/179138280-61121b12-af8b-450a-bac3-020804f497ae.png)

## Delimitação do Problema

Para a execução da ideia, partir de elementos mais básicos seria de maior dificuldade e fugiria do escopo da disciplina. Dessa maneira, foi utilizada a biblioteca multimídia SFML para a aplicação de elementos essenciais como áudio, janelas e gráficos. Com isso conseguimos nos delimitar a apenas implementar TADs relativos às funcionalidades especiais do projeto, desde mais básicos como movimentação de personagem, cenários e contagem de status até mecânicas especiais.

## Visão Geral sobre o Sistema

O sistema foi projetado a fim de obter uma base de fácil usabilidade para a criação de jogos no estilo 2d _top view_. Para isso, o programa possui diversas classes que lidam com as mecânicas básicas de um jogo. Contando com elementos relacionados a estrutura básica do jogo como o gameloop e os diferentes estados de jogo, e também com elementos que compõem a gameplay como o player e as diversas instancias que interagem com ele. 

## Classes e Funcionalidades

Foram adicionadas classes responsáveis por diferentes componentes da aplicação. Desde a mais básica, _Game_, responsável por gerenciar tempo de atualização dos frames e estados da aplicação até uma mais específica como _Dialogue_, responsável por apresentar um diálogo ao jogador.

A seguir a lista das classes junto de uma breve descrição:

- Animation:
- Audio:
- Background:
- Collision:
- Dialogue:
- DialogueTree:
- Game:
- GameState:
- Instance:
- Node:
- Npc:
- Player:
- SpriteSet:
- State:
- Wall:

## Organização do Projeto

O projeto está organizado em diferentes pastas, com arquivos únicos a cada classe. Há a separação entre contrato e implementação, de modo a favorecer a modularidade e obter mais componentes reutilizáveis.

Abaixo a árvore de pastas do repositório:

```
├── build
├── docs
├── doxygen
├── include
│   ├── animation
│   ├── audio
│   ├── collision
│   ├── dialogue
│   ├── game
│   ├── hud
│   ├── instances
│   └── sprite-set
├── libs
└── src
    ├── animation
    ├── audio
    ├── collision
    ├── dialogue
    ├── game
    ├── hud
    ├── instance
    └── sprite-set
```

## Execução e Compilação

Para executar o programa basta compilá-lo usando o comando _make_ e executá-lo com o comando _make run_

## Testando a Demo

O programa começa sua execução no estado de Menu e conta com três opções de seleção _New Game_, _Credits_, _Quit_. Clicando com o mouse em cima da opção _New Game_ você será redirecionado para a intro do jogo. Para passar os textos da intro é necessário pressionar a tecla _arrow right_, assim que todos os textos forem terminados o jogo irá começar. O objetivo é pegar e entregar os itens espalhados pelo cenário para os seus respectivos donos antes que o cronômetro zere.

Controles:
'Z' e 'X' para interagir com os objetos e selecionar as opções dentro do diálogo dos NPCs
'arrow_up', 'arrow_down', 'arrow_left', 'arrow_right' para movimentar o jogador
'S' para sair do menu de cráditos
 
## Pessoas Envolvidas

brisabn
heitoeu
mateuskrause
minipatch
