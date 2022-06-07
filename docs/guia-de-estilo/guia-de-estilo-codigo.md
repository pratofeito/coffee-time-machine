# Guia de Estilo de Código

Inspirado no guia de estilo do [Inkscape](https://inkscape.org/pt-br/desenvolvimento/estilo-de-codificacao/).

## Indentação, espaçamento e chaves

Segue a definição padrão do Visual Studio Code. Código de exemplo:

```
namespace PF
{
    namespace UI
    {

        Sandwich make_sandwich(int x);
        int make_a_mess(float y);

    }
}

class Loc
    : public Nonsense,
      protected Public
{
public:
    Loc()
        : _x(1024), _y(42)
    {
    }

private:
    void _forget();
    int _x, _y;
};

template <typename Basket>
void fill_basket(Basket &b)
{
    switch (a)
    {
    case 1:
        do_one();
        break;

    case 2:
        do_two();
        break;

    default:
        break;
    }

    for (int i = 0; i < 30; ++i)
    {
        b << PF::UI::make_sandwich();
    }
    return b;
}
```

## Convenções de nomenclatura

Macros e constantes usam _UPPER_SNAKE_CASE_. Em todos os outros momentos será utilizado _lower_snake_case_.

Nomes de variáveis devem ser substantivos. Nomes de função devem ser verbos, com exceção de métodos acessores de obtenção de valor (_getter_), que podem ser substantivos. Classes são substantivos começados em letra maiúscula.

### Convenções de nome de arquivo

Todos os arquivos a serem desenvolvidos deverão ter nome no estilo _minúsculas-com-hifens_. Não são permitidos espaços, letras maiusculas e caracteres de sublinhado. Usar números em nomes de arquivo não é recomendado.

## Layout de arquivo

Os arquivos têm um layout fixo. Cada arquivo de código deve conter as coisas nesta ordem:

- Um comentário do Doxygen com uma breve descrição do que está no arquivo.
- Inclusão de condição de abertura (só nos cabeçalhos).
- Inclusão de cabeçalhos do sistema, por exemplo, `#include <header>`. Esses cabeçalhos devem ser ordenados alfabeticamente ou ordenados por dependências de biblioteca.
- Inclusão de cabeçalho interno, por exemplo, #include "header.h". Esses cabeçalhos devem ser ordenados alfabeticamente.
- O próprio código. Aqui a ordem é mais flexível, mas geralmente as declarações de funções globais devem vir depois das declarações de classe. A ordem das definições no arquivo `.cpp` deve corresponder a ordem das declarações no arquivo `.hpp`. Comentários Doxygen mais específicos no arquivo `.hpp`.
- Fechamento de condição.

Exemplo:

```
/** @file
 * Selector component (click and rubberband)
 */

#ifndef SEEN_UI_TOOL_SELECTOR_H
#define SEEN_UI_TOOL_SELECTOR_H

#include <memory>
#include <gdk/gdk.h>
#include <2geom/rect.h>
#include "ui/tool/manipulator.h"

class SPDesktop;
class CtrlRect;

namespace Inkscape
{
    namespace UI
    {

        class SelectorPoint;

        class Selector : public Manipulator
        {
        public:
            Selector(SPDesktop *d);
            virtual ~Selector();
            virtual bool event(SPEventContext *, GdkEvent *);

            sigc::signal<void, Geom::Rect const &, GdkEventButton *> signal_area;
            sigc::signal<void, Geom::Point const &, GdkEventButton *> signal_point;

        private:
            SelectorPoint *_dragger;
            Geom::Point _start;
            CtrlRect *_rubber;
            gulong _connection;
            bool _cancel;
            friend class SelectorPoint;
        };

    } // namespace UI
} // namespace Inkscape

#endif
```
