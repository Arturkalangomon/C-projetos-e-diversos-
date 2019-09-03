#include <allegro.h>

int main(){
    //inicialização biblioteca allegro
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    set_window_title("Sprites Alternativo...");

    //variaveis...
    int x = 0, y = 0;//, vel = 5;

    BITMAP* buffer = create_bitmap(800, 600);
    BITMAP* imagem = load_bitmap("guilmon.bmp",NULL);//especifique a imagem (extensão de arquivo deve ser bitmap...
    BITMAP* imagem2 = load_bitmap("guilmon2.bmp",NULL);//vai desenhar outra imagem...
    BITMAP* face = load_bitmap("guilmon.bmp",NULL);

    ///os sprites deve ter fundo rosa (para que a função ignore a cor...

    //loop
    while(!key[KEY_ESC]){
        ///atualizados...
        //controles para a imagem...
        if(key[KEY_RIGHT]){ x += 1; face = imagem;}
        if(key[KEY_LEFT]) { x -= 1; face = imagem2;}
        if(key[KEY_UP])     y -= 1;
        if(key[KEY_DOWN])   y += 1;

        //draw_sprite(buffer, imagem, 100 + x, 100 + y); //define onde a imagem vai inicializar e controla a imagem...
        draw_sprite(buffer, face, 100 + x, 100 + y); //desenhará a face não mais a imagem.... (dando ilusão do sprite virar

        //desenha o sprite buffer...
        draw_sprite(screen, buffer, 0, 0);//desenha o sprite no respectiva coordenada...
        rest(1);//controla a velocidade do sprite...
        clear(buffer);//limpa o buffer...

    }

        destroy_bitmap(buffer);
        destroy_bitmap(imagem);
        destroy_bitmap(imagem2);
        destroy_bitmap(face);

return 0;
}
END_OF_MAIN();
