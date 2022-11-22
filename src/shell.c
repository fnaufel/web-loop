#include <emscripten.h>
#include <string.h>

#define MAXCHARSAIDA 256

/*
Função echo() para emitir um string no terminal.
Chama, em javascript, o método echo() do objeto terminal.
Esta função deve ser a ÚNICA maneira de emitir saída no shell.
*/
EM_JS(
      void,
      echo,
      (const char* str),
      { Module.term.echo(UTF8ToString(str)); }
)

/*
Função chamada pelo terminal para processar o comando entrado.

Esta função deve ser a ÚNICA maneira de obter entrada do shell.

A qualquer momento, esta função pode chamar a função echo(), definida
logo acima, para emitir saída no terminal.
*/
void process_command(char *command) {

  char saida[MAXCHARSAIDA];

  saida[0] = 0;

  strcat( saida, "Recebido o comando \"" );
  strcat( saida, command );
  strcat( saida, "\".");

  echo( saida );

}
