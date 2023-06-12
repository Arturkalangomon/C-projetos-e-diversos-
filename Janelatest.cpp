#include <windows.h>

/* This is where all the input to the window goes to */
/* Isso é aqui onde toda a entrada para a janela vai */
/* Protópito do procedimento da janela*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		/* Destruir processo pai, diz a thread principal para parar */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		/* TODAS as outras mensagens (um monte delas) são preocessadas usando procedimetnos padrões */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
/* A função "principal/main" de programas GUI Win32: É aqui que a execução começa */ //GUI Graphic User Interface (interface grafica de usuario))...
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */ //windowsclass wndclass classe da janela...
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */ //identificador , daí o H ou ponteiro nossa janela...
	MSG msg; /* A temporary location for all messages */ //mensagens... uma localização temporaria para todas as mensagens...

	/* zero out the struct and set the stuff we want to modify */
	/* zere a estrutura e defina as coisas que queremos modificar */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //define a cor de fundo da janela
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */ //define um icone padrão...
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */ //nome para projeto de icone...

	if(!RegisterClassEx(&wc)) { /* registrando a classe wc (extamente a wndclass no outro programa)*/
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Janela",WS_VISIBLE|WS_OVERLAPPEDWINDOW, /* Criando uma janela baseada na classe WindowsClass*/
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK); //WindowsClass falha na criação da janela
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage.
		
		Este é o coração do nosso programa onde todas a entrada são processadas e enviadas para WndProc.
		Note que GhetMessage bloqueia o fluxo de código até receber algo, então, ese loop (Laço) não produzirá
		uso excessivamente alto da CPU.
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam; //fim do programa
}
