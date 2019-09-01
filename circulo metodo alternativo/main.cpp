#include <allegro.h> ///importa a biblioteca allegro...

int main(){ //estrutura main (principal do programa)
    ///inicializa��o...
    allegro_init(); //inicializa o alegro...
    install_timer();//inicializa os timers
    install_keyboard();//instala e inicializa teclado
    set_color_depth(32); //32 bits cor suportada... (fundo)
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0); //resolu��o comprimento x altura... eixo x, y coordenadas... (define o tipo de placa de video)...
    set_window_title("Teste Allegro Circulo");//titulo da janela

    ///variaveis...
    int x = 100, y = 100; //variaveis para mover o objeto na tela...
    BITMAP* buffer = create_bitmap(800, 600); //fun��o para ponteiro BITMAP... (especifique o tamanho da janela a ser desenhado...
    ///acima, � criado um ponteiro para desenhar a janela...

    //nota no allegro, y � invertido a posi��o inicial do plano � sempre do top para a esquerda e de cima para baixo... alt + 201 (dica)

    while(!key[KEY_ESC]){///se esc for pressionada, a aplica��o � encerrada...
          ///os comandos abaixo permitem capturar a tecla referida...
          if(key[KEY_RIGHT]) x += 1; //vai para a direita...
          if(key[KEY_LEFT])  x -= 1; //vai para a esquerda...
          if(key[KEY_UP])    y -= 1; //aqui � necess�rio inverter
          if(key[KEY_DOWN])  y += 1;//idem item anterior...

          //circlefill(screen, x, y, 100,makecol(255,012,033));//desenha o circulo...(mapa de bits na tela....)
          circlefill(buffer, x, y, 100,makecol(255,012,033));
          draw_sprite(screen, buffer, 0, 0); //passa o buffer para screen... (desenha)... (posi��o incio x , y)

          rest(1);//controla a velocidade...(depende da performance da CPU para rodar ok...)
          //rest(10);
          clear(buffer);
          //clear(screen);//limpa e atualiza a tela... (mapa de bits)
          }
    destroy_bitmap(buffer);///destroi o bitmap e libera a mem�ria...
    return 0;//indica que o programa execultou oom sucesso...
}
END_OF_MAIN(); ///fim da fun��o main (Allegro)...