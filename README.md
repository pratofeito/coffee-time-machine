# 2022-1-TN-grupo02

Este projeto tem objetivo de desenvolver um protótipo de jogo no estilo RPG/Puzzle.

Utilizando conceitos de Programação Orientada à Objetos, foi criada uma base de código com as funcionalidades e mecânicas de um jogo 2d _top view_, junto com uma demonstração jogável.

- [Delimitação do Problema](#delimitação-do-problema)
- [Visão Geral sobre o Sistema](#visão-geral-sobre-o-sistema)
- [Classes e Funcionalidades](#classes-e-funcionalidades)
- [Organização do Projeto](#organização-do-projeto)
- [Execução e Compilação](#execução-e-compilação)
- [Pessoas Envolvidas](#pessoas-envolvidas)

## Delimitação do Problema

Para a execução da ideia, partir de elementos mais básicos seria de maior dificuldade e fugiria do escopo da disciplina. Dessa maneira, foi utilizada a biblioteca multimídia SFML para a aplicação de elementos essenciais como áudio, janelas e gráficos. Com isso conseguimos nos delimitar a apenas implementar TADs relativos às funcionalidades especiais do projeto, desde mais básicos como movimentação de personagem, cenários e contagem de status até mecânicas especiais.

## Visão Geral sobre o Sistema

TODO

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
│   ├── collision
│   ├── game
│   ├── instances
│   │   ├── audio
│   │   └── dialogue
│   └── sprite-set
├── libs
└── src
    ├── animation
    ├── collision
    ├── game
    ├── instances
    │   ├── audio
    │   └── dialogue
    └── sprite-set
```

## Execução e Compilação

TODO

## Pessoas Envolvidas

TODO