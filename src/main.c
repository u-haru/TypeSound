#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

void exitfunc(){
    printf("Exit now...\n");
	char c;
    while ((c = getchar()) != EOF){}//バッファクリア
}
int main()
{
    atexit(exitfunc);
	bool key[0xff];
	memset(key,0,sizeof(key));
	while (true)
	{
		for(int i = 0; i < 0xff; i++) {
			if(GetAsyncKeyState(i) && !key[i]){
				key[i] = true;
				switch(i){
					case VK_SPACE: PlaySound("Sounds/SPACE.wav", 0, SND_FILENAME | SND_ASYNC);break;
					case VK_RETURN: PlaySound("Sounds/ENTER.wav", 0, SND_FILENAME | SND_ASYNC);break;
					default: PlaySound("Sounds/KEYS.wav", 0, SND_FILENAME | SND_ASYNC);break;
				}
			}else if(!GetAsyncKeyState(i)) key[i] = false;
		}
	}
	return 0;
}